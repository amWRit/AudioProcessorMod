#ifndef FFTPROCESSOR_H
#define FFTPROCESSOR_H

#include <vector>
#include "../include/kissfft/kiss_fft.h"
#include "../include/kissfft/kiss_fftr.h"

class FFTProcessor {
    public:
        FFTProcessor(size_t fftSize, double sampleRate);
        ~FFTProcessor();

        void performFFT(const std::vector<double>& channelData);

        std::vector<double> performIFFT(const std::vector<kiss_fft_cpx>& fftOutput);

        const std::vector<kiss_fft_cpx>& getFFTOutput() const;

    private:
        size_t fftSize;
        double sampleRate;
        kiss_fft_cfg cfg; // For FFT
        kiss_fft_cfg cfgInverse; // For IFFT
        std::vector<kiss_fft_cpx> in;
        std::vector<kiss_fft_cpx> out;
        //Todo: calculation of frequencies and magnitudes has been moved to signalprocessor
        // so why this might be necessary here
        std::vector<double> frequencies; 
        std::vector<double> magnitudes;
};

#endif // FFTPROCESSOR_H
