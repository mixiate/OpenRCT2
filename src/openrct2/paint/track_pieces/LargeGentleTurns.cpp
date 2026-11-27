/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "LargeGentleTurns.h"

namespace OpenRCT2
{
    const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthToDiagUp25BoundingBoxes = { {
        { {
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
            { { { { 0, 0, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
        } },
        { {
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
        } },
        { {
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
            { { { { 0, 16, 0 }, { 32, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
        } },
        { {
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
        } },
    } };
    const LargeGentleTurnBoundingBoxes1Sprite kRightEighthToDiagUp25BoundingBoxes = flipTrackSequenceBoundBoxesXAxis(
        kLeftEighthToDiagUp25BoundingBoxes);

    const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthToDiagUp25BoundingBoxesHybrid = { {
        { {
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
            { { { { 0, 0, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
        } },
        { {
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 34, 3 } } } },
            { { { { 16, 16, 0 }, { 20, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 16, 0, 0 }, { 18, 16, 3 } } } },
        } },
        { {
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
            { { { { 0, 16, 0 }, { 32, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
        } },
        { {
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
            { { { { 16, 0, 4 }, { 20, 32, 1 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 16, 0 }, { 16, 20, 3 } } } },
        } },
    } };
    const LargeGentleTurnBoundingBoxes1Sprite kRightEighthToDiagUp25BoundingBoxesHybrid = flipTrackSequenceBoundBoxesXAxis(
        kLeftEighthToDiagUp25BoundingBoxesHybrid);

    const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthToOrthogonalUp25BoundingBoxes = { {
        { {
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 0, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
        } },
        { {
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
        } },
        { {
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
        } },
        { {
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
        } },
    } };
    const LargeGentleTurnBoundingBoxes1Sprite kRightEighthToOrthogonalUp25BoundingBoxes = flipTrackSequenceBoundBoxesDiagonal(
        kLeftEighthToOrthogonalUp25BoundingBoxes);

    const LargeGentleTurnBoundingBoxes2Sprites kLeftEighthToOrthogonalUp25BoundingBoxesHybrid = { {
        { {
            { { { { 0, 16, 0 }, { 18, 18, 3 } }, { { 2, 0, 48 }, { 32, 34, 1 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } }, { { 0, 0, 48 }, { 32, 32, 1 } } } },
            { { kBoundingBoxUnimplemented, kBoundingBoxUnimplemented } },
            { { { { 0, 0, 0 }, { 34, 16, 3 } }, { { 0, 28, 0 }, { 34, 1, 32 } } } },
            { { { { 0, 6, 0 }, { 34, 20, 3 } }, { { 8, 28, 0 }, { 40, 1, 32 } } } },
        } },
        { {
            { { { { 16, 16, 0 }, { 16, 16, 3 } }, { { 0, 0, 48 }, { 40, 32, 1 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } }, { { 0, 0, 48 }, { 32, 32, 1 } } } },
            { { kBoundingBoxUnimplemented, kBoundingBoxUnimplemented } },
            { { { { 0, 0, 0 }, { 16, 32, 3 } }, { { 28, 0, 8 }, { 1, 32, 48 } } } },
            { { { { 6, 0, 0 }, { 20, 32, 3 } }, { { 28, 0, 0 }, { 1, 32, 32 } } } },
        } },
        { {
            { { { { 16, 0, 0 }, { 18, 18, 3 } }, kBoundingBoxUnimplemented } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } }, kBoundingBoxUnimplemented } },
            { { kBoundingBoxUnimplemented, kBoundingBoxUnimplemented } },
            { { { { 0, 16, 0 }, { 32, 18, 3 } }, kBoundingBoxUnimplemented } },
            { { { { 0, 6, 0 }, { 32, 20, 3 } }, kBoundingBoxUnimplemented } },
        } },
        { {
            { { { { 0, 0, 0 }, { 16, 16, 3 } }, kBoundingBoxUnimplemented } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } }, kBoundingBoxUnimplemented } },
            { { kBoundingBoxUnimplemented, kBoundingBoxUnimplemented } },
            { { { { 16, 0, 0 }, { 18, 34, 3 } }, kBoundingBoxUnimplemented } },
            { { { { 6, 0, 0 }, { 20, 32, 3 } }, kBoundingBoxUnimplemented } },
        } },
    } };
    const LargeGentleTurnBoundingBoxes2Sprites kRightEighthToOrthogonalUp25BoundingBoxesHybrid
        = flipTrackSequenceBoundBoxesDiagonal(kLeftEighthToOrthogonalUp25BoundingBoxesHybrid);

    const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthBankToDiagUp25BoundingBoxes = { {
        { {
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
            { { { { 0, 0, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
        } },
        { {
            { { { { 27, 0, 0 }, { 1, 32, 32 } } } },
            { { { { 27, 0, 0 }, { 1, 32, 32 } } } },
            { { { { 0, 0, 37 }, { 40, 32, 1 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 0, 45 }, { 32, 32, 1 } } } },
        } },
        { {
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
            { { { { 0, 16, 0 }, { 32, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
        } },
        { {
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
        } },
    } };
    const LargeGentleTurnBoundingBoxes1Sprite kRightEighthBankToDiagUp25BoundingBoxes = flipTrackSequenceBoundBoxesXAxis(
        kLeftEighthBankToDiagUp25BoundingBoxes);

    const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthBankToDiagUp25BoundingBoxesHybrid = { {
        { {
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
            { { { { 0, 0, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
        } },
        { {
            { { { { 27, 0, 0 }, { 1, 32, 32 } } } },
            { { { { 27, 0, 0 }, { 1, 32, 32 } } } },
            { { { { 0, 0, 37 }, { 40, 32, 1 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 0, 45 }, { 32, 32, 1 } } } },
        } },
        { {
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
            { { { { 0, 16, 0 }, { 32, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
        } },
        { {
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
            { { { { 16, 0, 0 }, { 18, 32, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 16, 0 }, { 16, 18, 3 } } } },
        } },
    } };
    const LargeGentleTurnBoundingBoxes1Sprite kRightEighthBankToDiagUp25BoundingBoxesHybrid = flipTrackSequenceBoundBoxesXAxis(
        kLeftEighthBankToDiagUp25BoundingBoxesHybrid);

    const LargeGentleTurnBoundingBoxes1Sprite kLeftEighthBankToOrthogonalUp25BoundingBoxes = { {
        { {
            { { { { 0, 0, 37 }, { 32, 32, 1 } } } },
            { { { { 0, 0, 37 }, { 32, 32, 1 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 27, 0 }, { 32, 1, 32 } } } },
            { { { { 0, 27, 0 }, { 32, 1, 32 } } } },
        } },
        { {
            { { { { 0, 0, 32 }, { 32, 32, 1 } } } },
            { { { { 0, 0, 32 }, { 32, 32, 1 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 27, 0, 0 }, { 1, 32, 32 } } } },
            { { { { 27, 0, 0 }, { 1, 32, 32 } } } },
        } },
        { {
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
        } },
        { {
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
        } },
    } };
    const LargeGentleTurnBoundingBoxes1Sprite kRightEighthBankToOrthogonalUp25BoundingBoxes
        = flipTrackSequenceBoundBoxesDiagonal(kLeftEighthBankToOrthogonalUp25BoundingBoxes);
} // namespace OpenRCT2
