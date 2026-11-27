/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../track/TrackPaintGeneric.h"

namespace OpenRCT2
{
    static constexpr uint8_t kLargeGentleTurnSequenceCount = 5;

    typedef std::array<std::array<std::array<BoundBoxXYZ, 1>, kLargeGentleTurnSequenceCount>, kNumOrthogonalDirections>
        LargeGentleTurnBoundingBoxes1Sprite;
    typedef std::array<std::array<std::array<BoundBoxXYZ, 2>, kLargeGentleTurnSequenceCount>, kNumOrthogonalDirections>
        LargeGentleTurnBoundingBoxes2Sprites;

    static constexpr bool kLeftEighthToDiagUp25SpriteMapArray[kNumOrthogonalDirections][kLargeGentleTurnSequenceCount][1] = {
        { { true }, { true }, { true }, { false }, { true } },
        { { true }, { true }, { true }, { false }, { true } },
        { { true }, { true }, { true }, { false }, { true } },
        { { true }, { true }, { true }, { false }, { true } },
    };

    static constexpr uint64_t kLeftEighthToDiagUp25SpriteMap = createSpriteMap(
        kLeftEighthToDiagUp25SpriteMapArray, TrackSpriteMapFlip::none);
    static constexpr uint64_t kRightEighthToDiagUp25SpriteMap = createSpriteMap(
        kLeftEighthToDiagUp25SpriteMapArray, TrackSpriteMapFlip::xAxis);

    extern const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthToDiagUp25BoundingBoxes;
    extern const LargeGentleTurnBoundingBoxes1Sprite kRightEighthToDiagUp25BoundingBoxes;
    extern const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthToDiagUp25BoundingBoxesHybrid;
    extern const LargeGentleTurnBoundingBoxes1Sprite kRightEighthToDiagUp25BoundingBoxesHybrid;

    static constexpr bool kLeftEighthToOrthogonalUp25SpriteMapArray[kNumOrthogonalDirections][kLargeGentleTurnSequenceCount][1]
        = {
              { { true }, { true }, { false }, { true }, { true } },
              { { true }, { true }, { false }, { true }, { true } },
              { { true }, { true }, { false }, { true }, { true } },
              { { true }, { true }, { false }, { true }, { true } },
          };

    static constexpr uint64_t kLeftEighthToOrthogonalUp25SpriteMap = createSpriteMap(
        kLeftEighthToOrthogonalUp25SpriteMapArray, TrackSpriteMapFlip::none);
    static constexpr uint64_t kRightEighthToOrthogonalUp25SpriteMap = createSpriteMap(
        kLeftEighthToOrthogonalUp25SpriteMapArray, TrackSpriteMapFlip::diagonal);

    static constexpr bool kLeftEighthToOrthogonalUp25SpriteMapArrayHybrid[kNumOrthogonalDirections]
                                                                         [kLargeGentleTurnSequenceCount][2]
        = {
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
          };

    static constexpr uint64_t kLeftEighthToOrthogonalUp25SpriteMapHybrid = createSpriteMap(
        kLeftEighthToOrthogonalUp25SpriteMapArrayHybrid, TrackSpriteMapFlip::none);
    static constexpr uint64_t kRightEighthToOrthogonalUp25SpriteMapHybrid = createSpriteMap(
        kLeftEighthToOrthogonalUp25SpriteMapArrayHybrid, TrackSpriteMapFlip::diagonal);

    extern const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthToOrthogonalUp25BoundingBoxes;
    extern const LargeGentleTurnBoundingBoxes1Sprite kRightEighthToOrthogonalUp25BoundingBoxes;
    extern const LargeGentleTurnBoundingBoxes2Sprites kLeftEighthToOrthogonalUp25BoundingBoxesHybrid;
    extern const LargeGentleTurnBoundingBoxes2Sprites kRightEighthToOrthogonalUp25BoundingBoxesHybrid;

    static constexpr bool kLeftEighthBankToOrthogonalUp25SpriteMapArrayHybrid[kNumOrthogonalDirections]
                                                                             [kLargeGentleTurnSequenceCount][2]
        = {
              { { true, true }, { true, true }, { false, false }, { true, true }, { true, true } },
              { { false, true }, { false, true }, { false, false }, { false, true }, { false, true } },
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
          };

    static constexpr uint64_t kLeftEighthBankToOrthogonalUp25SpriteMapHybrid = createSpriteMap(
        kLeftEighthBankToOrthogonalUp25SpriteMapArrayHybrid, TrackSpriteMapFlip::none);
    static constexpr uint64_t kRightEighthBankToOrthogonalUp25SpriteMapHybrid = createSpriteMap(
        kLeftEighthBankToOrthogonalUp25SpriteMapArrayHybrid, TrackSpriteMapFlip::diagonal);

    extern const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthBankToDiagUp25BoundingBoxes;
    extern const LargeGentleTurnBoundingBoxes1Sprite kRightEighthBankToDiagUp25BoundingBoxes;
    extern const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthBankToDiagUp25BoundingBoxesHybrid;
    extern const LargeGentleTurnBoundingBoxes1Sprite kRightEighthBankToDiagUp25BoundingBoxesHybrid;

    extern const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthBankToOrthogonalUp25BoundingBoxes;
    extern const LargeGentleTurnBoundingBoxes1Sprite kRightEighthBankToOrthogonalUp25BoundingBoxes;
} // namespace OpenRCT2
