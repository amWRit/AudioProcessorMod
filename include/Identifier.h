#pragma once

#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <vector>
#include <string>

class Identifier {
    public:
        // Todo: now it just returns the filtered frequencies returned by filterFrequencies() method
        // See if this method can be used for something else
        virtual std::vector<double> identifyInstruments(const std::vector<double>& frequencies,
                                                const std::vector<double>& magnitudes) = 0;
        virtual ~Identifier() = default;

    protected:
        // Utility method to filter frequencies within a given range
        // Todo: what magnitudeThreshold is best?
        // it does the same job as filterFrequencyComponents() in signalprocessor - recheck
        std::vector<double> filterFrequencies(const std::vector<double>& frequencies,
                                            const std::vector<double>& magnitudes,
                                            double lowRange,
                                            double highRange,
                                            double magnitudeThreshold = 0.001);
};

#endif // IDENTIFIER_H