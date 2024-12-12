#pragma once
#include <string>
#include <algorithm>

class Utils {
public:
    static std::string getFileExtension(const std::string& filePath) {
        size_t dotPosition = filePath.find_last_of('.');
        if (dotPosition == std::string::npos) {
            return ""; // No extension found
        }
        std::string extension = filePath.substr(dotPosition + 1);
        std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
        return extension;
    }
};
