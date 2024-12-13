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
    std::string strategyType = "audioExtract";  // Example input (could be user-driven)

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
    std::cout << "===Audio Extracted successfully!===\n\n";

    // == CHANGE SPEED TEST
    strategyType = "changeAudioSpeed";  // Example input (could be user-driven)
    instrumentType = "";
    double factor = 0.5;
    strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType, factor);
    if (!strategy) {
        std::cerr << "Unsupported strategy!" << std::endl;
        return -1;
    }
    timeDomainSignal = strategy->process(fileHandler);
    outputFilePath = "../audio/output/" + strategyType + ".wav";
    fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);
    std::cout << "=== Audio Speed Changed Successfully by SPEED FACTOR:" << factor << " ===\n\n";

    // == CHANGE VOLUME TEST
    strategyType = "changeAudioVolume";  // Example input (could be user-driven)
    instrumentType = "";
    factor = 2;
    strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType, factor);
    if (!strategy) {
        std::cerr << "Unsupported strategy!" << std::endl;
        return -1;
    }
    timeDomainSignal = strategy->process(fileHandler);
    outputFilePath = "../audio/output/" + strategyType + ".wav";
    fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);
    std::cout << "=== Audio Volume Changed Successfully by FACTOR:" << factor << " ===\n\n";
    
    // == REVERB TEST
    strategyType = "audioReverb";  // Example input (could be user-driven)
    instrumentType = "";
    factor = 0.2;
    strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType, factor);
    if (!strategy) {
        std::cerr << "Unsupported strategy!" << std::endl;
        return -1;
    }
    timeDomainSignal = strategy->process(fileHandler);
    outputFilePath = "../audio/output/" + strategyType + ".wav";
    fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);
    std::cout << "=== Audio Reverb Successfully by FACTOR:" << factor << " ===\n\n";

    // == REVERSE TEST
    strategyType = "audioReverse";  // Example input (could be user-driven)
    instrumentType = "";
    factor = 0;
    strategy = AudioProcessingStrategyFactory::createStrategy(strategyType, instrumentType, factor);
    if (!strategy) {
        std::cerr << "Unsupported strategy!" << std::endl;
        return -1;
    }
    timeDomainSignal = strategy->process(fileHandler);
    outputFilePath = "../audio/output/" + strategyType + ".wav";
    fileHandler->saveAudio(outputFilePath, timeDomainSignal, sampleRate);
    std::cout << "=== Audio Reversed Successfully:" << factor << " ===\n\n";

    getchar();
    return 0;
}
