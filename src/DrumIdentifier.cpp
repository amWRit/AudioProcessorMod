#include "../include/DrumIdentifier.h"

std::vector<double> DrumIdentifier::identifyInstruments(const std::vector<double>& frequencies,
                                                  const std::vector<double>& magnitudes) {
    return filterFrequencies(frequencies, magnitudes, getLowDrum(), getHighDrum());
}
