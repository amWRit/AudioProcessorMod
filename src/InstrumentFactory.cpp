#include "../include/InstrumentFactory.h"
#include "../include/Guitar.h"
#include "../include/Drum.h"

std::shared_ptr<Instrument> InstrumentFactory::createInstrument(const std::string& instrumentType) {
    if (instrumentType == "guitar") {
        return std::make_shared<Guitar>();
    } else if (instrumentType == "drum") {
        return std::make_shared<Drum>();
    }
    return nullptr; // Or handle unknown instrument types
}
