/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "TrackElementDescriptor.h"

namespace OpenRCT2::TrackMetadata
{
    using PS = PaintSegment;

    static constexpr SequenceDescriptor kFlatToUp60LongBaseSeq0 = {
        .clearance = { 0, 0, 0, 8, { 0b1111, 0 }, {} },
        .allowedWallEdges = 0b1010,
        .flags = { SequenceFlag::hasHeightMarker },
        .woodenSupports = { WoodenSupportSubType::neSw, WoodenSupportTransitionType::flatToUp60DegLongBaseSeq0 },
        .metalSupports = { MetalSupportPlace::centre, true },
        .blockedSegments = kFlatStraightBlockedSegments,
    };

    static constexpr SequenceDescriptor kFlatToUp60LongBaseSeq1 = {
        .clearance = { -32, 0, 0, 16, { 0b1111, 0 }, {} },
        .allowedWallEdges = 0b1010,
        .woodenSupports = { WoodenSupportSubType::neSw, WoodenSupportTransitionType::flatToUp60DegLongBaseSeq1 },
        .metalSupports = { MetalSupportPlace::centre, true },
        .blockedSegments = kFlatStraightBlockedSegments,
    };

    static constexpr SequenceDescriptor kFlatToUp60LongBaseSeq2 = {
        .clearance = { -64, 0, 16, 24, { 0b1111, 0 }, {} },
        .allowedWallEdges = 0b1010,
        .woodenSupports = { WoodenSupportSubType::neSw, WoodenSupportTransitionType::flatToUp60DegLongBaseSeq2 },
        .metalSupports = { MetalSupportPlace::centre, true },
        .blockedSegments = kFlatStraightBlockedSegments,
    };

    static constexpr SequenceDescriptor kFlatToUp60LongBaseSeq3 = {
        .clearance = { -96, 0, 40, 48, { 0b1111, 0 }, {} },
        .allowedWallEdges = 0b1010,
        .flags = { SequenceFlag::hasHeightMarker },
        .woodenSupports = { WoodenSupportSubType::neSw, WoodenSupportTransitionType::flatToUp60DegLongBaseSeq3 },
        .metalSupports = { MetalSupportPlace::centre, true },
        .blockedSegments = kFlatStraightBlockedSegments,
    };

    static constexpr SequenceDescriptor kUp60ToFlatLongBaseSeq0 = {
        .clearance = { 0, 0, 0, 48, { 0b1111, 0 }, {} },
        .allowedWallEdges = 0b1010,
        .flags = { SequenceFlag::hasHeightMarker },
        .woodenSupports = { WoodenSupportSubType::neSw, WoodenSupportTransitionType::up60DegToFlatLongBaseSeq0 },
        .metalSupports = { MetalSupportPlace::centre, true },
        .blockedSegments = kFlatStraightBlockedSegments,
    };

    static constexpr SequenceDescriptor kUp60ToFlatLongBaseSeq1 = {
        .clearance = { -32, 0, 40, 48, { 0b1111, 0 }, {} },
        .allowedWallEdges = 0b1010,
        .woodenSupports = { WoodenSupportSubType::neSw, WoodenSupportTransitionType::up60DegToFlatLongBaseSeq1 },
        .metalSupports = { MetalSupportPlace::centre, true },
        .blockedSegments = kFlatStraightBlockedSegments,
    };

    static constexpr SequenceDescriptor kUp60ToFlatLongBaseSeq2 = {
        .clearance = { -64, 0, 64, 24, { 0b1111, 0 }, {} },
        .allowedWallEdges = 0b1010,
        .woodenSupports = { WoodenSupportSubType::neSw, WoodenSupportTransitionType::up60DegToFlatLongBaseSeq2 },
        .metalSupports = { MetalSupportPlace::centre, true },
        .blockedSegments = kFlatStraightBlockedSegments,
    };

    static constexpr SequenceDescriptor kUp60ToFlatLongBaseSeq3 = {
        .clearance = { -96, 0, 80, 8, { 0b1111, 0 }, {} },
        .allowedWallEdges = 0b1010,
        .flags = { SequenceFlag::hasHeightMarker },
        .woodenSupports = { WoodenSupportSubType::neSw, WoodenSupportTransitionType::up60DegToFlatLongBaseSeq3 },
        .metalSupports = { MetalSupportPlace::centre, true },
        .blockedSegments = kFlatStraightBlockedSegments,
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

    constexpr auto kTEDFlatToUp60LongBase = TrackElementDescriptor{
        .coordinates = { 0, 0, 0, 88, -96, 0 },
        .pieceLength = 165,
        .curveChain = { TrackCurve::none, TrackCurve::none },
        .priceModifier = 376832,
        .mirrorElement = TrackElemType::flatToUp60LongBase,
        .flags = { TrackElementFlag::up },
        .definition = { TrackGroup::slopeSteepLong, TrackPitch::up60, TrackPitch::none, TrackRoll::none, TrackRoll::none, 0 },
        .verticalFactor = EvaluatorConst<160>,
        .sequenceData = { 4,
                          { kFlatToUp60LongBaseSeq0, kFlatToUp60LongBaseSeq1, kFlatToUp60LongBaseSeq2,
                            kFlatToUp60LongBaseSeq3 } },
    };

    constexpr auto kTEDUp60ToFlatLongBase = TrackElementDescriptor{
        .coordinates = { 0, 0, 0, 88, -96, 0 },
        .pieceLength = 165,
        .curveChain = { TrackCurve::none, TrackCurve::none },
        .priceModifier = 376832,
        .mirrorElement = TrackElemType::up60ToFlatLongBase,
        .flags = { TrackElementFlag::up, TrackElementFlag::startsAtHalfHeight },
        .definition = { TrackGroup::slopeSteepLong, TrackPitch::none, TrackPitch::up60, TrackRoll::none, TrackRoll::none, 0 },
        .verticalFactor = EvaluatorConst<-160>,
        .sequenceData = { 4,
                          { kUp60ToFlatLongBaseSeq0, kUp60ToFlatLongBaseSeq1, kUp60ToFlatLongBaseSeq2,
                            kUp60ToFlatLongBaseSeq3 } },
    };

    constexpr auto kTEDDown60ToFlatLongBase = TrackElementDescriptor{
        .coordinates = { 0, 0, 88, 0, -96, 0 },
        .pieceLength = 165,
        .curveChain = { TrackCurve::none, TrackCurve::none },
        .priceModifier = 376832,
        .mirrorElement = TrackElemType::down60ToFlatLongBase,
        .flags = { TrackElementFlag::down },
        .definition = { TrackGroup::slopeSteepLong, TrackPitch::none, TrackPitch::down60, TrackRoll::none, TrackRoll::none, 0 },
        .verticalFactor = EvaluatorConst<160>,
        .sequenceData = kTEDFlatToUp60LongBase.sequenceData.rotate(2).offset({ -96, 0, 0 }).reverse({ 3, 2, 1, 0 }),
    };

    constexpr auto kTEDFlatToDown60LongBase = TrackElementDescriptor{
        .coordinates = { 0, 0, 88, 0, -96, 0 },
        .pieceLength = 165,
        .curveChain = { TrackCurve::none, TrackCurve::none },
        .priceModifier = 376832,
        .mirrorElement = TrackElemType::flatToDown60LongBase,
        .flags = { TrackElementFlag::down, TrackElementFlag::startsAtHalfHeight },
        .definition = { TrackGroup::slopeSteepLong, TrackPitch::down60, TrackPitch::none, TrackRoll::none, TrackRoll::none, 0 },
        .verticalFactor = EvaluatorConst<-160>,
        .sequenceData = kTEDUp60ToFlatLongBase.sequenceData.rotate(2).offset({ -96, 0, 0 }).reverse({ 3, 2, 1, 0 }),
    };
} // namespace OpenRCT2::TrackMetadata
