/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include <cstdint>

using Direction = uint8_t;
struct TileCornersZ;

namespace OpenRCT2
{
    constexpr uint8_t quartersFlipXAxis(const uint8_t quarters)
    {
        return ((quarters & 0b1010) >> 1) | ((quarters & 0b0101) << 1);
    }
} // namespace OpenRCT2

class QuarterTile
{
private:
    uint8_t _val{ 0 };

public:
    constexpr QuarterTile(uint8_t tileQuarter, uint8_t zQuarter)
        : _val(tileQuarter | (zQuarter << 4))
    {
    }

    constexpr QuarterTile(uint8_t tileAndZQuarter)
        : _val(tileAndZQuarter)
    {
    }

    // Rotate both of the values amount. Returns new RValue QuarterTile
    const QuarterTile Rotate(Direction amount) const;

    constexpr uint8_t GetBaseQuarterOccupied() const
    {
        return _val & 0xF;
    }

    constexpr uint8_t GetZQuarterOccupied() const
    {
        return (_val >> 4) & 0xF;
    }

    TileCornersZ GetQuarterHeights(int32_t height) const;

    constexpr QuarterTile flipXAxis() const
    {
        return QuarterTile(
            OpenRCT2::quartersFlipXAxis(GetBaseQuarterOccupied()), OpenRCT2::quartersFlipXAxis(GetZQuarterOccupied()));
    }
};

enum
{
    TILE_ELEMENT_QUADRANT_SW,
    TILE_ELEMENT_QUADRANT_NW,
    TILE_ELEMENT_QUADRANT_NE,
    TILE_ELEMENT_QUADRANT_SE
};
