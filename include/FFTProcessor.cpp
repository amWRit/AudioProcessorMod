#include "FFTProcessor.h"
#include <cmath>
#include <iostream>

FFTProcessor::FFTProcessor(size_t fftSize, double sampleRate) 
    : fftSize(fftSize), 
      sampleRate(sampleRate), 
      in(fftSize), 
      out(fftSize) {

    // Allocate FFT configuration
    cfg = kiss_fft_alloc(fftSize, 0, nullptr, nullptr);
    cfgInverse = kiss_fft_alloc(fftSize, 1, nullptr, nullptr); // Inverse FFT
}

FFTProcessor::~FFTProcessor() {
    // Free FFT configuration
    free(cfg);
}

// uses kiss_fft
void FFTProcessor::performFFT(const std::vector<double>& channelData) {
    // Resize channelData to fit FFT size (padding or truncating)
    std::vector<double> data = channelData;
    if (data.size() < fftSize) {
        data.resize(fftSize, 0.0);
    } else {
        data = std::vector<double>(data.begin(), data.begin() + fftSize);
    }

    // Fill the input array for FFT (real part, imaginary part is 0) - WHY?
    for (size_t i = 0; i < fftSize; ++i) {
        in[i].r = data[i];
        in[i].i = 0.0;
    }

    // Perform FFT
    kiss_fft(cfg, in.data(), out.data());
}

std::vector<double> FFTProcessor::performIFFT(const std::vector<kiss_fft_cpx>& fftOutput) {
    std::vector<double> timeDomainData(fftSize);
    std::vector<kiss_fft_cpx> ifftOutput(fftSize);
    // Perform Inverse FFT
    kiss_fft(cfgInverse, fftOutput.data(), ifftOutput.data());
    // Normalize and extract real part
    for (size_t i = 0; i < fftSize; ++i) {
        timeDomainData[i] = ifftOutput[i].r / fftSize; // Normalize by FFT size
    }
    return timeDomainData;
}


const std::vector<kiss_fft_cpx>& FFTProcessor::getFFTOutput() const {
    return out;
}