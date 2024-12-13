#include "../include/InstrumentFactory.h"
#include "../include/Guitar.h"
#include "../include/Drum.h"
#include "../include/Piano.h"
#include "../include/XXHuman.h"
#include "../include/XYHuman.h"
#include "../include/Cymbal.h"
#include "../include/Synth.h"

std::shared_ptr<Instrument> InstrumentFactory::createInstrument(const std::string& instrumentType) {
    if (instrumentType == "guitar") return std::make_shared<Guitar>();
    if (instrumentType == "drum") return std::make_shared<Drum>();
    if (instrumentType == "piano") return std::make_shared<Piano>();
    if (instrumentType == "xxhuman") return std::make_shared<XXHuman>();
    if (instrumentType == "xyhuman") return std::make_shared<XYHuman>();
    if (instrumentType == "cymbal") return std::make_shared<Cymbal>();
    if (instrumentType == "synth") return std::make_shared<Synth>();
    return nullptr; // Or handle unknown instrument types
}
