#include <iostream>
#include <vector>
#include <string>
#include "../include/WaveAudioProcessor.h"
#include "../include/FFTProcessor.h"
#include "../include/GuitarIdentifier.h"
#include "../include/DrumIdentifier.h"
#include "../include/SignalProcessor.h"


int main() {
    // Create an waveProcessor object (using WaveAudioProcessor)
    WaveAudioProcessor waveProcessor;

    std::string filePath = "../audio/input/hbsong.wav"; // Todo: Ask from user 
    if (!waveProcessor.loadAudio(filePath)) {
        std::cerr << "Failed to load audio file: " << filePath << std::endl;
        return -1;
    }

    // audioFile.printSummary();

    // Extract buffer and metadata
    const auto& buffer = waveProcessor.getBuffer();
    double sampleRate = waveProcessor.getSampleRate();
    int bitDepth = waveProcessor.getBitDepth();

    std::cout << "Audio file loaded successfully!\n";
    std::cout << "Sample Rate: " << sampleRate << " Hz\n";
    std::cout << "Bit Depth: " << bitDepth << " bits\n";
    std::cout << "Channels: " << buffer.size() << "\n";

    //Assuming the audio is only channel for now
    if (buffer.empty() || buffer[0].empty()) {
        std::cerr << "Audio buffer is empty or corrupted.\n";
        return -1;
    }

    // Process the first channel
    std::vector<double> originalSignal = buffer[0];
    // Set the FFT size
    size_t fftSize = 4096;

    // // -- testing
    // // Create a test signal (e.g., a sine wave)
    // // Signal parameters
    // sampleRate = 44100.0;  // 44.1 kHz sample rate
    // double duration = 2.0;        // Signal duration in seconds
    // double frequency = 440.0;     // Frequency of sine wave (e.g., 440 Hz, A4 note)

    // // Calculate the total number of samples for the desired duration
    // fftSize = static_cast<size_t>(sampleRate * duration);

    // // Create the signal with the desired length
    // std::vector<double> originalSignal(fftSize);

    // for (size_t i = 0; i < fftSize; ++i) {
    //     originalSignal[i] = std::sin(2.0 * M_PI * frequency * i / sampleRate);  // A 440 Hz sine wave
    // }
    // // -- testing

    // Create an FFTProcessor instance
    FFTProcessor fftProcessor(fftSize, sampleRate);

    // Perform FFT processing on the data
    fftProcessor.performFFT(originalSignal);

    // Retrieve frequencies and magnitudes
    // std::vector<double> frequencies = fftProcessor.getFrequencies();
    // std::vector<double> magnitudes = fftProcessor.getMagnitudes();
    // could use a map to store freq and mag --> use a single method ?
    std::vector<kiss_fft_cpx> fftOutput = fftProcessor.getFFTOutput();
    std::vector<double> frequencies = SignalProcessor::calculateFrequencies(fftSize, sampleRate, fftOutput);
    std::vector<double> magnitudes = SignalProcessor::calculateMagnitudes(fftSize, sampleRate, fftOutput);

    // Print the results (for demonstration purposes)
    std::cout << "Frequency Spectrum:\n";
    for (size_t i = 0; i < frequencies.size(); ++i) {
        std::cout << "Frequency: " << frequencies[i] << " Hz, Magnitude: " << magnitudes[i] << "\n";
    }

    std::cout << "FFT computed successfully!\n";
    std::cout << "Frequencies and magnitudes extracted.\n";

    // Identify frequencies of Guitar
    GuitarIdentifier guitarIdentifier;
    std::vector<double> guitarFrequencies = guitarIdentifier.identifyInstruments(frequencies, magnitudes);

    if (!guitarFrequencies.empty()) {
        std::cout << "Guitar Detected at Frequencies: ";
        for (double freq : guitarFrequencies) {
            std::cout << freq << " Hz ";
        }
        std::cout << "\n";
    }

    std::cout << "==================================\n";
    //Identify frequencies of Drum
    DrumIdentifier drumIdentifier;
    std::vector<double> drumFrequencies = drumIdentifier.identifyInstruments(frequencies, magnitudes);

    if (!drumFrequencies.empty()) {
        std::cout << "Drum Detected at Frequencies: ";
        for (double freq : drumFrequencies) {
            std::cout << freq << " Hz ";
        }
        std::cout << "\n";
    }
    std::cout << "==================================\n";

    // Perform the FFT on the original audio signal (assuming this is already done)
    fftOutput = fftProcessor.getFFTOutput();  // FFT of the original audio
    auto allTimeSignal = fftProcessor.performIFFT(fftOutput);  // Perform IFFT on the entire FFT output
    
    // -- testing
    // // Normalize the IFFT result
    // double scale = 1.0 / fftSize;  // Normalize by the FFT size
    // for (auto& sample : allTimeSignal) {
    //     sample *= scale;
    // }
    
    // Compare the original and the IFFT result
    bool result = SignalProcessor::compareSignals(originalSignal, allTimeSignal);
    if (result) {
        std::cout << "FFT and IFFT are successful, original and IFFT signals match!" << std::endl;
    } else {
        std::cerr << "FFT and IFFT results do not match!" << std::endl;
    }
    // -- testing 
    // waveProcessor.saveAudio("../audio/output/original.wav", originalSignal, sampleRate);
    // waveProcessor.saveAudio("../audio/output/all.wav", allTimeSignal, sampleRate);

    // Filter for Guitar
    // std::vector<kiss_fft_cpx> guitarFFT;
    // guitarFFT = SignalProcessor::filterFrequencyComponents(fftProcessor.getFFTOutput(), guitarFrequencies, guitarIdentifier.getLowGuitar(), guitarIdentifier.getHighGuitar());
    // auto guitarTimeSignal = fftProcessor.performIFFT(guitarFFT);
    // waveProcessor.saveAudio("../audio/output/guitarAudio.wav", guitarTimeSignal, sampleRate);

    // Filter for Drum
    // std::vector<kiss_fft_cpx> drumFFT;
    // drumFFT = SignalProcessor::filterFrequencyComponents(fftProcessor.getFFTOutput(), drumFrequencies, drumIdentifier.getLowDrum(), drumIdentifier.getHighDrum());
    // auto drumTimeSignal = fftProcessor.performIFFT(drumFFT);
    // waveProcessor.saveAudio("../audio/output/drumAudio.wav", drumTimeSignal, sampleRate);

    //using new extract audio method
    std::vector<double> guitarTimeSignal  = SignalProcessor::extractAudioFromChunks(
        originalSignal, fftSize, sampleRate, 
        guitarIdentifier.getLowGuitar(), guitarIdentifier.getHighGuitar(), 
        fftProcessor
    );
    waveProcessor.saveAudio("../audio/output/guitarAudio.wav", guitarTimeSignal, sampleRate);

    //using new extract audio method
    std::vector<double> drumTimeSignal  = SignalProcessor::extractAudioFromChunks(
        originalSignal, fftSize, sampleRate, 
        drumIdentifier.getLowDrum(), drumIdentifier.getHighDrum(), 
        fftProcessor
    );
    waveProcessor.saveAudio("../audio/output/drumAudio.wav", drumTimeSignal, sampleRate);
    std::cout << "Separated audio saved as guitarAudio.wav and drumAudio.wav\n";

    getchar();
    return 0;
}
