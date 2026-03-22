/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "LargeTurnGentle.h"

namespace OpenRCT2
{
    const TrackBoundingBoxes5Seq1Spr kLeftEighthToDiagUp25BoundingBoxes = { {
        { {
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
            { { { { 0, 0, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
        } },
        { {
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
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
            { { { { 16, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
        } },
    } };
    const TrackBoundingBoxes5Seq1Spr kRightEighthToDiagUp25BoundingBoxes = flipTrackSequenceBoundBoxesXAxis(
        kLeftEighthToDiagUp25BoundingBoxes);

    const TrackBoundingBoxes5Seq1Spr kLeftEighthToDiagUp25BoundingBoxesHybrid = { {
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
    const TrackBoundingBoxes5Seq1Spr kRightEighthToDiagUp25BoundingBoxesHybrid = flipTrackSequenceBoundBoxesXAxis(
        kLeftEighthToDiagUp25BoundingBoxesHybrid);

    const TrackBoundingBoxes5Seq1Spr kLeftEighthToOrthogonalUp25BoundingBoxes = { {
        { {
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 0, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
        } },
        { {
            { { { { 16, 16, 0 }, { 16, 16, 3 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
        } },
        { {
            { { { { 16, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 16, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
        } },
        { {
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 16, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
        } },
    } };
    const TrackBoundingBoxes5Seq1Spr kRightEighthToOrthogonalUp25BoundingBoxes = flipTrackSequenceBoundBoxesDiagonal(
        kLeftEighthToOrthogonalUp25BoundingBoxes);

    const TrackBoundingBoxes5Seq2Spr kLeftEighthToOrthogonalUp25BoundingBoxesHybrid = { {
        { {
            { { { { 0, 16, 0 }, { 18, 18, 3 } }, { { 2, 0, 48 }, { 32, 34, 1 } } } },
            { { { { 16, 16, 0 }, { 16, 16, 3 } }, { { 0, 0, 48 }, { 32, 32, 1 } } } },
            { { kBoundingBoxUnimplemented, kBoundingBoxUnimplemented } },
            { { { { 0, 0, 0 }, { 34, 16, 3 } }, { { 0, 31, 0 }, { 34, 1, 32 } } } },
            { { { { 0, 6, 0 }, { 34, 20, 3 } }, { { 8, 31, 0 }, { 40, 1, 32 } } } },
        } },
        { {
            { { { { 16, 16, 0 }, { 16, 16, 3 } }, { { 0, 0, 48 }, { 40, 32, 1 } } } },
            { { { { 16, 0, 0 }, { 16, 16, 3 } }, { { 0, 0, 48 }, { 32, 32, 1 } } } },
            { { kBoundingBoxUnimplemented, kBoundingBoxUnimplemented } },
            { { { { 0, 0, 0 }, { 16, 32, 3 } }, { { 31, 0, 8 }, { 1, 32, 48 } } } },
            { { { { 6, 0, 0 }, { 20, 32, 3 } }, { { 31, 0, 0 }, { 1, 32, 32 } } } },
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
    const TrackBoundingBoxes5Seq2Spr kRightEighthToOrthogonalUp25BoundingBoxesHybrid = flipTrackSequenceBoundBoxesDiagonal(
        kLeftEighthToOrthogonalUp25BoundingBoxesHybrid);

    const TrackBoundingBoxes5Seq1Spr kLeftEighthBankToDiagUp25BoundingBoxes = { {
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
            { { { { 0, 0, 32 }, { 40, 32, 1 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 0, 48 }, { 32, 32, 1 } } } },
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
            { { { { 16, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
        } },
    } };
    const TrackBoundingBoxes5Seq1Spr kRightEighthBankToDiagUp25BoundingBoxes = flipTrackSequenceBoundBoxesXAxis(
        kLeftEighthBankToDiagUp25BoundingBoxes);

    const TrackBoundingBoxes5Seq1Spr kLeftEighthBankToDiagUp25BoundingBoxesHybrid = { {
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
            { { { { 0, 0, 48 }, { 40, 32, 1 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 0, 48 }, { 32, 32, 1 } } } },
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
    const TrackBoundingBoxes5Seq1Spr kRightEighthBankToDiagUp25BoundingBoxesHybrid = flipTrackSequenceBoundBoxesXAxis(
        kLeftEighthBankToDiagUp25BoundingBoxesHybrid);

    const TrackBoundingBoxes5Seq1Spr kLeftEighthBankToOrthogonalUp25BoundingBoxes = { {
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
            { { kBoundingBoxUnimplemented } },
            { { { { 0, 16, 0 }, { 32, 16, 3 } } } },
            { { { { 0, 6, 0 }, { 32, 20, 3 } } } },
        } },
        { {
            { { { { 0, 0, 0 }, { 16, 16, 3 } } } },
            { { { { 0, 16, 0 }, { 16, 16, 3 } } } },
            { { kBoundingBoxUnimplemented } },
            { { { { 16, 0, 0 }, { 16, 32, 3 } } } },
            { { { { 6, 0, 0 }, { 20, 32, 3 } } } },
        } },
    } };
    const TrackBoundingBoxes5Seq1Spr kRightEighthBankToOrthogonalUp25BoundingBoxes = flipTrackSequenceBoundBoxesDiagonal(
        kLeftEighthBankToOrthogonalUp25BoundingBoxes);
} // namespace OpenRCT2
