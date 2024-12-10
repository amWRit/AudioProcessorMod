#include <iostream>
#include <vector>
#include <cmath>

void identifyInstruments(const std::vector<double>& frequencies, const std::vector<double>& magnitudes) {
    std::vector<double> bassFrequencies;
    std::vector<double> fluteFrequencies;

    for (size_t i = 0; i < frequencies.size(); ++i) {
        if (magnitudes[i] > 0.01) { // Ignore low-magnitude noise
            if (frequencies[i] >= 40 && frequencies[i] <= 400) {
                bassFrequencies.push_back(frequencies[i]);
            } else if (frequencies[i] >= 260 && frequencies[i] <= 4000) {
                fluteFrequencies.push_back(frequencies[i]);
            }
        }
    }

    // Output identified instruments
    if (!bassFrequencies.empty()) {
        std::cout << "Bass Guitar Detected at Frequencies: ";
        for (double freq : bassFrequencies) {
            std::cout << freq << " Hz ";
        }
        std::cout << "\n";
    }

    std::cout << "------------------------\n";
    
    if (!fluteFrequencies.empty()) {
        std::cout << "Flute Detected at Frequencies: ";
        for (double freq : fluteFrequencies) {
            std::cout << freq << " Hz ";
        }
        std::cout << "\n";
    }
}
