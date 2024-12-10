#include "GuitarIdentifier.h"

// Todo: now it just returns the filtered frequencies returned by filterFrequencies() method
// See if this method can be used for something else
std::vector<double> GuitarIdentifier::identifyInstruments(const std::vector<double>& frequencies,
                                                  const std::vector<double>& magnitudes) {
    // std::vector<double> guitarFrequencies;
    // // Example frequency ranges for guitar notes (simplified for demonstration)
    // const double LOW_E = 82.41;  // Low E string, 82.41 Hz
    // const double HIGH_E = 659.25; // High E string, 659.25 Hz

    // // Check if any frequencies fall within the typical guitar range

    // for (size_t i = 0; i < frequencies.size(); ++i) {
    //     if (magnitudes[i] > 0.01) // Ignore low-magnitude noise
    //         if (frequencies[i] >= LOW_E && frequencies[i] <= HIGH_E)
    //             guitarFrequencies.push_back(frequencies[i]);
    // }

    // return guitarFrequencies;
    // Example frequency ranges for guitar notes
    // const double LOW_E = 82.41;  // Low E string
    // const double HIGH_E = 659.25; // High E string

    return filterFrequencies(frequencies, magnitudes, getLowGuitar(), getHighGuitar());

}
