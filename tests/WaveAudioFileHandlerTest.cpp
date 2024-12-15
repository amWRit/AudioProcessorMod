#include <gtest/gtest.h>
#include "../include/WaveAudioFileHandler.h"
#include "AudioFile.h" // Ensure this includes the necessary functionality for your audio file handling

// Mock or Temporary Audio File Path
const std::string TEST_AUDIO_FILE = "../../audio/input/test1.wav";

// Test for loading audio using WaveAudioProcessor
TEST(WaveAudioFileHandlerTest, LoadAudioTest) {
    WaveAudioFileHandler fileHandler;

    // Test loading a valid file
    EXPECT_TRUE(fileHandler.loadAudio(TEST_AUDIO_FILE));

    // Test loading an invalid file
    EXPECT_FALSE(fileHandler.loadAudio("invalid_file.wav"));
}

// Test for saving audio to a file
TEST(WaveAudioFileHandlerTest, SaveAudioTest) {
    WaveAudioFileHandler fileHandler;

    // Load an audio file
    EXPECT_TRUE(fileHandler.loadAudio(TEST_AUDIO_FILE));

    // Save it to a new file
    const std::string outputFile = "output_audio.wav";
    fileHandler.saveAudio(outputFile, fileHandler.getBuffer()[0], fileHandler.getSampleRate());

    // Here you can check if the file exists or verify its properties if needed
    EXPECT_TRUE(std::ifstream(outputFile).good()); // Check if file exists
}

// Test for getBuffer
TEST(WaveAudioFileHandlerTest, GetBufferTest) {
    WaveAudioFileHandler fileHandler;

    // Load an audio file
    EXPECT_TRUE(fileHandler.loadAudio(TEST_AUDIO_FILE));

    // Check if buffer is populated
    const auto& buffer = fileHandler.getBuffer();
    EXPECT_FALSE(buffer.empty()); // Ensure the buffer isn't empty
}

// Test for getSampleRate
TEST(WaveAudioFileHandlerTest, GetSampleRateTest) {
    WaveAudioFileHandler fileHandler;

    // Load an audio file
    EXPECT_TRUE(fileHandler.loadAudio(TEST_AUDIO_FILE));

    // Verify the sample rate is correctly retrieved
    EXPECT_EQ(fileHandler.getSampleRate(), 44100); // Example: Expected sample rate of 44100
}

// Test for getBitDepth
TEST(WaveAudioFileHandlerTest, GetBitDepthTest) {
    WaveAudioFileHandler fileHandler;

    // Load an audio file
    EXPECT_TRUE(fileHandler.loadAudio(TEST_AUDIO_FILE));

    // Verify the bit depth is correctly retrieved
    EXPECT_EQ(fileHandler.getBitDepth(), 16); // Example: Expected bit depth of 16 bits
}
