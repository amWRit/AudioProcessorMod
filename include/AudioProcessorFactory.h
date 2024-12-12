#pragma once
#include <memory>
#include "AudioProcessor.h"
#include "WaveAudioProcessor.h"

class AudioProcessorFactory {
public:
    static std::unique_ptr<AudioProcessor> createAudioProcessor(const std::string& type) {
        if (type == "wav" || type == "aiff") {
            return std::make_unique<WaveAudioProcessor>();
        }

        // Todo: Add additional formats.
        // if (type == "mp3") {
        //     return std::make_unique<MP3AudioProcessor>();
        // }
        return nullptr;
    }
};
