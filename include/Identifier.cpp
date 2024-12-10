#include "Identifier.h"

// Utility method to filter frequencies within a given range
std::vector<double> Identifier::filterFrequencies(const std::vector<double>& frequencies,
                                                  const std::vector<double>& magnitudes,
                                                  double lowRange,
                                                  double highRange,
                                                  double magnitudeThreshold) {
    std::vector<double> filteredFrequencies;

    for (size_t i = 0; i < frequencies.size(); ++i) {
        if (magnitudes[i] > magnitudeThreshold) { // Suppress noise
            if (frequencies[i] >= lowRange && frequencies[i] <= highRange) {
                filteredFrequencies.push_back(frequencies[i]);
            }
        }
    }

    return filteredFrequencies;
}
