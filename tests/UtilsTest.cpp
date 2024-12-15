#include <gtest/gtest.h>
#include "../include/Utils.h"

// test for getting file extension from valid path
TEST(UtilsTest, ValidExtensions){
    const std::string wavFilePath = "../../audio/input/test1.wav";
    const std::string aiffFilePath = "../../audio/input/test1.aiff";
    const std::string jpgFilePath = "../../audio/input/test1.jpg";
    EXPECT_EQ(Utils::getFileExtension(wavFilePath), "wav");
    EXPECT_EQ(Utils::getFileExtension(aiffFilePath), "aiff");
    EXPECT_EQ(Utils::getFileExtension(jpgFilePath), "jpg");
}

// Test for filepaths with no extensions
TEST(UtilsTest, InvalidExtensions){
    EXPECT_EQ(Utils::getFileExtension(""), "");
    EXPECT_EQ(Utils::getFileExtension("noextensionhere"), "");
}

// Test for filepaths with multiple dots
TEST(UtilsTest, MultipleDots) {
    EXPECT_EQ(Utils::getFileExtension("my.file.name.wav"), "wav");
    EXPECT_EQ(Utils::getFileExtension("this.is.ext"), "ext");
}