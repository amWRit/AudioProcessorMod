#include <gtest/gtest.h>
#include "../include/WaveAudioProcessor.h"
#include "AudioFile.h" // Ensure this includes the necessary functionality for your audio file handling

// Mock or Temporary Audio File Path
const std::string TEST_AUDIO_FILE = "../../audio/input/test1.wav";

// Test for loading audio using WaveAudioProcessor
TEST(WaveAudioProcessorTest, LoadAudioTest) {
    WaveAudioProcessor processor;

    // Test loading a valid file
    EXPECT_TRUE(processor.loadAudio(TEST_AUDIO_FILE));

    // Test loading an invalid file
    EXPECT_FALSE(processor.loadAudio("invalid_file.wav"));
}

// Test for saving audio to a file
TEST(WaveAudioProcessorTest, SaveAudioTest) {
    WaveAudioProcessor processor;

    // Load an audio file
    EXPECT_TRUE(processor.loadAudio(TEST_AUDIO_FILE));

    // Save it to a new file
    const std::string outputFile = "output_audio.wav";
    processor.saveAudio(outputFile, processor.getBuffer()[0], processor.getSampleRate());

    // Here you can check if the file exists or verify its properties if needed
    EXPECT_TRUE(std::ifstream(outputFile).good()); // Check if file exists
}

// Test for getBuffer
TEST(WaveAudioProcessorTest, GetBufferTest) {
    WaveAudioProcessor processor;

    // Load an audio file
    EXPECT_TRUE(processor.loadAudio(TEST_AUDIO_FILE));

    // Check if buffer is populated
    const auto& buffer = processor.getBuffer();
    EXPECT_FALSE(buffer.empty()); // Ensure the buffer isn't empty
}

// Test for getSampleRate
TEST(WaveAudioProcessorTest, GetSampleRateTest) {
    WaveAudioProcessor processor;

    // Load an audio file
    EXPECT_TRUE(processor.loadAudio(TEST_AUDIO_FILE));

    // Verify the sample rate is correctly retrieved
    EXPECT_EQ(processor.getSampleRate(), 44100); // Example: Expected sample rate of 44100
}

// Test for getBitDepth
TEST(WaveAudioProcessorTest, GetBitDepthTest) {
    WaveAudioProcessor processor;

    // Load an audio file
    EXPECT_TRUE(processor.loadAudio(TEST_AUDIO_FILE));

    // Verify the bit depth is correctly retrieved
    EXPECT_EQ(processor.getBitDepth(), 16); // Example: Expected bit depth of 16 bits
}
