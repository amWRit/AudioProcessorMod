#include "Instrument.h"

class Drum : public Instrument {
public:
    double getLowFreq() const override { return 30.0; }
    double getHighFreq() const override { return 500.0; }
};
