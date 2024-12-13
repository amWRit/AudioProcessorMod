#include <iostream>
#include <vector>
#include <string>
#include "../include/Settings.h"
#include "../include/AudioFileHandlerFactory.h"
#include "../include/AudioProcessingStrategyFactory.h"
#include "../include/FFTProcessor.h"
#include "../include/InstrumentFactory.h"
#include "../include/SignalProcessor.h"
#include "../include/AudioFile.h"
#include "../include/Utils.h"

int main() {
    // Settings::setFFTSize(4096);
    size_t fftSize = Settings::getFFTSize();

    std::string inputFilePath = "../audio/input/test1.wav"; // Todo: Ask from user 

    // Get the file extension (e.g., "wav")
    std::string format = Utils::getFileExtension(inputFilePath);
    std::transform(format.begin(), format.end(), format.begin(), ::tolower); // Convert to lowercase for consistency

    std::cout << "format: " << format << std::endl;
    // Use the format to create an appropriate AudioProcessor
    auto fileHandler = AudioFileHandlerFactory::createAudioFileHandler(format);
    std::cout << "handler: " << fileHandler << std::endl;
    if (!fileHandler) {
        std::cerr << "Unsupported audio format!" << std::endl;
        return -1;
    }

    if (!fileHandler->loadAudio(inputFilePath)) {
        std::cerr << "Failed to load audio file: " << inputFilePath << std::endl;
        return -1;
    }

    // audioFile.printSummary();

    // Extract buffer and metadata
    const auto& buffer = fileHandler->getBuffer();
    double sampleRate = fileHandler->getSampleRate();
    int bitDepth = fileHandler->getBitDepth();

    std::cout << "Audio file loaded successfully!\n";
    std::cout << inputFilePath << "\n";
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
    //size_t fftSize = 4096;

    // Get the strategy type from user input or configuration (e.g., "fft" or "filter")
    std::string strategyType = "extract";  // Example input (could be user-driven)

    // Repeat for Drum
    std::string instrumentType = "drum";
    // Use the factory to create the appropriate strategy
    auto strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType);
    if (!strategy) {
        std::cerr << "Unsupported strategy!" << std::endl;
        return -1;
    }
    // Process the audio signal using the selected strategy
    std::vector<double> timeDomainSignal = strategy->process(fileHandler);
    std::string outputFilePath = "../audio/output/extracted" + instrumentType + "Audio.wav";
    fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);

    // Repeat for Cymbal
    instrumentType = "cymbal";
    strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType);
    if (!strategy) {
        std::cerr << "Unsupported strategy!" << std::endl;
        return -1;
    }
    timeDomainSignal = strategy->process(fileHandler);
    outputFilePath = "../audio/output/extracted" + instrumentType + "Audio.wav";
    fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);

    // Repeat for Synth
    instrumentType = "synth";
    strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType);
    if (!strategy) {
        std::cerr << "Unsupported strategy!" << std::endl;
        return -1;
    }
    timeDomainSignal = strategy->process(fileHandler);
    outputFilePath = "../audio/output/extracted" + instrumentType + "Audio.wav";
    fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);

    // Repeat for Cymbal
    instrumentType = "xxhuman";
    strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType);
    if (!strategy) {
        std::cerr << "Unsupported strategy!" << std::endl;
        return -1;
    }
    timeDomainSignal = strategy->process(fileHandler);
    outputFilePath = "../audio/output/extracted" + instrumentType + "Audio.wav";
    fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);

    // Repeat for Cymbal
    instrumentType = "xyhuman";
    strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType);
    if (!strategy) {
        std::cerr << "Unsupported strategy!" << std::endl;
        return -1;
    }
    timeDomainSignal = strategy->process(fileHandler);
    outputFilePath = "../audio/output/extracted" + instrumentType + "Audio.wav";
    fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);
    // //Repeat for guitar
    // instrumentType = "guitar";
    // strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType);
    // if (!strategy) {
    //     std::cerr << "Unsupported strategy!" << std::endl;
    //     return -1;
    // }
    // timeDomainSignal = strategy->process(fileHandler);
    // outputFilePath = "../audio/output/extracted" + instrumentType + "Audio.wav";
    // fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);

    // //Repeat for piano
    // instrumentType = "piano";
    // strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType);
    // if (!strategy) {
    //     std::cerr << "Unsupported strategy!" << std::endl;
    //     return -1;
    // }
    // timeDomainSignal = strategy->process(fileHandler);
    // outputFilePath = "../audio/output/extracted" + instrumentType + "Audio.wav";
    // fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);

    // //Repeat for human
    // instrumentType = "human";
    // strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType);
    // if (!strategy) {
    //     std::cerr << "Unsupported strategy!" << std::endl;
    //     return -1;
    // }
    // timeDomainSignal = strategy->process(fileHandler);
    // outputFilePath = "../audio/output/extracted" + instrumentType + "Audio.wav";
    // fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);

    // // Create an FFTProcessor instance
    // FFTProcessor fftProcessor(fftSize, sampleRate);

    // // Perform FFT processing on the data
    // fftProcessor.performFFT(originalSignal);

    // // Retrieve frequencies and magnitudes
    // // could use a map to store freq and mag --> use a single method ?
    // std::vector<std::complex<double>> fftOutput = fftProcessor.getFFTOutput();
    // std::vector<double> frequencies = SignalProcessor::calculateFrequencies(fftSize, sampleRate, fftOutput);
    // std::vector<double> magnitudes = SignalProcessor::calculateMagnitudes(fftSize, sampleRate, fftOutput);

    // // Print the results (for demonstration purposes)
    // std::cout << "Frequency Spectrum:\n";
    // for (size_t i = 0; i < frequencies.size(); ++i) {
    //     std::cout << "Frequency: " << frequencies[i] << " Hz, Magnitude: " << magnitudes[i] << "\n";
    // }

    // std::cout << "FFT computed successfully!\n";
    // std::cout << "Frequencies and magnitudes extracted.\n";

    // // Identify frequencies of Guitar
    // GuitarIdentifier guitarIdentifier;
    // std::vector<double> guitarFrequencies = guitarIdentifier.identifyInstruments(frequencies, magnitudes);

    // if (!guitarFrequencies.empty()) {
    //     std::cout << "Guitar Detected at Frequencies: ";
    //     for (double freq : guitarFrequencies) {
    //         std::cout << freq << " Hz ";
    //     }
    //     std::cout << "\n";
    // }

    // std::cout << "==================================\n";
    // //Identify frequencies of Drum
    // DrumIdentifier drumIdentifier;
    // std::vector<double> drumFrequencies = drumIdentifier.identifyInstruments(frequencies, magnitudes);

    // if (!drumFrequencies.empty()) {
    //     std::cout << "Drum Detected at Frequencies: ";
    //     for (double freq : drumFrequencies) {
    //         std::cout << freq << " Hz ";
    //     }
    //     std::cout << "\n";
    // }
    // std::cout << "==================================\n";

    // Perform the FFT on the original audio signal (assuming this is already done)
    // fftOutput = fftProcessor.getFFTOutput();  // FFT of the original audio
    // auto allTimeSignal = fftProcessor.performIFFT(fftOutput);  // Perform IFFT on the entire FFT output
    
    //  // Compare the original and the IFFT result
    // bool result = SignalProcessor::compareSignals(originalSignal, allTimeSignal);
    // if (result) {
    //     std::cout << "FFT and IFFT are successful, original and IFFT signals match!" << std::endl;
    // } else {
    //     std::cerr << "FFT and IFFT results do not match!" << std::endl;
    // }
 
    // //using new extract audio method
    // std::vector<double> guitarTimeSignal  = SignalProcessor::extractAudioFromChunks(
    //     originalSignal, sampleRate, 
    //     guitarIdentifier.getLowGuitar(), guitarIdentifier.getHighGuitar()
    // );
    // fileHandler->saveAudio("../audio/output/guitarAudio.wav", guitarTimeSignal, sampleRate);

    // //using new extract audio method
    // std::vector<double> drumTimeSignal  = SignalProcessor::extractAudioFromChunks(
    //     originalSignal, sampleRate, 
    //     drumIdentifier.getLowDrum(), drumIdentifier.getHighDrum()
    // );
    // fileHandler->saveAudio("../audio/output/drumAudio.wav", drumTimeSignal, sampleRate);
    // std::cout << "Separated audio saved as guitarAudio.wav and drumAudio.wav\n";

    getchar();
    return 0;
}
