/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include <gtest/gtest.h>
#include <openrct2/ride/TrackData.h>
#include <openrct2/ride/ted/TrackElementDescriptor.h>

using namespace OpenRCT2;
using namespace OpenRCT2::TrackMetadata;

using PS = PaintSegment;

static constexpr SequenceDescriptor kFlatSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kEndStationSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin,
               SequenceFlag::disallowDoors, SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsAllTypes(kSegmentsAll),
};

static constexpr SequenceDescriptor kBeginStationSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin,
               SequenceFlag::disallowDoors, SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsAllTypes(kSegmentsAll),
};

static constexpr SequenceDescriptor kMiddleStationSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin,
               SequenceFlag::disallowDoors, SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsAllTypes(kSegmentsAll),
};

static constexpr SequenceDescriptor kUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp60Seq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp25ToUp60Seq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp60ToUp25Seq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown60Seq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown25ToDown60Seq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown60ToDown25Seq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft },                  // narrow
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesSeq1 = {
    .clearance = { 0, -32, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        kSegmentsNone,                                // narrow
        kSegmentsNone,                                // inverted
        { PS::right, PS::topRight, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsAllTypes({ PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }),
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesSeq3 = {
    .clearance = { -32, -32, 0, 0, { 0b1101, 0 }, {} },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight },                                                   // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight },                                                   // inverted
        { PS::top, PS::right, PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesSeq4 = {
    .clearance = { -32, -64, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        kSegmentsNone,                                // narrow
        kSegmentsNone,                                // inverted
        { PS::right, PS::topRight, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesSeq5 = {
    .clearance = { -64, -32, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsAllTypes(
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }),
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesSeq6 = {
    .clearance = { -64, -64, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomRight },               // narrow
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn5TilesSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn5TilesSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn5TilesSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1110, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn5TilesSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesSeq4 = {
    .clearance = { -32, 64, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn5TilesSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesSeq5 = {
    .clearance = { -64, 32, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn5TilesSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesSeq6 = {
    .clearance = { -64, 64, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn5TilesSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kFlatToLeftBankSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft },                                         // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                                         // wide
    } },
};

static constexpr SequenceDescriptor kFlatToRightBankSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kFlatToLeftBankSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankToFlatSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft },                                         // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                                         // wide
    } },
};

static constexpr SequenceDescriptor kRightBankToFlatSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankToFlatSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kBankedLeftQuarterTurn5TilesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn5TilesSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kBankedLeftQuarterTurn5TilesSeq1 = {
    .clearance = { 0, -32, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterTurn5TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kBankedLeftQuarterTurn5TilesSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterTurn5TilesSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kBankedLeftQuarterTurn5TilesSeq3 = {
    .clearance = { -32, -32, 0, 0, { 0b1101, 0 }, {} },
    .blockedSegments = kLeftQuarterTurn5TilesSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kBankedLeftQuarterTurn5TilesSeq4 = {
    .clearance = { -32, -64, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterTurn5TilesSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kBankedLeftQuarterTurn5TilesSeq5 = {
    .clearance = { -64, -32, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterTurn5TilesSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kBankedLeftQuarterTurn5TilesSeq6 = {
    .clearance = { -64, -64, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn5TilesSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kBankedRightQuarterTurn5TilesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn5TilesSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kBankedRightQuarterTurn5TilesSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterTurn5TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kBankedRightQuarterTurn5TilesSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterTurn5TilesSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kBankedRightQuarterTurn5TilesSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1110, 0 }, {} },
    .blockedSegments = kRightQuarterTurn5TilesSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kBankedRightQuarterTurn5TilesSeq4 = {
    .clearance = { -32, 64, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterTurn5TilesSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kBankedRightQuarterTurn5TilesSeq5 = {
    .clearance = { -64, 32, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterTurn5TilesSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kBankedRightQuarterTurn5TilesSeq6 = {
    .clearance = { -64, 64, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn5TilesSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kLeftBankToUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft },                                         // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                                         // wide
    } },
};

static constexpr SequenceDescriptor kRightBankToUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankToUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kUp25ToLeftBankSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft },                                         // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                                         // wide
    } },
};

static constexpr SequenceDescriptor kUp25ToRightBankSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kUp25ToLeftBankSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankToDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft },                                         // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                                         // wide
    } },
};

static constexpr SequenceDescriptor kRightBankToDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankToDown25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kDown25ToLeftBankSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft },                                         // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                                         // wide
    } },
};

static constexpr SequenceDescriptor kDown25ToRightBankSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kDown25ToLeftBankSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft },                                         // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                                         // wide
    } },
};

static constexpr SequenceDescriptor kRightBankSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn5TilesSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesUp25Seq1 = {
    .clearance = { 0, -32, 16, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterTurn5TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesUp25Seq2 = {
    .clearance = { -32, 0, 16, 16, { 0b0111, 0b0100 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterTurn5TilesSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesUp25Seq3 = {
    .clearance = { -32, -32, 24, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kLeftQuarterTurn5TilesSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesUp25Seq4 = {
    .clearance = { -32, -64, 48, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterTurn5TilesSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesUp25Seq5 = {
    .clearance = { -64, -32, 32, 16, { 0b0111, 0b0100 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterTurn5TilesSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesUp25Seq6 = {
    .clearance = { -64, -64, 48, 16, { 0b1111, 0b0110 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn5TilesSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn5TilesSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesUp25Seq1 = {
    .clearance = { 0, 32, 16, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterTurn5TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesUp25Seq2 = {
    .clearance = { -32, 0, 16, 16, { 0b1011, 0b1000 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterTurn5TilesSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesUp25Seq3 = {
    .clearance = { -32, 32, 24, 16, { 0b1110, 0 }, {} },
    .blockedSegments = kRightQuarterTurn5TilesSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesUp25Seq4 = {
    .clearance = { -32, 64, 48, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterTurn5TilesSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesUp25Seq5 = {
    .clearance = { -64, 32, 32, 16, { 0b1011, 0b1000 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterTurn5TilesSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesUp25Seq6 = {
    .clearance = { -64, 64, 48, 16, { 0b1111, 0b1001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn5TilesSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesDown25Seq0 = {
    .clearance = { 0, 0, 48, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn5TilesSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesDown25Seq1 = {
    .clearance = { 0, -32, 48, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterTurn5TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesDown25Seq2 = {
    .clearance = { -32, 0, 32, 16, { 0b0111, 0b0001 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterTurn5TilesSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesDown25Seq3 = {
    .clearance = { -32, -32, 24, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kLeftQuarterTurn5TilesSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesDown25Seq4 = {
    .clearance = { -32, -64, 16, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterTurn5TilesSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesDown25Seq5 = {
    .clearance = { -64, -32, 16, 16, { 0b0111, 0b0001 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterTurn5TilesSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesDown25Seq6 = {
    .clearance = { -64, -64, 0, 16, { 0b1111, 0b1001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn5TilesSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesDown25Seq0 = {
    .clearance = { 0, 0, 48, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn5TilesSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesDown25Seq1 = {
    .clearance = { 0, 32, 48, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterTurn5TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesDown25Seq2 = {
    .clearance = { -32, 0, 32, 16, { 0b1011, 0b0010 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterTurn5TilesSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesDown25Seq3 = {
    .clearance = { -32, 32, 24, 16, { 0b1110, 0 }, {} },
    .blockedSegments = kRightQuarterTurn5TilesSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesDown25Seq4 = {
    .clearance = { -32, 64, 16, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterTurn5TilesSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesDown25Seq5 = {
    .clearance = { -64, 32, 16, 16, { 0b1011, 0b0010 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterTurn5TilesSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesDown25Seq6 = {
    .clearance = { -64, 64, 0, 16, { 0b1111, 0b0110 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn5TilesSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kSBendLeftSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kSBendLeftSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsAllTypes({ PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }),
};

static constexpr SequenceDescriptor kSBendLeftSeq2 = {
    .clearance = { -32, -32, 0, 0, { 0b1101, 0 }, {} },
    .allowedWallEdges = 0b1100,
    .blockedSegments = blockedSegmentsAllTypes(
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }),
};

static constexpr SequenceDescriptor kSBendLeftSeq3 = {
    .clearance = { -64, -32, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::bottom, PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kSBendRightSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kSBendLeftSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kSBendRightSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kSBendLeftSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kSBendRightSeq2 = {
    .clearance = { -32, 32, 0, 0, { 0b1110, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kSBendLeftSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kSBendRightSeq3 = {
    .clearance = { -64, 32, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kSBendLeftSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kLeftVerticalLoopSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft },                              // narrow
        { PS::top, PS::left, PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                                                    // wide
    } },
};

static constexpr SequenceDescriptor kLeftVerticalLoopSeq1 = {
    .clearance = { -32, 0, 16, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsAll,                                                                 // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftVerticalLoopSeq2 = {
    .clearance = { -64, 0, 32, 96, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                // wide
    } },
};

static constexpr SequenceDescriptor kLeftVerticalLoopSeq3 = {
    .clearance = { -32, 0, 120, 16, { 0b0110, 0 }, {} },
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftVerticalLoopSeq4 = {
    .clearance = { -32, -32, 120, 0, { 0b0000, 0 }, {} },
    .blockedSegments = { {
        kSegmentsNone,          // narrow
        kSegmentsNone,          // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kLeftVerticalLoopSeq5 = {
    .clearance = { 0, 0, 120, 0, { 0b0000, 0 }, {} },
    .blockedSegments = { {
        kSegmentsNone,          // narrow
        kSegmentsNone,          // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kLeftVerticalLoopSeq6 = {
    .clearance = { 0, -32, 120, 16, { 0b1001, 0 }, {} },
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftVerticalLoopSeq7 = {
    .clearance = { 32, -32, 32, 96, { 0b1000, 0 }, {} },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                   // wide
    } },
};

static constexpr SequenceDescriptor kLeftVerticalLoopSeq8 = {
    .clearance = { 0, -32, 16, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsAll,                                                                         // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftVerticalLoopSeq9 = {
    .clearance = { -32, -32, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight },                       // narrow
        { PS::top, PS::right, PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                                                     // wide
    } },
};

static constexpr SequenceDescriptor kRightVerticalLoopSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftVerticalLoopSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightVerticalLoopSeq1 = {
    .clearance = { -32, 0, 16, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftVerticalLoopSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightVerticalLoopSeq2 = {
    .clearance = { -64, 0, 32, 96, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftVerticalLoopSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightVerticalLoopSeq3 = {
    .clearance = { -32, 0, 120, 16, { 0b1001, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftVerticalLoopSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightVerticalLoopSeq4 = {
    .clearance = { -32, 32, 120, 0, { 0b0000, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftVerticalLoopSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightVerticalLoopSeq5 = {
    .clearance = { 0, 0, 120, 0, { 0b0000, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftVerticalLoopSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightVerticalLoopSeq6 = {
    .clearance = { 0, 32, 120, 16, { 0b0110, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftVerticalLoopSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kRightVerticalLoopSeq7 = {
    .clearance = { 32, 32, 32, 96, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftVerticalLoopSeq7.blockedSegments),
};

static constexpr SequenceDescriptor kRightVerticalLoopSeq8 = {
    .clearance = { 0, 32, 16, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftVerticalLoopSeq8.blockedSegments),
};

static constexpr SequenceDescriptor kRightVerticalLoopSeq9 = {
    .clearance = { -32, 32, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftVerticalLoopSeq9.blockedSegments),
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft },                  // narrow
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesSeq1 = {
    .clearance = { 0, -32, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsAllTypes({ PS::left, PS::centre, PS::topLeft, PS::bottomLeft }),
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesSeq3 = {
    .clearance = { -32, -32, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomRight },               // narrow
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TilesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft },                  // narrow
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TilesSeq1 = {
    .clearance = { 0, -32, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TilesSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsAllTypes({ PS::left, PS::centre, PS::topLeft, PS::bottomLeft }),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TilesSeq3 = {
    .clearance = { -32, -32, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomRight },               // narrow
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TilesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TilesSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TilesSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TilesSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TilesSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TilesSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TilesSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TilesSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b0111, 0b0100 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft },                  // narrow
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesUp25Seq1 = {
    .clearance = { 0, -32, 16, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesUp25Seq2 = {
    .clearance = { -32, 0, 16, 0, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        kSegmentsNone,                                         // narrow
        kSegmentsNone,                                         // inverted
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesUp25Seq3 = {
    .clearance = { -32, -32, 16, 16, { 0b0111, 0b0110 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomRight },               // narrow
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1011, 0b1000 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesUp25Seq1 = {
    .clearance = { 0, 32, 16, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesUp25Seq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesUp25Seq2 = {
    .clearance = { -32, 0, 16, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesUp25Seq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesUp25Seq3 = {
    .clearance = { -32, 32, 16, 16, { 0b1011, 0b1001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesUp25Seq3.blockedSegments),
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesDown25Seq0 = {
    .clearance = { 0, 0, 16, 16, { 0b0111, 0b0011 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn3TilesUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesDown25Seq1 = {
    .clearance = { 0, -32, 16, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterTurn3TilesUp25Seq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesDown25Seq2 = {
    .clearance = { -32, 0, 16, 0, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterTurn3TilesUp25Seq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesDown25Seq3 = {
    .clearance = { -32, -32, 0, 16, { 0b0111, 0b0001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn3TilesUp25Seq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesDown25Seq0 = {
    .clearance = { 0, 0, 16, 16, { 0b1011, 0b0011 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn3TilesUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesDown25Seq1 = {
    .clearance = { 0, 32, 16, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterTurn3TilesUp25Seq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesDown25Seq2 = {
    .clearance = { -32, 0, 16, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterTurn3TilesUp25Seq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesDown25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b1011, 0b0010 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn3TilesUp25Seq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn1TileSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kRightQuarterTurn1TileSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn1TileSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftTwistDownToUpSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft },         // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftTwistDownToUpSeq1 = {
    .clearance = { -32, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft },         // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftTwistDownToUpSeq2 = {
    .clearance = { -64, 0, 16, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft },         // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kRightTwistDownToUpSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftTwistDownToUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightTwistDownToUpSeq1 = {
    .clearance = { -32, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftTwistDownToUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightTwistDownToUpSeq2 = {
    .clearance = { -64, 0, 16, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftTwistDownToUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kLeftTwistUpToDownSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kLeftTwistDownToUpSeq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftTwistUpToDownSeq1 = {
    .clearance = { -32, 0, -16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsRotate(kLeftTwistDownToUpSeq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftTwistUpToDownSeq2 = {
    .clearance = { -64, 0, -16, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftTwistDownToUpSeq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kRightTwistUpToDownSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftTwistUpToDownSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightTwistUpToDownSeq1 = {
    .clearance = { -32, 0, -16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftTwistUpToDownSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightTwistUpToDownSeq2 = {
    .clearance = { -64, 0, -16, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftTwistUpToDownSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kHalfLoopUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kHalfLoopUpSeq1 = {
    .clearance = { -32, 0, 16, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsAll,           // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kHalfLoopUpSeq2 = {
    .clearance = { -64, 0, 32, 96, { 0b0011, 0 }, {} },
    .allowedWallEdges = 0b1011,
    .blockedSegments = { {
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kHalfLoopUpSeq3 = {
    .clearance = { -32, 0, 120, 16, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kHalfLoopDownSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kHalfLoopDownSeq1 = {
    .clearance = { -32, 0, -120, 96, { 0b0011, 0 }, {} },
    .allowedWallEdges = 0b1011,
    .blockedSegments = { {
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kHalfLoopDownSeq2 = {
    .clearance = { 0, 0, -136, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsAll,           // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kHalfLoopDownSeq3 = {
    .clearance = { 32, 0, -152, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftCorkscrewUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft },                            // narrow
        { PS::top, PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                                        // wide
    } },
};

static constexpr SequenceDescriptor kLeftCorkscrewUpSeq1 = {
    .clearance = { -32, 0, 24, 32, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsAll,           // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kLeftCorkscrewUpSeq2 = {
    .clearance = { -32, -32, 48, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight },                     // narrow
        { PS::top, PS::right, PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                                     // wide
    } },
};

static constexpr SequenceDescriptor kRightCorkscrewUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftCorkscrewUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightCorkscrewUpSeq1 = {
    .clearance = { -32, 0, 24, 32, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftCorkscrewUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightCorkscrewUpSeq2 = {
    .clearance = { -32, 32, 48, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight },                   // narrow
        { PS::top, PS::left, PS::right, PS::centre, PS::topLeft, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                                   // wide
    } },
};

static constexpr SequenceDescriptor kLeftCorkscrewDownSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kRightCorkscrewUpSeq2.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftCorkscrewDownSeq1 = {
    .clearance = { -32, 0, -56, 32, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsRotate(kRightCorkscrewUpSeq1.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftCorkscrewDownSeq2 = {
    .clearance = { -32, -32, -80, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightCorkscrewUpSeq0.blockedSegments, 1),
};

static constexpr SequenceDescriptor kRightCorkscrewDownSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kLeftCorkscrewUpSeq2.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightCorkscrewDownSeq1 = {
    .clearance = { -32, 0, -56, 32, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kLeftCorkscrewUpSeq1.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightCorkscrewDownSeq2 = {
    .clearance = { -32, 32, -80, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftCorkscrewUpSeq0.blockedSegments, 3),
};

static constexpr SequenceDescriptor kFlatToUp60Seq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp60ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToDown60Seq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown60ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kTowerBaseSeq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kTowerBaseSeq1 = {
    .clearance = { -32, -32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionNW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kTowerBaseSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE },
};

static constexpr SequenceDescriptor kTowerBaseSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kTowerBaseSeq4 = {
    .clearance = { 0, -32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNW },
};

static constexpr SequenceDescriptor kTowerBaseSeq5 = {
    .clearance = { 0, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE },
};

static constexpr SequenceDescriptor kTowerBaseSeq6 = {
    .clearance = { 32, -32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSW, SequenceFlag::entranceConnectionNW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kTowerBaseSeq7 = {
    .clearance = { 32, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kTowerBaseSeq8 = {
    .clearance = { 32, 0, 0, 0, { 0b1111, 0 }, { ClearanceFlag::flag1 } },
    .flags = { SequenceFlag::entranceConnectionSW },
};

static constexpr SequenceDescriptor kTowerSectionSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kTowerSectionSeq1 = {
    .clearance = { 32, 0, 0, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::flag1 } },
};

static constexpr SequenceDescriptor kFlatCoveredSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp25CoveredSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp60CoveredSeq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kUp60Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToUp25CoveredSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatToUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp25ToUp60CoveredSeq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kUp25ToUp60Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp60ToUp25CoveredSeq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kUp60ToUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp25ToFlatCoveredSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kUp25ToFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown25CoveredSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDown25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown60CoveredSeq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDown60Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToDown25CoveredSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatToDown25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown25ToDown60CoveredSeq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDown25ToDown60Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown60ToDown25CoveredSeq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDown60ToDown25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown25ToFlatCoveredSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDown25ToFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesCoveredSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn5TilesSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesCoveredSeq1 = {
    .clearance = { 0, -32, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterTurn5TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesCoveredSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterTurn5TilesSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesCoveredSeq3 = {
    .clearance = { -32, -32, 0, 0, { 0b1101, 0 }, {} },
    .blockedSegments = kLeftQuarterTurn5TilesSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesCoveredSeq4 = {
    .clearance = { -32, -64, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterTurn5TilesSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesCoveredSeq5 = {
    .clearance = { -64, -32, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterTurn5TilesSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn5TilesCoveredSeq6 = {
    .clearance = { -64, -64, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn5TilesSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesCoveredSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn5TilesSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesCoveredSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterTurn5TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesCoveredSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterTurn5TilesSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesCoveredSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1110, 0 }, {} },
    .blockedSegments = kRightQuarterTurn5TilesSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesCoveredSeq4 = {
    .clearance = { -32, 64, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterTurn5TilesSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesCoveredSeq5 = {
    .clearance = { -64, 32, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterTurn5TilesSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn5TilesCoveredSeq6 = {
    .clearance = { -64, 64, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn5TilesSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kSBendLeftCoveredSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kSBendLeftSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kSBendLeftCoveredSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kSBendLeftSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kSBendLeftCoveredSeq2 = {
    .clearance = { -32, -32, 0, 0, { 0b1101, 0 }, {} },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kSBendLeftSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kSBendLeftCoveredSeq3 = {
    .clearance = { -64, -32, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kSBendLeftSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kSBendRightCoveredSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kSBendRightSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kSBendRightCoveredSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kSBendRightSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kSBendRightCoveredSeq2 = {
    .clearance = { -32, 32, 0, 0, { 0b1110, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kSBendRightSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kSBendRightCoveredSeq3 = {
    .clearance = { -64, 32, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kSBendRightSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesCoveredSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn3TilesSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesCoveredSeq1 = {
    .clearance = { 0, -32, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterTurn3TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesCoveredSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterTurn3TilesSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesCoveredSeq3 = {
    .clearance = { -32, -32, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterTurn3TilesSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesCoveredSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn3TilesSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesCoveredSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterTurn3TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesCoveredSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterTurn3TilesSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesCoveredSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterTurn3TilesSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpSmallSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                             // inverted
        kSegmentsAll,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpSmallSeq1 = {
    .clearance = { 0, -32, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        kSegmentsNone,          // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsNone,          // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpSmallSeq2 = {
    .clearance = { -32, 0, 0, 4, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpSmallSeq3 = {
    .clearance = { -32, -32, 0, 4, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                   // inverted
        kSegmentsAll,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpSmallSeq4 = {
    .clearance = { -32, -64, 8, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                 // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpSmallSeq5 = {
    .clearance = { 0, -64, 8, 0, { 0b0100, 0b0000 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        kSegmentsNone,          // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsNone,          // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpSmallSeq6 = {
    .clearance = { -32, -96, 8, 4, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpSmallSeq7 = {
    .clearance = { 0, -96, 8, 4, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                   // inverted
        kSegmentsAll,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpSmallSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpSmallSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpSmallSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0b0000 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpSmallSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpSmallSeq2 = {
    .clearance = { -32, 0, 0, 4, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpSmallSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpSmallSeq3 = {
    .clearance = { -32, 32, 0, 4, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpSmallSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpSmallSeq4 = {
    .clearance = { -32, 64, 8, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpSmallSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpSmallSeq5 = {
    .clearance = { 0, 64, 8, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpSmallSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpSmallSeq6 = {
    .clearance = { -32, 96, 8, 4, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpSmallSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpSmallSeq7 = {
    .clearance = { 0, 96, 8, 4, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpSmallSeq7.blockedSegments),
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownSmallSeq0 = {
    .clearance = { 0, 0, 8, 4, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftHalfBankedHelixUpSmallSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownSmallSeq1 = {
    .clearance = { 0, -32, 8, 4, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftHalfBankedHelixUpSmallSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownSmallSeq2 = {
    .clearance = { -32, 0, 8, 0, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftHalfBankedHelixUpSmallSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownSmallSeq3 = {
    .clearance = { -32, -32, 8, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = kLeftHalfBankedHelixUpSmallSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownSmallSeq4 = {
    .clearance = { -32, -64, 0, 4, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = kLeftHalfBankedHelixUpSmallSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownSmallSeq5 = {
    .clearance = { 0, -64, 0, 4, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kLeftHalfBankedHelixUpSmallSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownSmallSeq6 = {
    .clearance = { -32, -96, 0, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kLeftHalfBankedHelixUpSmallSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownSmallSeq7 = {
    .clearance = { 0, -96, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftHalfBankedHelixUpSmallSeq7.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownSmallSeq0 = {
    .clearance = { 0, 0, 8, 4, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightHalfBankedHelixUpSmallSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownSmallSeq1 = {
    .clearance = { 0, 32, 8, 4, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightHalfBankedHelixUpSmallSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownSmallSeq2 = {
    .clearance = { -32, 0, 8, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightHalfBankedHelixUpSmallSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownSmallSeq3 = {
    .clearance = { -32, 32, 8, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = kRightHalfBankedHelixUpSmallSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownSmallSeq4 = {
    .clearance = { -32, 64, 0, 4, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = kRightHalfBankedHelixUpSmallSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownSmallSeq5 = {
    .clearance = { 0, 64, 0, 4, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kRightHalfBankedHelixUpSmallSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownSmallSeq6 = {
    .clearance = { -32, 96, 0, 0, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kRightHalfBankedHelixUpSmallSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownSmallSeq7 = {
    .clearance = { 0, 96, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightHalfBankedHelixUpSmallSeq7.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                             // inverted
        kSegmentsAll,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq1 = {
    .clearance = { 0, -32, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        kSegmentsNone,                                // narrow
        kSegmentsUnimplemented,                       // inverted
        { PS::right, PS::topRight, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq3 = {
    .clearance = { -32, -32, 0, 0, { 0b1101, 0 }, {} },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight },                                                   // narrow
        kSegmentsUnimplemented,                                                                                     // inverted
        { PS::top, PS::right, PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq4 = {
    .clearance = { -32, -64, 0, 4, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        kSegmentsNone,                                // narrow
        kSegmentsUnimplemented,                       // inverted
        { PS::right, PS::topRight, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq5 = {
    .clearance = { -64, -32, 0, 4, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                             // inverted
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq6 = {
    .clearance = { -64, -64, 0, 4, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                   // inverted
        kSegmentsAll,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq7 = {
    .clearance = { -64, -96, 8, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                 // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq8 = {
    .clearance = { -32, -96, 8, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        kSegmentsNone,                          // narrow
        kSegmentsUnimplemented,                 // inverted
        { PS::top, PS::topLeft, PS::topRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq9 = {
    .clearance = { -64, -128, 8, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                             // inverted
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq10 = {
    .clearance = { -32, -128, 8, 0, { 0b1110, 0 }, {} },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight },                                                       // narrow
        kSegmentsUnimplemented,                                                                                   // inverted
        { PS::top, PS::left, PS::right, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq11 = {
    .clearance = { 0, -128, 8, 4, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        kSegmentsNone,                          // narrow
        kSegmentsUnimplemented,                 // inverted
        { PS::top, PS::topLeft, PS::topRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq12 = {
    .clearance = { -32, -160, 8, 4, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                               // inverted
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixUpLargeSeq13 = {
    .clearance = { 0, -160, 8, 4, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                   // inverted
        kSegmentsAll,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1110, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq4 = {
    .clearance = { -32, 64, 0, 4, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq5 = {
    .clearance = { -64, 32, 0, 4, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq6 = {
    .clearance = { -64, 64, 0, 4, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq7 = {
    .clearance = { -64, 96, 8, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq7.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq8 = {
    .clearance = { -32, 96, 8, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq8.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq9 = {
    .clearance = { -64, 128, 8, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq9.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq10 = {
    .clearance = { -32, 128, 8, 0, { 0b1101, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq10.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq11 = {
    .clearance = { 0, 128, 8, 4, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq11.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq12 = {
    .clearance = { -32, 160, 8, 4, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq12.blockedSegments),
};

static constexpr SequenceDescriptor kRightHalfBankedHelixUpLargeSeq13 = {
    .clearance = { 0, 160, 8, 4, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHalfBankedHelixUpLargeSeq13.blockedSegments),
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq0 = {
    .clearance = { 0, 0, 8, 4, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq1 = {
    .clearance = { 0, -32, 8, 4, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq2 = {
    .clearance = { -32, 0, 8, 4, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq3 = {
    .clearance = { -32, -32, 8, 0, { 0b1101, 0 }, {} },
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq4 = {
    .clearance = { -32, -64, 8, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq5 = {
    .clearance = { -64, -32, 8, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq6 = {
    .clearance = { -64, -64, 8, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq7 = {
    .clearance = { -64, -96, 0, 4, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq7.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq8 = {
    .clearance = { -32, -96, 0, 4, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq8.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq9 = {
    .clearance = { -64, -128, 0, 4, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq9.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq10 = {
    .clearance = { -32, -128, 0, 0, { 0b1110, 0 }, {} },
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq10.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq11 = {
    .clearance = { 0, -128, 0, 0, { 0b0100, 0b0000 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq11.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq12 = {
    .clearance = { -32, -160, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq12.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHalfBankedHelixDownLargeSeq13 = {
    .clearance = { 0, -160, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftHalfBankedHelixUpLargeSeq13.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq0 = {
    .clearance = { 0, 0, 8, 4, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq1 = {
    .clearance = { 0, 32, 8, 4, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq2 = {
    .clearance = { -32, 0, 8, 4, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq3 = {
    .clearance = { -32, 32, 8, 0, { 0b1110, 0 }, {} },
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq4 = {
    .clearance = { -32, 64, 8, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq5 = {
    .clearance = { -64, 32, 8, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq6 = {
    .clearance = { -64, 64, 8, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq7 = {
    .clearance = { -64, 96, 0, 4, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq7.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq8 = {
    .clearance = { -32, 96, 0, 4, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq8.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq9 = {
    .clearance = { -64, 128, 0, 4, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq9.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq10 = {
    .clearance = { -32, 128, 0, 0, { 0b1101, 0 }, {} },
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq10.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq11 = {
    .clearance = { 0, 128, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq11.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq12 = {
    .clearance = { -32, 160, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq12.blockedSegments,
};

static constexpr SequenceDescriptor kRightHalfBankedHelixDownLargeSeq13 = {
    .clearance = { 0, 160, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightHalfBankedHelixUpLargeSeq13.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterTurn1TileUp60Seq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsAllTypes(kSegmentsAll),
};

static constexpr SequenceDescriptor kRightQuarterTurn1TileUp60Seq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsAllTypes(kSegmentsAll),
};

static constexpr SequenceDescriptor kLeftQuarterTurn1TileDown60Seq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsAllTypes(kSegmentsAll),
};

static constexpr SequenceDescriptor kRightQuarterTurn1TileDown60Seq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsAllTypes(kSegmentsAll),
};

static constexpr SequenceDescriptor kBrakesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kBoosterSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

// Maze sequence blocks do not have the height marker flag set because they are handled differently
static constexpr SequenceDescriptor kMazeSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq1 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq2 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq3 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq4 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq5 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq6 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq7 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq8 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq9 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq10 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq11 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq12 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq13 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq14 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kMazeSeq15 = {
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeUpSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft, PS::topLeft, PS::left }, // narrow
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight },       // inverted
        kSegmentsAll,                                                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeUpSeq1 = {
    .clearance = { 0, -32, 0, 8, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kBankedLeftQuarterTurn5TilesSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeUpSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft },                              // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft },                              // inverted
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottom, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeUpSeq3 = {
    .clearance = { -32, -32, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight, PS::bottom, PS::top },                              // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight },                                                   // inverted
        { PS::top, PS::right, PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeUpSeq4 = {
    .clearance = { -32, -64, 0, 16, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kBankedLeftQuarterTurn5TilesSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeUpSeq5 = {
    .clearance = { -64, -32, 0, 16, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight },                        // narrow
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight },                        // inverted
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight, PS::top, PS::topRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeUpSeq6 = {
    .clearance = { -64, -64, 0, 16, { 0b1111, 0b0110 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomRight, PS::bottomLeft, PS::left }, // narrow
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomRight },             // inverted
        kSegmentsAll,                                                                       // wide
    } },
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeUpSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterBankedHelixLargeUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeUpSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterBankedHelixLargeUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeUpSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterBankedHelixLargeUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeUpSeq3 = {
    .clearance = { -32, 32, 0, 16, { 0b1110, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterBankedHelixLargeUpSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeUpSeq4 = {
    .clearance = { -32, 64, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterBankedHelixLargeUpSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeUpSeq5 = {
    .clearance = { -64, 32, 0, 16, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterBankedHelixLargeUpSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeUpSeq6 = {
    .clearance = { -64, 64, 0, 16, { 0b1111, 0b1001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterBankedHelixLargeUpSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeDownSeq1 = {
    .clearance = { 0, -32, 0, 16, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeDownSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeDownSeq3 = {
    .clearance = { -32, -32, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeDownSeq4 = {
    .clearance = { -32, -64, 0, 8, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeDownSeq5 = {
    .clearance = { -64, -32, 0, 8, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterBankedHelixLargeDownSeq6 = {
    .clearance = { -64, -64, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterBankedHelixLargeUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeDownSeq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterBankedHelixLargeUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeDownSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterBankedHelixLargeUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeDownSeq3 = {
    .clearance = { -32, 32, 0, 16, { 0b1110, 0 }, {} },
    .blockedSegments = kRightQuarterBankedHelixLargeUpSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeDownSeq4 = {
    .clearance = { -32, 64, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterBankedHelixLargeUpSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeDownSeq5 = {
    .clearance = { -64, 32, 0, 8, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterBankedHelixLargeUpSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterBankedHelixLargeDownSeq6 = {
    .clearance = { -64, 64, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterBankedHelixLargeUpSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeUpSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft, PS::topLeft },     // narrow
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeUpSeq1 = {
    .clearance = { 0, -32, 0, 8, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeUpSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeUpSeq3 = {
    .clearance = { -32, -32, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeUpSeq4 = {
    .clearance = { -32, -64, 0, 16, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeUpSeq5 = {
    .clearance = { -64, -32, 0, 16, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeUpSeq6 = {
    .clearance = { -64, -64, 0, 16, { 0b1111, 0b0110 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomRight, PS::bottomLeft }, // narrow
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomRight },   // inverted
        kSegmentsAll,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeUpSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterHelixLargeUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeUpSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterHelixLargeUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeUpSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterHelixLargeUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeUpSeq3 = {
    .clearance = { -32, 32, 0, 16, { 0b1110, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterHelixLargeUpSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeUpSeq4 = {
    .clearance = { -32, 64, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterHelixLargeUpSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeUpSeq5 = {
    .clearance = { -64, 32, 0, 16, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterHelixLargeUpSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeUpSeq6 = {
    .clearance = { -64, 64, 0, 16, { 0b1111, 0b1001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterHelixLargeUpSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterHelixLargeUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeDownSeq1 = {
    .clearance = { 0, -32, 0, 16, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterHelixLargeUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeDownSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterHelixLargeUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeDownSeq3 = {
    .clearance = { -32, -32, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kLeftQuarterBankedHelixLargeUpSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeDownSeq4 = {
    .clearance = { -32, -64, 0, 8, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = kLeftQuarterHelixLargeUpSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeDownSeq5 = {
    .clearance = { -64, -32, 0, 8, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftQuarterHelixLargeUpSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kLeftQuarterHelixLargeDownSeq6 = {
    .clearance = { -64, -64, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftQuarterHelixLargeUpSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterHelixLargeUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeDownSeq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterHelixLargeUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeDownSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterHelixLargeUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeDownSeq3 = {
    .clearance = { -32, 32, 0, 16, { 0b1110, 0 }, {} },
    .blockedSegments = kRightQuarterBankedHelixLargeUpSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeDownSeq4 = {
    .clearance = { -32, 64, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kRightQuarterHelixLargeUpSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeDownSeq5 = {
    .clearance = { -64, 32, 0, 8, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightQuarterHelixLargeUpSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kRightQuarterHelixLargeDownSeq6 = {
    .clearance = { -64, 64, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightQuarterHelixLargeUpSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kUp25LeftBankedSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp25RightBankedSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kWaterfallSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kRapidsSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kOnRidePhotoSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsAllTypes(kSegmentsAll),
};

static constexpr SequenceDescriptor kDown25LeftBankedSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown25RightBankedSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kWaterSplashSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kWaterSplashSeq1 = {
    .clearance = { -32, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kWaterSplashSeq2 = {
    .clearance = { -64, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kWaterSplashSeq3 = {
    .clearance = { -96, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kWaterSplashSeq4 = {
    .clearance = { -128, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kFlatToUp60LongBaseSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToUp60LongBaseSeq1 = {
    .clearance = { -32, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToUp60LongBaseSeq2 = {
    .clearance = { -64, 0, 16, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToUp60LongBaseSeq3 = {
    .clearance = { -96, 0, 40, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp60ToFlatLongBaseSeq0 = {
    .clearance = { 0, 0, 0, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp60ToFlatLongBaseSeq1 = {
    .clearance = { -32, 0, 40, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp60ToFlatLongBaseSeq2 = {
    .clearance = { -64, 0, 64, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp60ToFlatLongBaseSeq3 = {
    .clearance = { -96, 0, 80, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kWhirlpoolSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kDown60ToFlatLongBaseSeq0 = {
    .clearance = { 0, 0, 40, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown60ToFlatLongBaseSeq1 = {
    .clearance = { -32, 0, 16, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown60ToFlatLongBaseSeq2 = {
    .clearance = { -64, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown60ToFlatLongBaseSeq3 = {
    .clearance = { -96, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToDown60LongBaseSeq0 = {
    .clearance = { 0, 0, 80, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToDown60LongBaseSeq1 = {
    .clearance = { -32, 0, 64, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToDown60LongBaseSeq2 = {
    .clearance = { -64, 0, 40, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatToDown60LongBaseSeq3 = {
    .clearance = { -96, 0, 0, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kCableLiftHillSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kCableLiftHillSeq1 = {
    .clearance = { -32, 0, 0, 8, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kCableLiftHillSeq2 = {
    .clearance = { -64, 0, -32, 32, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kCableLiftHillSeq3 = {
    .clearance = { -96, 0, -96, 64, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kReverseFreefallSlopeSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kReverseFreefallSlopeSeq1 = {
    .clearance = { -32, 0, 0, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kReverseFreefallSlopeSeq2 = {
    .clearance = { -64, 0, 0, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kReverseFreefallSlopeSeq3 = {
    .clearance = { -96, 0, 0, 80, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kReverseFreefallSlopeSeq4 = {
    .clearance = { -128, 0, 0, 160, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kReverseFreefallSlopeSeq5 = {
    .clearance = { -192, 0, 0, 208, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1011,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kReverseFreefallSlopeSeq6 = {
    .clearance = { -160, 0, 0, 208, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kReverseFreefallVerticalSeq0 = {
    .clearance = { 0, 0, 0, 48, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kReverseFreefallVerticalSeq1 = {
    .clearance = { 32, 0, 0, 48, { 0b1111, 0 }, {} },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp90Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1111,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp90Seq1 = {
    .clearance = { 32, 0, 0, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
};

static constexpr SequenceDescriptor kDown90Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1111,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown90Seq1 = {
    .clearance = { 32, 0, 0, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
};

static constexpr SequenceDescriptor kUp60ToUp90Seq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0b1100 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1011,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp60ToUp90Seq1 = {
    .clearance = { 32, 0, 0, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
};

static constexpr SequenceDescriptor kDown90ToDown60Seq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0b0011 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1110,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kUp90ToUp60Seq0 = {
    .clearance = { 0, 0, 0, 56, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1011,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown60ToDown90Seq0 = {
    .clearance = { 0, 0, 0, 56, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1110,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDown60ToDown90Seq1 = {
    .clearance = { 32, 0, 0, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
};

static constexpr SequenceDescriptor kBrakeForDropSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthToDiagSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthToDiagSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthToDiagSeq2 = {
    .clearance = { -32, -32, 0, 0, { 0b1000, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                                         // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthToDiagSeq3 = {
    .clearance = { -64, 0, 0, 0, { 0b0010, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthToDiagSeq4 = {
    .clearance = { -64, -32, 0, 0, { 0b0001, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                                           // wide
    } },
};

static constexpr SequenceDescriptor kRightEighthToDiagSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagSeq2 = {
    .clearance = { -32, 32, 0, 0, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagSeq3 = {
    .clearance = { -64, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagSeq4 = {
    .clearance = { -64, 32, 0, 0, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightEighthToDiagSeq4.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsRotate(kRightEighthToDiagSeq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalSeq2 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kRightEighthToDiagSeq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsRotate(kRightEighthToDiagSeq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalSeq4 = {
    .clearance = { -64, 32, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightEighthToDiagSeq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftEighthToDiagSeq4.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0100,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthToDiagSeq2.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthToDiagSeq3.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthToDiagSeq1.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalSeq4 = {
    .clearance = { -32, 64, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftEighthToDiagSeq0.blockedSegments, 3),
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft },                  // narrow
        { PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                  // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagSeq2 = {
    .clearance = { -32, -32, 0, 0, { 0b1000, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                                         // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagSeq3 = {
    .clearance = { -64, 0, 0, 0, { 0b0010, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagSeq4 = {
    .clearance = { -64, -32, 0, 0, { 0b0001, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight },            // narrow
        { PS::right, PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                                                      // wide
    } },
};

static constexpr SequenceDescriptor kRightEighthBankToDiagSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthBankToDiagSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthBankToDiagSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthBankToDiagSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthBankToDiagSeq2 = {
    .clearance = { -32, 32, 0, 0, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthBankToDiagSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthBankToDiagSeq3 = {
    .clearance = { -64, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthBankToDiagSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthBankToDiagSeq4 = {
    .clearance = { -64, 32, 0, 0, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthBankToDiagSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightEighthBankToDiagSeq4.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsRotate(kRightEighthBankToDiagSeq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalSeq2 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kRightEighthBankToDiagSeq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsRotate(kRightEighthBankToDiagSeq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalSeq4 = {
    .clearance = { -64, 32, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightEighthBankToDiagSeq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftEighthBankToDiagSeq4.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0100,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthBankToDiagSeq2.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthBankToDiagSeq3.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthBankToDiagSeq1.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalSeq4 = {
    .clearance = { -32, 64, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftEighthBankToDiagSeq0.blockedSegments, 3),
};

static constexpr SequenceDescriptor kDiagFlatSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60Seq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60Seq1 = {
    .clearance = { 0, 32, 0, 64, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60Seq2 = {
    .clearance = { -32, 0, 0, 64, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60Seq3 = {
    .clearance = { -32, 32, 0, 64, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToUp25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToUp25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToUp25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToUp60Seq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToUp60Seq1 = {
    .clearance = { 0, 32, 0, 32, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToUp60Seq2 = {
    .clearance = { -32, 0, 0, 32, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToUp60Seq3 = {
    .clearance = { -32, 32, 0, 32, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60ToUp25Seq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60ToUp25Seq1 = {
    .clearance = { 0, 32, 0, 32, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60ToUp25Seq2 = {
    .clearance = { -32, 0, 0, 32, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60ToUp25Seq3 = {
    .clearance = { -32, 32, 0, 32, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToFlatSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToFlatSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToFlatSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagDown25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = blockedSegmentsRotate(kDiagUp25Seq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagUp25Seq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagUp25Seq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kDiagUp25Seq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60Seq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1101, 0 }, {} },
    .blockedSegments = blockedSegmentsRotate(kDiagUp60Seq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60Seq1 = {
    .clearance = { 0, 32, 0, 64, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60Seq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60Seq2 = {
    .clearance = { -32, 0, 0, 64, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60Seq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60Seq3 = {
    .clearance = { -32, 32, 0, 64, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kDiagUp60Seq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagFlatToDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = blockedSegmentsRotate(kDiagUp25ToFlatSeq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagFlatToDown25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagUp25ToFlatSeq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagFlatToDown25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagUp25ToFlatSeq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagFlatToDown25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kDiagUp25ToFlatSeq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25ToDown60Seq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1101, 0 }, {} },
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToUp25Seq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25ToDown60Seq1 = {
    .clearance = { 0, 32, 0, 32, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToUp25Seq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25ToDown60Seq2 = {
    .clearance = { -32, 0, 0, 32, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToUp25Seq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25ToDown60Seq3 = {
    .clearance = { -32, 32, 0, 32, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToUp25Seq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60ToDown25Seq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1101, 0 }, {} },
    .blockedSegments = blockedSegmentsRotate(kDiagUp25ToUp60Seq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60ToDown25Seq1 = {
    .clearance = { 0, 32, 0, 32, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagUp25ToUp60Seq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60ToDown25Seq2 = {
    .clearance = { -32, 0, 0, 32, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagUp25ToUp60Seq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60ToDown25Seq3 = {
    .clearance = { -32, 32, 0, 32, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kDiagUp25ToUp60Seq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp25Seq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25ToFlatSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp25Seq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25ToFlatSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp25Seq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown25ToFlatSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp25Seq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagFlatToUp60Seq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                   // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToUp60Seq1 = {
    .clearance = { 0, 32, 0, 24, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        kSegmentsUnimplemented,                             // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToUp60Seq2 = {
    .clearance = { -32, 0, 0, 24, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToUp60Seq3 = {
    .clearance = { -32, 32, 0, 24, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                   // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60ToFlatSeq1 = {
    .clearance = { 0, 32, 0, 24, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        kSegmentsUnimplemented,                             // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60ToFlatSeq2 = {
    .clearance = { -32, 0, 0, 24, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp60ToFlatSeq3 = {
    .clearance = { -32, 32, 0, 24, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToDown60Seq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1101, 0 }, {} },
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatSeq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagFlatToDown60Seq1 = {
    .clearance = { 0, 32, 0, 24, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatSeq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagFlatToDown60Seq2 = {
    .clearance = { -32, 0, 0, 24, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatSeq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagFlatToDown60Seq3 = {
    .clearance = { -32, 32, 0, 24, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatSeq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1101, 0 }, {} },
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60Seq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60ToFlatSeq1 = {
    .clearance = { 0, 32, 0, 24, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60Seq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60ToFlatSeq2 = {
    .clearance = { -32, 0, 0, 24, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60Seq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagDown60ToFlatSeq3 = {
    .clearance = { -32, 32, 0, 24, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60Seq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft },             // narrow
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                                      // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToRightBankSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToRightBankSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToRightBankSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagFlatToRightBankSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft },          // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                                   // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToFlatSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToFlatSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToFlatSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToFlatSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft },             // narrow
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                                      // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToFlatSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToFlatSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToFlatSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToFlatSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft },          // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                                   // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToUp25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToUp25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToUp25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToUp25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToUp25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToUp25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToLeftBankSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToLeftBankSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToLeftBankSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToLeftBankSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToRightBankSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToRightBankSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToRightBankSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagUp25ToRightBankSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToDown25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToDown25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankToDown25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToDown25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToDown25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankToDown25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagDown25ToLeftBankSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagDown25ToLeftBankSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagDown25ToLeftBankSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagDown25ToLeftBankSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagDown25ToRightBankSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagDown25ToRightBankSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagDown25ToRightBankSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagDown25ToRightBankSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagLeftBankSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft },             // narrow
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                                      // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // inverted
        kSegmentsAll,                                       // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                // wide
    } },
};

static constexpr SequenceDescriptor kDiagRightBankSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b0010, 0 }, {} },
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft },          // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsAll,                                                   // wide
    } },
};

static constexpr SequenceDescriptor kLogFlumeReverserSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kSpinningTunnelSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::disallowDoors, SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftBarrelRollUpToDownSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                   // inverted
        kSegmentsAll,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kLeftBarrelRollUpToDownSeq1 = {
    .clearance = { -32, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                               // inverted
        kSegmentsAll,                                                                         // wide
    } },
};

static constexpr SequenceDescriptor kLeftBarrelRollUpToDownSeq2 = {
    .clearance = { -64, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                    // inverted
        kSegmentsAll,                                                              // wide
    } },
};

static constexpr SequenceDescriptor kRightBarrelRollUpToDownSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBarrelRollUpToDownSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightBarrelRollUpToDownSeq1 = {
    .clearance = { -32, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBarrelRollUpToDownSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightBarrelRollUpToDownSeq2 = {
    .clearance = { -64, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBarrelRollUpToDownSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBarrelRollDownToUpSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kLeftBarrelRollUpToDownSeq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftBarrelRollDownToUpSeq1 = {
    .clearance = { -32, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsRotate(kLeftBarrelRollUpToDownSeq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftBarrelRollDownToUpSeq2 = {
    .clearance = { -64, 0, -32, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftBarrelRollUpToDownSeq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kRightBarrelRollDownToUpSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBarrelRollDownToUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightBarrelRollDownToUpSeq1 = {
    .clearance = { -32, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBarrelRollDownToUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightBarrelRollDownToUpSeq2 = {
    .clearance = { -64, 0, -32, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBarrelRollDownToUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankToLeftQuarterTurn3TilesUp25Seq0 = {
    .clearance = { 0, 0, 0, 0, { 0b0111, 0b0100 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankToLeftQuarterTurn3TilesUp25Seq1 = {
    .clearance = { 0, -32, 0, 16, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        kSegmentsNone,          // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsNone,          // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankToLeftQuarterTurn3TilesUp25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        kSegmentsNone,                                         // narrow
        kSegmentsUnimplemented,                                // inverted
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankToLeftQuarterTurn3TilesUp25Seq3 = {
    .clearance = { -32, -32, 16, 16, { 0b0111, 0b0110 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                   // inverted
        kSegmentsAll,                                             // wide
    } },
};

static constexpr SequenceDescriptor kRightBankToRightQuarterTurn3TilesUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1011, 0b1000 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankToLeftQuarterTurn3TilesUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankToRightQuarterTurn3TilesUp25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankToLeftQuarterTurn3TilesUp25Seq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankToRightQuarterTurn3TilesUp25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankToLeftQuarterTurn3TilesUp25Seq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankToRightQuarterTurn3TilesUp25Seq3 = {
    .clearance = { -32, 32, 16, 16, { 0b1011, 0b1001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankToLeftQuarterTurn3TilesUp25Seq3.blockedSegments),
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesDown25ToLeftBankSeq0 = {
    .clearance = { 0, 0, 16, 16, { 0b0111, 0b0011 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightBankToRightQuarterTurn3TilesUp25Seq3.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesDown25ToLeftBankSeq1 = {
    .clearance = { 0, -32, 0, 16, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = blockedSegmentsRotate(kRightBankToRightQuarterTurn3TilesUp25Seq1.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesDown25ToLeftBankSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsRotate(kRightBankToRightQuarterTurn3TilesUp25Seq2.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftQuarterTurn3TilesDown25ToLeftBankSeq3 = {
    .clearance = { -32, -32, 0, 0, { 0b0111, 0b0001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightBankToRightQuarterTurn3TilesUp25Seq0.blockedSegments, 1),
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesDown25ToRightBankSeq0 = {
    .clearance = { 0, 0, 16, 16, { 0b1011, 0b0011 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesDown25ToLeftBankSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesDown25ToRightBankSeq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesDown25ToLeftBankSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesDown25ToRightBankSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesDown25ToLeftBankSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn3TilesDown25ToRightBankSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1011, 0b0010 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn3TilesDown25ToLeftBankSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kPoweredLiftSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopUpSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopUpSeq1 = {
    .clearance = { -32, 0, 16, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopUpSeq2 = {
    .clearance = { -64, 0, 32, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopUpSeq3 = {
    .clearance = { -96, 0, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopUpSeq4 = {
    .clearance = { -128, -32, 120, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopUpSeq5 = {
    .clearance = { -96, -32, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopUpSeq6 = {
    .clearance = { -64, -32, 248, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kRightLargeHalfLoopUpSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeHalfLoopUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeHalfLoopUpSeq1 = {
    .clearance = { -32, 0, 16, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeHalfLoopUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeHalfLoopUpSeq2 = {
    .clearance = { -64, 0, 32, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeHalfLoopUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeHalfLoopUpSeq3 = {
    .clearance = { -96, 0, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeHalfLoopUpSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeHalfLoopUpSeq4 = {
    .clearance = { -128, 32, 120, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeHalfLoopUpSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeHalfLoopUpSeq5 = {
    .clearance = { -96, 32, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeHalfLoopUpSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeHalfLoopUpSeq6 = {
    .clearance = { -64, 32, 248, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeHalfLoopUpSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopDownSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = kRightLargeHalfLoopUpSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopDownSeq1 = {
    .clearance = { -32, 0, -216, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = kRightLargeHalfLoopUpSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopDownSeq2 = {
    .clearance = { -64, 0, -160, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kRightLargeHalfLoopUpSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopDownSeq3 = {
    .clearance = { -32, -32, -216, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightLargeHalfLoopUpSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopDownSeq4 = {
    .clearance = { 0, -32, -248, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = kRightLargeHalfLoopUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopDownSeq5 = {
    .clearance = { 32, -32, -264, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kRightLargeHalfLoopUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftLargeHalfLoopDownSeq6 = {
    .clearance = { 64, -32, -280, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightLargeHalfLoopUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightLargeHalfLoopDownSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = kLeftLargeHalfLoopUpSeq6.blockedSegments,
};

static constexpr SequenceDescriptor kRightLargeHalfLoopDownSeq1 = {
    .clearance = { -32, 0, -216, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = kLeftLargeHalfLoopUpSeq5.blockedSegments,
};

static constexpr SequenceDescriptor kRightLargeHalfLoopDownSeq2 = {
    .clearance = { -64, 0, -160, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kLeftLargeHalfLoopUpSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightLargeHalfLoopDownSeq3 = {
    .clearance = { -32, 32, -216, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftLargeHalfLoopUpSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightLargeHalfLoopDownSeq4 = {
    .clearance = { 0, 32, -248, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = kLeftLargeHalfLoopUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightLargeHalfLoopDownSeq5 = {
    .clearance = { 32, 32, -264, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kLeftLargeHalfLoopUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightLargeHalfLoopDownSeq6 = {
    .clearance = { 64, 32, -280, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftLargeHalfLoopUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftFlyerTwistUpSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerTwistUpSeq1 = {
    .clearance = { -32, 0, -16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerTwistUpSeq2 = {
    .clearance = { -64, 0, -16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kRightFlyerTwistUpSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerTwistUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerTwistUpSeq1 = {
    .clearance = { -32, 0, -16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerTwistUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerTwistUpSeq2 = {
    .clearance = { -64, 0, -16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerTwistUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kLeftFlyerTwistDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftFlyerTwistUpSeq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftFlyerTwistDownSeq1 = {
    .clearance = { -32, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsRotate(kLeftFlyerTwistUpSeq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftFlyerTwistDownSeq2 = {
    .clearance = { -64, 0, 16, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kLeftFlyerTwistUpSeq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kRightFlyerTwistDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerTwistDownSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerTwistDownSeq1 = {
    .clearance = { -32, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerTwistDownSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerTwistDownSeq2 = {
    .clearance = { -64, 0, 16, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerTwistDownSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kFlyerHalfLoopUninvertedUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopUninvertedUpSeq1 = {
    .clearance = { -32, 0, 16, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsAll,           // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopUninvertedUpSeq2 = {
    .clearance = { -64, 0, 32, 96, { 0b0011, 0 }, {} },
    .allowedWallEdges = 0b1011,
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::left, PS::bottom, PS::centre, PS::bottomLeft, PS::topLeft, PS::bottomRight }, // narrow
        { PS::left, PS::bottom, PS::centre, PS::bottomLeft, PS::topLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopUninvertedUpSeq3 = {
    .clearance = { -32, 0, 120, 16, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopInvertedDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlyerHalfLoopUninvertedUpSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kFlyerHalfLoopInvertedDownSeq1 = {
    .clearance = { -32, 0, -88, 96, { 0b0011, 0 }, {} },
    .allowedWallEdges = 0b1011,
    .blockedSegments = kFlyerHalfLoopUninvertedUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kFlyerHalfLoopInvertedDownSeq2 = {
    .clearance = { 0, 0, -104, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .invertSegmentBlocking = true,
    .blockedSegments = kFlyerHalfLoopUninvertedUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kFlyerHalfLoopInvertedDownSeq3 = {
    .clearance = { 32, 0, -120, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = kFlyerHalfLoopUninvertedUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftFlyerCorkscrewUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftCorkscrewUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftFlyerCorkscrewUpSeq1 = {
    .clearance = { -32, 0, 24, 32, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftCorkscrewUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftFlyerCorkscrewUpSeq2 = {
    .clearance = { -32, -32, 48, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = kLeftCorkscrewUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightFlyerCorkscrewUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightCorkscrewUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightFlyerCorkscrewUpSeq1 = {
    .clearance = { -32, 0, 24, 32, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightCorkscrewUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightFlyerCorkscrewUpSeq2 = {
    .clearance = { -32, 32, 48, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = kRightCorkscrewUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftFlyerCorkscrewDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented,                                             // narrow
        { PS::top, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                             // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerCorkscrewDownSeq1 = {
    .clearance = { -32, 0, -24, 32, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsAll,           // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerCorkscrewDownSeq2 = {
    .clearance = { -32, -32, -48, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                   // narrow
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                   // wide
    } },
};

static constexpr SequenceDescriptor kRightFlyerCorkscrewDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                    // narrow
        { PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                    // wide
    } },
};

static constexpr SequenceDescriptor kRightFlyerCorkscrewDownSeq1 = {
    .clearance = { -32, 0, -24, 32, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerCorkscrewDownSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerCorkscrewDownSeq2 = {
    .clearance = { -32, 32, -48, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerCorkscrewDownSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kHeartLineTransferUpSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kHeartLineTransferUpSeq1 = {
    .clearance = { -32, 0, 0, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kHeartLineTransferUpSeq2 = {
    .clearance = { -64, 0, 16, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kHeartLineTransferUpSeq3 = {
    .clearance = { 0, 0, 32, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kHeartLineTransferDownSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kHeartLineTransferUpSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kHeartLineTransferDownSeq1 = {
    .clearance = { -32, 0, -32, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kHeartLineTransferUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kHeartLineTransferDownSeq2 = {
    .clearance = { -64, 0, -16, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kHeartLineTransferUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kHeartLineTransferDownSeq3 = {
    .clearance = { 0, 0, -32, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kHeartLineTransferUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftHeartLineRollSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftHeartLineRollSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftHeartLineRollSeq2 = {
    .clearance = { -64, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftHeartLineRollSeq3 = {
    .clearance = { -96, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftHeartLineRollSeq4 = {
    .clearance = { -128, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftHeartLineRollSeq5 = {
    .clearance = { -160, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kRightHeartLineRollSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHeartLineRollSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightHeartLineRollSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHeartLineRollSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightHeartLineRollSeq2 = {
    .clearance = { -64, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHeartLineRollSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightHeartLineRollSeq3 = {
    .clearance = { -96, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHeartLineRollSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightHeartLineRollSeq4 = {
    .clearance = { -128, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHeartLineRollSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightHeartLineRollSeq5 = {
    .clearance = { -160, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftHeartLineRollSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kMinigolfHoleASeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleASeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleBSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleBSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleCSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleCSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleDSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleDSeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleDSeq2 = {
    .clearance = { -32, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleESeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleESeq1 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMinigolfHoleESeq2 = {
    .clearance = { -32, -32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kMultiDimInvertedFlatToDown90QuarterLoopSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimInvertedFlatToDown90QuarterLoopSeq1 = {
    .clearance = { -32, 0, -40, 32, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimInvertedFlatToDown90QuarterLoopSeq2 = {
    .clearance = { -64, 0, -96, 56, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimInvertedFlatToDown90QuarterLoopSeq3 = {
    .clearance = { -96, 0, -96, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
};

static constexpr SequenceDescriptor kUp90ToInvertedFlatQuarterLoopSeq0 = {
    .clearance = { 0, 0, 0, 56, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kUp90ToInvertedFlatQuarterLoopSeq1 = {
    .clearance = { 32, 0, 56, 32, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kUp90ToInvertedFlatQuarterLoopSeq2 = {
    .clearance = { 64, 0, 96, 16, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kInvertedFlatToDown90QuarterLoopSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kInvertedFlatToDown90QuarterLoopSeq1 = {
    .clearance = { -32, 0, -72, 32, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kInvertedFlatToDown90QuarterLoopSeq2 = {
    .clearance = { -64, 0, -128, 56, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kInvertedFlatToDown90QuarterLoopSeq3 = {
    .clearance = { -96, 0, -128, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
    .blockedSegments = { {
        kSegmentsNone,          // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsNone,          // wide
    } },
};

static constexpr SequenceDescriptor kLeftCurvedLiftHillSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        kSegmentsUnimplemented,                                // wide
    } },
};

static constexpr SequenceDescriptor kLeftCurvedLiftHillSeq1 = {
    .clearance = { 0, -32, 0, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        kSegmentsNone,          // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kLeftCurvedLiftHillSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        kSegmentsNone,          // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kLeftCurvedLiftHillSeq3 = {
    .clearance = { -32, -32, 0, 8, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                   // inverted
        kSegmentsUnimplemented,                                   // wide
    } },
};

static constexpr SequenceDescriptor kRightCurvedLiftHillSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftCurvedLiftHillSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightCurvedLiftHillSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftCurvedLiftHillSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightCurvedLiftHillSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftCurvedLiftHillSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightCurvedLiftHillSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftCurvedLiftHillSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kLeftReverserSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftReverserSeq1 = {
    .clearance = { 0, -32, 0, 0, { 0b1111, 0 }, {} },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftReverserSeq2 = {
    .clearance = { -32, -32, 0, 0, { 0b1111, 0 }, {} },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftReverserSeq3 = {
    .clearance = { -64, -32, 0, 0, { 0b1111, 0 }, {} },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftReverserSeq4 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kLeftReverserSeq5 = {
    .clearance = { -64, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kRightReverserSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftReverserSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightReverserSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b1111, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftReverserSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightReverserSeq2 = {
    .clearance = { -32, 32, 0, 0, { 0b1111, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftReverserSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightReverserSeq3 = {
    .clearance = { -64, 32, 0, 0, { 0b1111, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftReverserSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightReverserSeq4 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftReverserSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightReverserSeq5 = {
    .clearance = { -64, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftReverserSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kAirThrustTopCapSeq0 = {
    .clearance = { 0, 0, 0, 32, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustTopCapSeq1 = {
    .clearance = { 32, 0, 0, 32, { 0b1111, 0 }, {} },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustTopCapSeq2 = {
    .clearance = { -64, 0, 0, 32, { 0b1111, 0 }, {} },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustTopCapSeq3 = {
    .clearance = { -32, 0, 0, 32, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustVerticalDownSeq0 = {
    .clearance = { 0, 0, 0, 48, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustVerticalDownSeq1 = {
    .clearance = { 32, 0, 0, 48, { 0b1111, 0 }, {} },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustVerticalDownToLevelSeq0 = {
    .clearance = { 0, 0, 0, 208, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustVerticalDownToLevelSeq1 = {
    .clearance = { 32, 0, 0, 208, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1110,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustVerticalDownToLevelSeq2 = {
    .clearance = { -32, 0, 0, 160, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustVerticalDownToLevelSeq3 = {
    .clearance = { -64, 0, 0, 80, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustVerticalDownToLevelSeq4 = {
    .clearance = { -96, 0, 0, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustVerticalDownToLevelSeq5 = {
    .clearance = { -128, 0, 0, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kAirThrustVerticalDownToLevelSeq6 = {
    .clearance = { -160, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .woodenSupports = { WoodenSupportSubType::neSw },
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsAll,           // wide
    } },
};

static constexpr SequenceDescriptor kBlockBrakesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TileUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b0111, 0b0100 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft },                  // narrow
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TileUp25Seq1 = {
    .clearance = { 0, -32, 16, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TileUp25Seq2 = {
    .clearance = { -32, 0, 16, 0, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        kSegmentsNone,                                         // narrow
        kSegmentsNone,                                         // inverted
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TileUp25Seq3 = {
    .clearance = { -32, -32, 16, 16, { 0b0111, 0b0110 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomRight },               // narrow
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TileUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1011, 0b1000 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TileUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TileUp25Seq1 = {
    .clearance = { 0, 32, 16, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TileUp25Seq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TileUp25Seq2 = {
    .clearance = { -32, 0, 16, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TileUp25Seq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TileUp25Seq3 = {
    .clearance = { -32, 32, 16, 16, { 0b1011, 0b1001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TileUp25Seq3.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TileDown25Seq0 = {
    .clearance = { 0, 0, 16, 16, { 0b0111, 0b0011 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn3TileUp25Seq3.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TileDown25Seq1 = {
    .clearance = { 0, -32, 16, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn3TileUp25Seq1.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TileDown25Seq2 = {
    .clearance = { -32, 0, 16, 0, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn3TileUp25Seq2.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn3TileDown25Seq3 = {
    .clearance = { -32, -32, 0, 16, { 0b0111, 0b0001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn3TileUp25Seq0.blockedSegments, 1),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TileDown25Seq0 = {
    .clearance = { 0, 0, 16, 16, { 0b1011, 0b0011 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TileDown25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TileDown25Seq1 = {
    .clearance = { 0, 32, 16, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TileDown25Seq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TileDown25Seq2 = {
    .clearance = { -32, 0, 16, 0, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TileDown25Seq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn3TileDown25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b1011, 0b0010 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn3TileDown25Seq3.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft },                  // narrow
        { PS::top, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileUp25Seq1 = {
    .clearance = { 0, -32, 16, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        kSegmentsNone,                                // narrow
        kSegmentsNone,                                // inverted
        { PS::right, PS::topRight, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileUp25Seq2 = {
    .clearance = { -32, 0, 16, 16, { 0b0111, 0b0100 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsAllTypes({ PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileUp25Seq3 = {
    .clearance = { -32, -32, 24, 16, { 0b1101, 0 }, {} },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight },                                                   // narrow
        { PS::right, PS::centre, PS::topRight, PS::bottomRight },                                                   // inverted
        { PS::top, PS::right, PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileUp25Seq4 = {
    .clearance = { -32, -64, 48, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        kSegmentsNone,                                // narrow
        kSegmentsNone,                                // inverted
        { PS::right, PS::topRight, PS::bottomRight }, // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileUp25Seq5 = {
    .clearance = { -64, -32, 32, 16, { 0b0111, 0b0100 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsAllTypes(
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileUp25Seq6 = {
    .clearance = { -64, -64, 48, 16, { 0b1111, 0b0110 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::bottomRight },               // narrow
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomRight }, // inverted
        kSegmentsAll,                                                           // wide
    } },
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileUp25Seq7 = {};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileUp25Seq1 = {
    .clearance = { 0, 32, 16, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileUp25Seq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileUp25Seq2 = {
    .clearance = { -32, 0, 16, 16, { 0b1011, 0b1000 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileUp25Seq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileUp25Seq3 = {
    .clearance = { -32, 32, 24, 16, { 0b1110, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileUp25Seq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileUp25Seq4 = {
    .clearance = { -32, 64, 48, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileUp25Seq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileUp25Seq5 = {
    .clearance = { -64, 32, 32, 16, { 0b1011, 0b1000 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileUp25Seq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileUp25Seq6 = {
    .clearance = { -64, 64, 48, 16, { 0b1111, 0b1001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileUp25Seq6.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileUp25Seq7 = {};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileDown25Seq0 = {
    .clearance = { 0, 0, 48, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn5TileUp25Seq6.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileDown25Seq1 = {
    .clearance = { 0, -32, 48, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn5TileUp25Seq4.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileDown25Seq2 = {
    .clearance = { -32, 0, 32, 16, { 0b0111, 0b0001 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn5TileUp25Seq5.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileDown25Seq3 = {
    .clearance = { -32, -32, 24, 16, { 0b1101, 0 }, {} },
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn5TileUp25Seq3.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileDown25Seq4 = {
    .clearance = { -32, -64, 16, 0, { 0b1000, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1100,
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn5TileUp25Seq1.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileDown25Seq5 = {
    .clearance = { -64, -32, 16, 16, { 0b0111, 0b0001 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn5TileUp25Seq2.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileDown25Seq6 = {
    .clearance = { -64, -64, 0, 16, { 0b1111, 0b1001 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightBankedQuarterTurn5TileUp25Seq0.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftBankedQuarterTurn5TileDown25Seq7 = {};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileDown25Seq0 = {
    .clearance = { 0, 0, 48, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileDown25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileDown25Seq1 = {
    .clearance = { 0, 32, 48, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileDown25Seq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileDown25Seq2 = {
    .clearance = { -32, 0, 32, 16, { 0b1011, 0b0010 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileDown25Seq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileDown25Seq3 = {
    .clearance = { -32, 32, 24, 16, { 0b1110, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileDown25Seq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileDown25Seq4 = {
    .clearance = { -32, 64, 16, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileDown25Seq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileDown25Seq5 = {
    .clearance = { -64, 32, 16, 16, { 0b1011, 0b0010 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileDown25Seq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileDown25Seq6 = {
    .clearance = { -64, 64, 0, 16, { 0b1111, 0b0110 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedQuarterTurn5TileDown25Seq6.blockedSegments),
};

static constexpr SequenceDescriptor kRightBankedQuarterTurn5TileDown25Seq7 = {};

static constexpr SequenceDescriptor kUp25ToLeftBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kUp25ToRightBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kUp25ToLeftBankedUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedUp25ToUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kRightBankedUp25ToUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedUp25ToUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kDown25ToLeftBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kDown25ToRightBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kDown25ToLeftBankedDown25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedDown25ToDown25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kRightBankedDown25ToDown25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedDown25ToDown25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedFlatToLeftBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kRightBankedFlatToRightBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedFlatToLeftBankedUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedUp25ToLeftBankedFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kRightBankedUp25ToRightBankedFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedUp25ToLeftBankedFlatSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedFlatToLeftBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kRightBankedFlatToRightBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedFlatToLeftBankedDown25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedDown25ToLeftBankedFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kRightBankedDown25ToRightBankedFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedDown25ToLeftBankedFlatSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kFlatToLeftBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kFlatToRightBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kFlatToLeftBankedUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedUp25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kRightBankedUp25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedUp25ToFlatSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kFlatToLeftBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kFlatToRightBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0b0011 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kFlatToLeftBankedDown25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftBankedDown25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kRightBankedDown25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftBankedDown25ToFlatSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kLeftQuarterTurn1TileUp90Seq0 = {
    .clearance = { 0, 0, 0, 72, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1111,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterTurn1TileUp90Seq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
};

static constexpr SequenceDescriptor kRightQuarterTurn1TileUp90Seq0 = {
    .clearance = { 0, 0, 0, 72, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1111,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn1TileUp90Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn1TileUp90Seq1 = {
    .clearance = { 0, -32, 0, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
};

static constexpr SequenceDescriptor kLeftQuarterTurn1TileDown90Seq0 = {
    .clearance = { 0, 0, 0, 72, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1111,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topLeft, PS::bottomRight }, // narrow
        { PS::centre, PS::topLeft, PS::bottomRight }, // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftQuarterTurn1TileDown90Seq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
};

static constexpr SequenceDescriptor kRightQuarterTurn1TileDown90Seq0 = {
    .clearance = { 0, 0, 0, 72, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1111,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftQuarterTurn1TileDown90Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightQuarterTurn1TileDown90Seq1 = {
    .clearance = { 0, -32, 0, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
};

static constexpr SequenceDescriptor kMultiDimUp90ToInvertedFlatQuarterLoopSeq0 = {
    .clearance = { 0, 0, 0, 56, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimUp90ToInvertedFlatQuarterLoopSeq1 = {
    .clearance = { 32, 0, 56, 32, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimUp90ToInvertedFlatQuarterLoopSeq2 = {
    .clearance = { 64, 0, 96, 16, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimFlatToDown90QuarterLoopSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimFlatToDown90QuarterLoopSeq1 = {
    .clearance = { -32, 0, -72, 32, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimFlatToDown90QuarterLoopSeq2 = {
    .clearance = { -64, 0, -128, 56, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimFlatToDown90QuarterLoopSeq3 = {
    .clearance = { -96, 0, -128, 0, { 0b0000, 0 }, { ClearanceFlag::flag0, ClearanceFlag::isVertical } },
};

static constexpr SequenceDescriptor kMultiDimInvertedUp90ToFlatQuarterLoopSeq0 = {
    .clearance = { 0, 0, 32, 56, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimInvertedUp90ToFlatQuarterLoopSeq1 = {
    .clearance = { 32, 0, 88, 32, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kMultiDimInvertedUp90ToFlatQuarterLoopSeq2 = {
    .clearance = { 64, 0, 128, 16, { 0b1111, 0 }, { ClearanceFlag::isVertical } },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRotationControlToggleSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kFlatTrack1x4ASeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin,
               SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack1x4ASeq1 = {
    .clearance = { -64, 0, 0, 0, { 0b1111, 0 }, {} },
};

static constexpr SequenceDescriptor kFlatTrack1x4ASeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack1x4ASeq3 = {
    .clearance = { 32, 0, 0, 0, { 0b1111, 0 }, { ClearanceFlag::flag1 } },
};

static constexpr SequenceDescriptor kFlatTrack2x2Seq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin,
               SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack2x2Seq1 = {
    .clearance = { 0, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack2x2Seq2 = {
    .clearance = { 32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSW, SequenceFlag::entranceConnectionNW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack2x2Seq3 = {
    .clearance = { 32, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin,
               SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq1 = {
    .clearance = { 0, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq2 = {
    .clearance = { 0, 64, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq3 = {
    .clearance = { 0, 96, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq4 = {
    .clearance = { 32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNW },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq5 = {
    .clearance = { 32, 32, 0, 0, { 0b1111, 0 }, {} },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq6 = {
    .clearance = { 32, 64, 0, 0, { 0b1111, 0 }, {} },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq7 = {
    .clearance = { 32, 96, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq8 = {
    .clearance = { 64, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNW },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq9 = {
    .clearance = { 64, 32, 0, 0, { 0b1111, 0 }, {} },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq10 = {
    .clearance = { 64, 64, 0, 0, { 0b1111, 0 }, {} },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq11 = {
    .clearance = { 64, 96, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq12 = {
    .clearance = { 96, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSW, SequenceFlag::entranceConnectionNW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq13 = {
    .clearance = { 96, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSW },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq14 = {
    .clearance = { 96, 64, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSW },
};

static constexpr SequenceDescriptor kFlatTrack4x4Seq15 = {
    .clearance = { 96, 96, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack2x4Seq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin,
               SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack2x4Seq1 = {
    .clearance = { 0, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE },
};

static constexpr SequenceDescriptor kFlatTrack2x4Seq2 = {
    .clearance = { 0, 64, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE },
};

static constexpr SequenceDescriptor kFlatTrack2x4Seq3 = {
    .clearance = { 0, 96, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack2x4Seq4 = {
    .clearance = { 32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSW, SequenceFlag::entranceConnectionNW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack2x4Seq5 = {
    .clearance = { 32, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSW },
};

static constexpr SequenceDescriptor kFlatTrack2x4Seq6 = {
    .clearance = { 32, 64, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSW },
};

static constexpr SequenceDescriptor kFlatTrack2x4Seq7 = {
    .clearance = { 32, 96, 0, 0, { 0b1111, 0 }, { ClearanceFlag::flag1 } },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack1x5Seq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kFlatTrack1x5Seq1 = {
    .clearance = { -64, 0, 0, 0, { 0b1111, 0 }, {} },
};

static constexpr SequenceDescriptor kFlatTrack1x5Seq2 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack1x5Seq3 = {
    .clearance = { 32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack1x5Seq4 = {
    .clearance = { 64, 0, 0, 0, { 0b1111, 0 }, { ClearanceFlag::flag1 } },
};

static constexpr SequenceDescriptor kFlatTrack1x1ASeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::trackOrigin, SequenceFlag::connectsToPath,
               SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack1x4BSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::trackOrigin, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack1x4BSeq1 = {
    .clearance = { -64, 0, 0, 0, { 0b1111, 0 }, {} },
};

static constexpr SequenceDescriptor kFlatTrack1x4BSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack1x4BSeq3 = {
    .clearance = { 32, 0, 0, 0, { 0b1111, 0 }, { ClearanceFlag::flag1 } },
};

static constexpr SequenceDescriptor kFlatTrack1x1BSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW,
               SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin, SequenceFlag::connectsToPath,
               SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack1x4CSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW, SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kFlatTrack1x4CSeq1 = {
    .clearance = { -64, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW,
               SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack1x4CSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionNW },
};

static constexpr SequenceDescriptor kFlatTrack1x4CSeq3 = {
    .clearance = { 32, 0, 0, 0, { 0b1111, 0 }, { ClearanceFlag::flag1 } },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW, SequenceFlag::entranceConnectionNW,
               SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack3x3Seq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::trackOrigin },
};

static constexpr SequenceDescriptor kFlatTrack3x3Seq1 = {
    .clearance = { -32, -32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionNW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack3x3Seq2 = {
    .clearance = { -32, 0, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE },
};

static constexpr SequenceDescriptor kFlatTrack3x3Seq3 = {
    .clearance = { -32, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNE, SequenceFlag::entranceConnectionSE, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack3x3Seq4 = {
    .clearance = { 0, -32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionNW },
};

static constexpr SequenceDescriptor kFlatTrack3x3Seq5 = {
    .clearance = { 0, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE },
};

static constexpr SequenceDescriptor kFlatTrack3x3Seq6 = {
    .clearance = { 32, -32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSW, SequenceFlag::entranceConnectionNW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack3x3Seq7 = {
    .clearance = { 32, 32, 0, 0, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::entranceConnectionSE, SequenceFlag::entranceConnectionSW, SequenceFlag::hasHeightMarker },
};

static constexpr SequenceDescriptor kFlatTrack3x3Seq8 = {
    .clearance = { 32, 0, 0, 0, { 0b1111, 0 }, { ClearanceFlag::flag1 } },
    .flags = { SequenceFlag::entranceConnectionSW },
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                             // inverted
        kSegmentsUnimplemented,                                             // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewUpSeq1 = {
    .clearance = { -32, 0, 8, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewUpSeq2 = {
    .clearance = { -64, 0, 32, 24, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        kSegmentsUnimplemented,                                // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewUpSeq3 = {
    .clearance = { -32, -32, 32, 24, { 0b1000, 0 }, {} },
    .allowedWallEdges = 0b1100,
    .blockedSegments = { {
        kSegmentsNone,          // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewUpSeq4 = {
    .clearance = { -64, -32, 48, 40, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                             // inverted
        kSegmentsUnimplemented,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewUpSeq5 = {
    .clearance = { -64, -64, 72, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                             // inverted
        kSegmentsUnimplemented,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kRightLargeCorkscrewUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewUpSeq1 = {
    .clearance = { -32, 0, 8, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewUpSeq2 = {
    .clearance = { -64, 0, 32, 24, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewUpSeq3 = {
    .clearance = { -32, 32, 32, 24, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewUpSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewUpSeq4 = {
    .clearance = { -64, 32, 48, 40, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewUpSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewUpSeq5 = {
    .clearance = { -64, 64, 72, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewUpSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewDownSeq0 = {
    .clearance = { 0, 0, -40, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kRightLargeCorkscrewUpSeq5.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewDownSeq1 = {
    .clearance = { -32, 0, -64, 40, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kRightLargeCorkscrewUpSeq4.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewDownSeq2 = {
    .clearance = { -32, -32, -80, 24, { 0b1000, 0 }, {} },
    .allowedWallEdges = 0b1100,
    .blockedSegments = blockedSegmentsRotate(kRightLargeCorkscrewUpSeq3.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewDownSeq3 = {
    .clearance = { -64, 0, -80, 24, { 0b0111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsRotate(kRightLargeCorkscrewUpSeq2.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewDownSeq4 = {
    .clearance = { -64, -32, -104, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsRotate(kRightLargeCorkscrewUpSeq1.blockedSegments, 1),
};

static constexpr SequenceDescriptor kLeftLargeCorkscrewDownSeq5 = {
    .clearance = { -64, -64, -112, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightLargeCorkscrewUpSeq0.blockedSegments, 1),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewDownSeq0 = {
    .clearance = { 0, 0, -40, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewDownSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewDownSeq1 = {
    .clearance = { -32, 0, -64, 40, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewDownSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewDownSeq2 = {
    .clearance = { -32, 32, -80, 24, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewDownSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewDownSeq3 = {
    .clearance = { -64, 0, -80, 24, { 0b1011, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewDownSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewDownSeq4 = {
    .clearance = { -64, 32, -104, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewDownSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeCorkscrewDownSeq5 = {
    .clearance = { -64, 64, -112, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeCorkscrewDownSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kLeftMediumHalfLoopUpSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftMediumHalfLoopUpSeq1 = {
    .clearance = { -32, 0, 16, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftMediumHalfLoopUpSeq2 = {
    .clearance = { -64, 0, 56, 120, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        kSegmentsUnimplemented,                                // wide
    } },
};

static constexpr SequenceDescriptor kLeftMediumHalfLoopUpSeq3 = {
    .clearance = { -64, -32, 56, 120, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};

static constexpr SequenceDescriptor kLeftMediumHalfLoopUpSeq4 = {
    .clearance = { -32, -32, 168, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                               // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kRightMediumHalfLoopUpSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftMediumHalfLoopUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightMediumHalfLoopUpSeq1 = {
    .clearance = { -32, 0, 16, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftMediumHalfLoopUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightMediumHalfLoopUpSeq2 = {
    .clearance = { -64, 0, 56, 120, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftMediumHalfLoopUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightMediumHalfLoopUpSeq3 = {
    .clearance = { -64, 32, 56, 120, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftMediumHalfLoopUpSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightMediumHalfLoopUpSeq4 = {
    .clearance = { -32, 32, 168, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftMediumHalfLoopUpSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kLeftMediumHalfLoopDownSeq0 = {
    .clearance = { 0, 0, -48, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightMediumHalfLoopUpSeq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftMediumHalfLoopDownSeq1 = {
    .clearance = { -32, 0, -160, 120, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kRightMediumHalfLoopUpSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftMediumHalfLoopDownSeq2 = {
    .clearance = { -32, -32, -160, 120, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightMediumHalfLoopUpSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftMediumHalfLoopDownSeq3 = {
    .clearance = { 0, -32, -200, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = kRightMediumHalfLoopUpSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftMediumHalfLoopDownSeq4 = {
    .clearance = { 32, -32, -216, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightMediumHalfLoopUpSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightMediumHalfLoopDownSeq0 = {
    .clearance = { 0, 0, -48, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftMediumHalfLoopDownSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightMediumHalfLoopDownSeq1 = {
    .clearance = { -32, 0, -160, 120, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftMediumHalfLoopDownSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightMediumHalfLoopDownSeq2 = {
    .clearance = { -32, 32, -160, 120, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftMediumHalfLoopDownSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightMediumHalfLoopDownSeq3 = {
    .clearance = { 0, 32, -200, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftMediumHalfLoopDownSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightMediumHalfLoopDownSeq4 = {
    .clearance = { 32, 32, -216, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftMediumHalfLoopDownSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kLeftZeroGRollUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftZeroGRollUpSeq1 = {
    .clearance = { -32, 0, 8, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsAll,                                                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftZeroGRollUpSeq2 = {
    .clearance = { -64, 0, 24, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsAll,                                                                 // wide
    } },
};

static constexpr SequenceDescriptor kRightZeroGRollUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftZeroGRollUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightZeroGRollUpSeq1 = {
    .clearance = { -32, 0, 8, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftZeroGRollUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightZeroGRollUpSeq2 = {
    .clearance = { -64, 0, 24, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftZeroGRollUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kLeftZeroGRollDownSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kLeftZeroGRollUpSeq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftZeroGRollDownSeq1 = {
    .clearance = { -32, 0, -48, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsRotate(kLeftZeroGRollUpSeq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftZeroGRollDownSeq2 = {
    .clearance = { -64, 0, -56, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftZeroGRollUpSeq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kRightZeroGRollDownSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftZeroGRollDownSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightZeroGRollDownSeq1 = {
    .clearance = { -32, 0, -48, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftZeroGRollDownSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightZeroGRollDownSeq2 = {
    .clearance = { -64, 0, -56, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftZeroGRollDownSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kLeftLargeZeroGRollUpSeq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeZeroGRollUpSeq1 = {
    .clearance = { -32, 0, 56, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeZeroGRollUpSeq2 = {
    .clearance = { -64, 0, 96, 40, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsAll,                                                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftLargeZeroGRollUpSeq3 = {
    .clearance = { -96, 0, 120, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsAll,                                                                 // wide
    } },
};

static constexpr SequenceDescriptor kRightLargeZeroGRollUpSeq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeZeroGRollUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeZeroGRollUpSeq1 = {
    .clearance = { -32, 0, 56, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeZeroGRollUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeZeroGRollUpSeq2 = {
    .clearance = { -64, 0, 96, 40, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeZeroGRollUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeZeroGRollUpSeq3 = {
    .clearance = { -96, 0, 120, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeZeroGRollUpSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kLeftLargeZeroGRollDownSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kLeftLargeZeroGRollUpSeq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftLargeZeroGRollDownSeq1 = {
    .clearance = { -32, 0, -56, 40, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsRotate(kLeftLargeZeroGRollUpSeq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftLargeZeroGRollDownSeq2 = {
    .clearance = { -64, 0, -96, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsRotate(kLeftLargeZeroGRollUpSeq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftLargeZeroGRollDownSeq3 = {
    .clearance = { -96, 0, -152, 64, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftLargeZeroGRollUpSeq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kRightLargeZeroGRollDownSeq0 = {
    .clearance = { 0, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeZeroGRollDownSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeZeroGRollDownSeq1 = {
    .clearance = { -32, 0, -56, 40, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeZeroGRollDownSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeZeroGRollDownSeq2 = {
    .clearance = { -64, 0, -96, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeZeroGRollDownSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightLargeZeroGRollDownSeq3 = {
    .clearance = { -96, 0, -152, 64, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftLargeZeroGRollDownSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedUpSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedUpSeq1 = {
    .clearance = { -32, 0, 16, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedUpSeq2 = {
    .clearance = { -64, 0, 32, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedUpSeq3 = {
    .clearance = { -96, 0, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedUpSeq4 = {
    .clearance = { -128, -32, 120, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedUpSeq5 = {
    .clearance = { -96, -32, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                               // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedUpSeq6 = {
    .clearance = { -64, -32, 248, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                               // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedUpSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedUpSeq1 = {
    .clearance = { -32, 0, 16, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedUpSeq2 = {
    .clearance = { -64, 0, 32, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedUpSeq3 = {
    .clearance = { -96, 0, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedUpSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedUpSeq4 = {
    .clearance = { -128, 32, 120, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedUpSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedUpSeq5 = {
    .clearance = { -96, 32, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedUpSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedUpSeq6 = {
    .clearance = { -64, 32, 248, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedUpSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                       // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedDownSeq1 = {
    .clearance = { -32, 0, -184, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                       // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedDownSeq2 = {
    .clearance = { -64, 0, -128, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                // narrow
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedDownSeq3 = {
    .clearance = { -32, -32, -184, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                               // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedDownSeq4 = {
    .clearance = { 0, -32, -216, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                               // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedDownSeq5 = {
    .clearance = { 32, -32, -232, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        kSegmentsUnimplemented,                       // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedDownSeq6 = {
    .clearance = { 64, -32, -248, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        kSegmentsUnimplemented,                       // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedDownSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedDownSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedDownSeq1 = {
    .clearance = { -32, 0, -184, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedDownSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedDownSeq2 = {
    .clearance = { -64, 0, -128, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedDownSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedDownSeq3 = {
    .clearance = { -32, 32, -184, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedDownSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedDownSeq4 = {
    .clearance = { 0, 32, -216, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedDownSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedDownSeq5 = {
    .clearance = { 32, 32, -232, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedDownSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedDownSeq6 = {
    .clearance = { 64, 32, -248, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedDownSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedUpSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented,                       // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedUpSeq1 = {
    .clearance = { -32, 0, 16, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented,                       // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedUpSeq2 = {
    .clearance = { -64, 0, 32, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                       // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedUpSeq3 = {
    .clearance = { -96, 0, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                       // narrow
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedUpSeq4 = {
    .clearance = { -128, -32, 120, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                      // narrow
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedUpSeq5 = {
    .clearance = { -96, -32, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                               // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopInvertedUpSeq6 = {
    .clearance = { -64, -32, 248, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                               // narrow
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedUpSeq0 = {
    .clearance = { 0, 0, 0, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedUpSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedUpSeq1 = {
    .clearance = { -32, 0, 16, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedUpSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedUpSeq2 = {
    .clearance = { -64, 0, 32, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedUpSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedUpSeq3 = {
    .clearance = { -96, 0, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedUpSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedUpSeq4 = {
    .clearance = { -128, 32, 120, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedUpSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedUpSeq5 = {
    .clearance = { -96, 32, 64, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedUpSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopInvertedUpSeq6 = {
    .clearance = { -64, 32, 248, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopInvertedUpSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedDownSeq0 = {
    .clearance = { 0, 0, -32, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedDownSeq1 = {
    .clearance = { -32, 0, -216, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedDownSeq2 = {
    .clearance = { -64, 0, -160, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        kSegmentsUnimplemented,                                // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedDownSeq3 = {
    .clearance = { -32, -32, -216, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                               // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedDownSeq4 = {
    .clearance = { 0, -32, -248, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                               // inverted
        kSegmentsUnimplemented,                                                               // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedDownSeq5 = {
    .clearance = { 32, -32, -264, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftFlyerLargeHalfLoopUninvertedDownSeq6 = {
    .clearance = { 64, -32, -280, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedDownSeq0 = {
    .clearance = { 0, 0, -32, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedDownSeq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedDownSeq1 = {
    .clearance = { -32, 0, -216, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedDownSeq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedDownSeq2 = {
    .clearance = { -64, 0, -160, 96, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedDownSeq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedDownSeq3 = {
    .clearance = { -32, 32, -216, 192, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedDownSeq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedDownSeq4 = {
    .clearance = { 0, 32, -248, 56, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedDownSeq4.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedDownSeq5 = {
    .clearance = { 32, 32, -264, 40, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedDownSeq5.blockedSegments),
};

static constexpr SequenceDescriptor kRightFlyerLargeHalfLoopUninvertedDownSeq6 = {
    .clearance = { 64, 32, -280, 24, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftFlyerLargeHalfLoopUninvertedDownSeq6.blockedSegments),
};

static constexpr SequenceDescriptor kFlyerHalfLoopInvertedUpSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        kSegmentsUnimplemented,                       // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopInvertedUpSeq1 = {
    .clearance = { -32, 0, 16, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsUnimplemented, // narrow
        kSegmentsAll,           // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopInvertedUpSeq2 = {
    .clearance = { -64, 0, 32, 96, { 0b0011, 0 }, {} },
    .allowedWallEdges = 0b1011,
    .blockedSegments = { {
        kSegmentsUnimplemented,                                                             // narrow
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // inverted
        kSegmentsUnimplemented,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopInvertedUpSeq3 = {
    .clearance = { -32, 0, 120, 32, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        kSegmentsUnimplemented,                       // narrow
        { PS::centre, PS::topRight, PS::bottomLeft }, // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopUninvertedDownSeq0 = {
    .clearance = { 0, 0, -32, 32, { 0b1111, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopUninvertedDownSeq1 = {
    .clearance = { -32, 0, -120, 96, { 0b0011, 0 }, {} },
    .allowedWallEdges = 0b1011,
    .blockedSegments = { {
        { PS::left, PS::bottom, PS::centre, PS::topLeft, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                             // inverted
        kSegmentsUnimplemented,                                                             // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopUninvertedDownSeq2 = {
    .clearance = { 0, 0, -136, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .blockedSegments = { {
        kSegmentsAll,           // narrow
        kSegmentsUnimplemented, // inverted
        kSegmentsUnimplemented, // wide
    } },
};

static constexpr SequenceDescriptor kFlyerHalfLoopUninvertedDownSeq3 = {
    .clearance = { 32, 0, -152, 16, { 0b1111, 0b1100 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsUnimplemented,                       // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthToDiagUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::centre, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                       // inverted
        kSegmentsAll,                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthToDiagUp25Seq1 = {
    .clearance = { -32, 0, 16, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsAll,                                                                 // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthToDiagUp25Seq2 = {
    .clearance = { -32, -32, 32, 16, { 0b1000, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = { {
        { PS::right, PS::bottom, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                               // inverted
        kSegmentsAll,                                                         // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthToDiagUp25Seq3 = {
    .clearance = { -64, 0, 32, 16, { 0b0010, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0011,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        kSegmentsAll,                                          // wide
    } },
};

static constexpr SequenceDescriptor kLeftEighthToDiagUp25Seq4 = {
    .clearance = { -64, -32, 32, 24, { 0b0001, 0 }, {} },
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                                 // inverted
        kSegmentsAll,                                                                           // wide
    } },
};

static constexpr SequenceDescriptor kRightEighthToDiagUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagUp25Seq1 = {
    .clearance = { -32, 0, 16, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagUp25Seq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagUp25Seq2 = {
    .clearance = { -32, 32, 32, 16, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagUp25Seq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagUp25Seq3 = {
    .clearance = { -64, 0, 32, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagUp25Seq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagUp25Seq4 = {
    .clearance = { -64, 32, 32, 24, { 0b0010, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagUp25Seq4.blockedSegments),
};

static constexpr SequenceDescriptor kLeftEighthToDiagDown25Seq0 = {
    .clearance = { 0, 0, -16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftEighthToDiagUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthToDiagDown25Seq1 = {
    .clearance = { -32, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = kLeftEighthToDiagUp25Seq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthToDiagDown25Seq2 = {
    .clearance = { -32, -32, -48, 16, { 0b1000, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = kLeftEighthToDiagUp25Seq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthToDiagDown25Seq3 = {
    .clearance = { -64, 0, -48, 16, { 0b0010, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftEighthToDiagUp25Seq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthToDiagDown25Seq4 = {
    .clearance = { -64, -32, -48, 16, { 0b0001, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftEighthToDiagUp25Seq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthToDiagDown25Seq0 = {
    .clearance = { 0, 0, -16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagDown25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagDown25Seq1 = {
    .clearance = { -32, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagDown25Seq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagDown25Seq2 = {
    .clearance = { -32, 32, -48, 16, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagDown25Seq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagDown25Seq3 = {
    .clearance = { -64, 0, -48, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagDown25Seq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthToDiagDown25Seq4 = {
    .clearance = { -64, 32, -48, 16, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthToDiagDown25Seq4.blockedSegments),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightEighthToDiagUp25Seq4.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalUp25Seq1 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsRotate(kRightEighthToDiagUp25Seq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalUp25Seq2 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kRightEighthToDiagUp25Seq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalUp25Seq3 = {
    .clearance = { -32, 32, 16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsRotate(kRightEighthToDiagUp25Seq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalUp25Seq4 = {
    .clearance = { -64, 32, 32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightEighthToDiagUp25Seq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftEighthToDiagUp25Seq4.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalUp25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0100,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthToDiagUp25Seq2.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalUp25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthToDiagUp25Seq3.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalUp25Seq3 = {
    .clearance = { -32, 32, 16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthToDiagUp25Seq1.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalUp25Seq4 = {
    .clearance = { -32, 64, 32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftEighthToDiagUp25Seq0.blockedSegments, 3),
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalDown25Seq0 = {
    .clearance = { 0, 0, -16, 24, { 0b1101, 0 }, {} },
    .blockedSegments = kLeftEighthToOrthogonalUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalDown25Seq1 = {
    .clearance = { -32, 0, -16, 16, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = kLeftEighthToOrthogonalUp25Seq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalDown25Seq2 = {
    .clearance = { 0, 32, -16, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kLeftEighthToOrthogonalUp25Seq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalDown25Seq3 = {
    .clearance = { -32, 32, -32, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = kLeftEighthToOrthogonalUp25Seq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthToOrthogonalDown25Seq4 = {
    .clearance = { -64, 32, -48, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftEighthToOrthogonalUp25Seq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalDown25Seq0 = {
    .clearance = { 0, 0, -16, 24, { 0b1101, 0 }, {} },
    .blockedSegments = kRightEighthToOrthogonalUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalDown25Seq1 = {
    .clearance = { 0, 32, -16, 16, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0100,
    .blockedSegments = kRightEighthToOrthogonalUp25Seq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalDown25Seq2 = {
    .clearance = { -32, 0, -16, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightEighthToOrthogonalUp25Seq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalDown25Seq3 = {
    .clearance = { -32, 32, -32, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = kRightEighthToOrthogonalUp25Seq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthToOrthogonalDown25Seq4 = {
    .clearance = { -32, 64, -48, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightEighthToOrthogonalUp25Seq4.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25ToLeftBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25ToLeftBankedUp25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25ToLeftBankedUp25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25ToLeftBankedUp25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25ToRightBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25ToRightBankedUp25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25ToRightBankedUp25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25ToRightBankedUp25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToUp25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToUp25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToUp25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToUp25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToUp25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToUp25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25ToLeftBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25ToLeftBankedDown25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25ToLeftBankedDown25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25ToLeftBankedDown25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25ToRightBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25ToRightBankedDown25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25ToRightBankedDown25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25ToRightBankedDown25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToDown25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToDown25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToDown25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToDown25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToDown25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToDown25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToDown25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToDown25Seq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedFlatToLeftBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedFlatToLeftBankedUp25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedFlatToLeftBankedUp25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedFlatToLeftBankedUp25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedFlatToRightBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedFlatToRightBankedUp25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedFlatToRightBankedUp25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedFlatToRightBankedUp25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToLeftBankedFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToLeftBankedFlatSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToLeftBankedFlatSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToLeftBankedFlatSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToRightBankedFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToRightBankedFlatSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToRightBankedFlatSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToRightBankedFlatSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedFlatToLeftBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedFlatToLeftBankedDown25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedFlatToLeftBankedDown25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedFlatToLeftBankedDown25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedFlatToRightBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedFlatToRightBankedDown25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedFlatToRightBankedDown25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedFlatToRightBankedDown25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToLeftBankedFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToLeftBankedFlatSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToLeftBankedFlatSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToLeftBankedFlatSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToRightBankedFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToRightBankedFlatSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToRightBankedFlatSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToRightBankedFlatSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankedUp25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankedUp25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankedUp25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToRightBankedUp25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToRightBankedUp25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToRightBankedUp25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToRightBankedUp25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToFlatSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToFlatSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedUp25ToFlatSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToFlatSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToFlatSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedUp25ToFlatSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankedDown25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankedDown25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToLeftBankedDown25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToRightBankedDown25Seq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToRightBankedDown25Seq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToRightBankedDown25Seq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToRightBankedDown25Seq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToFlatSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToFlatSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagLeftBankedDown25ToFlatSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToFlatSeq0 = {
    .clearance = { 0, 0, 0, 8, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToFlatSeq1 = {
    .clearance = { 0, 32, 0, 8, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToFlatSeq2 = {
    .clearance = { -32, 0, 0, 8, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagRightBankedDown25ToFlatSeq3 = {
    .clearance = { -32, 32, 0, 8, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25LeftBankedSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25LeftBankedSeq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25LeftBankedSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25LeftBankedSeq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25RightBankedSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25RightBankedSeq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25RightBankedSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagUp25RightBankedSeq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25LeftBankedSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25LeftBankedSeq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25LeftBankedSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25LeftBankedSeq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25RightBankedSeq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25RightBankedSeq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25RightBankedSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagDown25RightBankedSeq3 = {
    .clearance = { -32, 32, 0, 16, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftEighthToDiagUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagUp25Seq1 = {
    .clearance = { -32, 0, 16, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = kLeftEighthToDiagUp25Seq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagUp25Seq2 = {
    .clearance = { -32, -32, 32, 16, { 0b1000, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = kLeftEighthToDiagUp25Seq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagUp25Seq3 = {
    .clearance = { -64, 0, 32, 16, { 0b0010, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftEighthToDiagUp25Seq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagUp25Seq4 = {
    .clearance = { -64, -32, 32, 24, { 0b0001, 0 }, {} },
    .blockedSegments = kLeftEighthToDiagUp25Seq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToDiagUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthBankToDiagUp25Seq0.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthBankToDiagUp25Seq1 = {
    .clearance = { -32, 0, 16, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthBankToDiagUp25Seq1.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthBankToDiagUp25Seq2 = {
    .clearance = { -32, 32, 32, 16, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthBankToDiagUp25Seq2.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthBankToDiagUp25Seq3 = {
    .clearance = { -64, 0, 32, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthBankToDiagUp25Seq3.blockedSegments),
};

static constexpr SequenceDescriptor kRightEighthBankToDiagUp25Seq4 = {
    .clearance = { -64, 32, 32, 24, { 0b0010, 0 }, {} },
    .blockedSegments = blockedSegmentsFlipXAxis(kLeftEighthBankToDiagUp25Seq4.blockedSegments),
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagDown25Seq0 = {
    .clearance = { 0, 0, -16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftEighthBankToDiagUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagDown25Seq1 = {
    .clearance = { -32, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = kLeftEighthBankToDiagUp25Seq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagDown25Seq2 = {
    .clearance = { -32, -32, -48, 16, { 0b1000, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = kLeftEighthBankToDiagUp25Seq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagDown25Seq3 = {
    .clearance = { -64, 0, -48, 16, { 0b0010, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0011,
    .blockedSegments = kLeftEighthBankToDiagUp25Seq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToDiagDown25Seq4 = {
    .clearance = { -64, -32, -48, 16, { 0b0001, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftEighthBankToDiagUp25Seq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToDiagDown25Seq0 = {
    .clearance = { 0, 0, -16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightEighthBankToDiagUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToDiagDown25Seq1 = {
    .clearance = { -32, 0, -32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = kRightEighthBankToDiagUp25Seq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToDiagDown25Seq2 = {
    .clearance = { -32, 32, -48, 16, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = kRightEighthBankToDiagUp25Seq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToDiagDown25Seq3 = {
    .clearance = { -64, 0, -48, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightEighthBankToDiagUp25Seq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToDiagDown25Seq4 = {
    .clearance = { -64, 32, -48, 16, { 0b0010, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightEighthBankToDiagUp25Seq4.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightEighthBankToDiagUp25Seq4.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalUp25Seq1 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsRotate(kRightEighthBankToDiagUp25Seq2.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalUp25Seq2 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kRightEighthBankToDiagUp25Seq3.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalUp25Seq3 = {
    .clearance = { -32, 32, 16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsRotate(kRightEighthBankToDiagUp25Seq1.blockedSegments, 2),
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalUp25Seq4 = {
    .clearance = { -64, 32, 32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightEighthBankToDiagUp25Seq0.blockedSegments, 2),
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalUp25Seq0 = {
    .clearance = { 0, 0, 0, 16, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftEighthBankToDiagUp25Seq4.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalUp25Seq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0100,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthBankToDiagUp25Seq2.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalUp25Seq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthBankToDiagUp25Seq3.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalUp25Seq3 = {
    .clearance = { -32, 32, 16, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthBankToDiagUp25Seq1.blockedSegments, 3),
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalUp25Seq4 = {
    .clearance = { -32, 64, 32, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftEighthBankToDiagUp25Seq0.blockedSegments, 3),
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalDown25Seq0 = {
    .clearance = { 0, 0, -16, 24, { 0b1101, 0 }, {} },
    .blockedSegments = kLeftEighthBankToOrthogonalUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalDown25Seq1 = {
    .clearance = { -32, 0, -16, 16, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = kLeftEighthBankToOrthogonalUp25Seq1.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalDown25Seq2 = {
    .clearance = { 0, 32, -16, 16, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kLeftEighthBankToOrthogonalUp25Seq2.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalDown25Seq3 = {
    .clearance = { -32, 32, -32, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = kLeftEighthBankToOrthogonalUp25Seq3.blockedSegments,
};

static constexpr SequenceDescriptor kLeftEighthBankToOrthogonalDown25Seq4 = {
    .clearance = { -64, 32, -48, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kLeftEighthBankToOrthogonalUp25Seq4.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalDown25Seq0 = {
    .clearance = { 0, 0, -16, 24, { 0b1101, 0 }, {} },
    .blockedSegments = kRightEighthBankToOrthogonalUp25Seq0.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalDown25Seq1 = {
    .clearance = { 0, 32, -16, 16, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0100,
    .blockedSegments = kRightEighthBankToOrthogonalUp25Seq1.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalDown25Seq2 = {
    .clearance = { -32, 0, -16, 16, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kRightEighthBankToOrthogonalUp25Seq2.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalDown25Seq3 = {
    .clearance = { -32, 32, -32, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = kRightEighthBankToOrthogonalUp25Seq3.blockedSegments,
};

static constexpr SequenceDescriptor kRightEighthBankToOrthogonalDown25Seq4 = {
    .clearance = { -32, 64, -48, 16, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kRightEighthBankToOrthogonalUp25Seq4.blockedSegments,
};

static constexpr SequenceDescriptor kDiagBrakesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagBrakesSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagBrakesSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagBrakesSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagBlockBrakesSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = kDiagFlatSeq0.blockedSegments,
};

static constexpr SequenceDescriptor kDiagBlockBrakesSeq1 = {
    .clearance = { 0, 32, 0, 0, { 0b0100, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b0110,
    .blockedSegments = kDiagFlatSeq1.blockedSegments,
};

static constexpr SequenceDescriptor kDiagBlockBrakesSeq2 = {
    .clearance = { -32, 0, 0, 0, { 0b0001, 0 }, { ClearanceFlag::flag0 } },
    .allowedWallEdges = 0b1001,
    .blockedSegments = kDiagFlatSeq2.blockedSegments,
};

static constexpr SequenceDescriptor kDiagBlockBrakesSeq3 = {
    .clearance = { -32, 32, 0, 0, { 0b0010, 0 }, {} },
    .blockedSegments = kDiagFlatSeq3.blockedSegments,
};

static constexpr SequenceDescriptor kDiagFlatToUp60LongBaseSeq0 = {
    .clearance = { 0, 0, 0, 0, { 0b1101, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                   // inverted
        kSegmentsUnimplemented,                                   // wide
    } },
};
static constexpr SequenceDescriptor kDiagFlatToUp60LongBaseSeq1 = {
    .clearance = { 0, 32, 0, 16, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        kSegmentsUnimplemented,                             // inverted
        kSegmentsUnimplemented,                             // wide
    } },
};
static constexpr SequenceDescriptor kDiagFlatToUp60LongBaseSeq2 = {
    .clearance = { -32, 0, 0, 16, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};
static constexpr SequenceDescriptor kDiagFlatToUp60LongBaseSeq3 = {
    .clearance = { -32, 32, 0, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = { {
        { PS::left, PS::right, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                                          // inverted
        kSegmentsUnimplemented,                                                                          // wide
    } },
};
static constexpr SequenceDescriptor kDiagFlatToUp60LongBaseSeq4 = {
    .clearance = { -32, 64, 8, 40, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        kSegmentsUnimplemented,                             // inverted
        kSegmentsUnimplemented,                             // wide
    } },
};
static constexpr SequenceDescriptor kDiagFlatToUp60LongBaseSeq5 = {
    .clearance = { -64, 32, 8, 40, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};
static constexpr SequenceDescriptor kDiagFlatToUp60LongBaseSeq6 = {
    .clearance = { -64, 64, 8, 64, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = { {
        { PS::left, PS::right, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                                          // inverted
        kSegmentsUnimplemented,                                                                          // wide
    } },
};
static constexpr SequenceDescriptor kDiagFlatToUp60LongBaseSeq7 = {
    .clearance = { -64, 96, 40, 88, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        kSegmentsUnimplemented,                             // inverted
        kSegmentsUnimplemented,                             // wide
    } },
};
static constexpr SequenceDescriptor kDiagFlatToUp60LongBaseSeq8 = {
    .clearance = { -96, 64, 40, 88, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};
static constexpr SequenceDescriptor kDiagFlatToUp60LongBaseSeq9 = {
    .clearance = { -96, 96, 40, 104, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        kSegmentsUnimplemented,                                // wide
    } },
};
static constexpr SequenceDescriptor kDiagUp60ToFlatLongBaseSeq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1101, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                   // inverted
        kSegmentsUnimplemented,                                   // wide
    } },
};
static constexpr SequenceDescriptor kDiagUp60ToFlatLongBaseSeq1 = {
    .clearance = { 0, 32, 0, 72, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        kSegmentsUnimplemented,                             // inverted
        kSegmentsUnimplemented,                             // wide
    } },
};
static constexpr SequenceDescriptor kDiagUp60ToFlatLongBaseSeq2 = {
    .clearance = { -32, 0, 0, 72, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};
static constexpr SequenceDescriptor kDiagUp60ToFlatLongBaseSeq3 = {
    .clearance = { -32, 32, 0, 80, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = { {
        { PS::left, PS::right, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                                          // inverted
        kSegmentsUnimplemented,                                                                          // wide
    } },
};
static constexpr SequenceDescriptor kDiagUp60ToFlatLongBaseSeq4 = {
    .clearance = { -32, 64, 56, 32, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        kSegmentsUnimplemented,                             // inverted
        kSegmentsUnimplemented,                             // wide
    } },
};
static constexpr SequenceDescriptor kDiagUp60ToFlatLongBaseSeq5 = {
    .clearance = { -64, 32, 56, 32, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};
static constexpr SequenceDescriptor kDiagUp60ToFlatLongBaseSeq6 = {
    .clearance = { -64, 64, 56, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = { {
        { PS::left, PS::right, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                                                          // inverted
        kSegmentsUnimplemented,                                                                          // wide
    } },
};
static constexpr SequenceDescriptor kDiagUp60ToFlatLongBaseSeq7 = {
    .clearance = { -64, 96, 80, 8, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        kSegmentsUnimplemented,                             // inverted
        kSegmentsUnimplemented,                             // wide
    } },
};
static constexpr SequenceDescriptor kDiagUp60ToFlatLongBaseSeq8 = {
    .clearance = { -96, 64, 80, 8, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};
static constexpr SequenceDescriptor kDiagUp60ToFlatLongBaseSeq9 = {
    .clearance = { -96, 96, 80, 8, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = { {
        { PS::left, PS::centre, PS::topLeft, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                // inverted
        kSegmentsUnimplemented,                                // wide
    } },
};
static constexpr SequenceDescriptor kDiagFlatToDown60LongBaseSeq0 = {
    .clearance = { 0, 0, 80, 8, { 0b1101, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatLongBaseSeq9.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagFlatToDown60LongBaseSeq1 = {
    .clearance = { 0, 32, 80, 8, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatLongBaseSeq8.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagFlatToDown60LongBaseSeq2 = {
    .clearance = { -32, 0, 80, 8, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatLongBaseSeq7.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagFlatToDown60LongBaseSeq3 = {
    .clearance = { -32, 32, 56, 8, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatLongBaseSeq6.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagFlatToDown60LongBaseSeq4 = {
    .clearance = { -32, 64, 56, 32, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatLongBaseSeq5.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagFlatToDown60LongBaseSeq5 = {
    .clearance = { -64, 32, 56, 32, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatLongBaseSeq4.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagFlatToDown60LongBaseSeq6 = {
    .clearance = { -64, 64, 0, 80, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatLongBaseSeq3.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagFlatToDown60LongBaseSeq7 = {
    .clearance = { -64, 96, 0, 72, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatLongBaseSeq2.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagFlatToDown60LongBaseSeq8 = {
    .clearance = { -96, 64, 0, 72, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatLongBaseSeq1.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagFlatToDown60LongBaseSeq9 = {
    .clearance = { -96, 96, 0, 64, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kDiagUp60ToFlatLongBaseSeq0.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagDown60ToFlatLongBaseSeq0 = {
    .clearance = { 0, 0, 40, 104, { 0b1101, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60LongBaseSeq9.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagDown60ToFlatLongBaseSeq1 = {
    .clearance = { 0, 32, 40, 88, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60LongBaseSeq8.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagDown60ToFlatLongBaseSeq2 = {
    .clearance = { -32, 0, 40, 88, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60LongBaseSeq7.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagDown60ToFlatLongBaseSeq3 = {
    .clearance = { -32, 32, 8, 64, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60LongBaseSeq6.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagDown60ToFlatLongBaseSeq4 = {
    .clearance = { -32, 64, 8, 40, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60LongBaseSeq5.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagDown60ToFlatLongBaseSeq5 = {
    .clearance = { -64, 32, 8, 40, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60LongBaseSeq4.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagDown60ToFlatLongBaseSeq6 = {
    .clearance = { -64, 64, 0, 32, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60LongBaseSeq3.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagDown60ToFlatLongBaseSeq7 = {
    .clearance = { -64, 96, 0, 16, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60LongBaseSeq2.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagDown60ToFlatLongBaseSeq8 = {
    .clearance = { -96, 64, 0, 16, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60LongBaseSeq1.blockedSegments, 2),
};
static constexpr SequenceDescriptor kDiagDown60ToFlatLongBaseSeq9 = {
    .clearance = { -96, 96, 0, 0, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kDiagFlatToUp60LongBaseSeq0.blockedSegments, 2),
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopUpToOrthogonalSeq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1101, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = { {
        { PS::right, PS::centre, PS::topRight, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                   // inverted
        kSegmentsUnimplemented,                                   // wide
    } },
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopUpToOrthogonalSeq1 = {
    .clearance = { 0, 32, 0, 88, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = { {
        { PS::top, PS::centre, PS::topLeft, PS::topRight }, // narrow
        kSegmentsUnimplemented,                             // inverted
        kSegmentsUnimplemented,                             // wide
    } },
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopUpToOrthogonalSeq2 = {
    .clearance = { -32, 0, 0, 88, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = { {
        { PS::bottom, PS::centre, PS::bottomLeft, PS::bottomRight }, // narrow
        kSegmentsUnimplemented,                                      // inverted
        kSegmentsUnimplemented,                                      // wide
    } },
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopUpToOrthogonalSeq3 = {
    .clearance = { -32, 32, 32, 80, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopUpToOrthogonalSeq4 = {
    .clearance = { -64, 32, 80, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopUpToOrthogonalSeq5 = {
    .clearance = { -96, 32, 112, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = { {
        { PS::top, PS::left, PS::centre, PS::topLeft, PS::topRight, PS::bottomLeft }, // narrow
        kSegmentsUnimplemented,                                                       // inverted
        kSegmentsUnimplemented,                                                       // wide
    } },
};
static constexpr SequenceDescriptor kRightEighthDiveLoopUpToOrthogonalSeq0 = {
    .clearance = { 0, 0, 0, 64, { 0b1101, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(
        blockedSegmentsFlipXAxis(kLeftEighthDiveLoopUpToOrthogonalSeq0.blockedSegments), 1),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopUpToOrthogonalSeq1 = {
    .clearance = { -32, 0, 0, 88, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(
        blockedSegmentsFlipXAxis(kLeftEighthDiveLoopUpToOrthogonalSeq1.blockedSegments), 1),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopUpToOrthogonalSeq2 = {
    .clearance = { 0, 32, 0, 88, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(
        blockedSegmentsFlipXAxis(kLeftEighthDiveLoopUpToOrthogonalSeq2.blockedSegments), 1),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopUpToOrthogonalSeq3 = {
    .clearance = { -32, 32, 32, 80, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0001,
    .blockedSegments = blockedSegmentsRotate(
        blockedSegmentsFlipXAxis(kLeftEighthDiveLoopUpToOrthogonalSeq3.blockedSegments), 1),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopUpToOrthogonalSeq4 = {
    .clearance = { -32, 64, 80, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(
        blockedSegmentsFlipXAxis(kLeftEighthDiveLoopUpToOrthogonalSeq4.blockedSegments), 1),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopUpToOrthogonalSeq5 = {
    .clearance = { -32, 96, 112, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0101,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(
        blockedSegmentsFlipXAxis(kLeftEighthDiveLoopUpToOrthogonalSeq5.blockedSegments), 1),
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopDownToDiagSeq0 = {
    .clearance = { 0, 0, 112, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kRightEighthDiveLoopUpToOrthogonalSeq5.blockedSegments, 1),
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopDownToDiagSeq1 = {
    .clearance = { -32, 0, 80, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kRightEighthDiveLoopUpToOrthogonalSeq4.blockedSegments, 1),
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopDownToDiagSeq2 = {
    .clearance = { -64, 0, 32, 80, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b0010,
    .blockedSegments = blockedSegmentsRotate(kRightEighthDiveLoopUpToOrthogonalSeq3.blockedSegments, 1),
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopDownToDiagSeq3 = {
    .clearance = { -64, -32, 0, 88, { 0b1000, 0 }, {} },
    .allowedWallEdges = 0b1100,
    .blockedSegments = blockedSegmentsRotate(kRightEighthDiveLoopUpToOrthogonalSeq2.blockedSegments, 1),
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopDownToDiagSeq4 = {
    .clearance = { -96, 0, 0, 88, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0011,
    .blockedSegments = blockedSegmentsRotate(kRightEighthDiveLoopUpToOrthogonalSeq1.blockedSegments, 1),
};
static constexpr SequenceDescriptor kLeftEighthDiveLoopDownToDiagSeq5 = {
    .clearance = { -96, -32, 0, 64, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kRightEighthDiveLoopUpToOrthogonalSeq0.blockedSegments, 1),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopDownToDiagSeq0 = {
    .clearance = { 0, 0, 112, 24, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .flags = { SequenceFlag::hasHeightMarker },
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthDiveLoopUpToOrthogonalSeq5.blockedSegments, 2),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopDownToDiagSeq1 = {
    .clearance = { -32, 0, 80, 48, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1010,
    .invertSegmentBlocking = true,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthDiveLoopUpToOrthogonalSeq4.blockedSegments, 2),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopDownToDiagSeq2 = {
    .clearance = { -64, 0, 32, 80, { 0b1111, 0 }, {} },
    .allowedWallEdges = 0b1000,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthDiveLoopUpToOrthogonalSeq3.blockedSegments, 2),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopDownToDiagSeq3 = {
    .clearance = { -64, 32, 0, 88, { 0b0100, 0 }, {} },
    .allowedWallEdges = 0b0110,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthDiveLoopUpToOrthogonalSeq2.blockedSegments, 2),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopDownToDiagSeq4 = {
    .clearance = { -96, 0, 0, 88, { 0b0001, 0 }, {} },
    .allowedWallEdges = 0b1001,
    .blockedSegments = blockedSegmentsRotate(kLeftEighthDiveLoopUpToOrthogonalSeq1.blockedSegments, 2),
};
static constexpr SequenceDescriptor kRightEighthDiveLoopDownToDiagSeq5 = {
    .clearance = { -96, 32, 0, 64, { 0b0010, 0 }, {} },
    .allowedWallEdges = 0b0000,
    .flags = { SequenceFlag::hasHeightMarker },
    .blockedSegments = blockedSegmentsRotate(kLeftEighthDiveLoopUpToOrthogonalSeq0.blockedSegments, 2),
};

const std::pair<TrackElemType, SequenceTable> kTrackPieces[] = {
    {
        TrackElemType::flat,
        { 1, { kFlatSeq0 } },
    },
    {
        TrackElemType::endStation,
        { 1, { kEndStationSeq0 } },
    },
    {
        TrackElemType::beginStation,
        { 1, { kBeginStationSeq0 } },
    },
    {
        TrackElemType::middleStation,
        { 1, { kMiddleStationSeq0 } },
    },
    {
        TrackElemType::up25,
        { 1, { kUp25Seq0 } },
    },
    {
        TrackElemType::up60,
        { 1, { kUp60Seq0 } },
    },
    {
        TrackElemType::flatToUp25,
        { 1, { kFlatToUp25Seq0 } },
    },
    {
        TrackElemType::up25ToUp60,
        { 1, { kUp25ToUp60Seq0 } },
    },
    {
        TrackElemType::up60ToUp25,
        { 1, { kUp60ToUp25Seq0 } },
    },
    {
        TrackElemType::up25ToFlat,
        { 1, { kUp25ToFlatSeq0 } },
    },
    {
        TrackElemType::down25,
        { 1, { kDown25Seq0 } },
    },
    {
        TrackElemType::down60,
        { 1, { kDown60Seq0 } },
    },
    {
        TrackElemType::flatToDown25,
        { 1, { kFlatToDown25Seq0 } },
    },
    {
        TrackElemType::down25ToDown60,
        { 1, { kDown25ToDown60Seq0 } },
    },
    {
        TrackElemType::down60ToDown25,
        { 1, { kDown60ToDown25Seq0 } },
    },
    {
        TrackElemType::down25ToFlat,
        { 1, { kDown25ToFlatSeq0 } },
    },
    {
        TrackElemType::leftQuarterTurn5Tiles,
        { 7,
          { kLeftQuarterTurn5TilesSeq0, kLeftQuarterTurn5TilesSeq1, kLeftQuarterTurn5TilesSeq2, kLeftQuarterTurn5TilesSeq3,
            kLeftQuarterTurn5TilesSeq4, kLeftQuarterTurn5TilesSeq5, kLeftQuarterTurn5TilesSeq6 } },
    },
    {
        TrackElemType::rightQuarterTurn5Tiles,
        { 7,
          { kRightQuarterTurn5TilesSeq0, kRightQuarterTurn5TilesSeq1, kRightQuarterTurn5TilesSeq2, kRightQuarterTurn5TilesSeq3,
            kRightQuarterTurn5TilesSeq4, kRightQuarterTurn5TilesSeq5, kRightQuarterTurn5TilesSeq6 } },
    },
    {
        TrackElemType::flatToLeftBank,
        { 1, { kFlatToLeftBankSeq0 } },
    },
    {
        TrackElemType::flatToRightBank,
        { 1, { kFlatToRightBankSeq0 } },
    },
    {
        TrackElemType::leftBankToFlat,
        { 1, { kLeftBankToFlatSeq0 } },
    },
    {
        TrackElemType::rightBankToFlat,
        { 1, { kRightBankToFlatSeq0 } },
    },
    {
        TrackElemType::bankedLeftQuarterTurn5Tiles,
        { 7,
          { kBankedLeftQuarterTurn5TilesSeq0, kBankedLeftQuarterTurn5TilesSeq1, kBankedLeftQuarterTurn5TilesSeq2,
            kBankedLeftQuarterTurn5TilesSeq3, kBankedLeftQuarterTurn5TilesSeq4, kBankedLeftQuarterTurn5TilesSeq5,
            kBankedLeftQuarterTurn5TilesSeq6 } },
    },
    {
        TrackElemType::bankedRightQuarterTurn5Tiles,
        { 7,
          { kBankedRightQuarterTurn5TilesSeq0, kBankedRightQuarterTurn5TilesSeq1, kBankedRightQuarterTurn5TilesSeq2,
            kBankedRightQuarterTurn5TilesSeq3, kBankedRightQuarterTurn5TilesSeq4, kBankedRightQuarterTurn5TilesSeq5,
            kBankedRightQuarterTurn5TilesSeq6 } },
    },
    {
        TrackElemType::leftBankToUp25,
        { 1, { kLeftBankToUp25Seq0 } },
    },
    {
        TrackElemType::rightBankToUp25,
        { 1, { kRightBankToUp25Seq0 } },
    },
    {
        TrackElemType::up25ToLeftBank,
        { 1, { kUp25ToLeftBankSeq0 } },
    },
    {
        TrackElemType::up25ToRightBank,
        { 1, { kUp25ToRightBankSeq0 } },
    },
    {
        TrackElemType::leftBankToDown25,
        { 1, { kLeftBankToDown25Seq0 } },
    },
    {
        TrackElemType::rightBankToDown25,
        { 1, { kRightBankToDown25Seq0 } },
    },
    {
        TrackElemType::down25ToLeftBank,
        { 1, { kDown25ToLeftBankSeq0 } },
    },
    {
        TrackElemType::down25ToRightBank,
        { 1, { kDown25ToRightBankSeq0 } },
    },
    {
        TrackElemType::leftBank,
        { 1, { kLeftBankSeq0 } },
    },
    {
        TrackElemType::rightBank,
        { 1, { kRightBankSeq0 } },
    },
    {
        TrackElemType::leftQuarterTurn5TilesUp25,
        { 7,
          { kLeftQuarterTurn5TilesUp25Seq0, kLeftQuarterTurn5TilesUp25Seq1, kLeftQuarterTurn5TilesUp25Seq2,
            kLeftQuarterTurn5TilesUp25Seq3, kLeftQuarterTurn5TilesUp25Seq4, kLeftQuarterTurn5TilesUp25Seq5,
            kLeftQuarterTurn5TilesUp25Seq6 } },
    },
    {
        TrackElemType::rightQuarterTurn5TilesUp25,
        { 7,
          { kRightQuarterTurn5TilesUp25Seq0, kRightQuarterTurn5TilesUp25Seq1, kRightQuarterTurn5TilesUp25Seq2,
            kRightQuarterTurn5TilesUp25Seq3, kRightQuarterTurn5TilesUp25Seq4, kRightQuarterTurn5TilesUp25Seq5,
            kRightQuarterTurn5TilesUp25Seq6 } },
    },
    {
        TrackElemType::leftQuarterTurn5TilesDown25,
        { 7,
          { kLeftQuarterTurn5TilesDown25Seq0, kLeftQuarterTurn5TilesDown25Seq1, kLeftQuarterTurn5TilesDown25Seq2,
            kLeftQuarterTurn5TilesDown25Seq3, kLeftQuarterTurn5TilesDown25Seq4, kLeftQuarterTurn5TilesDown25Seq5,
            kLeftQuarterTurn5TilesDown25Seq6 } },
    },
    {
        TrackElemType::rightQuarterTurn5TilesDown25,
        { 7,
          { kRightQuarterTurn5TilesDown25Seq0, kRightQuarterTurn5TilesDown25Seq1, kRightQuarterTurn5TilesDown25Seq2,
            kRightQuarterTurn5TilesDown25Seq3, kRightQuarterTurn5TilesDown25Seq4, kRightQuarterTurn5TilesDown25Seq5,
            kRightQuarterTurn5TilesDown25Seq6 } },
    },
    {
        TrackElemType::sBendLeft,
        { 4, { kSBendLeftSeq0, kSBendLeftSeq1, kSBendLeftSeq2, kSBendLeftSeq3 } },
    },
    {
        TrackElemType::sBendRight,
        { 4, { kSBendRightSeq0, kSBendRightSeq1, kSBendRightSeq2, kSBendRightSeq3 } },
    },
    {
        TrackElemType::leftVerticalLoop,
        { 10,
          { kLeftVerticalLoopSeq0, kLeftVerticalLoopSeq1, kLeftVerticalLoopSeq2, kLeftVerticalLoopSeq3, kLeftVerticalLoopSeq4,
            kLeftVerticalLoopSeq5, kLeftVerticalLoopSeq6, kLeftVerticalLoopSeq7, kLeftVerticalLoopSeq8,
            kLeftVerticalLoopSeq9 } },
    },
    {
        TrackElemType::rightVerticalLoop,
        { 10,
          { kRightVerticalLoopSeq0, kRightVerticalLoopSeq1, kRightVerticalLoopSeq2, kRightVerticalLoopSeq3,
            kRightVerticalLoopSeq4, kRightVerticalLoopSeq5, kRightVerticalLoopSeq6, kRightVerticalLoopSeq7,
            kRightVerticalLoopSeq8, kRightVerticalLoopSeq9 } },
    },
    {
        TrackElemType::leftQuarterTurn3Tiles,
        { 4,
          { kLeftQuarterTurn3TilesSeq0, kLeftQuarterTurn3TilesSeq1, kLeftQuarterTurn3TilesSeq2, kLeftQuarterTurn3TilesSeq3 } },
    },
    {
        TrackElemType::rightQuarterTurn3Tiles,
        { 4,
          { kRightQuarterTurn3TilesSeq0, kRightQuarterTurn3TilesSeq1, kRightQuarterTurn3TilesSeq2,
            kRightQuarterTurn3TilesSeq3 } },
    },
    {
        TrackElemType::leftBankedQuarterTurn3Tiles,
        { 4,
          { kLeftBankedQuarterTurn3TilesSeq0, kLeftBankedQuarterTurn3TilesSeq1, kLeftBankedQuarterTurn3TilesSeq2,
            kLeftBankedQuarterTurn3TilesSeq3 } },
    },
    {
        TrackElemType::rightBankedQuarterTurn3Tiles,
        { 4,
          { kRightBankedQuarterTurn3TilesSeq0, kRightBankedQuarterTurn3TilesSeq1, kRightBankedQuarterTurn3TilesSeq2,
            kRightBankedQuarterTurn3TilesSeq3 } },
    },
    {
        TrackElemType::leftQuarterTurn3TilesUp25,
        { 4,
          { kLeftQuarterTurn3TilesUp25Seq0, kLeftQuarterTurn3TilesUp25Seq1, kLeftQuarterTurn3TilesUp25Seq2,
            kLeftQuarterTurn3TilesUp25Seq3 } },
    },
    {
        TrackElemType::rightQuarterTurn3TilesUp25,
        { 4,
          { kRightQuarterTurn3TilesUp25Seq0, kRightQuarterTurn3TilesUp25Seq1, kRightQuarterTurn3TilesUp25Seq2,
            kRightQuarterTurn3TilesUp25Seq3 } },
    },
    {
        TrackElemType::leftQuarterTurn3TilesDown25,
        { 4,
          { kLeftQuarterTurn3TilesDown25Seq0, kLeftQuarterTurn3TilesDown25Seq1, kLeftQuarterTurn3TilesDown25Seq2,
            kLeftQuarterTurn3TilesDown25Seq3 } },
    },
    {
        TrackElemType::rightQuarterTurn3TilesDown25,
        { 4,
          { kRightQuarterTurn3TilesDown25Seq0, kRightQuarterTurn3TilesDown25Seq1, kRightQuarterTurn3TilesDown25Seq2,
            kRightQuarterTurn3TilesDown25Seq3 } },
    },
    {
        TrackElemType::leftQuarterTurn1Tile,
        { 1, { kLeftQuarterTurn1TileSeq0 } },
    },
    {
        TrackElemType::rightQuarterTurn1Tile,
        { 1, { kRightQuarterTurn1TileSeq0 } },
    },
    {
        TrackElemType::leftTwistDownToUp,
        { 3, { kLeftTwistDownToUpSeq0, kLeftTwistDownToUpSeq1, kLeftTwistDownToUpSeq2 } },
    },
    {
        TrackElemType::rightTwistDownToUp,
        { 3, { kRightTwistDownToUpSeq0, kRightTwistDownToUpSeq1, kRightTwistDownToUpSeq2 } },
    },
    {
        TrackElemType::leftTwistUpToDown,
        { 3, { kLeftTwistUpToDownSeq0, kLeftTwistUpToDownSeq1, kLeftTwistUpToDownSeq2 } },
    },
    {
        TrackElemType::rightTwistUpToDown,
        { 3, { kRightTwistUpToDownSeq0, kRightTwistUpToDownSeq1, kRightTwistUpToDownSeq2 } },
    },
    {
        TrackElemType::halfLoopUp,
        { 4, { kHalfLoopUpSeq0, kHalfLoopUpSeq1, kHalfLoopUpSeq2, kHalfLoopUpSeq3 } },
    },
    {
        TrackElemType::halfLoopDown,
        { 4, { kHalfLoopDownSeq0, kHalfLoopDownSeq1, kHalfLoopDownSeq2, kHalfLoopDownSeq3 } },
    },
    {
        TrackElemType::leftCorkscrewUp,
        { 3, { kLeftCorkscrewUpSeq0, kLeftCorkscrewUpSeq1, kLeftCorkscrewUpSeq2 } },
    },
    {
        TrackElemType::rightCorkscrewUp,
        { 3, { kRightCorkscrewUpSeq0, kRightCorkscrewUpSeq1, kRightCorkscrewUpSeq2 } },
    },
    {
        TrackElemType::leftCorkscrewDown,
        { 3, { kLeftCorkscrewDownSeq0, kLeftCorkscrewDownSeq1, kLeftCorkscrewDownSeq2 } },
    },
    {
        TrackElemType::rightCorkscrewDown,
        { 3, { kRightCorkscrewDownSeq0, kRightCorkscrewDownSeq1, kRightCorkscrewDownSeq2 } },
    },
    {
        TrackElemType::flatToUp60,
        { 1, { kFlatToUp60Seq0 } },
    },
    {
        TrackElemType::up60ToFlat,
        { 1, { kUp60ToFlatSeq0 } },
    },
    {
        TrackElemType::flatToDown60,
        { 1, { kFlatToDown60Seq0 } },
    },
    {
        TrackElemType::down60ToFlat,
        { 1, { kDown60ToFlatSeq0 } },
    },
    {
        TrackElemType::towerBase,
        { 9,
          { kTowerBaseSeq0, kTowerBaseSeq1, kTowerBaseSeq2, kTowerBaseSeq3, kTowerBaseSeq4, kTowerBaseSeq5, kTowerBaseSeq6,
            kTowerBaseSeq7, kTowerBaseSeq8 } },
    },
    {
        TrackElemType::towerSection,
        { 2, { kTowerSectionSeq0, kTowerSectionSeq1 } },
    },
    {
        TrackElemType::flatCovered,
        { 1, { kFlatCoveredSeq0 } },
    },
    {
        TrackElemType::up25Covered,
        { 1, { kUp25CoveredSeq0 } },
    },
    {
        TrackElemType::up60Covered,
        { 1, { kUp60CoveredSeq0 } },
    },
    {
        TrackElemType::flatToUp25Covered,
        { 1, { kFlatToUp25CoveredSeq0 } },
    },
    {
        TrackElemType::up25ToUp60Covered,
        { 1, { kUp25ToUp60CoveredSeq0 } },
    },
    {
        TrackElemType::up60ToUp25Covered,
        { 1, { kUp60ToUp25CoveredSeq0 } },
    },
    {
        TrackElemType::up25ToFlatCovered,
        { 1, { kUp25ToFlatCoveredSeq0 } },
    },
    {
        TrackElemType::down25Covered,
        { 1, { kDown25CoveredSeq0 } },
    },
    {
        TrackElemType::down60Covered,
        { 1, { kDown60CoveredSeq0 } },
    },
    {
        TrackElemType::flatToDown25Covered,
        { 1, { kFlatToDown25CoveredSeq0 } },
    },
    {
        TrackElemType::down25ToDown60Covered,
        { 1, { kDown25ToDown60CoveredSeq0 } },
    },
    {
        TrackElemType::down60ToDown25Covered,
        { 1, { kDown60ToDown25CoveredSeq0 } },
    },
    {
        TrackElemType::down25ToFlatCovered,
        { 1, { kDown25ToFlatCoveredSeq0 } },
    },
    {
        TrackElemType::leftQuarterTurn5TilesCovered,
        { 7,
          { kLeftQuarterTurn5TilesCoveredSeq0, kLeftQuarterTurn5TilesCoveredSeq1, kLeftQuarterTurn5TilesCoveredSeq2,
            kLeftQuarterTurn5TilesCoveredSeq3, kLeftQuarterTurn5TilesCoveredSeq4, kLeftQuarterTurn5TilesCoveredSeq5,
            kLeftQuarterTurn5TilesCoveredSeq6 } },
    },
    {
        TrackElemType::rightQuarterTurn5TilesCovered,
        { 7,
          { kRightQuarterTurn5TilesCoveredSeq0, kRightQuarterTurn5TilesCoveredSeq1, kRightQuarterTurn5TilesCoveredSeq2,
            kRightQuarterTurn5TilesCoveredSeq3, kRightQuarterTurn5TilesCoveredSeq4, kRightQuarterTurn5TilesCoveredSeq5,
            kRightQuarterTurn5TilesCoveredSeq6 } },
    },
    {
        TrackElemType::sBendLeftCovered,
        { 4, { kSBendLeftCoveredSeq0, kSBendLeftCoveredSeq1, kSBendLeftCoveredSeq2, kSBendLeftCoveredSeq3 } },
    },
    {
        TrackElemType::sBendRightCovered,
        { 4, { kSBendRightCoveredSeq0, kSBendRightCoveredSeq1, kSBendRightCoveredSeq2, kSBendRightCoveredSeq3 } },
    },
    {
        TrackElemType::leftQuarterTurn3TilesCovered,
        { 4,
          { kLeftQuarterTurn3TilesCoveredSeq0, kLeftQuarterTurn3TilesCoveredSeq1, kLeftQuarterTurn3TilesCoveredSeq2,
            kLeftQuarterTurn3TilesCoveredSeq3 } },
    },
    {
        TrackElemType::rightQuarterTurn3TilesCovered,
        { 4,
          { kRightQuarterTurn3TilesCoveredSeq0, kRightQuarterTurn3TilesCoveredSeq1, kRightQuarterTurn3TilesCoveredSeq2,
            kRightQuarterTurn3TilesCoveredSeq3 } },
    },
    {
        TrackElemType::leftHalfBankedHelixUpSmall,
        { 8,
          { kLeftHalfBankedHelixUpSmallSeq0, kLeftHalfBankedHelixUpSmallSeq1, kLeftHalfBankedHelixUpSmallSeq2,
            kLeftHalfBankedHelixUpSmallSeq3, kLeftHalfBankedHelixUpSmallSeq4, kLeftHalfBankedHelixUpSmallSeq5,
            kLeftHalfBankedHelixUpSmallSeq6, kLeftHalfBankedHelixUpSmallSeq7 } },
    },
    {
        TrackElemType::rightHalfBankedHelixUpSmall,
        { 8,
          { kRightHalfBankedHelixUpSmallSeq0, kRightHalfBankedHelixUpSmallSeq1, kRightHalfBankedHelixUpSmallSeq2,
            kRightHalfBankedHelixUpSmallSeq3, kRightHalfBankedHelixUpSmallSeq4, kRightHalfBankedHelixUpSmallSeq5,
            kRightHalfBankedHelixUpSmallSeq6, kRightHalfBankedHelixUpSmallSeq7 } },
    },
    {
        TrackElemType::leftHalfBankedHelixDownSmall,
        { 8,
          { kLeftHalfBankedHelixDownSmallSeq0, kLeftHalfBankedHelixDownSmallSeq1, kLeftHalfBankedHelixDownSmallSeq2,
            kLeftHalfBankedHelixDownSmallSeq3, kLeftHalfBankedHelixDownSmallSeq4, kLeftHalfBankedHelixDownSmallSeq5,
            kLeftHalfBankedHelixDownSmallSeq6, kLeftHalfBankedHelixDownSmallSeq7 } },
    },
    {
        TrackElemType::rightHalfBankedHelixDownSmall,
        { 8,
          { kRightHalfBankedHelixDownSmallSeq0, kRightHalfBankedHelixDownSmallSeq1, kRightHalfBankedHelixDownSmallSeq2,
            kRightHalfBankedHelixDownSmallSeq3, kRightHalfBankedHelixDownSmallSeq4, kRightHalfBankedHelixDownSmallSeq5,
            kRightHalfBankedHelixDownSmallSeq6, kRightHalfBankedHelixDownSmallSeq7 } },
    },
    {
        TrackElemType::leftHalfBankedHelixUpLarge,
        { 14,
          { kLeftHalfBankedHelixUpLargeSeq0, kLeftHalfBankedHelixUpLargeSeq1, kLeftHalfBankedHelixUpLargeSeq2,
            kLeftHalfBankedHelixUpLargeSeq3, kLeftHalfBankedHelixUpLargeSeq4, kLeftHalfBankedHelixUpLargeSeq5,
            kLeftHalfBankedHelixUpLargeSeq6, kLeftHalfBankedHelixUpLargeSeq7, kLeftHalfBankedHelixUpLargeSeq8,
            kLeftHalfBankedHelixUpLargeSeq9, kLeftHalfBankedHelixUpLargeSeq10, kLeftHalfBankedHelixUpLargeSeq11,
            kLeftHalfBankedHelixUpLargeSeq12, kLeftHalfBankedHelixUpLargeSeq13 } },
    },
    {
        TrackElemType::rightHalfBankedHelixUpLarge,
        { 14,
          { kRightHalfBankedHelixUpLargeSeq0, kRightHalfBankedHelixUpLargeSeq1, kRightHalfBankedHelixUpLargeSeq2,
            kRightHalfBankedHelixUpLargeSeq3, kRightHalfBankedHelixUpLargeSeq4, kRightHalfBankedHelixUpLargeSeq5,
            kRightHalfBankedHelixUpLargeSeq6, kRightHalfBankedHelixUpLargeSeq7, kRightHalfBankedHelixUpLargeSeq8,
            kRightHalfBankedHelixUpLargeSeq9, kRightHalfBankedHelixUpLargeSeq10, kRightHalfBankedHelixUpLargeSeq11,
            kRightHalfBankedHelixUpLargeSeq12, kRightHalfBankedHelixUpLargeSeq13 } },
    },
    {
        TrackElemType::leftHalfBankedHelixDownLarge,
        { 14,
          { kLeftHalfBankedHelixDownLargeSeq0, kLeftHalfBankedHelixDownLargeSeq1, kLeftHalfBankedHelixDownLargeSeq2,
            kLeftHalfBankedHelixDownLargeSeq3, kLeftHalfBankedHelixDownLargeSeq4, kLeftHalfBankedHelixDownLargeSeq5,
            kLeftHalfBankedHelixDownLargeSeq6, kLeftHalfBankedHelixDownLargeSeq7, kLeftHalfBankedHelixDownLargeSeq8,
            kLeftHalfBankedHelixDownLargeSeq9, kLeftHalfBankedHelixDownLargeSeq10, kLeftHalfBankedHelixDownLargeSeq11,
            kLeftHalfBankedHelixDownLargeSeq12, kLeftHalfBankedHelixDownLargeSeq13 } },
    },
    {
        TrackElemType::rightHalfBankedHelixDownLarge,
        { 14,
          { kRightHalfBankedHelixDownLargeSeq0, kRightHalfBankedHelixDownLargeSeq1, kRightHalfBankedHelixDownLargeSeq2,
            kRightHalfBankedHelixDownLargeSeq3, kRightHalfBankedHelixDownLargeSeq4, kRightHalfBankedHelixDownLargeSeq5,
            kRightHalfBankedHelixDownLargeSeq6, kRightHalfBankedHelixDownLargeSeq7, kRightHalfBankedHelixDownLargeSeq8,
            kRightHalfBankedHelixDownLargeSeq9, kRightHalfBankedHelixDownLargeSeq10, kRightHalfBankedHelixDownLargeSeq11,
            kRightHalfBankedHelixDownLargeSeq12, kRightHalfBankedHelixDownLargeSeq13 } },
    },
    {
        TrackElemType::leftQuarterTurn1TileUp60,
        { 1, { kLeftQuarterTurn1TileUp60Seq0 } },
    },
    {
        TrackElemType::rightQuarterTurn1TileUp60,
        { 1, { kRightQuarterTurn1TileUp60Seq0 } },
    },
    {
        TrackElemType::leftQuarterTurn1TileDown60,
        { 1, { kLeftQuarterTurn1TileDown60Seq0 } },
    },
    {
        TrackElemType::rightQuarterTurn1TileDown60,
        { 1, { kRightQuarterTurn1TileDown60Seq0 } },
    },
    {
        TrackElemType::brakes,
        { 1, { kBrakesSeq0 } },
    },
    {
        TrackElemType::booster,
        { 1, { kBoosterSeq0 } },
    },
    {
        TrackElemType::maze,
        { 1,
          { kMazeSeq0, kMazeSeq1, kMazeSeq2, kMazeSeq3, kMazeSeq4, kMazeSeq5, kMazeSeq6, kMazeSeq7, kMazeSeq8, kMazeSeq9,
            kMazeSeq10, kMazeSeq11, kMazeSeq12, kMazeSeq13, kMazeSeq14, kMazeSeq15 } },
    },
    {
        TrackElemType::leftQuarterBankedHelixLargeUp,
        { 7,
          { kLeftQuarterBankedHelixLargeUpSeq0, kLeftQuarterBankedHelixLargeUpSeq1, kLeftQuarterBankedHelixLargeUpSeq2,
            kLeftQuarterBankedHelixLargeUpSeq3, kLeftQuarterBankedHelixLargeUpSeq4, kLeftQuarterBankedHelixLargeUpSeq5,
            kLeftQuarterBankedHelixLargeUpSeq6 } },
    },
    {
        TrackElemType::rightQuarterBankedHelixLargeUp,
        { 7,
          { kRightQuarterBankedHelixLargeUpSeq0, kRightQuarterBankedHelixLargeUpSeq1, kRightQuarterBankedHelixLargeUpSeq2,
            kRightQuarterBankedHelixLargeUpSeq3, kRightQuarterBankedHelixLargeUpSeq4, kRightQuarterBankedHelixLargeUpSeq5,
            kRightQuarterBankedHelixLargeUpSeq6 } },
    },
    {
        TrackElemType::leftQuarterBankedHelixLargeDown,
        { 7,
          { kLeftQuarterBankedHelixLargeDownSeq0, kLeftQuarterBankedHelixLargeDownSeq1, kLeftQuarterBankedHelixLargeDownSeq2,
            kLeftQuarterBankedHelixLargeDownSeq3, kLeftQuarterBankedHelixLargeDownSeq4, kLeftQuarterBankedHelixLargeDownSeq5,
            kLeftQuarterBankedHelixLargeDownSeq6 } },
    },
    {
        TrackElemType::rightQuarterBankedHelixLargeDown,
        { 7,
          { kRightQuarterBankedHelixLargeDownSeq0, kRightQuarterBankedHelixLargeDownSeq1, kRightQuarterBankedHelixLargeDownSeq2,
            kRightQuarterBankedHelixLargeDownSeq3, kRightQuarterBankedHelixLargeDownSeq4, kRightQuarterBankedHelixLargeDownSeq5,
            kRightQuarterBankedHelixLargeDownSeq6 } },
    },
    {
        TrackElemType::leftQuarterHelixLargeUp,
        { 7,
          { kLeftQuarterHelixLargeUpSeq0, kLeftQuarterHelixLargeUpSeq1, kLeftQuarterHelixLargeUpSeq2,
            kLeftQuarterHelixLargeUpSeq3, kLeftQuarterHelixLargeUpSeq4, kLeftQuarterHelixLargeUpSeq5,
            kLeftQuarterHelixLargeUpSeq6 } },
    },
    {
        TrackElemType::rightQuarterHelixLargeUp,
        { 7,
          { kRightQuarterHelixLargeUpSeq0, kRightQuarterHelixLargeUpSeq1, kRightQuarterHelixLargeUpSeq2,
            kRightQuarterHelixLargeUpSeq3, kRightQuarterHelixLargeUpSeq4, kRightQuarterHelixLargeUpSeq5,
            kRightQuarterHelixLargeUpSeq6 } },
    },
    {
        TrackElemType::leftQuarterHelixLargeDown,
        { 7,
          { kLeftQuarterHelixLargeDownSeq0, kLeftQuarterHelixLargeDownSeq1, kLeftQuarterHelixLargeDownSeq2,
            kLeftQuarterHelixLargeDownSeq3, kLeftQuarterHelixLargeDownSeq4, kLeftQuarterHelixLargeDownSeq5,
            kLeftQuarterHelixLargeDownSeq6 } },
    },
    {
        TrackElemType::rightQuarterHelixLargeDown,
        { 7,
          { kRightQuarterHelixLargeDownSeq0, kRightQuarterHelixLargeDownSeq1, kRightQuarterHelixLargeDownSeq2,
            kRightQuarterHelixLargeDownSeq3, kRightQuarterHelixLargeDownSeq4, kRightQuarterHelixLargeDownSeq5,
            kRightQuarterHelixLargeDownSeq6 } },
    },
    {
        TrackElemType::up25LeftBanked,
        { 1, { kUp25LeftBankedSeq0 } },
    },
    {
        TrackElemType::up25RightBanked,
        { 1, { kUp25RightBankedSeq0 } },
    },
    {
        TrackElemType::waterfall,
        { 1, { kWaterfallSeq0 } },
    },
    {
        TrackElemType::rapids,
        { 1, { kRapidsSeq0 } },
    },
    {
        TrackElemType::onRidePhoto,
        { 1, { kOnRidePhotoSeq0 } },
    },
    {
        TrackElemType::down25LeftBanked,
        { 1, { kDown25LeftBankedSeq0 } },
    },
    {
        TrackElemType::down25RightBanked,
        { 1, { kDown25RightBankedSeq0 } },
    },
    {
        TrackElemType::waterSplash,
        { 5, { kWaterSplashSeq0, kWaterSplashSeq1, kWaterSplashSeq2, kWaterSplashSeq3, kWaterSplashSeq4 } },
    },
    {
        TrackElemType::flatToUp60LongBase,
        { 4, { kFlatToUp60LongBaseSeq0, kFlatToUp60LongBaseSeq1, kFlatToUp60LongBaseSeq2, kFlatToUp60LongBaseSeq3 } },
    },
    {
        TrackElemType::up60ToFlatLongBase,
        { 4, { kUp60ToFlatLongBaseSeq0, kUp60ToFlatLongBaseSeq1, kUp60ToFlatLongBaseSeq2, kUp60ToFlatLongBaseSeq3 } },
    },
    {
        TrackElemType::whirlpool,
        { 1, { kWhirlpoolSeq0 } },
    },
    {
        TrackElemType::down60ToFlatLongBase,
        { 4, { kDown60ToFlatLongBaseSeq0, kDown60ToFlatLongBaseSeq1, kDown60ToFlatLongBaseSeq2, kDown60ToFlatLongBaseSeq3 } },
    },
    {
        TrackElemType::flatToDown60LongBase,
        { 4, { kFlatToDown60LongBaseSeq0, kFlatToDown60LongBaseSeq1, kFlatToDown60LongBaseSeq2, kFlatToDown60LongBaseSeq3 } },
    },
    {
        TrackElemType::cableLiftHill,
        { 4, { kCableLiftHillSeq0, kCableLiftHillSeq1, kCableLiftHillSeq2, kCableLiftHillSeq3 } },
    },
    {
        TrackElemType::reverseFreefallSlope,
        { 7,
          { kReverseFreefallSlopeSeq0, kReverseFreefallSlopeSeq1, kReverseFreefallSlopeSeq2, kReverseFreefallSlopeSeq3,
            kReverseFreefallSlopeSeq4, kReverseFreefallSlopeSeq5, kReverseFreefallSlopeSeq6 } },
    },
    {
        TrackElemType::reverseFreefallVertical,
        { 2, { kReverseFreefallVerticalSeq0, kReverseFreefallVerticalSeq1 } },
    },
    {
        TrackElemType::up90,
        { 2, { kUp90Seq0, kUp90Seq1 } },
    },
    {
        TrackElemType::down90,
        { 2, { kDown90Seq0, kDown90Seq1 } },
    },
    {
        TrackElemType::up60ToUp90,
        { 2, { kUp60ToUp90Seq0, kUp60ToUp90Seq1 } },
    },
    {
        TrackElemType::down90ToDown60,
        { 1, { kDown90ToDown60Seq0 } },
    },
    {
        TrackElemType::up90ToUp60,
        { 1, { kUp90ToUp60Seq0 } },
    },
    {
        TrackElemType::down60ToDown90,
        { 2, { kDown60ToDown90Seq0, kDown60ToDown90Seq1 } },
    },
    {
        TrackElemType::brakeForDrop,
        { 1, { kBrakeForDropSeq0 } },
    },
    {
        TrackElemType::leftEighthToDiag,
        { 5,
          { kLeftEighthToDiagSeq0, kLeftEighthToDiagSeq1, kLeftEighthToDiagSeq2, kLeftEighthToDiagSeq3,
            kLeftEighthToDiagSeq4 } },
    },
    {
        TrackElemType::rightEighthToDiag,
        { 5,
          { kRightEighthToDiagSeq0, kRightEighthToDiagSeq1, kRightEighthToDiagSeq2, kRightEighthToDiagSeq3,
            kRightEighthToDiagSeq4 } },
    },
    {
        TrackElemType::leftEighthToOrthogonal,
        { 5,
          { kLeftEighthToOrthogonalSeq0, kLeftEighthToOrthogonalSeq1, kLeftEighthToOrthogonalSeq2, kLeftEighthToOrthogonalSeq3,
            kLeftEighthToOrthogonalSeq4 } },
    },
    {
        TrackElemType::rightEighthToOrthogonal,
        { 5,
          { kRightEighthToOrthogonalSeq0, kRightEighthToOrthogonalSeq1, kRightEighthToOrthogonalSeq2,
            kRightEighthToOrthogonalSeq3, kRightEighthToOrthogonalSeq4 } },
    },
    {
        TrackElemType::leftEighthBankToDiag,
        { 5,
          { kLeftEighthBankToDiagSeq0, kLeftEighthBankToDiagSeq1, kLeftEighthBankToDiagSeq2, kLeftEighthBankToDiagSeq3,
            kLeftEighthBankToDiagSeq4 } },
    },
    {
        TrackElemType::rightEighthBankToDiag,
        { 5,
          { kRightEighthBankToDiagSeq0, kRightEighthBankToDiagSeq1, kRightEighthBankToDiagSeq2, kRightEighthBankToDiagSeq3,
            kRightEighthBankToDiagSeq4 } },
    },
    {
        TrackElemType::leftEighthBankToOrthogonal,
        { 5,
          { kLeftEighthBankToOrthogonalSeq0, kLeftEighthBankToOrthogonalSeq1, kLeftEighthBankToOrthogonalSeq2,
            kLeftEighthBankToOrthogonalSeq3, kLeftEighthBankToOrthogonalSeq4 } },
    },
    {
        TrackElemType::rightEighthBankToOrthogonal,
        { 5,
          { kRightEighthBankToOrthogonalSeq0, kRightEighthBankToOrthogonalSeq1, kRightEighthBankToOrthogonalSeq2,
            kRightEighthBankToOrthogonalSeq3, kRightEighthBankToOrthogonalSeq4 } },
    },
    {
        TrackElemType::diagFlat,
        { 4, { kDiagFlatSeq0, kDiagFlatSeq1, kDiagFlatSeq2, kDiagFlatSeq3 } },
    },
    {
        TrackElemType::diagUp25,
        { 4, { kDiagUp25Seq0, kDiagUp25Seq1, kDiagUp25Seq2, kDiagUp25Seq3 } },
    },
    {
        TrackElemType::diagUp60,
        { 4, { kDiagUp60Seq0, kDiagUp60Seq1, kDiagUp60Seq2, kDiagUp60Seq3 } },
    },
    {
        TrackElemType::diagFlatToUp25,
        { 4, { kDiagFlatToUp25Seq0, kDiagFlatToUp25Seq1, kDiagFlatToUp25Seq2, kDiagFlatToUp25Seq3 } },
    },
    {
        TrackElemType::diagUp25ToUp60,
        { 4, { kDiagUp25ToUp60Seq0, kDiagUp25ToUp60Seq1, kDiagUp25ToUp60Seq2, kDiagUp25ToUp60Seq3 } },
    },
    {
        TrackElemType::diagUp60ToUp25,
        { 4, { kDiagUp60ToUp25Seq0, kDiagUp60ToUp25Seq1, kDiagUp60ToUp25Seq2, kDiagUp60ToUp25Seq3 } },
    },
    {
        TrackElemType::diagUp25ToFlat,
        { 4, { kDiagUp25ToFlatSeq0, kDiagUp25ToFlatSeq1, kDiagUp25ToFlatSeq2, kDiagUp25ToFlatSeq3 } },
    },
    {
        TrackElemType::diagDown25,
        { 4, { kDiagDown25Seq0, kDiagDown25Seq1, kDiagDown25Seq2, kDiagDown25Seq3 } },
    },
    {
        TrackElemType::diagDown60,
        { 4, { kDiagDown60Seq0, kDiagDown60Seq1, kDiagDown60Seq2, kDiagDown60Seq3 } },
    },
    {
        TrackElemType::diagFlatToDown25,
        { 4, { kDiagFlatToDown25Seq0, kDiagFlatToDown25Seq1, kDiagFlatToDown25Seq2, kDiagFlatToDown25Seq3 } },
    },
    {
        TrackElemType::diagDown25ToDown60,
        { 4, { kDiagDown25ToDown60Seq0, kDiagDown25ToDown60Seq1, kDiagDown25ToDown60Seq2, kDiagDown25ToDown60Seq3 } },
    },
    {
        TrackElemType::diagDown60ToDown25,
        { 4, { kDiagDown60ToDown25Seq0, kDiagDown60ToDown25Seq1, kDiagDown60ToDown25Seq2, kDiagDown60ToDown25Seq3 } },
    },
    {
        TrackElemType::diagDown25ToFlat,
        { 4, { kDiagDown25ToFlatSeq0, kDiagDown25ToFlatSeq1, kDiagDown25ToFlatSeq2, kDiagDown25ToFlatSeq3 } },
    },
    {
        TrackElemType::diagFlatToUp60,
        { 4, { kDiagFlatToUp60Seq0, kDiagFlatToUp60Seq1, kDiagFlatToUp60Seq2, kDiagFlatToUp60Seq3 } },
    },
    {
        TrackElemType::diagUp60ToFlat,
        { 4, { kDiagUp60ToFlatSeq0, kDiagUp60ToFlatSeq1, kDiagUp60ToFlatSeq2, kDiagUp60ToFlatSeq3 } },
    },
    {
        TrackElemType::diagFlatToDown60,
        { 4, { kDiagFlatToDown60Seq0, kDiagFlatToDown60Seq1, kDiagFlatToDown60Seq2, kDiagFlatToDown60Seq3 } },
    },
    {
        TrackElemType::diagDown60ToFlat,
        { 4, { kDiagDown60ToFlatSeq0, kDiagDown60ToFlatSeq1, kDiagDown60ToFlatSeq2, kDiagDown60ToFlatSeq3 } },
    },
    {
        TrackElemType::diagFlatToLeftBank,
        { 4, { kDiagFlatToLeftBankSeq0, kDiagFlatToLeftBankSeq1, kDiagFlatToLeftBankSeq2, kDiagFlatToLeftBankSeq3 } },
    },
    {
        TrackElemType::diagFlatToRightBank,
        { 4, { kDiagFlatToRightBankSeq0, kDiagFlatToRightBankSeq1, kDiagFlatToRightBankSeq2, kDiagFlatToRightBankSeq3 } },
    },
    {
        TrackElemType::diagLeftBankToFlat,
        { 4, { kDiagLeftBankToFlatSeq0, kDiagLeftBankToFlatSeq1, kDiagLeftBankToFlatSeq2, kDiagLeftBankToFlatSeq3 } },
    },
    {
        TrackElemType::diagRightBankToFlat,
        { 4, { kDiagRightBankToFlatSeq0, kDiagRightBankToFlatSeq1, kDiagRightBankToFlatSeq2, kDiagRightBankToFlatSeq3 } },
    },
    {
        TrackElemType::diagLeftBankToUp25,
        { 4, { kDiagLeftBankToUp25Seq0, kDiagLeftBankToUp25Seq1, kDiagLeftBankToUp25Seq2, kDiagLeftBankToUp25Seq3 } },
    },
    {
        TrackElemType::diagRightBankToUp25,
        { 4, { kDiagRightBankToUp25Seq0, kDiagRightBankToUp25Seq1, kDiagRightBankToUp25Seq2, kDiagRightBankToUp25Seq3 } },
    },
    {
        TrackElemType::diagUp25ToLeftBank,
        { 4, { kDiagUp25ToLeftBankSeq0, kDiagUp25ToLeftBankSeq1, kDiagUp25ToLeftBankSeq2, kDiagUp25ToLeftBankSeq3 } },
    },
    {
        TrackElemType::diagUp25ToRightBank,
        { 4, { kDiagUp25ToRightBankSeq0, kDiagUp25ToRightBankSeq1, kDiagUp25ToRightBankSeq2, kDiagUp25ToRightBankSeq3 } },
    },
    {
        TrackElemType::diagLeftBankToDown25,
        { 4, { kDiagLeftBankToDown25Seq0, kDiagLeftBankToDown25Seq1, kDiagLeftBankToDown25Seq2, kDiagLeftBankToDown25Seq3 } },
    },
    {
        TrackElemType::diagRightBankToDown25,
        { 4,
          { kDiagRightBankToDown25Seq0, kDiagRightBankToDown25Seq1, kDiagRightBankToDown25Seq2, kDiagRightBankToDown25Seq3 } },
    },
    {
        TrackElemType::diagDown25ToLeftBank,
        { 4, { kDiagDown25ToLeftBankSeq0, kDiagDown25ToLeftBankSeq1, kDiagDown25ToLeftBankSeq2, kDiagDown25ToLeftBankSeq3 } },
    },
    {
        TrackElemType::diagDown25ToRightBank,
        { 4,
          { kDiagDown25ToRightBankSeq0, kDiagDown25ToRightBankSeq1, kDiagDown25ToRightBankSeq2, kDiagDown25ToRightBankSeq3 } },
    },
    {
        TrackElemType::diagLeftBank,
        { 4, { kDiagLeftBankSeq0, kDiagLeftBankSeq1, kDiagLeftBankSeq2, kDiagLeftBankSeq3 } },
    },
    {
        TrackElemType::diagRightBank,
        { 4, { kDiagRightBankSeq0, kDiagRightBankSeq1, kDiagRightBankSeq2, kDiagRightBankSeq3 } },
    },
    {
        TrackElemType::logFlumeReverser,
        { 1, { kLogFlumeReverserSeq0 } },
    },
    {
        TrackElemType::spinningTunnel,
        { 1, { kSpinningTunnelSeq0 } },
    },
    {
        TrackElemType::leftBarrelRollUpToDown,
        { 3, { kLeftBarrelRollUpToDownSeq0, kLeftBarrelRollUpToDownSeq1, kLeftBarrelRollUpToDownSeq2 } },
    },
    {
        TrackElemType::rightBarrelRollUpToDown,
        { 3, { kRightBarrelRollUpToDownSeq0, kRightBarrelRollUpToDownSeq1, kRightBarrelRollUpToDownSeq2 } },
    },
    {
        TrackElemType::leftBarrelRollDownToUp,
        { 3, { kLeftBarrelRollDownToUpSeq0, kLeftBarrelRollDownToUpSeq1, kLeftBarrelRollDownToUpSeq2 } },
    },
    {
        TrackElemType::rightBarrelRollDownToUp,
        { 3, { kRightBarrelRollDownToUpSeq0, kRightBarrelRollDownToUpSeq1, kRightBarrelRollDownToUpSeq2 } },
    },
    {
        TrackElemType::leftBankToLeftQuarterTurn3TilesUp25,
        { 4,
          { kLeftBankToLeftQuarterTurn3TilesUp25Seq0, kLeftBankToLeftQuarterTurn3TilesUp25Seq1,
            kLeftBankToLeftQuarterTurn3TilesUp25Seq2, kLeftBankToLeftQuarterTurn3TilesUp25Seq3 } },
    },
    {
        TrackElemType::rightBankToRightQuarterTurn3TilesUp25,
        { 4,
          { kRightBankToRightQuarterTurn3TilesUp25Seq0, kRightBankToRightQuarterTurn3TilesUp25Seq1,
            kRightBankToRightQuarterTurn3TilesUp25Seq2, kRightBankToRightQuarterTurn3TilesUp25Seq3 } },
    },
    {
        TrackElemType::leftQuarterTurn3TilesDown25ToLeftBank,
        { 4,
          { kLeftQuarterTurn3TilesDown25ToLeftBankSeq0, kLeftQuarterTurn3TilesDown25ToLeftBankSeq1,
            kLeftQuarterTurn3TilesDown25ToLeftBankSeq2, kLeftQuarterTurn3TilesDown25ToLeftBankSeq3 } },
    },
    {
        TrackElemType::rightQuarterTurn3TilesDown25ToRightBank,
        { 4,
          { kRightQuarterTurn3TilesDown25ToRightBankSeq0, kRightQuarterTurn3TilesDown25ToRightBankSeq1,
            kRightQuarterTurn3TilesDown25ToRightBankSeq2, kRightQuarterTurn3TilesDown25ToRightBankSeq3 } },
    },
    {
        TrackElemType::poweredLift,
        { 1, { kPoweredLiftSeq0 } },
    },
    {
        TrackElemType::leftLargeHalfLoopUp,
        { 7,
          { kLeftLargeHalfLoopUpSeq0, kLeftLargeHalfLoopUpSeq1, kLeftLargeHalfLoopUpSeq2, kLeftLargeHalfLoopUpSeq3,
            kLeftLargeHalfLoopUpSeq4, kLeftLargeHalfLoopUpSeq5, kLeftLargeHalfLoopUpSeq6 } },
    },
    {
        TrackElemType::rightLargeHalfLoopUp,
        { 7,
          { kRightLargeHalfLoopUpSeq0, kRightLargeHalfLoopUpSeq1, kRightLargeHalfLoopUpSeq2, kRightLargeHalfLoopUpSeq3,
            kRightLargeHalfLoopUpSeq4, kRightLargeHalfLoopUpSeq5, kRightLargeHalfLoopUpSeq6 } },
    },
    {
        TrackElemType::leftLargeHalfLoopDown,
        { 7,
          { kLeftLargeHalfLoopDownSeq0, kLeftLargeHalfLoopDownSeq1, kLeftLargeHalfLoopDownSeq2, kLeftLargeHalfLoopDownSeq3,
            kLeftLargeHalfLoopDownSeq4, kLeftLargeHalfLoopDownSeq5, kLeftLargeHalfLoopDownSeq6 } },
    },
    {
        TrackElemType::rightLargeHalfLoopDown,
        { 7,
          { kRightLargeHalfLoopDownSeq0, kRightLargeHalfLoopDownSeq1, kRightLargeHalfLoopDownSeq2, kRightLargeHalfLoopDownSeq3,
            kRightLargeHalfLoopDownSeq4, kRightLargeHalfLoopDownSeq5, kRightLargeHalfLoopDownSeq6 } },
    },
    {
        TrackElemType::leftFlyerTwistUp,
        { 3, { kLeftFlyerTwistUpSeq0, kLeftFlyerTwistUpSeq1, kLeftFlyerTwistUpSeq2 } },
    },
    {
        TrackElemType::rightFlyerTwistUp,
        { 3, { kRightFlyerTwistUpSeq0, kRightFlyerTwistUpSeq1, kRightFlyerTwistUpSeq2 } },
    },
    {
        TrackElemType::leftFlyerTwistDown,
        { 3, { kLeftFlyerTwistDownSeq0, kLeftFlyerTwistDownSeq1, kLeftFlyerTwistDownSeq2 } },
    },
    {
        TrackElemType::rightFlyerTwistDown,
        { 3, { kRightFlyerTwistDownSeq0, kRightFlyerTwistDownSeq1, kRightFlyerTwistDownSeq2 } },
    },
    {
        TrackElemType::flyerHalfLoopUninvertedUp,
        { 4,
          { kFlyerHalfLoopUninvertedUpSeq0, kFlyerHalfLoopUninvertedUpSeq1, kFlyerHalfLoopUninvertedUpSeq2,
            kFlyerHalfLoopUninvertedUpSeq3 } },
    },
    {
        TrackElemType::flyerHalfLoopInvertedDown,
        { 4,
          { kFlyerHalfLoopInvertedDownSeq0, kFlyerHalfLoopInvertedDownSeq1, kFlyerHalfLoopInvertedDownSeq2,
            kFlyerHalfLoopInvertedDownSeq3 } },
    },
    {
        TrackElemType::leftFlyerCorkscrewUp,
        { 3, { kLeftFlyerCorkscrewUpSeq0, kLeftFlyerCorkscrewUpSeq1, kLeftFlyerCorkscrewUpSeq2 } },
    },
    {
        TrackElemType::rightFlyerCorkscrewUp,
        { 3, { kRightFlyerCorkscrewUpSeq0, kRightFlyerCorkscrewUpSeq1, kRightFlyerCorkscrewUpSeq2 } },
    },
    {
        TrackElemType::leftFlyerCorkscrewDown,
        { 3, { kLeftFlyerCorkscrewDownSeq0, kLeftFlyerCorkscrewDownSeq1, kLeftFlyerCorkscrewDownSeq2 } },
    },
    {
        TrackElemType::rightFlyerCorkscrewDown,
        { 3, { kRightFlyerCorkscrewDownSeq0, kRightFlyerCorkscrewDownSeq1, kRightFlyerCorkscrewDownSeq2 } },
    },
    {
        TrackElemType::heartLineTransferUp,
        { 4, { kHeartLineTransferUpSeq0, kHeartLineTransferUpSeq1, kHeartLineTransferUpSeq2, kHeartLineTransferUpSeq3 } },
    },
    {
        TrackElemType::heartLineTransferDown,
        { 4,
          { kHeartLineTransferDownSeq0, kHeartLineTransferDownSeq1, kHeartLineTransferDownSeq2, kHeartLineTransferDownSeq3 } },
    },
    {
        TrackElemType::leftHeartLineRoll,
        { 6,
          { kLeftHeartLineRollSeq0, kLeftHeartLineRollSeq1, kLeftHeartLineRollSeq2, kLeftHeartLineRollSeq3,
            kLeftHeartLineRollSeq4, kLeftHeartLineRollSeq5 } },
    },
    {
        TrackElemType::rightHeartLineRoll,
        { 6,
          { kRightHeartLineRollSeq0, kRightHeartLineRollSeq1, kRightHeartLineRollSeq2, kRightHeartLineRollSeq3,
            kRightHeartLineRollSeq4, kRightHeartLineRollSeq5 } },
    },
    {
        TrackElemType::minigolfHoleA,
        { 2, { kMinigolfHoleASeq0, kMinigolfHoleASeq1 } },
    },
    {
        TrackElemType::minigolfHoleB,
        { 2, { kMinigolfHoleBSeq0, kMinigolfHoleBSeq1 } },
    },
    {
        TrackElemType::minigolfHoleC,
        { 2, { kMinigolfHoleCSeq0, kMinigolfHoleCSeq1 } },
    },
    {
        TrackElemType::minigolfHoleD,
        { 3, { kMinigolfHoleDSeq0, kMinigolfHoleDSeq1, kMinigolfHoleDSeq2 } },
    },
    {
        TrackElemType::minigolfHoleE,
        { 3, { kMinigolfHoleESeq0, kMinigolfHoleESeq1, kMinigolfHoleESeq2 } },
    },
    {
        TrackElemType::multiDimInvertedFlatToDown90QuarterLoop,
        { 4,
          { kMultiDimInvertedFlatToDown90QuarterLoopSeq0, kMultiDimInvertedFlatToDown90QuarterLoopSeq1,
            kMultiDimInvertedFlatToDown90QuarterLoopSeq2, kMultiDimInvertedFlatToDown90QuarterLoopSeq3 } },
    },
    {
        TrackElemType::up90ToInvertedFlatQuarterLoop,
        { 3, { kUp90ToInvertedFlatQuarterLoopSeq0, kUp90ToInvertedFlatQuarterLoopSeq1, kUp90ToInvertedFlatQuarterLoopSeq2 } },
    },
    {
        TrackElemType::invertedFlatToDown90QuarterLoop,
        { 4,
          { kInvertedFlatToDown90QuarterLoopSeq0, kInvertedFlatToDown90QuarterLoopSeq1, kInvertedFlatToDown90QuarterLoopSeq2,
            kInvertedFlatToDown90QuarterLoopSeq3 } },
    },
    {
        TrackElemType::leftCurvedLiftHill,
        { 4, { kLeftCurvedLiftHillSeq0, kLeftCurvedLiftHillSeq1, kLeftCurvedLiftHillSeq2, kLeftCurvedLiftHillSeq3 } },
    },
    {
        TrackElemType::rightCurvedLiftHill,
        { 4, { kRightCurvedLiftHillSeq0, kRightCurvedLiftHillSeq1, kRightCurvedLiftHillSeq2, kRightCurvedLiftHillSeq3 } },
    },
    {
        TrackElemType::leftReverser,
        { 6,
          { kLeftReverserSeq0, kLeftReverserSeq1, kLeftReverserSeq2, kLeftReverserSeq3, kLeftReverserSeq4,
            kLeftReverserSeq5 } },
    },
    {
        TrackElemType::rightReverser,
        { 6,
          { kRightReverserSeq0, kRightReverserSeq1, kRightReverserSeq2, kRightReverserSeq3, kRightReverserSeq4,
            kRightReverserSeq5 } },
    },
    {
        TrackElemType::airThrustTopCap,
        { 4, { kAirThrustTopCapSeq0, kAirThrustTopCapSeq1, kAirThrustTopCapSeq2, kAirThrustTopCapSeq3 } },
    },
    {
        TrackElemType::airThrustVerticalDown,
        { 2, { kAirThrustVerticalDownSeq0, kAirThrustVerticalDownSeq1 } },
    },
    {
        TrackElemType::airThrustVerticalDownToLevel,
        { 7,
          { kAirThrustVerticalDownToLevelSeq0, kAirThrustVerticalDownToLevelSeq1, kAirThrustVerticalDownToLevelSeq2,
            kAirThrustVerticalDownToLevelSeq3, kAirThrustVerticalDownToLevelSeq4, kAirThrustVerticalDownToLevelSeq5,
            kAirThrustVerticalDownToLevelSeq6 } },
    },
    {
        TrackElemType::blockBrakes,
        { 1, { kBlockBrakesSeq0 } },
    },
    {
        TrackElemType::leftBankedQuarterTurn3TileUp25,
        { 4,
          { kLeftBankedQuarterTurn3TileUp25Seq0, kLeftBankedQuarterTurn3TileUp25Seq1, kLeftBankedQuarterTurn3TileUp25Seq2,
            kLeftBankedQuarterTurn3TileUp25Seq3 } },
    },
    {
        TrackElemType::rightBankedQuarterTurn3TileUp25,
        { 4,
          { kRightBankedQuarterTurn3TileUp25Seq0, kRightBankedQuarterTurn3TileUp25Seq1, kRightBankedQuarterTurn3TileUp25Seq2,
            kRightBankedQuarterTurn3TileUp25Seq3 } },
    },
    {
        TrackElemType::leftBankedQuarterTurn3TileDown25,
        { 4,
          { kLeftBankedQuarterTurn3TileDown25Seq0, kLeftBankedQuarterTurn3TileDown25Seq1, kLeftBankedQuarterTurn3TileDown25Seq2,
            kLeftBankedQuarterTurn3TileDown25Seq3 } },
    },
    {
        TrackElemType::rightBankedQuarterTurn3TileDown25,
        { 4,
          { kRightBankedQuarterTurn3TileDown25Seq0, kRightBankedQuarterTurn3TileDown25Seq1,
            kRightBankedQuarterTurn3TileDown25Seq2, kRightBankedQuarterTurn3TileDown25Seq3 } },
    },
    {
        TrackElemType::leftBankedQuarterTurn5TileUp25,
        { 7,
          { kLeftBankedQuarterTurn5TileUp25Seq0, kLeftBankedQuarterTurn5TileUp25Seq1, kLeftBankedQuarterTurn5TileUp25Seq2,
            kLeftBankedQuarterTurn5TileUp25Seq3, kLeftBankedQuarterTurn5TileUp25Seq4, kLeftBankedQuarterTurn5TileUp25Seq5,
            kLeftBankedQuarterTurn5TileUp25Seq6, kLeftBankedQuarterTurn5TileUp25Seq7 } },
    },
    {
        TrackElemType::rightBankedQuarterTurn5TileUp25,
        { 7,
          { kRightBankedQuarterTurn5TileUp25Seq0, kRightBankedQuarterTurn5TileUp25Seq1, kRightBankedQuarterTurn5TileUp25Seq2,
            kRightBankedQuarterTurn5TileUp25Seq3, kRightBankedQuarterTurn5TileUp25Seq4, kRightBankedQuarterTurn5TileUp25Seq5,
            kRightBankedQuarterTurn5TileUp25Seq6, kRightBankedQuarterTurn5TileUp25Seq7 } },
    },
    {
        TrackElemType::leftBankedQuarterTurn5TileDown25,
        { 7,
          { kLeftBankedQuarterTurn5TileDown25Seq0, kLeftBankedQuarterTurn5TileDown25Seq1, kLeftBankedQuarterTurn5TileDown25Seq2,
            kLeftBankedQuarterTurn5TileDown25Seq3, kLeftBankedQuarterTurn5TileDown25Seq4, kLeftBankedQuarterTurn5TileDown25Seq5,
            kLeftBankedQuarterTurn5TileDown25Seq6, kLeftBankedQuarterTurn5TileDown25Seq7 } },
    },
    {
        TrackElemType::rightBankedQuarterTurn5TileDown25,
        { 7,
          { kRightBankedQuarterTurn5TileDown25Seq0, kRightBankedQuarterTurn5TileDown25Seq1,
            kRightBankedQuarterTurn5TileDown25Seq2, kRightBankedQuarterTurn5TileDown25Seq3,
            kRightBankedQuarterTurn5TileDown25Seq4, kRightBankedQuarterTurn5TileDown25Seq5,
            kRightBankedQuarterTurn5TileDown25Seq6, kRightBankedQuarterTurn5TileDown25Seq7 } },
    },
    {
        TrackElemType::up25ToLeftBankedUp25,
        { 1, { kUp25ToLeftBankedUp25Seq0 } },
    },
    {
        TrackElemType::up25ToRightBankedUp25,
        { 1, { kUp25ToRightBankedUp25Seq0 } },
    },
    {
        TrackElemType::leftBankedUp25ToUp25,
        { 1, { kLeftBankedUp25ToUp25Seq0 } },
    },
    {
        TrackElemType::rightBankedUp25ToUp25,
        { 1, { kRightBankedUp25ToUp25Seq0 } },
    },
    {
        TrackElemType::down25ToLeftBankedDown25,
        { 1, { kDown25ToLeftBankedDown25Seq0 } },
    },
    {
        TrackElemType::down25ToRightBankedDown25,
        { 1, { kDown25ToRightBankedDown25Seq0 } },
    },
    {
        TrackElemType::leftBankedDown25ToDown25,
        { 1, { kLeftBankedDown25ToDown25Seq0 } },
    },
    {
        TrackElemType::rightBankedDown25ToDown25,
        { 1, { kRightBankedDown25ToDown25Seq0 } },
    },
    {
        TrackElemType::leftBankedFlatToLeftBankedUp25,
        { 1, { kLeftBankedFlatToLeftBankedUp25Seq0 } },
    },
    {
        TrackElemType::rightBankedFlatToRightBankedUp25,
        { 1, { kRightBankedFlatToRightBankedUp25Seq0 } },
    },
    {
        TrackElemType::leftBankedUp25ToLeftBankedFlat,
        { 1, { kLeftBankedUp25ToLeftBankedFlatSeq0 } },
    },
    {
        TrackElemType::rightBankedUp25ToRightBankedFlat,
        { 1, { kRightBankedUp25ToRightBankedFlatSeq0 } },
    },
    {
        TrackElemType::leftBankedFlatToLeftBankedDown25,
        { 1, { kLeftBankedFlatToLeftBankedDown25Seq0 } },
    },
    {
        TrackElemType::rightBankedFlatToRightBankedDown25,
        { 1, { kRightBankedFlatToRightBankedDown25Seq0 } },
    },
    {
        TrackElemType::leftBankedDown25ToLeftBankedFlat,
        { 1, { kLeftBankedDown25ToLeftBankedFlatSeq0 } },
    },
    {
        TrackElemType::rightBankedDown25ToRightBankedFlat,
        { 1, { kRightBankedDown25ToRightBankedFlatSeq0 } },
    },
    {
        TrackElemType::flatToLeftBankedUp25,
        { 1, { kFlatToLeftBankedUp25Seq0 } },
    },
    {
        TrackElemType::flatToRightBankedUp25,
        { 1, { kFlatToRightBankedUp25Seq0 } },
    },
    {
        TrackElemType::leftBankedUp25ToFlat,
        { 1, { kLeftBankedUp25ToFlatSeq0 } },
    },
    {
        TrackElemType::rightBankedUp25ToFlat,
        { 1, { kRightBankedUp25ToFlatSeq0 } },
    },
    {
        TrackElemType::flatToLeftBankedDown25,
        { 1, { kFlatToLeftBankedDown25Seq0 } },
    },
    {
        TrackElemType::flatToRightBankedDown25,
        { 1, { kFlatToRightBankedDown25Seq0 } },
    },
    {
        TrackElemType::leftBankedDown25ToFlat,
        { 1, { kLeftBankedDown25ToFlatSeq0 } },
    },
    {
        TrackElemType::rightBankedDown25ToFlat,
        { 1, { kRightBankedDown25ToFlatSeq0 } },
    },
    {
        TrackElemType::leftQuarterTurn1TileUp90,
        { 2, { kLeftQuarterTurn1TileUp90Seq0, kLeftQuarterTurn1TileUp90Seq1 } },
    },
    {
        TrackElemType::rightQuarterTurn1TileUp90,
        { 2, { kRightQuarterTurn1TileUp90Seq0, kRightQuarterTurn1TileUp90Seq1 } },
    },
    {
        TrackElemType::leftQuarterTurn1TileDown90,
        { 2, { kLeftQuarterTurn1TileDown90Seq0, kLeftQuarterTurn1TileDown90Seq1 } },
    },
    {
        TrackElemType::rightQuarterTurn1TileDown90,
        { 2, { kRightQuarterTurn1TileDown90Seq0, kRightQuarterTurn1TileDown90Seq1 } },
    },
    {
        TrackElemType::multiDimUp90ToInvertedFlatQuarterLoop,
        { 3,
          { kMultiDimUp90ToInvertedFlatQuarterLoopSeq0, kMultiDimUp90ToInvertedFlatQuarterLoopSeq1,
            kMultiDimUp90ToInvertedFlatQuarterLoopSeq2 } },
    },
    {
        TrackElemType::multiDimFlatToDown90QuarterLoop,
        { 4,
          { kMultiDimFlatToDown90QuarterLoopSeq0, kMultiDimFlatToDown90QuarterLoopSeq1, kMultiDimFlatToDown90QuarterLoopSeq2,
            kMultiDimFlatToDown90QuarterLoopSeq3 } },
    },
    {
        TrackElemType::multiDimInvertedUp90ToFlatQuarterLoop,
        { 3,
          { kMultiDimInvertedUp90ToFlatQuarterLoopSeq0, kMultiDimInvertedUp90ToFlatQuarterLoopSeq1,
            kMultiDimInvertedUp90ToFlatQuarterLoopSeq2 } },
    },
    {
        TrackElemType::rotationControlToggle,
        { 1, { kRotationControlToggleSeq0 } },
    },
    {
        TrackElemType::flatTrack1x4A,
        { 4, { kFlatTrack1x4ASeq0, kFlatTrack1x4ASeq1, kFlatTrack1x4ASeq2, kFlatTrack1x4ASeq3 } },
    },
    {
        TrackElemType::flatTrack2x2,
        { 4, { kFlatTrack2x2Seq0, kFlatTrack2x2Seq1, kFlatTrack2x2Seq2, kFlatTrack2x2Seq3 } },
    },
    {
        TrackElemType::flatTrack4x4,
        { 16,
          { kFlatTrack4x4Seq0, kFlatTrack4x4Seq1, kFlatTrack4x4Seq2, kFlatTrack4x4Seq3, kFlatTrack4x4Seq4, kFlatTrack4x4Seq5,
            kFlatTrack4x4Seq6, kFlatTrack4x4Seq7, kFlatTrack4x4Seq8, kFlatTrack4x4Seq9, kFlatTrack4x4Seq10, kFlatTrack4x4Seq11,
            kFlatTrack4x4Seq12, kFlatTrack4x4Seq13, kFlatTrack4x4Seq14, kFlatTrack4x4Seq15 } },
    },
    {
        TrackElemType::flatTrack2x4,
        { 8,
          { kFlatTrack2x4Seq0, kFlatTrack2x4Seq1, kFlatTrack2x4Seq2, kFlatTrack2x4Seq3, kFlatTrack2x4Seq4, kFlatTrack2x4Seq5,
            kFlatTrack2x4Seq6, kFlatTrack2x4Seq7 } },
    },
    {
        TrackElemType::flatTrack1x5,
        { 5, { kFlatTrack1x5Seq0, kFlatTrack1x5Seq1, kFlatTrack1x5Seq2, kFlatTrack1x5Seq3, kFlatTrack1x5Seq4 } },
    },
    {
        TrackElemType::flatTrack1x1A,
        { 1, { kFlatTrack1x1ASeq0 } },
    },
    {
        TrackElemType::flatTrack1x4B,
        { 4, { kFlatTrack1x4BSeq0, kFlatTrack1x4BSeq1, kFlatTrack1x4BSeq2, kFlatTrack1x4BSeq3 } },
    },
    {
        TrackElemType::flatTrack1x1B,
        { 1, { kFlatTrack1x1BSeq0 } },
    },
    {
        TrackElemType::flatTrack1x4C,
        { 4, { kFlatTrack1x4CSeq0, kFlatTrack1x4CSeq1, kFlatTrack1x4CSeq2, kFlatTrack1x4CSeq3 } },
    },
    {
        TrackElemType::flatTrack3x3,
        { 9,
          { kFlatTrack3x3Seq0, kFlatTrack3x3Seq1, kFlatTrack3x3Seq2, kFlatTrack3x3Seq3, kFlatTrack3x3Seq4, kFlatTrack3x3Seq5,
            kFlatTrack3x3Seq6, kFlatTrack3x3Seq7, kFlatTrack3x3Seq8 } },
    },
    {
        TrackElemType::leftLargeCorkscrewUp,
        { 6,
          { kLeftLargeCorkscrewUpSeq0, kLeftLargeCorkscrewUpSeq1, kLeftLargeCorkscrewUpSeq2, kLeftLargeCorkscrewUpSeq3,
            kLeftLargeCorkscrewUpSeq4, kLeftLargeCorkscrewUpSeq5 } },
    },
    {
        TrackElemType::rightLargeCorkscrewUp,
        { 6,
          { kRightLargeCorkscrewUpSeq0, kRightLargeCorkscrewUpSeq1, kRightLargeCorkscrewUpSeq2, kRightLargeCorkscrewUpSeq3,
            kRightLargeCorkscrewUpSeq4, kRightLargeCorkscrewUpSeq5 } },
    },
    {
        TrackElemType::leftLargeCorkscrewDown,
        { 6,
          { kLeftLargeCorkscrewDownSeq0, kLeftLargeCorkscrewDownSeq1, kLeftLargeCorkscrewDownSeq2, kLeftLargeCorkscrewDownSeq3,
            kLeftLargeCorkscrewDownSeq4, kLeftLargeCorkscrewDownSeq5 } },
    },
    {
        TrackElemType::rightLargeCorkscrewDown,
        { 6,
          { kRightLargeCorkscrewDownSeq0, kRightLargeCorkscrewDownSeq1, kRightLargeCorkscrewDownSeq2,
            kRightLargeCorkscrewDownSeq3, kRightLargeCorkscrewDownSeq4, kRightLargeCorkscrewDownSeq5 } },
    },
    {
        TrackElemType::leftMediumHalfLoopUp,
        { 5,
          { kLeftMediumHalfLoopUpSeq0, kLeftMediumHalfLoopUpSeq1, kLeftMediumHalfLoopUpSeq2, kLeftMediumHalfLoopUpSeq3,
            kLeftMediumHalfLoopUpSeq4 } },
    },
    {
        TrackElemType::rightMediumHalfLoopUp,
        { 5,
          { kRightMediumHalfLoopUpSeq0, kRightMediumHalfLoopUpSeq1, kRightMediumHalfLoopUpSeq2, kRightMediumHalfLoopUpSeq3,
            kRightMediumHalfLoopUpSeq4 } },
    },
    {
        TrackElemType::leftMediumHalfLoopDown,
        { 5,
          { kLeftMediumHalfLoopDownSeq0, kLeftMediumHalfLoopDownSeq1, kLeftMediumHalfLoopDownSeq2, kLeftMediumHalfLoopDownSeq3,
            kLeftMediumHalfLoopDownSeq4 } },
    },
    {
        TrackElemType::rightMediumHalfLoopDown,
        { 5,
          { kRightMediumHalfLoopDownSeq0, kRightMediumHalfLoopDownSeq1, kRightMediumHalfLoopDownSeq2,
            kRightMediumHalfLoopDownSeq3, kRightMediumHalfLoopDownSeq4 } },
    },
    {
        TrackElemType::leftZeroGRollUp,
        { 3, { kLeftZeroGRollUpSeq0, kLeftZeroGRollUpSeq1, kLeftZeroGRollUpSeq2 } },
    },
    {
        TrackElemType::rightZeroGRollUp,
        { 3, { kRightZeroGRollUpSeq0, kRightZeroGRollUpSeq1, kRightZeroGRollUpSeq2 } },
    },
    {
        TrackElemType::leftZeroGRollDown,
        { 3, { kLeftZeroGRollDownSeq0, kLeftZeroGRollDownSeq1, kLeftZeroGRollDownSeq2 } },
    },
    {
        TrackElemType::rightZeroGRollDown,
        { 3, { kRightZeroGRollDownSeq0, kRightZeroGRollDownSeq1, kRightZeroGRollDownSeq2 } },
    },
    {
        TrackElemType::leftLargeZeroGRollUp,
        { 4, { kLeftLargeZeroGRollUpSeq0, kLeftLargeZeroGRollUpSeq1, kLeftLargeZeroGRollUpSeq2, kLeftLargeZeroGRollUpSeq3 } },
    },
    {
        TrackElemType::rightLargeZeroGRollUp,
        { 4,
          { kRightLargeZeroGRollUpSeq0, kRightLargeZeroGRollUpSeq1, kRightLargeZeroGRollUpSeq2, kRightLargeZeroGRollUpSeq3 } },
    },
    {
        TrackElemType::leftLargeZeroGRollDown,
        { 4,
          { kLeftLargeZeroGRollDownSeq0, kLeftLargeZeroGRollDownSeq1, kLeftLargeZeroGRollDownSeq2,
            kLeftLargeZeroGRollDownSeq3 } },
    },
    {
        TrackElemType::rightLargeZeroGRollDown,
        { 4,
          { kRightLargeZeroGRollDownSeq0, kRightLargeZeroGRollDownSeq1, kRightLargeZeroGRollDownSeq2,
            kRightLargeZeroGRollDownSeq3 } },
    },
    {
        TrackElemType::leftFlyerLargeHalfLoopUninvertedUp,
        { 7,
          { kLeftFlyerLargeHalfLoopUninvertedUpSeq0, kLeftFlyerLargeHalfLoopUninvertedUpSeq1,
            kLeftFlyerLargeHalfLoopUninvertedUpSeq2, kLeftFlyerLargeHalfLoopUninvertedUpSeq3,
            kLeftFlyerLargeHalfLoopUninvertedUpSeq4, kLeftFlyerLargeHalfLoopUninvertedUpSeq5,
            kLeftFlyerLargeHalfLoopUninvertedUpSeq6 } },
    },
    {
        TrackElemType::rightFlyerLargeHalfLoopUninvertedUp,
        { 7,
          { kRightFlyerLargeHalfLoopUninvertedUpSeq0, kRightFlyerLargeHalfLoopUninvertedUpSeq1,
            kRightFlyerLargeHalfLoopUninvertedUpSeq2, kRightFlyerLargeHalfLoopUninvertedUpSeq3,
            kRightFlyerLargeHalfLoopUninvertedUpSeq4, kRightFlyerLargeHalfLoopUninvertedUpSeq5,
            kRightFlyerLargeHalfLoopUninvertedUpSeq6 } },
    },
    {
        TrackElemType::leftFlyerLargeHalfLoopInvertedDown,
        { 7,
          { kLeftFlyerLargeHalfLoopInvertedDownSeq0, kLeftFlyerLargeHalfLoopInvertedDownSeq1,
            kLeftFlyerLargeHalfLoopInvertedDownSeq2, kLeftFlyerLargeHalfLoopInvertedDownSeq3,
            kLeftFlyerLargeHalfLoopInvertedDownSeq4, kLeftFlyerLargeHalfLoopInvertedDownSeq5,
            kLeftFlyerLargeHalfLoopInvertedDownSeq6 } },
    },
    {
        TrackElemType::rightFlyerLargeHalfLoopInvertedDown,
        { 7,
          { kRightFlyerLargeHalfLoopInvertedDownSeq0, kRightFlyerLargeHalfLoopInvertedDownSeq1,
            kRightFlyerLargeHalfLoopInvertedDownSeq2, kRightFlyerLargeHalfLoopInvertedDownSeq3,
            kRightFlyerLargeHalfLoopInvertedDownSeq4, kRightFlyerLargeHalfLoopInvertedDownSeq5,
            kRightFlyerLargeHalfLoopInvertedDownSeq6 } },
    },
    {
        TrackElemType::leftFlyerLargeHalfLoopInvertedUp,
        { 7,
          { kLeftFlyerLargeHalfLoopInvertedUpSeq0, kLeftFlyerLargeHalfLoopInvertedUpSeq1, kLeftFlyerLargeHalfLoopInvertedUpSeq2,
            kLeftFlyerLargeHalfLoopInvertedUpSeq3, kLeftFlyerLargeHalfLoopInvertedUpSeq4, kLeftFlyerLargeHalfLoopInvertedUpSeq5,
            kLeftFlyerLargeHalfLoopInvertedUpSeq6 } },
    },
    {
        TrackElemType::rightFlyerLargeHalfLoopInvertedUp,
        { 7,
          { kRightFlyerLargeHalfLoopInvertedUpSeq0, kRightFlyerLargeHalfLoopInvertedUpSeq1,
            kRightFlyerLargeHalfLoopInvertedUpSeq2, kRightFlyerLargeHalfLoopInvertedUpSeq3,
            kRightFlyerLargeHalfLoopInvertedUpSeq4, kRightFlyerLargeHalfLoopInvertedUpSeq5,
            kRightFlyerLargeHalfLoopInvertedUpSeq6 } },
    },
    {
        TrackElemType::leftFlyerLargeHalfLoopUninvertedDown,
        { 7,
          { kLeftFlyerLargeHalfLoopUninvertedDownSeq0, kLeftFlyerLargeHalfLoopUninvertedDownSeq1,
            kLeftFlyerLargeHalfLoopUninvertedDownSeq2, kLeftFlyerLargeHalfLoopUninvertedDownSeq3,
            kLeftFlyerLargeHalfLoopUninvertedDownSeq4, kLeftFlyerLargeHalfLoopUninvertedDownSeq5,
            kLeftFlyerLargeHalfLoopUninvertedDownSeq6 } },
    },
    {
        TrackElemType::rightFlyerLargeHalfLoopUninvertedDown,
        { 7,
          { kRightFlyerLargeHalfLoopUninvertedDownSeq0, kRightFlyerLargeHalfLoopUninvertedDownSeq1,
            kRightFlyerLargeHalfLoopUninvertedDownSeq2, kRightFlyerLargeHalfLoopUninvertedDownSeq3,
            kRightFlyerLargeHalfLoopUninvertedDownSeq4, kRightFlyerLargeHalfLoopUninvertedDownSeq5,
            kRightFlyerLargeHalfLoopUninvertedDownSeq6 } },
    },
    {
        TrackElemType::flyerHalfLoopInvertedUp,
        { 4,
          { kFlyerHalfLoopInvertedUpSeq0, kFlyerHalfLoopInvertedUpSeq1, kFlyerHalfLoopInvertedUpSeq2,
            kFlyerHalfLoopInvertedUpSeq3 } },
    },
    {
        TrackElemType::flyerHalfLoopUninvertedDown,
        { 4,
          { kFlyerHalfLoopUninvertedDownSeq0, kFlyerHalfLoopUninvertedDownSeq1, kFlyerHalfLoopUninvertedDownSeq2,
            kFlyerHalfLoopUninvertedDownSeq3 } },
    },
    {
        TrackElemType::leftEighthToDiagUp25,
        { 5,
          { kLeftEighthToDiagUp25Seq0, kLeftEighthToDiagUp25Seq1, kLeftEighthToDiagUp25Seq2, kLeftEighthToDiagUp25Seq3,
            kLeftEighthToDiagUp25Seq4 } },
    },
    {
        TrackElemType::rightEighthToDiagUp25,
        { 5,
          { kRightEighthToDiagUp25Seq0, kRightEighthToDiagUp25Seq1, kRightEighthToDiagUp25Seq2, kRightEighthToDiagUp25Seq3,
            kRightEighthToDiagUp25Seq4 } },
    },
    {
        TrackElemType::leftEighthToDiagDown25,
        { 5,
          { kLeftEighthToDiagDown25Seq0, kLeftEighthToDiagDown25Seq1, kLeftEighthToDiagDown25Seq2, kLeftEighthToDiagDown25Seq3,
            kLeftEighthToDiagDown25Seq4 } },
    },
    {
        TrackElemType::rightEighthToDiagDown25,
        { 5,
          { kRightEighthToDiagDown25Seq0, kRightEighthToDiagDown25Seq1, kRightEighthToDiagDown25Seq2,
            kRightEighthToDiagDown25Seq3, kRightEighthToDiagDown25Seq4 } },
    },
    {
        TrackElemType::leftEighthToOrthogonalUp25,
        { 5,
          { kLeftEighthToOrthogonalUp25Seq0, kLeftEighthToOrthogonalUp25Seq1, kLeftEighthToOrthogonalUp25Seq2,
            kLeftEighthToOrthogonalUp25Seq3, kLeftEighthToOrthogonalUp25Seq4 } },
    },
    {
        TrackElemType::rightEighthToOrthogonalUp25,
        { 5,
          { kRightEighthToOrthogonalUp25Seq0, kRightEighthToOrthogonalUp25Seq1, kRightEighthToOrthogonalUp25Seq2,
            kRightEighthToOrthogonalUp25Seq3, kRightEighthToOrthogonalUp25Seq4 } },
    },
    {
        TrackElemType::leftEighthToOrthogonalDown25,
        { 5,
          { kLeftEighthToOrthogonalDown25Seq0, kLeftEighthToOrthogonalDown25Seq1, kLeftEighthToOrthogonalDown25Seq2,
            kLeftEighthToOrthogonalDown25Seq3, kLeftEighthToOrthogonalDown25Seq4 } },
    },
    {
        TrackElemType::rightEighthToOrthogonalDown25,
        { 5,
          { kRightEighthToOrthogonalDown25Seq0, kRightEighthToOrthogonalDown25Seq1, kRightEighthToOrthogonalDown25Seq2,
            kRightEighthToOrthogonalDown25Seq3, kRightEighthToOrthogonalDown25Seq4 } },
    },
    {
        TrackElemType::diagUp25ToLeftBankedUp25,
        { 4,
          { kDiagUp25ToLeftBankedUp25Seq0, kDiagUp25ToLeftBankedUp25Seq1, kDiagUp25ToLeftBankedUp25Seq2,
            kDiagUp25ToLeftBankedUp25Seq3 } },
    },
    {
        TrackElemType::diagUp25ToRightBankedUp25,
        { 4,
          { kDiagUp25ToRightBankedUp25Seq0, kDiagUp25ToRightBankedUp25Seq1, kDiagUp25ToRightBankedUp25Seq2,
            kDiagUp25ToRightBankedUp25Seq3 } },
    },
    {
        TrackElemType::diagLeftBankedUp25ToUp25,
        { 4,
          { kDiagLeftBankedUp25ToUp25Seq0, kDiagLeftBankedUp25ToUp25Seq1, kDiagLeftBankedUp25ToUp25Seq2,
            kDiagLeftBankedUp25ToUp25Seq3 } },
    },
    {
        TrackElemType::diagRightBankedUp25ToUp25,
        { 4,
          { kDiagRightBankedUp25ToUp25Seq0, kDiagRightBankedUp25ToUp25Seq1, kDiagRightBankedUp25ToUp25Seq2,
            kDiagRightBankedUp25ToUp25Seq3 } },
    },
    {
        TrackElemType::diagDown25ToLeftBankedDown25,
        { 4,
          { kDiagDown25ToLeftBankedDown25Seq0, kDiagDown25ToLeftBankedDown25Seq1, kDiagDown25ToLeftBankedDown25Seq2,
            kDiagDown25ToLeftBankedDown25Seq3 } },
    },
    {
        TrackElemType::diagDown25ToRightBankedDown25,
        { 4,
          { kDiagDown25ToRightBankedDown25Seq0, kDiagDown25ToRightBankedDown25Seq1, kDiagDown25ToRightBankedDown25Seq2,
            kDiagDown25ToRightBankedDown25Seq3 } },
    },
    {
        TrackElemType::diagLeftBankedDown25ToDown25,
        { 4,
          { kDiagLeftBankedDown25ToDown25Seq0, kDiagLeftBankedDown25ToDown25Seq1, kDiagLeftBankedDown25ToDown25Seq2,
            kDiagLeftBankedDown25ToDown25Seq3 } },
    },
    {
        TrackElemType::diagRightBankedDown25ToDown25,
        { 4,
          { kDiagRightBankedDown25ToDown25Seq0, kDiagRightBankedDown25ToDown25Seq1, kDiagRightBankedDown25ToDown25Seq2,
            kDiagRightBankedDown25ToDown25Seq3 } },
    },
    {
        TrackElemType::diagLeftBankedFlatToLeftBankedUp25,
        { 4,
          { kDiagLeftBankedFlatToLeftBankedUp25Seq0, kDiagLeftBankedFlatToLeftBankedUp25Seq1,
            kDiagLeftBankedFlatToLeftBankedUp25Seq2, kDiagLeftBankedFlatToLeftBankedUp25Seq3 } },
    },
    {
        TrackElemType::diagRightBankedFlatToRightBankedUp25,
        { 4,
          { kDiagRightBankedFlatToRightBankedUp25Seq0, kDiagRightBankedFlatToRightBankedUp25Seq1,
            kDiagRightBankedFlatToRightBankedUp25Seq2, kDiagRightBankedFlatToRightBankedUp25Seq3 } },
    },
    {
        TrackElemType::diagLeftBankedUp25ToLeftBankedFlat,
        { 4,
          { kDiagLeftBankedUp25ToLeftBankedFlatSeq0, kDiagLeftBankedUp25ToLeftBankedFlatSeq1,
            kDiagLeftBankedUp25ToLeftBankedFlatSeq2, kDiagLeftBankedUp25ToLeftBankedFlatSeq3 } },
    },
    {
        TrackElemType::diagRightBankedUp25ToRightBankedFlat,
        { 4,
          { kDiagRightBankedUp25ToRightBankedFlatSeq0, kDiagRightBankedUp25ToRightBankedFlatSeq1,
            kDiagRightBankedUp25ToRightBankedFlatSeq2, kDiagRightBankedUp25ToRightBankedFlatSeq3 } },
    },
    {
        TrackElemType::diagLeftBankedFlatToLeftBankedDown25,
        { 4,
          { kDiagLeftBankedFlatToLeftBankedDown25Seq0, kDiagLeftBankedFlatToLeftBankedDown25Seq1,
            kDiagLeftBankedFlatToLeftBankedDown25Seq2, kDiagLeftBankedFlatToLeftBankedDown25Seq3 } },
    },
    {
        TrackElemType::diagRightBankedFlatToRightBankedDown25,
        { 4,
          { kDiagRightBankedFlatToRightBankedDown25Seq0, kDiagRightBankedFlatToRightBankedDown25Seq1,
            kDiagRightBankedFlatToRightBankedDown25Seq2, kDiagRightBankedFlatToRightBankedDown25Seq3 } },
    },
    {
        TrackElemType::diagLeftBankedDown25ToLeftBankedFlat,
        { 4,
          { kDiagLeftBankedDown25ToLeftBankedFlatSeq0, kDiagLeftBankedDown25ToLeftBankedFlatSeq1,
            kDiagLeftBankedDown25ToLeftBankedFlatSeq2, kDiagLeftBankedDown25ToLeftBankedFlatSeq3 } },
    },
    {
        TrackElemType::diagRightBankedDown25ToRightBankedFlat,
        { 4,
          { kDiagRightBankedDown25ToRightBankedFlatSeq0, kDiagRightBankedDown25ToRightBankedFlatSeq1,
            kDiagRightBankedDown25ToRightBankedFlatSeq2, kDiagRightBankedDown25ToRightBankedFlatSeq3 } },
    },
    {
        TrackElemType::diagFlatToLeftBankedUp25,
        { 4,
          { kDiagFlatToLeftBankedUp25Seq0, kDiagFlatToLeftBankedUp25Seq1, kDiagFlatToLeftBankedUp25Seq2,
            kDiagFlatToLeftBankedUp25Seq3 } },
    },
    {
        TrackElemType::diagFlatToRightBankedUp25,
        { 4,
          { kDiagFlatToRightBankedUp25Seq0, kDiagFlatToRightBankedUp25Seq1, kDiagFlatToRightBankedUp25Seq2,
            kDiagFlatToRightBankedUp25Seq3 } },
    },
    {
        TrackElemType::diagLeftBankedUp25ToFlat,
        { 4,
          { kDiagLeftBankedUp25ToFlatSeq0, kDiagLeftBankedUp25ToFlatSeq1, kDiagLeftBankedUp25ToFlatSeq2,
            kDiagLeftBankedUp25ToFlatSeq3 } },
    },
    {
        TrackElemType::diagRightBankedUp25ToFlat,
        { 4,
          { kDiagRightBankedUp25ToFlatSeq0, kDiagRightBankedUp25ToFlatSeq1, kDiagRightBankedUp25ToFlatSeq2,
            kDiagRightBankedUp25ToFlatSeq3 } },
    },
    {
        TrackElemType::diagFlatToLeftBankedDown25,
        { 4,
          { kDiagFlatToLeftBankedDown25Seq0, kDiagFlatToLeftBankedDown25Seq1, kDiagFlatToLeftBankedDown25Seq2,
            kDiagFlatToLeftBankedDown25Seq3 } },
    },
    {
        TrackElemType::diagFlatToRightBankedDown25,
        { 4,
          { kDiagFlatToRightBankedDown25Seq0, kDiagFlatToRightBankedDown25Seq1, kDiagFlatToRightBankedDown25Seq2,
            kDiagFlatToRightBankedDown25Seq3 } },
    },
    {
        TrackElemType::diagLeftBankedDown25ToFlat,
        { 4,
          { kDiagLeftBankedDown25ToFlatSeq0, kDiagLeftBankedDown25ToFlatSeq1, kDiagLeftBankedDown25ToFlatSeq2,
            kDiagLeftBankedDown25ToFlatSeq3 } },
    },
    {
        TrackElemType::diagRightBankedDown25ToFlat,
        { 4,
          { kDiagRightBankedDown25ToFlatSeq0, kDiagRightBankedDown25ToFlatSeq1, kDiagRightBankedDown25ToFlatSeq2,
            kDiagRightBankedDown25ToFlatSeq3 } },
    },
    {
        TrackElemType::diagUp25LeftBanked,
        { 4, { kDiagUp25LeftBankedSeq0, kDiagUp25LeftBankedSeq1, kDiagUp25LeftBankedSeq2, kDiagUp25LeftBankedSeq3 } },
    },
    {
        TrackElemType::diagUp25RightBanked,
        { 4, { kDiagUp25RightBankedSeq0, kDiagUp25RightBankedSeq1, kDiagUp25RightBankedSeq2, kDiagUp25RightBankedSeq3 } },
    },
    {
        TrackElemType::diagDown25LeftBanked,
        { 4, { kDiagDown25LeftBankedSeq0, kDiagDown25LeftBankedSeq1, kDiagDown25LeftBankedSeq2, kDiagDown25LeftBankedSeq3 } },
    },
    {
        TrackElemType::diagDown25RightBanked,
        { 4,
          { kDiagDown25RightBankedSeq0, kDiagDown25RightBankedSeq1, kDiagDown25RightBankedSeq2, kDiagDown25RightBankedSeq3 } },
    },
    {
        TrackElemType::leftEighthBankToDiagUp25,
        { 5,
          { kLeftEighthBankToDiagUp25Seq0, kLeftEighthBankToDiagUp25Seq1, kLeftEighthBankToDiagUp25Seq2,
            kLeftEighthBankToDiagUp25Seq3, kLeftEighthBankToDiagUp25Seq4 } },
    },
    {
        TrackElemType::rightEighthBankToDiagUp25,
        { 5,
          { kRightEighthBankToDiagUp25Seq0, kRightEighthBankToDiagUp25Seq1, kRightEighthBankToDiagUp25Seq2,
            kRightEighthBankToDiagUp25Seq3, kRightEighthBankToDiagUp25Seq4 } },
    },
    {
        TrackElemType::leftEighthBankToDiagDown25,
        { 5,
          { kLeftEighthBankToDiagDown25Seq0, kLeftEighthBankToDiagDown25Seq1, kLeftEighthBankToDiagDown25Seq2,
            kLeftEighthBankToDiagDown25Seq3, kLeftEighthBankToDiagDown25Seq4 } },
    },
    {
        TrackElemType::rightEighthBankToDiagDown25,
        { 5,
          { kRightEighthBankToDiagDown25Seq0, kRightEighthBankToDiagDown25Seq1, kRightEighthBankToDiagDown25Seq2,
            kRightEighthBankToDiagDown25Seq3, kRightEighthBankToDiagDown25Seq4 } },
    },
    {
        TrackElemType::leftEighthBankToOrthogonalUp25,
        { 5,
          { kLeftEighthBankToOrthogonalUp25Seq0, kLeftEighthBankToOrthogonalUp25Seq1, kLeftEighthBankToOrthogonalUp25Seq2,
            kLeftEighthBankToOrthogonalUp25Seq3, kLeftEighthBankToOrthogonalUp25Seq4 } },
    },
    {
        TrackElemType::rightEighthBankToOrthogonalUp25,
        { 5,
          { kRightEighthBankToOrthogonalUp25Seq0, kRightEighthBankToOrthogonalUp25Seq1, kRightEighthBankToOrthogonalUp25Seq2,
            kRightEighthBankToOrthogonalUp25Seq3, kRightEighthBankToOrthogonalUp25Seq4 } },
    },
    {
        TrackElemType::leftEighthBankToOrthogonalDown25,
        { 5,
          { kLeftEighthBankToOrthogonalDown25Seq0, kLeftEighthBankToOrthogonalDown25Seq1, kLeftEighthBankToOrthogonalDown25Seq2,
            kLeftEighthBankToOrthogonalDown25Seq3, kLeftEighthBankToOrthogonalDown25Seq4 } },
    },
    {
        TrackElemType::rightEighthBankToOrthogonalDown25,
        { 5,
          { kRightEighthBankToOrthogonalDown25Seq0, kRightEighthBankToOrthogonalDown25Seq1,
            kRightEighthBankToOrthogonalDown25Seq2, kRightEighthBankToOrthogonalDown25Seq3,
            kRightEighthBankToOrthogonalDown25Seq4 } },
    },
    {
        TrackElemType::diagBrakes,
        { 4, { kDiagBrakesSeq0, kDiagBrakesSeq1, kDiagBrakesSeq2, kDiagBrakesSeq3 } },
    },
    {
        TrackElemType::diagBlockBrakes,
        { 4, { kDiagBlockBrakesSeq0, kDiagBlockBrakesSeq1, kDiagBlockBrakesSeq2, kDiagBlockBrakesSeq3 } },
    },
    {
        TrackElemType::down25Brakes,
        { 1, { kDown25Seq0 } },
    },
    {
        TrackElemType::diagBooster,
        { 4, { kDiagFlatSeq0, kDiagFlatSeq1, kDiagFlatSeq2, kDiagFlatSeq3 } },
    },
    {
        TrackElemType::diagFlatToUp60LongBase,
        { 10,
          { kDiagFlatToUp60LongBaseSeq0, kDiagFlatToUp60LongBaseSeq1, kDiagFlatToUp60LongBaseSeq2, kDiagFlatToUp60LongBaseSeq3,
            kDiagFlatToUp60LongBaseSeq4, kDiagFlatToUp60LongBaseSeq5, kDiagFlatToUp60LongBaseSeq6, kDiagFlatToUp60LongBaseSeq7,
            kDiagFlatToUp60LongBaseSeq8, kDiagFlatToUp60LongBaseSeq9 } },
    },
    {
        TrackElemType::diagUp60ToFlatLongBase,
        { 10,
          { kDiagUp60ToFlatLongBaseSeq0, kDiagUp60ToFlatLongBaseSeq1, kDiagUp60ToFlatLongBaseSeq2, kDiagUp60ToFlatLongBaseSeq3,
            kDiagUp60ToFlatLongBaseSeq4, kDiagUp60ToFlatLongBaseSeq5, kDiagUp60ToFlatLongBaseSeq6, kDiagUp60ToFlatLongBaseSeq7,
            kDiagUp60ToFlatLongBaseSeq8, kDiagUp60ToFlatLongBaseSeq9 } },
    },
    {
        TrackElemType::diagFlatToDown60LongBase,
        { 10,
          { kDiagFlatToDown60LongBaseSeq0, kDiagFlatToDown60LongBaseSeq1, kDiagFlatToDown60LongBaseSeq2,
            kDiagFlatToDown60LongBaseSeq3, kDiagFlatToDown60LongBaseSeq4, kDiagFlatToDown60LongBaseSeq5,
            kDiagFlatToDown60LongBaseSeq6, kDiagFlatToDown60LongBaseSeq7, kDiagFlatToDown60LongBaseSeq8,
            kDiagFlatToDown60LongBaseSeq9 } },
    },
    {
        TrackElemType::diagDown60ToFlatLongBase,
        { 10,
          { kDiagDown60ToFlatLongBaseSeq0, kDiagDown60ToFlatLongBaseSeq1, kDiagDown60ToFlatLongBaseSeq2,
            kDiagDown60ToFlatLongBaseSeq3, kDiagDown60ToFlatLongBaseSeq4, kDiagDown60ToFlatLongBaseSeq5,
            kDiagDown60ToFlatLongBaseSeq6, kDiagDown60ToFlatLongBaseSeq7, kDiagDown60ToFlatLongBaseSeq8,
            kDiagDown60ToFlatLongBaseSeq9 } },
    },
    {
        TrackElemType::leftEighthDiveLoopUpToOrthogonal,
        { 6,
          { kLeftEighthDiveLoopUpToOrthogonalSeq0, kLeftEighthDiveLoopUpToOrthogonalSeq1, kLeftEighthDiveLoopUpToOrthogonalSeq2,
            kLeftEighthDiveLoopUpToOrthogonalSeq3, kLeftEighthDiveLoopUpToOrthogonalSeq4,
            kLeftEighthDiveLoopUpToOrthogonalSeq5 } },
    },
    {
        TrackElemType::rightEighthDiveLoopUpToOrthogonal,
        { 6,
          { kRightEighthDiveLoopUpToOrthogonalSeq0, kRightEighthDiveLoopUpToOrthogonalSeq1,
            kRightEighthDiveLoopUpToOrthogonalSeq2, kRightEighthDiveLoopUpToOrthogonalSeq3,
            kRightEighthDiveLoopUpToOrthogonalSeq4, kRightEighthDiveLoopUpToOrthogonalSeq5 } },
    },
    {
        TrackElemType::leftEighthDiveLoopDownToDiag,
        { 6,
          { kLeftEighthDiveLoopDownToDiagSeq0, kLeftEighthDiveLoopDownToDiagSeq1, kLeftEighthDiveLoopDownToDiagSeq2,
            kLeftEighthDiveLoopDownToDiagSeq3, kLeftEighthDiveLoopDownToDiagSeq4, kLeftEighthDiveLoopDownToDiagSeq5 } },
    },
    {
        TrackElemType::rightEighthDiveLoopDownToDiag,
        { 6,
          { kRightEighthDiveLoopDownToDiagSeq0, kRightEighthDiveLoopDownToDiagSeq1, kRightEighthDiveLoopDownToDiagSeq2,
            kRightEighthDiveLoopDownToDiagSeq3, kRightEighthDiveLoopDownToDiagSeq4, kRightEighthDiveLoopDownToDiagSeq5 } },
    },
    {
        TrackElemType::diagDown25Brakes,
        { 4, { kDiagDown25Seq0, kDiagDown25Seq1, kDiagDown25Seq2, kDiagDown25Seq3 } },
    },
};

TEST(TedSequenceFlipReverse, CompareSequences)
{
    for (const auto& trackPiece : kTrackPieces)
    {
        const auto& ted = GetTrackElementDescriptor(trackPiece.first);
        EXPECT_EQ(ted.sequenceData.numSequences, trackPiece.second.numSequences);
        for (size_t i = 0; i < ted.sequenceData.numSequences; i++)
        {
            EXPECT_EQ(ted.sequenceData.sequences[i].clearance, trackPiece.second.sequences[i].clearance)
                << "clearance difference! TrackElemType: " << EnumValue(trackPiece.first) << " Index: " << i;
            EXPECT_EQ(ted.sequenceData.sequences[i].allowedWallEdges, trackPiece.second.sequences[i].allowedWallEdges)
                << "allowedWallEdges difference! TrackElemType: " << EnumValue(trackPiece.first) << " Index: " << i;
            EXPECT_EQ(ted.sequenceData.sequences[i].flags, trackPiece.second.sequences[i].flags)
                << "flags difference! TrackElemType: " << EnumValue(trackPiece.first) << " Index: " << i;
            EXPECT_EQ(ted.sequenceData.sequences[i].invertSegmentBlocking, trackPiece.second.sequences[i].invertSegmentBlocking)
                << "invertSegmentBlocking difference! TrackElemType: " << EnumValue(trackPiece.first) << " Index: " << i;
            EXPECT_EQ(ted.sequenceData.sequences[i].blockedSegments, trackPiece.second.sequences[i].blockedSegments)
                << "blockedSegments difference! TrackElemType: " << EnumValue(trackPiece.first) << " Index: " << i;
        }
    }
}
