#pragma once
#ifndef INSTRUMENT_FACTORY_H
#define INSTRUMENT_FACTORY_H

#include <memory>
#include <string>
#include "Instrument.h"

class InstrumentFactory {
public:
    static std::shared_ptr<Instrument> createInstrument(const std::string& instrumentType);
};

#endif // INSTRUMENT_H