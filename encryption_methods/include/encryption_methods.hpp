#pragma once

#include <cstdint>

namespace encr_methods
{
    uint8_t calculateEncryptedLetterPosition(uint8_t letter, uint32_t shiftKey);
} // namespace encr_methods