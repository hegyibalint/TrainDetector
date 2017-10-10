#pragma once

#include <stdint.h>
#include "enums.h"

namespace td {

    class Debouncer {
    protected:
        uint8_t debounce = 0;
        EdgeDirection lastDir = EdgeDirection::NOEDGE;

    public:
        EdgeDirection addSample(bool signal);
    };

};