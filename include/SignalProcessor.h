#ifndef SIGNALPROCESSOR_H
#define SIGNALPROCESSOR_H

#include <vector>
#include <functional>
#include "../include/FFTProcessor.h"

// Todo: for now all the methods here are static
// this could be combined with audioprocessor?
class SignalProcessor {
    public:
        // 
        static std::vector<std::complex<double>> filterFrequencyComponents(
            const std::vector<std::complex<double>>& fftOutput,
            const std::vector<double>& frequencies,
            double lowFreq, double highFreq);
        
        // Helper function to compare two signals
        static bool compareSignals(
            const std::vector<double>& original, 
            const std::vector<double>& processed, 
            double tolerance = 1e-6);

        // return frequencies from fftouput
        static std::vector<double> calculateFrequencies(
            size_t fftSize,
            double sampleRate,
            const std::vector<std::complex<double>>& fftOutput
        );

        // return magnittudes from fftouput
        static std::vector<double> calculateMagnitudes(
            size_t fftSize,
            double sampleRate,
            const std::vector<std::complex<double>>& fftOutput
        );

        // method for chunking, processing and reconstructing audio
        static std::vector<double> extractAudioFromChunks(
            const std::vector<double>& originalSignal, 
            size_t fftSize, 
            double sampleRate,
            double lowFreq, 
            double highFreq,
            FFTProcessor& fftProcessor
        );

};

#endif // SIGNALPROCESSOR_H
