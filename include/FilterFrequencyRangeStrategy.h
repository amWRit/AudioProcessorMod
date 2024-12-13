// // FilterFrequencyRangeStrategy.h
// #pragma once
// #include "AudioProcessingStrategy.h"
// #include "AudioFileHandler.h"

// class FilterFrequencyRangeStrategy : public AudioProcessingStrategy {
// private:
//     double minFreq;
//     double maxFreq;

// public:
//     FilterFrequencyRangeStrategy(double minFreq, double maxFreq)
//         : minFreq(minFreq), maxFreq(maxFreq) {}

//     std::vector<double> process(AudioFileHandler& fileHandler) const override {
//         // Implement the logic to filter frequencies in the signal here.
//         // This is a placeholder for actual frequency-based filtering.
//         // Access buffer and metadata through AudioFileHandler
//         const auto& buffer = fileHandler.getBuffer();
//         double sampleRate = fileHandler.getSampleRate();

//         return fileHandler.getBuffer()[0];
//     }
// };
