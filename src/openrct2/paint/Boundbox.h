/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../world/Location.hpp"

#include <array>
#include <cstdint>

struct BoundBoxXY
{
    CoordsXY offset{};
    CoordsXY length{};

    constexpr BoundBoxXY() = default;
    constexpr BoundBoxXY(CoordsXY _offset, CoordsXY _length)
        : offset(_offset)
        , length(_length)
    {
    }
};

struct BoundBoxXYZ
{
    CoordsXYZ offset{};
    CoordsXYZ length{};

    constexpr BoundBoxXYZ() = default;
    constexpr BoundBoxXYZ(CoordsXYZ _offset, CoordsXYZ _length)
        : offset(_offset)
        , length(_length)
    {
    }
};

constexpr BoundBoxXYZ kBoundingBoxUnimplemented{};

static constexpr std ::array<size_t, kNumOrthogonalDirections> kDirectionMapFlipX = { 3, 2, 1, 0 };
static constexpr std ::array<size_t, kNumOrthogonalDirections> kDirectionMapFlipDiagonal = { 2, 1, 0, 3 };

template<size_t trackSequenceCount, size_t spriteCount, const std ::array<size_t, kNumOrthogonalDirections> directionMap>
constexpr std::array<std::array<std::array<BoundBoxXYZ, spriteCount>, trackSequenceCount>, kNumOrthogonalDirections>
    flipTrackSequenceBoundBoxes(
        const std::array<std::array<std::array<BoundBoxXYZ, spriteCount>, trackSequenceCount>, kNumOrthogonalDirections>&
            boundBoxes)
{
    auto flippedBoundBoxes = boundBoxes;
    for (const Direction direction : kAllDirections)
    {
        flippedBoundBoxes[direction] = boundBoxes[directionMap[direction]];
    }
    for (auto& view : flippedBoundBoxes)
    {
        for (auto& trackSequence : view)
        {
            for (auto& boundBox : trackSequence)
            {
                std::swap(boundBox.offset.x, boundBox.offset.y);
                std::swap(boundBox.length.x, boundBox.length.y);
            }
        }
    }
    return flippedBoundBoxes;
}

template<size_t trackSequenceCount, size_t spriteCount>
constexpr std::array<std::array<std::array<BoundBoxXYZ, spriteCount>, trackSequenceCount>, kNumOrthogonalDirections>
    flipTrackSequenceBoundBoxesXAxis(
        const std::array<std::array<std::array<BoundBoxXYZ, spriteCount>, trackSequenceCount>, kNumOrthogonalDirections>&
            boundBoxes)
{
    return flipTrackSequenceBoundBoxes<trackSequenceCount, spriteCount, kDirectionMapFlipX>(boundBoxes);
}

template<size_t trackSequenceCount, size_t spriteCount>
constexpr std::array<std::array<std::array<BoundBoxXYZ, spriteCount>, trackSequenceCount>, kNumOrthogonalDirections>
    flipTrackSequenceBoundBoxesDiagonal(
        const std::array<std::array<std::array<BoundBoxXYZ, spriteCount>, trackSequenceCount>, kNumOrthogonalDirections>&
            boundBoxes)
{
    return flipTrackSequenceBoundBoxes<trackSequenceCount, spriteCount, kDirectionMapFlipDiagonal>(boundBoxes);
}
