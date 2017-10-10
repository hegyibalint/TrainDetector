#include "debouncer.h"

using namespace td;

EdgeDirection Debouncer::addSample(bool signal) {
    this->debounce = static_cast<uint8_t>(this->debounce << 1 | signal);

    auto upper = static_cast<uint8_t>(this->debounce >> 4 & 0x0F);
    auto lower = static_cast<uint8_t>(this->debounce & 0x0F);

    if (upper == 0x0F && lower == 0 && this->lastDir != FALL) {
        this->lastDir = FALL;
        return FALL;
    } else if (upper == 0 && lower == 0x0F && this->lastDir != RISE) {
        this->lastDir = RISE;
        return RISE;
    } else {
        return NOEDGE;
    }
}
