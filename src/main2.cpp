#include "../include/AudioFile.h"
#include "../include/kissfft/kiss_fft.h"
#include <cmath>
#include <iostream>
#include <vector>

#include "../include/identify.h"

class WavFile {
    private:
        std::string filename;
        int sampleRate;
        int bitDepth;
        std::vector<uint8_t> data;

    public:
        WavFile(const std::string& file) : filename(file) {}
        void parseHeader();
        const std::vector<uint8_t>& getData() const { return data; }
        int getSampleRate() const { return sampleRate; }
};

int main() {
    // Load the audio file
    AudioFile<double> audioFile;
    audioFile.load("../audio/test1.wav");
    auto buffer = audioFile.samples;
    double sampleRate = audioFile.getSampleRate();

    audioFile.printSummary();

    // Process the first channel
    std::vector<double> channelData = buffer[0];
    size_t fftSize = 1024;

    // Resize to fit FFT requirements
    if (channelData.size() < fftSize) {
        channelData.resize(fftSize, 0.0);
    } else {
        channelData = std::vector<double>(channelData.begin(), channelData.begin() + fftSize);
    }

    // Perform FFT
    kiss_fft_cfg cfg = kiss_fft_alloc(fftSize, 0, nullptr, nullptr);
    std::vector<kiss_fft_cpx> in(fftSize);
    std::vector<kiss_fft_cpx> out(fftSize);

    for (size_t i = 0; i < fftSize; ++i) {
        in[i].r = channelData[i];
        in[i].i = 0.0;
    }

    kiss_fft(cfg, in.data(), out.data());
    free(cfg);

    std::vector<double> frequencies;
    std::vector<double> magnitudes;

    // Print FFT magnitude and corresponding frequencies
    std::cout << "Frequency Spectrum:\n";
    for (size_t i = 0; i < fftSize / 2; ++i) { // Only up to Nyquist
        double magnitude = std::sqrt(out[i].r * out[i].r + out[i].i * out[i].i);
        double frequency = i * sampleRate / fftSize;
        frequencies.emplace_back(frequency);
        magnitudes.emplace_back(magnitude);
        //std::cout << "Frequency: " << frequency << " Hz, Magnitude: " << magnitude << "\n";
    }
    std::cout << "------------------------\n";
    identifyInstruments(frequencies, magnitudes);
    getchar();
    return 0;
}

