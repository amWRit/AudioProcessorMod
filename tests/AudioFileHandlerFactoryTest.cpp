#include <gtest/gtest.h>
#include "../include/AudioFileHandlerFactory.h"
#include "../include/WaveAudioFileHandler.h"

TEST(AudioFileHandlerFactoryTest, SupportedTypes) {
    // Test for "wav"
    auto wavHandler = AudioFileHandlerFactory::createAudioFileHandler("wav");
    EXPECT_NE(wavHandler, nullptr); // Should not be null
    EXPECT_TRUE(dynamic_cast<WaveAudioFileHandler*>(wavHandler.get()) != nullptr);

    // Test for "aiff"
    auto aiffHandler = AudioFileHandlerFactory::createAudioFileHandler("aiff");
    EXPECT_NE(aiffHandler, nullptr); // Should not be null
    EXPECT_TRUE(dynamic_cast<WaveAudioFileHandler*>(aiffHandler.get()) != nullptr);
}

TEST(AudioFileHandlerFactoryTest, UnsupportedTypes) {
    // Test for unsupported type "mp3"
    auto mp3Handler = AudioFileHandlerFactory::createAudioFileHandler("mp3");
    EXPECT_EQ(mp3Handler, nullptr);

    // Test for unsupported type "txt"
    auto txtHandler = AudioFileHandlerFactory::createAudioFileHandler("txt");
    EXPECT_EQ(txtHandler, nullptr);

    // Test for random invalid input
    auto invalidHandler = AudioFileHandlerFactory::createAudioFileHandler("invalid_type");
    EXPECT_EQ(invalidHandler, nullptr); // Should return null

    // Test for empty string
    auto emptyHandler = AudioFileHandlerFactory::createAudioFileHandler("");
    EXPECT_EQ(emptyHandler, nullptr);
}
