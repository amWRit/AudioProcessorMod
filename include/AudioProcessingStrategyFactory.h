#pragma once
#include <memory>

#include "AudioFileHandler.h"
#include "AudioProcessingStrategy.h"
#include "ExtractAudioChunksStrategy.h"
#include "FilterFrequencyRangeStrategy.h"

class AudioProcessingStrategyFactory {
public:
    static std::shared_ptr<AudioProcessingStrategy> createStrategy(const std::string& strategyType) {
        if (strategyType == "extract") {
            return std::make_shared<ExtractAudioChunksStrategy>(80.0, 5000.0);
        } else if (strategyType == "filter") {
            //return std::make_shared<FilterFrequencyRangeStrategy>(100.0, 1000.0);  // Example values
        }
        // Add more strategy creation logic as needed
        return nullptr;
    }
};
