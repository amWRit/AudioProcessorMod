#pragma once
#include <memory>

#include "AudioFileHandler.h"
#include "AudioProcessingStrategy.h"
#include "ExtractAudioChunksStrategy.h"
#include "FilterFrequencyRangeStrategy.h"
#include "ChangeAudioSpeedStrategy.h"
#include "ChangeAudioVolumeStrategy.h"
#include "AudioReverbStrategy.h"
#include "AudioReverseStrategy.h"
#include "InstrumentFactory.h"
#include "EnumClass.h"

class AudioProcessingStrategyFactory {
    public:
        static std::shared_ptr<AudioProcessingStrategy> createStrategy(StrategyType strategyType, InstrumentType instrumentType = InstrumentType::Unknown, double factor = 1.0) {
            if (strategyType == StrategyType::AudioExtract) {
                // return std::make_shared<ExtractAudioChunksStrategy>(80.0, 5000.0);
                std::shared_ptr<Instrument> instrument = InstrumentFactory::createInstrument(instrumentType);
                if (instrument) {
                    double lowFreq = instrument->getLowFreq();
                    double highFreq = instrument->getHighFreq();
                    
                    return std::make_shared<ExtractAudioChunksStrategy>(lowFreq, highFreq);
                }
            } else if (strategyType == StrategyType::ChangeAudioSpeed) {
                return std::make_shared<ChangeAudioSpeedStrategy>(factor);
            }
            else if (strategyType == StrategyType::ChangeAudioVolume) {
                return std::make_shared<ChangeAudioVolumeStrategy>(factor);
            }
            //Todo: ask decayFactor frrom user 
            else if (strategyType == StrategyType::AudioReverb) {
                return std::make_shared<AudioReverbStrategy>(factor, 0.5);
            }
            else if (strategyType == StrategyType::AudioReverse) {
                return std::make_shared<AudioReverseStrategy>();
            }
            // Add more strategy creation logic as needed
            return nullptr;
        }
};
