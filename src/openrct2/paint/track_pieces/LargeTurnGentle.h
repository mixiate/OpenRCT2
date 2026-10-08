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
    static constexpr uint8_t kLargeTurnGentleSequenceCount = 5;

    static constexpr bool kLeftEighthToDiagUp25SpriteMapArray[kNumOrthogonalDirections][kLargeTurnGentleSequenceCount][1] = {
        { { true }, { true }, { true }, { false }, { true } },
        { { true }, { true }, { true }, { false }, { true } },
        { { true }, { true }, { true }, { false }, { true } },
        { { true }, { true }, { true }, { false }, { true } },
    };

    static constexpr uint64_t kLeftEighthToDiagUp25SpriteMap = createSpriteMap<false>(kLeftEighthToDiagUp25SpriteMapArray);
    static constexpr uint64_t kRightEighthToDiagUp25SpriteMap = createSpriteMap<true>(kLeftEighthToDiagUp25SpriteMapArray);

    extern const TrackBoundingBoxes5Seq1Spr kLeftEighthToDiagUp25BoundingBoxes;
    extern const TrackBoundingBoxes5Seq1Spr kRightEighthToDiagUp25BoundingBoxes;
    extern const TrackBoundingBoxes5Seq1Spr kLeftEighthToDiagUp25BoundingBoxesHybrid;
    extern const TrackBoundingBoxes5Seq1Spr kRightEighthToDiagUp25BoundingBoxesHybrid;

    static constexpr bool kLeftEighthToOrthogonalUp25SpriteMapArray[kNumOrthogonalDirections][kLargeTurnGentleSequenceCount][1]
        = {
              { { true }, { true }, { false }, { true }, { true } },
              { { true }, { true }, { false }, { true }, { true } },
              { { true }, { true }, { false }, { true }, { true } },
              { { true }, { true }, { false }, { true }, { true } },
          };

    static constexpr uint64_t kLeftEighthToOrthogonalUp25SpriteMap = createSpriteMap<false>(
        kLeftEighthToOrthogonalUp25SpriteMapArray);
    static constexpr uint64_t kRightEighthToOrthogonalUp25SpriteMap = createSpriteMapFlipDiagonal(
        kLeftEighthToOrthogonalUp25SpriteMapArray);

    static constexpr bool kLeftEighthToOrthogonalUp25SpriteMapArrayHybrid[kNumOrthogonalDirections]
                                                                         [kLargeTurnGentleSequenceCount][2]
        = {
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
          };

    static constexpr uint64_t kLeftEighthToOrthogonalUp25SpriteMapHybrid = createSpriteMap<false>(
        kLeftEighthToOrthogonalUp25SpriteMapArrayHybrid);
    static constexpr uint64_t kRightEighthToOrthogonalUp25SpriteMapHybrid = createSpriteMapFlipDiagonal(
        kLeftEighthToOrthogonalUp25SpriteMapArrayHybrid);

    extern const TrackBoundingBoxes5Seq1Spr kLeftEighthToOrthogonalUp25BoundingBoxes;
    extern const TrackBoundingBoxes5Seq1Spr kRightEighthToOrthogonalUp25BoundingBoxes;
    extern const TrackBoundingBoxes5Seq2Spr kLeftEighthToOrthogonalUp25BoundingBoxesHybrid;
    extern const TrackBoundingBoxes5Seq2Spr kRightEighthToOrthogonalUp25BoundingBoxesHybrid;

    static constexpr bool kLeftEighthBankToOrthogonalUp25SpriteMapArrayHybrid[kNumOrthogonalDirections]
                                                                             [kLargeTurnGentleSequenceCount][2]
        = {
              { { true, true }, { true, true }, { false, false }, { true, true }, { true, true } },
              { { false, true }, { false, true }, { false, false }, { false, true }, { false, true } },
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
              { { true, false }, { true, false }, { false, false }, { true, false }, { true, false } },
          };

    static constexpr uint64_t kLeftEighthBankToOrthogonalUp25SpriteMapHybrid = createSpriteMap<false>(
        kLeftEighthBankToOrthogonalUp25SpriteMapArrayHybrid);
    static constexpr uint64_t kRightEighthBankToOrthogonalUp25SpriteMapHybrid = createSpriteMapFlipDiagonal(
        kLeftEighthBankToOrthogonalUp25SpriteMapArrayHybrid);

    extern const TrackBoundingBoxes5Seq1Spr kLeftEighthBankToDiagUp25BoundingBoxes;
    extern const TrackBoundingBoxes5Seq1Spr kRightEighthBankToDiagUp25BoundingBoxes;
    extern const TrackBoundingBoxes5Seq1Spr kLeftEighthBankToDiagUp25BoundingBoxesHybrid;
    extern const TrackBoundingBoxes5Seq1Spr kRightEighthBankToDiagUp25BoundingBoxesHybrid;

    extern const TrackBoundingBoxes5Seq1Spr kLeftEighthBankToOrthogonalUp25BoundingBoxes;
    extern const TrackBoundingBoxes5Seq1Spr kRightEighthBankToOrthogonalUp25BoundingBoxes;
} // namespace OpenRCT2
