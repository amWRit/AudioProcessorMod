#pragma once
#include "Identifier.h"

class DrumIdentifier : public Identifier {
    private:
        // Example: Low drum range, Bass Drum
        double LOW_DRUM = 40.0;
        double HIGH_DRUM = 500.0;

    public:
        double getLowDrum() const { return LOW_DRUM; }
        double getHighDrum() const { return HIGH_DRUM; }

        std::vector<double> identifyInstruments(const std::vector<double>& frequencies,
                                            const std::vector<double>& magnitudes) override;
};