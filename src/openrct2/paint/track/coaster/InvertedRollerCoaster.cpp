/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../../../SpriteIds.h"
#include "../../../ride/Track.h"
#include "../../../ride/TrackPaint.h"
#include "../../../world/tile_element/TrackElement.h"
#include "../../Paint.h"
#include "../../support/MetalSupports.h"
#include "../../track/Segment.h"

using namespace OpenRCT2;

namespace
{
    static constexpr TunnelGroup kTunnelGroup = TunnelGroup::Inverted;
    static constexpr uint8_t kSupportHeight = 44;

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void trackFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        if (trackElement.HasChain())
        {
            switch (direction)
            {
                case 0:
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex), { 0, 0, height + 29 },
                        { { 0, 6, height + 29 }, { 32, 20, 3 } });
                    break;
                case 1:
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 1), { 0, 0, height + 29 },
                        { { 0, 6, height + 29 }, { 32, 20, 3 } });
                    break;
            }
        }
        else
        {
            switch (direction)
            {
                case 0:
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                        { { 0, 6, height + 29 }, { 32, 20, 3 } });
                    break;
                case 1:
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                        { { 0, 6, height + 29 }, { 32, 20, 3 } });
                    break;
            }
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            MetalASupportsPaintSetup(
                session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);
        }

        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex>
    void trackStation(
        PaintSession& session, const Ride& ride, [[maybe_unused]] uint8_t trackSequence, const Direction direction,
        const int32_t height, const TrackElement& trackElement, const SupportType supportType)
    {
        static constexpr ImageIndex imageIds[4][2] = {
            { spriteIndex, SPR_STATION_INVERTED_BAR_C_SW_NE },
            { spriteIndex + 1, SPR_STATION_INVERTED_BAR_C_NW_SE },
            { spriteIndex, SPR_STATION_INVERTED_BAR_C_SW_NE },
            { spriteIndex + 1, SPR_STATION_INVERTED_BAR_C_NW_SE },
        };
        const bool stationDrawn = TrackPaintUtilDrawStationInverted(
            session, ride, direction, height, trackElement, STATION_VARIANT_TALL);
        PaintAddImageAsParentRotated(
            session, direction, session.TrackColours.WithIndex(imageIds[direction][0]), { 0, 0, height + 29 },
            { { 0, 6, height + 29 }, { 32, 20, 3 } });
        if (stationDrawn)
        {
            PaintAddImageAsChildRotated(
                session, direction, session.SupportColours.WithIndex(imageIds[direction][1]), { 0, 6, height + 29 },
                { { 0, 6, height + 29 }, { 32, 20, 3 } });
            DrawSupportsSideBySide(session, direction, height, session.SupportColours, supportType.metal);
        }
        TrackPaintUtilDrawStationTunnelTall(session, direction, height);
        PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void track25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        if (trackElement.HasChain())
        {
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex), { 0, 0, height + 29 },
                        { { 0, 6, height + 45 }, { 32, 20, 3 } });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 1), { 0, 0, height + 29 },
                        { { 0, 6, height + 45 }, { 32, 20, 3 } });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 2), { 0, 0, height + 29 },
                        { { 0, 6, height + 45 }, { 32, 20, 3 } });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 3), { 0, 0, height + 29 },
                        { { 0, 6, height + 45 }, { 32, 20, 3 } });
                    break;
            }
        }
        else
        {
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                        { { 0, 6, height + 45 }, { 32, 20, 3 } });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                        { { 0, 6, height + 45 }, { 32, 20, 3 } });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                        { { 0, 6, height + 45 }, { 32, 20, 3 } });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                        { { 0, 6, height + 45 }, { 32, 20, 3 } });
                    break;
            }
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 62, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 62, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 72);
    }

    template<ImageIndex spriteIndex>
    void track60DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 93 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 4, height + 11 }, { 32, 2, 81 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 4, height + 11 }, { 32, 2, 81 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 93 }, { 32, 20, 3 } });
                break;
        }
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 56, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 120);
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void trackFlatTo25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        if (trackElement.HasChain())
        {
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 1), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 2), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 3), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
            }
        }
        else
        {
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
            }
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 54, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 54, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 54, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 54, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 64);
    }

    template<ImageIndex spriteIndex>
    void track25DegUpTo60DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 61 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 10, height + 11 }, { 32, 10, 49 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 4, height + 11 }, { 32, 2, 49 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                    { { 0, 10, height + 11 }, { 32, 10, 49 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 4, height + 11 }, { 32, 2, 49 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                    { { 0, 6, height + 61 }, { 32, 20, 3 } });
                break;
        }
        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 24, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 88);
    }

    template<ImageIndex spriteIndex>
    void track60DegUpTo25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 61 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 10, height + 11 }, { 32, 10, 49 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 4, height + 11 }, { 32, 2, 49 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                    { { 0, 10, height + 11 }, { 32, 10, 49 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 4, height + 11 }, { 32, 2, 49 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                    { { 0, 6, height + 61 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 76, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 76, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 76, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 76, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 24, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 88);
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void track25DegUpToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        if (trackElement.HasChain())
        {
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 1), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 2), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 3), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
            }
        }
        else
        {
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                        { { 0, 6, height + 37 }, { 32, 20, 3 } });
                    break;
            }
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 52, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 52, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::FlatTo25Deg);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 56);
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void track25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track25DegUp<spriteIndex, chainSpriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void track60DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track60DegUp<spriteIndex>(session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void trackFlatTo25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track25DegUpToFlat<spriteIndex, chainSpriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void track25DegDownTo60DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track60DegUpTo25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void track60DegDownTo25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track25DegUpTo60DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void track25DegDownToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackFlatTo25DegUp<spriteIndex, chainSpriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn5(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 16), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 17), { 0, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 4:
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 5:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 18), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 19), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                switch (direction)
                {
                    case 2:
                        PaintUtilPushTunnelRight(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 3:
                        PaintUtilPushTunnelLeft(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn5(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftQuarterTurn5<spriteIndex>(
            session, ride, kMapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence], DirectionPrev(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackFlatToLeftBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session,
            PaintUtilRotateSegments(
                EnumsToFlags(
                    PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                    PaintSegment::bottomLeft, PaintSegment::bottomRight),
                direction),
            0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            MetalASupportsPaintSetup(
                session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);
        }

        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex>
    void trackFlatToRightBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session,
            PaintUtilRotateSegments(
                EnumsToFlags(
                    PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                    PaintSegment::bottomLeft),
                direction),
            0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            MetalASupportsPaintSetup(
                session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);
        }

        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBankToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session,
            PaintUtilRotateSegments(
                EnumsToFlags(
                    PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                    PaintSegment::bottomLeft, PaintSegment::bottomRight),
                direction),
            0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            MetalASupportsPaintSetup(
                session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);
        }

        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex>
    void trackRightBankToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session,
            PaintUtilRotateSegments(
                EnumsToFlags(
                    PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                    PaintSegment::bottomLeft),
                direction),
            0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            MetalASupportsPaintSetup(
                session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);
        }

        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex>
    void trackBankedLeftQuarterTurn5(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 16), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 17), { 0, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 4:
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 5:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 18), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 19), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                switch (direction)
                {
                    case 2:
                        PaintUtilPushTunnelRight(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 3:
                        PaintUtilPushTunnelLeft(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackBankedRightQuarterTurn5(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackBankedLeftQuarterTurn5<spriteIndex>(
            session, ride, kMapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence], DirectionPrev(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBankTo25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session,
            PaintUtilRotateSegments(
                EnumsToFlags(
                    PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                    PaintSegment::bottomLeft, PaintSegment::bottomRight),
                direction),
            0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 52, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 52, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 64);
    }

    template<ImageIndex spriteIndex>
    void trackRightBankTo25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session,
            PaintUtilRotateSegments(
                EnumsToFlags(
                    PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                    PaintSegment::bottomLeft),
                direction),
            0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 52, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 52, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 64);
    }

    template<ImageIndex spriteIndex>
    void track25DegUpToLeftBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session,
            PaintUtilRotateSegments(
                EnumsToFlags(
                    PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                    PaintSegment::bottomLeft, PaintSegment::bottomRight),
                direction),
            0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 52, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 52, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::FlatTo25Deg);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 56);
    }

    template<ImageIndex spriteIndex>
    void track25DegUpToRightBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session,
            PaintUtilRotateSegments(
                EnumsToFlags(
                    PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                    PaintSegment::bottomLeft),
                direction),
            0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 52, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 52, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::FlatTo25Deg);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 56);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBankTo25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track25DegUpToRightBank<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightBankTo25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track25DegUpToLeftBank<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void track25DegDownToLeftBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightBankTo25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void track25DegDownToRightBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftBankTo25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session,
            PaintUtilRotateSegments(
                EnumsToFlags(
                    PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                    PaintSegment::bottomLeft, PaintSegment::bottomRight),
                direction),
            0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            MetalASupportsPaintSetup(
                session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);
        }

        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex>
    void trackRightBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftBank<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn525DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 54, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 16, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 16), { 0, 16, height + 29 },
                            { 32, 16, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 16, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 16, 16, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 16, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 17), { 0, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 80);
                break;
            case 4:
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 5:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 16, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 18), { 16, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 19), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 54, session.SupportColours);

                switch (direction)
                {
                    case 2:
                        PaintUtilPushTunnelRight(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                    case 3:
                        PaintUtilPushTunnelLeft(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn525DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 54, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 16, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 16, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 16), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 16, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 16, 16, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 17), { 0, 16, height + 29 },
                            { 16, 16, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 80);
                break;
            case 4:
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 5:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 16, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 18), { 16, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 19), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 54, session.SupportColours);

                switch (direction)
                {
                    case 0:
                        PaintUtilPushTunnelRight(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                    case 1:
                        PaintUtilPushTunnelLeft(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn525DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightQuarterTurn525DegUp<spriteIndex>(
            session, ride, kMapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence], DirectionNext(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn525DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftQuarterTurn525DegUp<spriteIndex>(
            session, ride, kMapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence], DirectionPrev(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackSBendLeft(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                DrawSBendLeftSupports(session, supportType.metal, trackSequence, direction, height + kSupportHeight, 0, 0);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { 32, 26, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { 32, 26, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 26, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 26, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                DrawSBendLeftSupports(session, supportType.metal, trackSequence, direction, height + kSupportHeight, 0, 0);

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 26, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 26, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { 32, 26, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { 32, 26, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                DrawSBendLeftSupports(session, supportType.metal, trackSequence, direction, height + kSupportHeight, 0, 0);

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                DrawSBendLeftSupports(session, supportType.metal, trackSequence, direction, height + kSupportHeight, 0, 0);

                switch (direction)
                {
                    case 1:
                        PaintUtilPushTunnelRight(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 2:
                        PaintUtilPushTunnelLeft(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackSBendRight(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                DrawSBendRightSupports(session, supportType.metal, trackSequence, direction, height + kSupportHeight, 0, 0);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 26, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 26, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { 32, 26, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { 32, 26, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                DrawSBendRightSupports(session, supportType.metal, trackSequence, direction, height + kSupportHeight, 0, 0);

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { 32, 26, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { 32, 26, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 26, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 26, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                DrawSBendRightSupports(session, supportType.metal, trackSequence, direction, height + kSupportHeight, 0, 0);

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                DrawSBendRightSupports(session, supportType.metal, trackSequence, direction, height + kSupportHeight, 0, 0);

                switch (direction)
                {
                    case 1:
                        PaintUtilPushTunnelRight(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 2:
                        PaintUtilPushTunnelLeft(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftVerticalLoop(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 6, height + 29 },
                            { { 0, 6, height + 45 }, { 32, 10, 7 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::bottom, PaintSegment::centre,
                            PaintSegment::topLeft, PaintSegment::topRight, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 55,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 55,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 55,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 55, session.SupportColours);
                        break;
                }

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 14, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 63 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 6, height + 29 },
                            { { 0, 0, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 6, height + 29 },
                            { { 29, 20, height + 29 }, { 2, 2, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 16, 0, height + 29 },
                            { { 16, 29, height + 2 }, { 5, 2, 119 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 12, 0, height + 29 },
                            { { 0, -6, height + 2 }, { 32, 2, 119 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 10, 16, height + 29 },
                            { { 10, 0, height + 2 }, { 4, 2, 119 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 16, 16, height + 29 },
                            { { 29, 29, height + 2 }, { 2, 2, 119 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 168);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 0, height - 6 }, { 32, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 0, height - 6 }, { 2, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 16, height + 29 },
                            { { 0, 0, height - 6 }, { 32, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 16, height + 29 },
                            { { 0, 0, height - 6 }, { 2, 2, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 4:
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 5:
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 16, height + 29 },
                            { { 0, 0, height - 6 }, { 32, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 16, height + 29 },
                            { { 0, 0, height - 6 }, { 2, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 0, height - 6 }, { 32, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 0, height - 6 }, { 2, 2, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 7:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 10, 16, height + 29 },
                            { { 10, 0, height + 2 }, { 4, 2, 119 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 16, 16, height + 29 },
                            { { 29, 29, height + 2 }, { 2, 2, 119 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 16, 0, height + 29 },
                            { { 16, 29, height + 2 }, { 5, 2, 119 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 12, 0, height + 29 },
                            { { 0, -6, height + 2 }, { 32, 2, 119 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 168);
                break;
            case 8:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 6, height + 29 },
                            { { 0, 0, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 6, height + 29 },
                            { { 29, 20, height + 29 }, { 2, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 14, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 63 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 9:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 6, height + 29 },
                            { { 0, 6, height + 45 }, { 32, 10, 7 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::right, PaintSegment::bottom, PaintSegment::centre,
                            PaintSegment::topLeft, PaintSegment::topRight, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 55,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 55, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 55,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 55,
                            session.SupportColours);
                        break;
                }

                switch (direction)
                {
                    case 1:
                        PaintUtilPushTunnelRight(session, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                        break;
                    case 2:
                        PaintUtilPushTunnelLeft(session, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightVerticalLoop(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { { 0, 6, height + 45 }, { 32, 10, 7 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::right, PaintSegment::bottom, PaintSegment::centre,
                            PaintSegment::topLeft, PaintSegment::topRight, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 55,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 55,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 55,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 55, session.SupportColours);
                        break;
                }

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 6, height + 29 },
                            { { 29, 20, height + 29 }, { 2, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 6, height + 29 },
                            { { 0, 0, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 14, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 63 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 16, 16, height + 29 },
                            { { 29, 29, height + 2 }, { 2, 2, 119 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 10, 16, height + 29 },
                            { { 10, 0, height + 2 }, { 4, 2, 119 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 12, 0, height + 29 },
                            { { 0, -6, height + 2 }, { 32, 2, 119 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 16, 0, height + 29 },
                            { { 16, 29, height + 2 }, { 5, 2, 119 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 168);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 16, height + 29 },
                            { { 0, 0, height - 6 }, { 2, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 16, height + 29 },
                            { { 0, 0, height - 6 }, { 32, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 0, height - 6 }, { 2, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 0, 0, height - 6 }, { 32, 2, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 4:
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 5:
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 0, height - 6 }, { 2, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 0, 0, height - 6 }, { 32, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 16, height + 29 },
                            { { 0, 0, height - 6 }, { 2, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 16, height + 29 },
                            { { 0, 0, height - 6 }, { 32, 2, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 7:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 12, 0, height + 29 },
                            { { 0, -6, height + 2 }, { 32, 2, 119 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 16, 0, height + 29 },
                            { { 16, 29, height + 2 }, { 5, 2, 119 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 16, 16, height + 29 },
                            { { 29, 29, height + 2 }, { 2, 2, 119 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 10, 16, height + 29 },
                            { { 10, 0, height + 2 }, { 4, 2, 119 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 168);
                break;
            case 8:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 14, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 63 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 6, height + 29 },
                            { { 29, 20, height + 29 }, { 2, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 6, height + 29 },
                            { { 0, 0, height + 29 }, { 32, 2, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 9:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { { 0, 6, height + 45 }, { 32, 10, 7 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::right, PaintSegment::centre,
                            PaintSegment::topLeft, PaintSegment::topRight, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 55,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 55, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 55,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 55,
                            session.SupportColours);
                        break;
                }

                switch (direction)
                {
                    case 1:
                        PaintUtilPushTunnelRight(session, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                        break;
                    case 2:
                        PaintUtilPushTunnelLeft(session, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn3(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                switch (direction)
                {
                    case 2:
                        PaintUtilPushTunnelRight(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 3:
                        PaintUtilPushTunnelLeft(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn3(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftQuarterTurn3<spriteIndex>(
            session, ride, kMapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence], DirectionPrev(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn3Bank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 6, 0, height + 29 }, { 20, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                switch (direction)
                {
                    case 2:
                        PaintUtilPushTunnelRight(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 3:
                        PaintUtilPushTunnelLeft(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn3Bank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftQuarterTurn3Bank<spriteIndex>(
            session, ride, kMapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence], DirectionPrev(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn325DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 52, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 52, session.SupportColours);

                switch (direction)
                {
                    case 2:
                        PaintUtilPushTunnelRight(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                    case 3:
                        PaintUtilPushTunnelLeft(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn325DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 52, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 52, session.SupportColours);

                switch (direction)
                {
                    case 0:
                        PaintUtilPushTunnelRight(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                    case 1:
                        PaintUtilPushTunnelLeft(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn325DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightQuarterTurn325DegUp<spriteIndex>(
            session, ride, kMapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence], DirectionNext(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn325DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftQuarterTurn325DegUp<spriteIndex>(
            session, ride, kMapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence], DirectionPrev(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftTwistDownToUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 6, height + 29 },
                            { { 0, 6, height }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 6, height + 29 },
                            { { 0, 6, height }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 6, height + 29 },
                            { { 0, 6, height }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 6, height + 29 },
                            { { 0, 6, height }, { 32, 20, 3 } });
                        break;
                }
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height, session.SupportColours);
                switch (direction)
                {
                    case 1:
                        PaintUtilPushTunnelRight(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 2:
                        PaintUtilPushTunnelLeft(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightTwistDownToUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 6, height + 29 },
                            { { 0, 6, height }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 6, height + 29 },
                            { { 0, 6, height }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 6, height + 29 },
                            { { 0, 6, height }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 6, height + 29 },
                            { { 0, 6, height }, { 32, 20, 3 } });
                        break;
                }
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height, session.SupportColours);
                switch (direction)
                {
                    case 1:
                        PaintUtilPushTunnelRight(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 2:
                        PaintUtilPushTunnelLeft(session, height, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftTwistUpToDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftTwistDownToUp<spriteIndex>(
            session, ride, 2 - trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightTwistUpToDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightTwistDownToUp<spriteIndex>(
            session, ride, 2 - trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackHalfLoopUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { { 0, 6, height + 45 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { { 0, 6, height + 45 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 6, height + 29 },
                            { { 0, 6, height + 45 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 6, height + 29 },
                            { { 0, 6, height + 45 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 62,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 62,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 62,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 62, session.SupportColours);
                        break;
                }

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 14, height + 29 },
                            { { 0, 29, height + 29 }, { 32, 2, 63 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 6, height + 29 },
                            { { 0, 0, height + 29 }, { 32, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 6, height + 29 },
                            { { 29, 20, height + 29 }, { 2, 2, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 16, 0, height + 29 },
                            { { 16, 29, height + 2 }, { 5, 2, 119 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 12, 0, height + 29 },
                            { { 0, -6, height + 2 }, { 32, 2, 119 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 10, 16, height + 29 },
                            { { 10, 0, height + 2 }, { 4, 2, 119 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 16, 16, height + 29 },
                            { { 29, 29, height + 2 }, { 2, 2, 119 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 168);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 34 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 0, height - 6 }, { 2, 2, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 16, height + 29 },
                            { { 0, 0, height - 6 }, { 32, 2, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 16, height + 29 },
                            { { 0, 6, height + 34 }, { 32, 20, 3 } });
                        break;
                }
                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height + 32, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackHalfLoopDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackHalfLoopUp<spriteIndex>(session, ride, 3 - trackSequence, direction, height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftCorkscrewUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 33 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 33 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 6, height + 33 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 0, 6, height + 33 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::right, PaintSegment::bottom, PaintSegment::centre,
                            PaintSegment::topRight, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 50, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 6, 6, height + 24 }, { 20, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 6, 6, height + 24 }, { 20, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 6, 6, height + 24 }, { 20, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 6, 6, height + 24 }, { 20, 20, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 6, 0, height + 39 }, { 20, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 6, 0, height + 39 }, { 20, 32, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 6, 0, height + 39 }, { 20, 32, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 6, 0, height + 39 }, { 20, 32, 3 } });
                        break;
                }
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 28, session.SupportColours);
                switch (direction)
                {
                    case 2:
                        PaintUtilPushTunnelRight(session, height + 40, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 3:
                        PaintUtilPushTunnelLeft(session, height + 40, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::right, PaintSegment::bottom, PaintSegment::centre,
                            PaintSegment::topLeft, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightCorkscrewUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 33 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 33 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 6, height + 33 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 0, 6, height + 33 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::right, PaintSegment::centre,
                            PaintSegment::topLeft, PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 50, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 6, 6, height + 24 }, { 20, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 6, 6, height + 24 }, { 20, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 6, 6, height + 24 }, { 20, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 6, 6, height + 24 }, { 20, 20, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 6, 0, height + 39 }, { 20, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 6, 0, height + 39 }, { 20, 32, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 6, 0, height + 39 }, { 20, 32, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 6, 0, height + 39 }, { 20, 32, 3 } });
                        break;
                }
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 28, session.SupportColours);
                switch (direction)
                {
                    case 0:
                        PaintUtilPushTunnelRight(session, height + 40, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 1:
                        PaintUtilPushTunnelLeft(session, height + 40, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::right, PaintSegment::centre,
                            PaintSegment::topLeft, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftCorkscrewDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightCorkscrewUp<spriteIndex>(
            session, ride, 2 - trackSequence, DirectionNext(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightCorkscrewDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftCorkscrewUp<spriteIndex>(
            session, ride, 2 - trackSequence, DirectionPrev(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn160DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 2, 2, height }, { 28, 28, 3 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 2, 2, height + 99 }, { 28, 28, 1 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 2, 2, height }, { 28, 28, 3 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 2, 2, height + 99 }, { 28, 28, 1 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                    { { 2, 2, height }, { 28, 28, 3 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                    { { 2, 2, height + 99 }, { 28, 28, 1 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                    { { 2, 2, height }, { 28, 28, 3 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                    { { 2, 2, height + 99 }, { 28, 28, 1 } });
                break;
        }
        TrackPaintUtilLeftQuarterTurn1TileTunnel(
            session, kTunnelGroup, direction, height, -8, TunnelSubType::SlopeStart, +56, TunnelSubType::SlopeEnd);
        PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 104);
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn160DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 2, 2, height }, { 28, 28, 3 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 2, 2, height + 99 }, { 28, 28, 1 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 2, 2, height }, { 28, 28, 3 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 2, 2, height + 99 }, { 28, 28, 1 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                    { { 2, 2, height }, { 28, 28, 3 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                    { { 2, 2, height + 99 }, { 28, 28, 1 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                    { { 2, 2, height }, { 28, 28, 3 } });
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                    { { 2, 2, height + 99 }, { 28, 28, 1 } });
                break;
        }
        TrackPaintUtilRightQuarterTurn1TileTunnel(
            session, kTunnelGroup, direction, height, -8, TunnelSubType::SlopeStart, +56, TunnelSubType::SlopeEnd);
        PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 104);
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn160DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightQuarterTurn160DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionNext(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn160DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftQuarterTurn160DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionPrev(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackBrakes(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 1:
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            MetalASupportsPaintSetup(
                session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);
        }

        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterHelixLargeUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 35 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 6, height + 35 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 0, 6, height + 35 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 0, 6, height + 35 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 46, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 0, height + 43 }, { 32, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 0, height + 43 }, { 32, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 16, height + 43 }, { 32, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 16), { 0, 0, height + 29 },
                            { { 0, 16, height + 43 }, { 32, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 16, height + 43 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 16, 16, height + 43 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 0, height + 29 },
                            { { 16, 0, height + 43 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 17), { 0, 0, height + 29 },
                            { { 0, 0, height + 43 }, { 16, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 4:
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 5:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 16, 0, height + 43 }, { 16, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 0, 0, height + 43 }, { 16, 32, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { { 0, 0, height + 43 }, { 16, 32, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 18), { 0, 0, height + 29 },
                            { { 16, 0, height + 43 }, { 16, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 6, 0, height + 43 }, { 20, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 6, 0, height + 43 }, { 20, 32, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 0, 0, height + 29 },
                            { { 6, 0, height + 43 }, { 20, 32, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 19), { 0, 0, height + 29 },
                            { { 6, 0, height + 43 }, { 20, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 58, session.SupportColours);

                switch (direction)
                {
                    case 2:
                        PaintUtilPushTunnelRight(session, height + 16, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 3:
                        PaintUtilPushTunnelLeft(session, height + 16, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterHelixLargeUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 35 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 6, height + 35 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 0, 6, height + 35 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 0, 6, height + 35 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 46, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 16, height + 43 }, { 32, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 16, height + 43 }, { 32, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 0, height + 43 }, { 32, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 16), { 0, 0, height + 29 },
                            { { 0, 0, height + 43 }, { 32, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 0, height + 43 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 16, 0, height + 43 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 0, height + 29 },
                            { { 16, 16, height + 43 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 17), { 0, 0, height + 29 },
                            { { 0, 16, height + 43 }, { 16, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 4:
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 5:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 16, 0, height + 43 }, { 16, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 0, 0, height + 43 }, { 16, 32, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { { 0, 0, height + 43 }, { 16, 32, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 18), { 0, 0, height + 29 },
                            { { 16, 0, height + 43 }, { 16, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 6, 0, height + 43 }, { 20, 32, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 6, 0, height + 43 }, { 20, 32, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 0, 0, height + 29 },
                            { { 6, 0, height + 43 }, { 20, 32, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 19), { 0, 0, height + 29 },
                            { { 6, 0, height + 43 }, { 20, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 58, session.SupportColours);

                switch (direction)
                {
                    case 0:
                        PaintUtilPushTunnelRight(session, height + 16, kTunnelGroup, TunnelSubType::Flat);
                        break;
                    case 1:
                        PaintUtilPushTunnelLeft(session, height + 16, kTunnelGroup, TunnelSubType::Flat);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterHelixLargeDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightQuarterHelixLargeUp<spriteIndex>(
            session, ride, kMapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence], DirectionNext(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterHelixLargeDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftQuarterHelixLargeUp<spriteIndex>(
            session, ride, kMapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence], DirectionPrev(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void track25DegUpLeftBanked(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 62, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 62, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 72);
    }

    template<ImageIndex spriteIndex>
    void track25DegUpRightBanked(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 62, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 62, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 72);
    }

    template<ImageIndex spriteIndex>
    void trackOnRidePhoto(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        TrackPaintUtilOnridePhotoPlatformPaint(session, direction, height, supportType.metal);

        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
        }
        TrackPaintUtilOnridePhotoPaint2(session, direction, trackElement, height, kGeneralSupportHeightOnRidePhotoInverted);
    }

    template<ImageIndex spriteIndex>
    void track25DegDownLeftBanked(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track25DegUpRightBanked<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void track25DegDownRightBanked(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track25DegUpLeftBanked<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftEighthToDiag(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 32, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 34, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 4:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 18, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightEighthToDiag(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 34, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 32, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 4:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 18, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftEighthToOrthogonal(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightEighthToDiag<spriteIndex>(
            session, ride, mapLeftEighthTurnToOrthogonal[trackSequence], DirectionReverse(direction), height, trackElement,
            supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightEighthToOrthogonal(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftEighthToDiag<spriteIndex>(
            session, ride, mapLeftEighthTurnToOrthogonal[trackSequence], DirectionPrev(direction), height, trackElement,
            supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftEighthBankToDiag(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 32, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 34, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 4:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 18, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightEighthBankToDiag(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 32, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 34, 16, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 32, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 4, 4, height + 29 }, { 28, 28, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 4:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 16, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 0, height + 29 }, { 16, 16, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 16, height + 29 }, { 16, 18, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 16, 16, height + 29 }, { 16, 16, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftEighthBankToOrthogonal(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightEighthBankToDiag<spriteIndex>(
            session, ride, mapLeftEighthTurnToOrthogonal[trackSequence], DirectionReverse(direction), height, trackElement,
            supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightEighthBankToOrthogonal(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftEighthBankToDiag<spriteIndex>(
            session, ride, mapLeftEighthTurnToOrthogonal[trackSequence], DirectionPrev(direction), height, trackElement,
            supportType);
    }

    void trackDiagFlatBase(
        PaintSession& session, const uint8_t trackSequence, const ImageIndex* images, const Direction direction,
        const int32_t height, const SupportType supportType)
    {
        TrackPaintUtilDiagTilesPaint(
            session, 1, height + 29, direction, trackSequence, images, defaultDiagTileOffsets, defaultDiagBoundLengths,
            nullptr);

        int32_t blockedSegments = BlockedSegments::kDiagStraightFlat[trackSequence];
        PaintUtilSetSegmentSupportHeight(session, PaintUtilRotateSegments(blockedSegments, direction), 0xFFFF, 0);

        if (trackSequence == 3)
        {
            MetalASupportsPaintSetup(
                session, supportType.metal, kDiagSupportPlacement[direction], 0, height + kSupportHeight,
                session.SupportColours);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void trackDiagFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        static constexpr ImageIndex imageIndices[2][kNumOrthogonalDirections] = {
            { spriteIndex, spriteIndex + 1, spriteIndex + 2, spriteIndex + 3 },
            { chainSpriteIndex, chainSpriteIndex + 1, chainSpriteIndex + 2, chainSpriteIndex + 3 },
        };
        const auto* images = imageIndices[trackElement.HasChain()];
        trackDiagFlatBase(session, trackSequence, images, direction, height, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackDiagBrakes(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        static constexpr ImageIndex imageIndices[kNumOrthogonalDirections] = {
            spriteIndex,
            spriteIndex + 1,
            spriteIndex,
            spriteIndex + 1,
        };
        trackDiagFlatBase(session, trackSequence, imageIndices, direction, height, supportType);
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void trackDiag25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 3),
                                { -16, -16, height + 29 }, { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                                { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 1:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 2),
                                { -16, -16, height + 29 }, { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                                { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 3:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 1),
                                { -16, -16, height + 29 }, { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                                { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 56, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 56, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 56, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 56,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiag60DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 93 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 120);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 93 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 120);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 93 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 120);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 32, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 36, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 32, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 36, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 120);
                break;
        }
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void trackDiagFlatTo25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 3),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 1:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 2:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 2),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 3:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 1),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 48,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiag25DegUpTo60DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 16, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 16, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 16, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 16, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiag60DegUpTo25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { 0, 0, height + 61 }, { 16, 16, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 21, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 21, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 21, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 21, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void trackDiag25DegUpToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 3),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 1:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 2),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 3:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 1),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 50,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
        }
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void trackDiag25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 1),
                                { -16, -16, height + 29 }, { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                                { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 1:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 2),
                                { -16, -16, height + 29 }, { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                                { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 3:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 3),
                                { -16, -16, height + 29 }, { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                                { { -16, -16, height + 45 }, { 32, 32, 3 } });
                            break;
                    }
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 56, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 56, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 56, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 56,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiag60DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 120);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 93 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 120);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 93 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 120);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 93 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 24, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 28, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 24, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 28, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 120);
                break;
        }
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void trackDiagFlatTo25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 1),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                break;
            case 1:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 2),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                break;
            case 2:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                break;
            case 3:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 3),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 50,
                            session.SupportColours);
                        break;
                }
                break;
        }

        PaintUtilSetGeneralSupportHeight(session, height + 72);
    }

    template<ImageIndex spriteIndex>
    void trackDiag25DegDownTo60DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { 0, 0, height + 61 }, { 16, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 17, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 17, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 17, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 17, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiag60DegDownTo25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 61 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 8, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 8, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 8, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalBSupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 8, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex, ImageIndex chainSpriteIndex>
    void trackDiag25DegDownToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 1),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 3:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 1:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 2),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 0:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 2:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 2:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 3:
                if (trackElement.HasChain())
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(chainSpriteIndex + 3),
                                { -16, -16, height + 29 }, { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }
                else
                {
                    switch (direction)
                    {
                        case 1:
                            PaintAddImageAsParentRotated(
                                session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                                { { -16, -16, height + 37 }, { 32, 32, 3 } });
                            break;
                    }
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 48,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiagFlatToLeftBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiagFlatToRightBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiagLeftBankToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiagRightBankToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiagLeftBankTo25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 48,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiagRightBankTo25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 48,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiag25DegUpToLeftBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 50,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiag25DegUpToRightBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 50,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiagLeftBankTo25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 50,
                            session.SupportColours);
                        break;
                }
                break;
        }

        PaintUtilSetGeneralSupportHeight(session, height + 72);
    }

    template<ImageIndex spriteIndex>
    void trackDiagRightBankTo25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 50, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 50,
                            session.SupportColours);
                        break;
                }
                break;
        }

        PaintUtilSetGeneralSupportHeight(session, height + 72);
    }

    template<ImageIndex spriteIndex>
    void trackDiag25DegDownToLeftBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 48,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiag25DegDownToRightBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 37 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + 48, session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + 48,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 64);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiagLeftBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDiagRightBank(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 2:
                switch (direction)
                {
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
            case 3:
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { -16, -16, height + 29 },
                            { { -16, -16, height + 29 }, { 32, 32, 3 } });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                switch (direction)
                {
                    case 0:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::leftCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 1:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::topCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 2:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::rightCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                    case 3:
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::bottomCorner, 0, height + kSupportHeight,
                            session.SupportColours);
                        break;
                }

                PaintUtilSetGeneralSupportHeight(session, height + 48);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftLargeHalfLoopUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 21), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }
                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 56);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 9 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 22), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 8, 0, height + 40 }, { 24, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 0, 0, height }, { 32, 16, 0 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 16), { 0, 0, height + 29 },
                            { { 0, 16, height }, { 32, 16, 0 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 23), { 0, 0, height + 29 },
                            { { 30, 16, height + 70 }, { 2, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 24, 0, height + 29 }, { 8, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 0, 0, height }, { 32, 16, 0 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 17), { 0, 0, height + 29 },
                            { { 0, 16, height }, { 32, 16, 0 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 24), { 0, 0, height + 29 },
                            { { 30, 16, height + 100 }, { 2, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 224);
                break;
            case 4:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 30, 30, height + 80 }, { 2, 2, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 16, height }, { 16, 16, 0 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 18), { 0, 0, height + 29 },
                            { { 0, 0, height }, { 16, 16, 0 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 25), { 0, 0, height + 29 },
                            { { 30, 0, height + 90 }, { 2, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 128);
                break;
            case 5:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 30, 16, height }, { 2, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 0, height + 29 },
                            { { 0, 16, height }, { 32, 16, 0 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 19), { 0, 0, height + 29 },
                            { { 0, 0, height }, { 32, 16, 0 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 26), { 0, 0, height + 29 },
                            { { 30, 0, height + 140 }, { 2, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 224);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 16, height + 32 }, { 32, 16, 0 } });
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::centre, 27, height, session.SupportColours);
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { { 0, 16, height }, { 32, 16, 0 } });
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::centre, 27, height, session.SupportColours);
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 20), { 0, 0, height + 29 },
                            { { 0, 0, height }, { 32, 16, 0 } });
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::centre, 25, height, session.SupportColours);
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 27), { 0, 0, height + 29 },
                            { { 0, 0, height + 32 }, { 32, 16, 0 } });
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::centre, 27, height, session.SupportColours);
                        break;
                }
                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height + 32, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 40);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightLargeHalfLoopUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 21), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }
                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 56);
                break;
            case 1:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 19 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 22), { 0, 0, height + 29 },
                            { { 0, 6, height + 29 }, { 32, 20, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 16, height + 70 }, { 32, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 0, 0, height + 29 },
                            { { 0, 16, height }, { 32, 16, 0 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 16), { 0, 0, height + 29 },
                            { { 0, 0, height }, { 32, 16, 0 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 23), { 0, 0, height + 29 },
                            { { 0, 0, height + 70 }, { 32, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 16, height + 100 }, { 32, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 0, height + 29 },
                            { { 0, 16, height }, { 32, 16, 0 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 17), { 0, 0, height + 29 },
                            { { 0, 0, height }, { 32, 16, 0 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 24), { 0, 0, height + 29 },
                            { { 0, 0, height + 100 }, { 32, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 224);
                break;
            case 4:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 16, 0, height + 90 }, { 16, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { { 0, 0, height }, { 16, 16, 0 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 18), { 0, 0, height + 29 },
                            { { 0, 16, height }, { 16, 16, 0 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 25), { 0, 0, height + 29 },
                            { { 30, 16, height + 110 }, { 2, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 128);
                break;
            case 5:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 30, 0, height + 140 }, { 2, 16, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 0, 0, height + 29 },
                            { { 0, 0, height }, { 32, 16, 0 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 19), { 0, 0, height + 29 },
                            { { 0, 16, height }, { 32, 16, 0 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 26), { 0, 0, height + 29 },
                            { { 30, 16, height + 140 }, { 2, 16, 3 } });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 224);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 0, height + 32 }, { 32, 16, 0 } });
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::centre, 27, height, session.SupportColours);
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { { 0, 0, height }, { 32, 16, 0 } });
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::centre, 25, height, session.SupportColours);
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 20), { 0, 0, height + 29 },
                            { { 0, 16, height }, { 32, 16, 0 } });
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::centre, 27, height, session.SupportColours);
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 27), { 0, 0, height + 29 },
                            { { 0, 16, height + 32 }, { 32, 16, 0 } });
                        MetalASupportsPaintSetup(
                            session, supportType.metal, MetalSupportPlace::centre, 27, height, session.SupportColours);
                        break;
                }
                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height + 32, kTunnelGroup, TunnelSubType::Flat);
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 40);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftLargeHalfLoopDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightLargeHalfLoopUp<spriteIndex>(session, ride, 6 - trackSequence, direction, height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightLargeHalfLoopDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftLargeHalfLoopUp<spriteIndex>(session, ride, 6 - trackSequence, direction, height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackBlockBrakes(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
            case 1:
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 29 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            MetalASupportsPaintSetup(
                session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);
        }

        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBankedQuarterTurn325DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 52, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 52, session.SupportColours);

                switch (direction)
                {
                    case 2:
                        PaintUtilPushTunnelRight(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                    case 3:
                        PaintUtilPushTunnelLeft(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightBankedQuarterTurn325DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 52, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 2:
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 52, session.SupportColours);

                switch (direction)
                {
                    case 0:
                        PaintUtilPushTunnelRight(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                    case 1:
                        PaintUtilPushTunnelLeft(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftBankedQuarterTurn325DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightBankedQuarterTurn325DegUp<spriteIndex>(
            session, ride, kMapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence], DirectionNext(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightBankedQuarterTurn325DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftBankedQuarterTurn325DegUp<spriteIndex>(
            session, ride, kMapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence], DirectionPrev(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBankedQuarterTurn525DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomLeft,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 54, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 16, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 16), { 0, 16, height + 29 },
                            { 32, 16, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::top, PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::topRight, PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 16, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 16, 16, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 16, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 17), { 0, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topRight, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 80);
                break;
            case 4:
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 5:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 16, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 18), { 16, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 19), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 54, session.SupportColours);

                switch (direction)
                {
                    case 2:
                        PaintUtilPushTunnelRight(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                    case 3:
                        PaintUtilPushTunnelLeft(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightBankedQuarterTurn525DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 10), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 15), { 0, 6, height + 29 },
                            { 32, 20, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomLeft),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 54, session.SupportColours);

                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 1:
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 2:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 16, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 16, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 11), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 16), { 0, 0, height + 29 },
                            { 32, 16, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::right, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topRight,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 3:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 7), { 16, 0, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 12), { 16, 16, height + 29 },
                            { 16, 16, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 17), { 0, 16, height + 29 },
                            { 16, 16, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(PaintSegment::top, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 80);
                break;
            case 4:
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 5:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 16, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 8), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 13), { 0, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 18), { 16, 0, height + 29 },
                            { 16, 32, 3 });
                        break;
                }
                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::bottom, PaintSegment::centre, PaintSegment::topLeft,
                            PaintSegment::bottomLeft, PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
            case 6:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 9), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 14), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 19), { 6, 0, height + 29 },
                            { 20, 32, 3 });
                        break;
                }

                PaintUtilSetSegmentSupportHeight(
                    session,
                    PaintUtilRotateSegments(
                        EnumsToFlags(
                            PaintSegment::left, PaintSegment::centre, PaintSegment::topLeft, PaintSegment::topRight,
                            PaintSegment::bottomRight),
                        direction),
                    0xFFFF, 0);
                MetalASupportsPaintSetup(
                    session, supportType.metal, MetalSupportPlace::centre, 0, height + 54, session.SupportColours);

                switch (direction)
                {
                    case 0:
                        PaintUtilPushTunnelRight(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                    case 1:
                        PaintUtilPushTunnelLeft(session, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
                        break;
                }
                PaintUtilSetGeneralSupportHeight(session, height + 88);
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftBankedQuarterTurn525DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightBankedQuarterTurn525DegUp<spriteIndex>(
            session, ride, kMapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence], DirectionNext(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightBankedQuarterTurn525DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftBankedQuarterTurn525DegUp<spriteIndex>(
            session, ride, kMapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence], DirectionPrev(direction), height,
            trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void track25DegUpToLeftBanked25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 62, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 62, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 72);
    }

    template<ImageIndex spriteIndex>
    void track25DegUpToRightBanked25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 62, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 62, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 72);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBanked25DegUpTo25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 62, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 62, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 72);
    }

    template<ImageIndex spriteIndex>
    void trackRightBanked25DegUpTo25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 45 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 62, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 62, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 62, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 72);
    }

    template<ImageIndex spriteIndex>
    void track25DegDownToLeftBanked25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightBanked25DegUpTo25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void track25DegDownToRightBanked25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftBanked25DegUpTo25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBanked25DegDownTo25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track25DegUpToRightBanked25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightBanked25DegDownTo25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        track25DegUpToLeftBanked25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBankedFlatToLeftBanked25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 54, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 54, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 54, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 54, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 64);
    }

    template<ImageIndex spriteIndex>
    void trackRightBankedFlatToRightBanked25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 54, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 54, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 54, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 54, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 64);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBanked25DegUpToLeftBankedFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 52, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 52, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::FlatTo25Deg);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 56);
    }

    template<ImageIndex spriteIndex>
    void trackRightBanked25DegUpToRightBankedFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 52, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 52, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::FlatTo25Deg);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 56);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBankedFlatToLeftBanked25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightBanked25DegUpToRightBankedFlat<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightBankedFlatToRightBanked25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftBanked25DegUpToLeftBankedFlat<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBanked25DegDownToLeftBankedFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightBankedFlatToRightBanked25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightBanked25DegDownToRightBankedFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftBankedFlatToLeftBanked25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackFlatToLeftBanked25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 54, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 54, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 54, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 54, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 64);
    }

    template<ImageIndex spriteIndex>
    void trackFlatToRightBanked25DegUp(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 54, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 54, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 54, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 54, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::SlopeEnd);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 64);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBanked25DegUpToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 52, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 52, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::FlatTo25Deg);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 56);
    }

    template<ImageIndex spriteIndex>
    void trackRightBanked25DegUpToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 37 }, { 32, 20, 3 } });
                break;
        }

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            switch (direction)
            {
                case 0:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 1:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomRightSide, 0, height + 52, session.SupportColours);
                    break;
                case 2:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::bottomLeftSide, 0, height + 52, session.SupportColours);
                    break;
                case 3:
                    MetalASupportsPaintSetup(
                        session, supportType.metal, MetalSupportPlace::topLeftSide, 0, height + 52, session.SupportColours);
                    break;
            }
        }

        if (direction == 0 || direction == 3)
        {
            PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::Flat);
        }
        else
        {
            PaintUtilPushTunnelRotated(session, direction, height + 8, kTunnelGroup, TunnelSubType::FlatTo25Deg);
        }
        PaintUtilSetGeneralSupportHeight(session, height + 56);
    }

    template<ImageIndex spriteIndex>
    void trackFlatToLeftBanked25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightBanked25DegUpToFlat<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackFlatToRightBanked25DegDown(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftBanked25DegUpToFlat<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackLeftBanked25DegDownToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackFlatToRightBanked25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightBanked25DegDownToFlat(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackFlatToLeftBanked25DegUp<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackBooster(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        const auto imageId = (direction & 1) ? spriteIndex + 1 : spriteIndex;
        PaintAddImageAsParentRotated(
            session, direction, session.TrackColours.WithIndex(imageId), { 0, 0, height + 29 },
            { { 0, 6, height + 29 }, { 32, 20, 1 } });

        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        if (TrackPaintUtilShouldPaintSupports(session.MapPosition))
        {
            MetalASupportsPaintSetup(
                session, supportType.metal, MetalSupportPlace::centre, 0, height + kSupportHeight, session.SupportColours);
        }

        PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
        PaintUtilSetGeneralSupportHeight(session, height + 48);
    }

    template<ImageIndex spriteIndex>
    void trackUp90(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 61 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 4, height + 11 }, { 32, 2, 31 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 4, height + 11 }, { 32, 2, 31 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 61 }, { 32, 20, 3 } });
                        break;
                }
                PaintUtilSetVerticalTunnel(session, height + 32);
                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + kDefaultGeneralSupportHeight);
                break;
            case 1:
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDown90(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackUp90<spriteIndex>(session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackUp60ToUp90(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 85 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 4, height + 11 }, { 32, 2, 55 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 4, height + 11 }, { 32, 2, 55 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 85 }, { 32, 20, 3 } });
                        break;
                }
                if (direction == 0 || direction == 3)
                {
                    PaintUtilPushTunnelRotated(session, direction, height - 8, kTunnelGroup, TunnelSubType::SlopeStart);
                }
                PaintUtilSetVerticalTunnel(session, height + 56);
                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 72);
                break;
            case 1:
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackDown90ToDown60(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackUp60ToUp90<spriteIndex>(
            session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackUp90ToUp60(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (direction)
        {
            case 0:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                    { { 0, 6, height + 85 }, { 32, 20, 3 } });
                break;
            case 1:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                    { { 0, 4, height + 11 }, { 32, 2, 55 } });
                break;
            case 2:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                    { { 0, 4, height + 11 }, { 32, 2, 55 } });
                break;
            case 3:
                PaintAddImageAsParentRotated(
                    session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                    { { 0, 6, height + 85 }, { 32, 20, 3 } });
                break;
        }
        switch (direction)
        {
            case 1:
                PaintUtilPushTunnelRight(session, height + 48, kTunnelGroup, TunnelSubType::SlopeEnd);
                break;
            case 2:
                PaintUtilPushTunnelLeft(session, height + 48, kTunnelGroup, TunnelSubType::SlopeEnd);
                break;
        }
        PaintUtilSetSegmentSupportHeight(
            session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
        PaintUtilSetGeneralSupportHeight(session, height + 96);
    }

    template<ImageIndex spriteIndex>
    void trackDown60ToDown90(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        if (trackSequence == 0)
        {
            trackUp90ToUp60<spriteIndex>(
                session, ride, trackSequence, DirectionReverse(direction), height, trackElement, supportType);
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn1TileUp90(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 6, height + 125 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 4, 0, height + 11 }, { 2, 32, 31 } });
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 6, height + 125 }, { 32, 20, 3 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 6, height + 125 }, { 32, 20, 3 } });
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 4, height + 11 }, { 32, 2, 31 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 4, height + 11 }, { 32, 2, 31 } });
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 6, height + 125 }, { 32, 20, 3 } });
                        break;
                }
                PaintUtilSetVerticalTunnel(session, height + 96);
                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 96);
                break;
            case 1:
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn1TileUp90(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        switch (trackSequence)
        {
            case 0:
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex), { 0, 0, height + 29 },
                            { { 0, 4, height + 11 }, { 32, 2, 31 } });
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 1), { 0, 0, height + 29 },
                            { { 0, 6, height + 125 }, { 32, 20, 3 } });
                        break;
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 2), { 0, 0, height + 29 },
                            { { 0, 6, height + 125 }, { 32, 20, 3 } });
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 3), { 0, 0, height + 29 },
                            { { 0, 4, height + 11 }, { 32, 2, 31 } });
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 4), { 0, 0, height + 29 },
                            { { 0, 4, height + 11 }, { 32, 2, 31 } });
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 5), { 0, 0, height + 29 },
                            { { 0, 6, height + 125 }, { 32, 20, 3 } });
                        break;
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, session.TrackColours.WithIndex(spriteIndex + 6), { 0, 0, height + 29 },
                            { { 0, 6, height + 125 }, { 32, 20, 3 } });
                        break;
                }
                PaintUtilSetVerticalTunnel(session, height + 96);
                PaintUtilSetSegmentSupportHeight(
                    session, PaintUtilRotateSegments(BlockedSegments::kStraightFlat, direction), 0xFFFF, 0);
                PaintUtilSetGeneralSupportHeight(session, height + 96);
                break;
            case 1:
                break;
        }
    }

    template<ImageIndex spriteIndex>
    void trackLeftQuarterTurn1TileDown90(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackRightQuarterTurn1TileUp90<spriteIndex>(
            session, ride, trackSequence, DirectionNext(direction), height, trackElement, supportType);
    }

    template<ImageIndex spriteIndex>
    void trackRightQuarterTurn1TileDown90(
        PaintSession& session, const Ride& ride, const uint8_t trackSequence, const Direction direction, const int32_t height,
        const TrackElement& trackElement, const SupportType supportType)
    {
        trackLeftQuarterTurn1TileUp90<spriteIndex>(
            session, ride, trackSequence, DirectionPrev(direction), height, trackElement, supportType);
    }

    // clang-format off
    constexpr std::array<std::remove_reference<TrackPaintFunction>::type*, EnumValue(TrackElemType::count)> paintFunctions =
        []() {
        using enum TrackElemType;
        std::array<std::remove_reference<TrackPaintFunction>::type*, EnumValue(TrackElemType::count)> fns{};
        fns.fill(TrackPaintFunctionDummy);
        fns[EnumValue(flat)] = trackFlat<SPR_TRACKS_BM_INVERT_FLAT, SPR_TRACKS_BM_INVERT_FLAT>; // needs chain sprite
        fns[EnumValue(endStation)] = trackStation<SPR_TRACKS_BM_INVERT_FLAT>; // needs sprite
        fns[EnumValue(beginStation)] = trackStation<SPR_TRACKS_BM_INVERT_FLAT>; // needs sprite
        fns[EnumValue(middleStation)] = trackStation<SPR_TRACKS_BM_INVERT_FLAT>; // needs sprite
        fns[EnumValue(up25)] = track25DegUp<SPR_TRACKS_BM_INVERT_GENTLE, SPR_TRACKS_BM_INVERT_GENTLE>;
        fns[EnumValue(up60)] = track60DegUp<SPR_TRACKS_BM_INVERT_STEEP>;
        fns[EnumValue(flatToUp25)] = trackFlatTo25DegUp<SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE, SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE>; // needs chain sprite
        fns[EnumValue(up25ToUp60)] = track25DegUpTo60DegUp<SPR_TRACKS_BM_INVERT_GENTLE_TO_STEEP>;
        fns[EnumValue(up60ToUp25)] = track60DegUpTo25DegUp<SPR_TRACKS_BM_INVERT_STEEP_TO_GENTLE>;
        fns[EnumValue(up25ToFlat)] = track25DegUpToFlat<SPR_TRACKS_BM_INVERT_GENTLE_TO_FLAT, SPR_TRACKS_BM_INVERT_GENTLE_TO_FLAT>; // needs chain sprite
        fns[EnumValue(down25)] = track25DegDown<SPR_TRACKS_BM_INVERT_GENTLE, SPR_TRACKS_BM_INVERT_GENTLE>;
        fns[EnumValue(down60)] = track60DegDown<SPR_TRACKS_BM_INVERT_STEEP>;
        fns[EnumValue(flatToDown25)] = trackFlatTo25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_TO_FLAT, SPR_TRACKS_BM_INVERT_GENTLE_TO_FLAT>; // needs chain sprite
        fns[EnumValue(down25ToDown60)] = track25DegDownTo60DegDown<SPR_TRACKS_BM_INVERT_STEEP_TO_GENTLE>;
        fns[EnumValue(down60ToDown25)] = track60DegDownTo25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_TO_STEEP>;
        fns[EnumValue(down25ToFlat)] = track25DegDownToFlat<SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE, SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE>; // needs chain sprite
        fns[EnumValue(leftQuarterTurn5Tiles)] = trackLeftQuarterTurn5<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_LEFT>;
        fns[EnumValue(rightQuarterTurn5Tiles)] = trackRightQuarterTurn5<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_LEFT>;
        fns[EnumValue(flatToLeftBank)] = trackFlatToLeftBank<SPR_TRACKS_BM_INVERT_FLAT_TO_LEFT_BANK>;
        fns[EnumValue(flatToRightBank)] = trackFlatToRightBank<SPR_TRACKS_BM_INVERT_FLAT_TO_RIGHT_BANK>;
        fns[EnumValue(leftBankToFlat)] = trackLeftBankToFlat<SPR_TRACKS_BM_INVERT_FLAT_TO_RIGHT_BANK>;
        fns[EnumValue(rightBankToFlat)] = trackRightBankToFlat<SPR_TRACKS_BM_INVERT_FLAT_TO_LEFT_BANK>;
        fns[EnumValue(bankedLeftQuarterTurn5Tiles)] = trackBankedLeftQuarterTurn5<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_LEFT_BANK>;
        fns[EnumValue(bankedRightQuarterTurn5Tiles)] = trackBankedRightQuarterTurn5<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_LEFT_BANK>;
        fns[EnumValue(leftBankToUp25)] = trackLeftBankTo25DegUp<SPR_TRACKS_BM_INVERT_LEFT_BANK_TO_GENTLE>;
        fns[EnumValue(rightBankToUp25)] = trackRightBankTo25DegUp<SPR_TRACKS_BM_INVERT_RIGHT_BANK_TO_GENTLE>;
        fns[EnumValue(up25ToLeftBank)] = track25DegUpToLeftBank<SPR_TRACKS_BM_INVERT_GENTLE_TO_LEFT_BANK>;
        fns[EnumValue(up25ToRightBank)] = track25DegUpToRightBank<SPR_TRACKS_BM_INVERT_GENTLE_TO_RIGHT_BANK>;
        fns[EnumValue(leftBankToDown25)] = trackLeftBankTo25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_TO_RIGHT_BANK>;
        fns[EnumValue(rightBankToDown25)] = trackRightBankTo25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_TO_LEFT_BANK>;
        fns[EnumValue(down25ToLeftBank)] = track25DegDownToLeftBank<SPR_TRACKS_BM_INVERT_RIGHT_BANK_TO_GENTLE>;
        fns[EnumValue(down25ToRightBank)] = track25DegDownToRightBank<SPR_TRACKS_BM_INVERT_LEFT_BANK_TO_GENTLE>;
        fns[EnumValue(leftBank)] = trackLeftBank<SPR_TRACKS_BM_INVERT_LEFT_BANK>;
        fns[EnumValue(rightBank)] = trackRightBank<SPR_TRACKS_BM_INVERT_LEFT_BANK>;
        fns[EnumValue(leftQuarterTurn5TilesUp25)] = trackLeftQuarterTurn525DegUp<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_LEFT_GENTLE>;
        fns[EnumValue(rightQuarterTurn5TilesUp25)] = trackRightQuarterTurn525DegUp<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_RIGHT_GENTLE>;
        fns[EnumValue(leftQuarterTurn5TilesDown25)] = trackLeftQuarterTurn525DegDown<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_RIGHT_GENTLE>;
        fns[EnumValue(rightQuarterTurn5TilesDown25)] = trackRightQuarterTurn525DegDown<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_LEFT_GENTLE>;
        fns[EnumValue(sBendLeft)] = trackSBendLeft<SPR_TRACKS_BM_INVERT_S_BEND_LEFT>;
        fns[EnumValue(sBendRight)] = trackSBendRight<SPR_TRACKS_BM_INVERT_S_BEND_RIGHT>;
        fns[EnumValue(leftVerticalLoop)] = trackLeftVerticalLoop<SPR_TRACKS_BM_INVERT_VERTICAL_LOOP_LEFT>;
        fns[EnumValue(rightVerticalLoop)] = trackRightVerticalLoop<SPR_TRACKS_BM_INVERT_VERTICAL_LOOP_RIGHT>;
        fns[EnumValue(leftQuarterTurn3Tiles)] = trackLeftQuarterTurn3<SPR_TRACKS_BM_INVERT_SMALL_TURN_LEFT>;
        fns[EnumValue(rightQuarterTurn3Tiles)] = trackRightQuarterTurn3<SPR_TRACKS_BM_INVERT_SMALL_TURN_LEFT>;
        fns[EnumValue(leftBankedQuarterTurn3Tiles)] = trackLeftQuarterTurn3Bank<SPR_TRACKS_BM_INVERT_SMALL_TURN_LEFT_BANK>;
        fns[EnumValue(rightBankedQuarterTurn3Tiles)] = trackRightQuarterTurn3Bank<SPR_TRACKS_BM_INVERT_SMALL_TURN_LEFT_BANK>;
        fns[EnumValue(leftQuarterTurn3TilesUp25)] = trackLeftQuarterTurn325DegUp<SPR_TRACKS_BM_INVERT_SMALL_TURN_LEFT_GENTLE>;
        fns[EnumValue(rightQuarterTurn3TilesUp25)] = trackRightQuarterTurn325DegUp<SPR_TRACKS_BM_INVERT_SMALL_TURN_RIGHT_GENTLE>;
        fns[EnumValue(leftQuarterTurn3TilesDown25)] = trackLeftQuarterTurn325DegDown<SPR_TRACKS_BM_INVERT_SMALL_TURN_RIGHT_GENTLE>;
        fns[EnumValue(rightQuarterTurn3TilesDown25)] = trackRightQuarterTurn325DegDown<SPR_TRACKS_BM_INVERT_SMALL_TURN_LEFT_GENTLE>;
        fns[EnumValue(leftTwistDownToUp)] = trackLeftTwistDownToUp<SPR_TRACKS_BM_INVERT_INLINE_TWIST_LEFT>;
        fns[EnumValue(rightTwistDownToUp)] = trackRightTwistDownToUp<SPR_TRACKS_BM_INVERT_INLINE_TWIST_RIGHT>;
        fns[EnumValue(leftTwistUpToDown)] = trackLeftTwistUpToDown<SPR_TRACKS_BM_INVERT_INLINE_TWIST_LEFT>;
        fns[EnumValue(rightTwistUpToDown)] = trackRightTwistUpToDown<SPR_TRACKS_BM_INVERT_INLINE_TWIST_RIGHT>;
        fns[EnumValue(halfLoopUp)] = trackHalfLoopUp<SPR_TRACKS_BM_INVERT_HALF_LOOP>;
        fns[EnumValue(halfLoopDown)] = trackHalfLoopDown<SPR_TRACKS_BM_INVERT_HALF_LOOP>;
        fns[EnumValue(leftCorkscrewUp)] = trackLeftCorkscrewUp<SPR_TRACKS_BM_INVERT_CORKSCREW_LEFT>;
        fns[EnumValue(rightCorkscrewUp)] = trackRightCorkscrewUp<SPR_TRACKS_BM_INVERT_CORKSCREW_RIGHT>;
        fns[EnumValue(leftCorkscrewDown)] = trackLeftCorkscrewDown<SPR_TRACKS_BM_INVERT_CORKSCREW_RIGHT>;
        fns[EnumValue(rightCorkscrewDown)] = trackRightCorkscrewDown<SPR_TRACKS_BM_INVERT_CORKSCREW_LEFT>;
        fns[EnumValue(leftQuarterTurn1TileUp60)] = trackLeftQuarterTurn160DegUp<SPR_TRACKS_BM_INVERT_VERY_SMALL_TURN_LEFT_STEEP>;
        fns[EnumValue(rightQuarterTurn1TileUp60)] = trackRightQuarterTurn160DegUp<SPR_TRACKS_BM_INVERT_VERY_SMALL_TURN_RIGHT_STEEP>;
        fns[EnumValue(leftQuarterTurn1TileDown60)] = trackLeftQuarterTurn160DegDown<SPR_TRACKS_BM_INVERT_VERY_SMALL_TURN_RIGHT_STEEP>;
        fns[EnumValue(rightQuarterTurn1TileDown60)] = trackRightQuarterTurn160DegDown<SPR_TRACKS_BM_INVERT_VERY_SMALL_TURN_LEFT_STEEP>;
        fns[EnumValue(brakes)] = trackBrakes<SPR_TRACKS_BM_INVERT_FLAT>; // needs sprite
        fns[EnumValue(leftQuarterBankedHelixLargeUp)] = trackLeftQuarterHelixLargeUp<SPR_TRACKS_BM_INVERT_MEDIUM_QUARTER_HELIX_LEFT_BANK>;
        fns[EnumValue(rightQuarterBankedHelixLargeUp)] = trackRightQuarterHelixLargeUp<SPR_TRACKS_BM_INVERT_MEDIUM_QUARTER_HELIX_RIGHT_BANK>;
        fns[EnumValue(leftQuarterBankedHelixLargeDown)] = trackLeftQuarterHelixLargeDown<SPR_TRACKS_BM_INVERT_MEDIUM_QUARTER_HELIX_RIGHT_BANK>;
        fns[EnumValue(rightQuarterBankedHelixLargeDown)] = trackRightQuarterHelixLargeDown<SPR_TRACKS_BM_INVERT_MEDIUM_QUARTER_HELIX_LEFT_BANK>;
        fns[EnumValue(leftQuarterHelixLargeUp)] = trackLeftQuarterHelixLargeUp<SPR_TRACKS_BM_INVERT_MEDIUM_QUARTER_HELIX_LEFT>;
        fns[EnumValue(rightQuarterHelixLargeUp)] = trackRightQuarterHelixLargeUp<SPR_TRACKS_BM_INVERT_MEDIUM_QUARTER_HELIX_RIGHT>;
        fns[EnumValue(leftQuarterHelixLargeDown)] = trackLeftQuarterHelixLargeDown<SPR_TRACKS_BM_INVERT_MEDIUM_QUARTER_HELIX_RIGHT>;
        fns[EnumValue(rightQuarterHelixLargeDown)] = trackRightQuarterHelixLargeDown<SPR_TRACKS_BM_INVERT_MEDIUM_QUARTER_HELIX_LEFT>;
        fns[EnumValue(up25LeftBanked)] = track25DegUpLeftBanked<SPR_TRACKS_BM_INVERT_GENTLE_LEFT_BANK>;
        fns[EnumValue(up25RightBanked)] = track25DegUpRightBanked<SPR_TRACKS_BM_INVERT_GENTLE_RIGHT_BANK>;
        fns[EnumValue(onRidePhoto)] = trackOnRidePhoto<SPR_TRACKS_BM_INVERT_FLAT>;
        fns[EnumValue(down25LeftBanked)] = track25DegDownLeftBanked<SPR_TRACKS_BM_INVERT_GENTLE_RIGHT_BANK>;
        fns[EnumValue(down25RightBanked)] = track25DegDownRightBanked<SPR_TRACKS_BM_INVERT_GENTLE_LEFT_BANK>;
        fns[EnumValue(leftEighthToDiag)] = trackLeftEighthToDiag<SPR_TRACKS_BM_INVERT_LARGE_TURN_LEFT>;
        fns[EnumValue(rightEighthToDiag)] = trackRightEighthToDiag<SPR_TRACKS_BM_INVERT_LARGE_TURN_RIGHT>;
        fns[EnumValue(leftEighthToOrthogonal)] = trackLeftEighthToOrthogonal<SPR_TRACKS_BM_INVERT_LARGE_TURN_RIGHT>;
        fns[EnumValue(rightEighthToOrthogonal)] = trackRightEighthToOrthogonal<SPR_TRACKS_BM_INVERT_LARGE_TURN_LEFT>;
        fns[EnumValue(leftEighthBankToDiag)] = trackLeftEighthBankToDiag<SPR_TRACKS_BM_INVERT_LARGE_TURN_LEFT_TO_DIAG_BANK>;
        fns[EnumValue(rightEighthBankToDiag)] = trackRightEighthBankToDiag<SPR_TRACKS_BM_INVERT_LARGE_TURN_RIGHT_TO_DIAG_BANK>;
        fns[EnumValue(leftEighthBankToOrthogonal)] = trackLeftEighthBankToOrthogonal<SPR_TRACKS_BM_INVERT_LARGE_TURN_RIGHT_TO_DIAG_BANK>;
        fns[EnumValue(rightEighthBankToOrthogonal)] = trackRightEighthBankToOrthogonal<SPR_TRACKS_BM_INVERT_LARGE_TURN_LEFT_TO_DIAG_BANK>;
        fns[EnumValue(diagFlat)] = trackDiagFlat<SPR_TRACKS_BM_INVERT_FLAT_DIAG, SPR_TRACKS_BM_INVERT_FLAT_DIAG>;
        fns[EnumValue(diagUp25)] = trackDiag25DegUp<SPR_TRACKS_BM_INVERT_GENTLE_DIAG, SPR_TRACKS_BM_INVERT_GENTLE_DIAG>; // needs chain sprite
        fns[EnumValue(diagUp60)] = trackDiag60DegUp<SPR_TRACKS_BM_INVERT_STEEP_DIAG>;
        fns[EnumValue(diagFlatToUp25)] = trackDiagFlatTo25DegUp<SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE_DIAG, SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE_DIAG>; // needs chain sprite
        fns[EnumValue(diagUp25ToUp60)] = trackDiag25DegUpTo60DegUp<SPR_TRACKS_BM_INVERT_GENTLE_TO_STEEP_DIAG>;
        fns[EnumValue(diagUp60ToUp25)] = trackDiag60DegUpTo25DegUp<SPR_TRACKS_BM_INVERT_STEEP_TO_GENTLE_DIAG>;
        fns[EnumValue(diagUp25ToFlat)] = trackDiag25DegUpToFlat<SPR_TRACKS_BM_INVERT_GENTLE_TO_FLAT_DIAG, SPR_TRACKS_BM_INVERT_GENTLE_TO_FLAT_DIAG>; // needs chain sprite
        fns[EnumValue(diagDown25)] = trackDiag25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_DIAG, SPR_TRACKS_BM_INVERT_GENTLE_DIAG>; // needs chain sprite
        fns[EnumValue(diagDown60)] = trackDiag60DegDown<SPR_TRACKS_BM_INVERT_STEEP_DIAG>;
        fns[EnumValue(diagFlatToDown25)] = trackDiagFlatTo25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_TO_FLAT_DIAG, SPR_TRACKS_BM_INVERT_GENTLE_TO_FLAT_DIAG>; // needs chain sprite
        fns[EnumValue(diagDown25ToDown60)] = trackDiag25DegDownTo60DegDown<SPR_TRACKS_BM_INVERT_STEEP_TO_GENTLE_DIAG>;
        fns[EnumValue(diagDown60ToDown25)] = trackDiag60DegDownTo25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_TO_STEEP_DIAG>;
        fns[EnumValue(diagDown25ToFlat)] = trackDiag25DegDownToFlat<SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE_DIAG, SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE_DIAG>; // needs chain sprite
        fns[EnumValue(diagFlatToLeftBank)] = trackDiagFlatToLeftBank<SPR_TRACKS_BM_INVERT_FLAT_TO_LEFT_BANK_DIAG>;
        fns[EnumValue(diagFlatToRightBank)] = trackDiagFlatToRightBank<SPR_TRACKS_BM_INVERT_FLAT_TO_RIGHT_BANK_DIAG>;
        fns[EnumValue(diagLeftBankToFlat)] = trackDiagLeftBankToFlat<SPR_TRACKS_BM_INVERT_FLAT_TO_RIGHT_BANK_DIAG>;
        fns[EnumValue(diagRightBankToFlat)] = trackDiagRightBankToFlat<SPR_TRACKS_BM_INVERT_FLAT_TO_LEFT_BANK_DIAG>;
        fns[EnumValue(diagLeftBankToUp25)] = trackDiagLeftBankTo25DegUp<SPR_TRACKS_BM_INVERT_LEFT_BANK_TO_GENTLE_DIAG>;
        fns[EnumValue(diagRightBankToUp25)] = trackDiagRightBankTo25DegUp<SPR_TRACKS_BM_INVERT_RIGHT_BANK_TO_GENTLE_DIAG>;
        fns[EnumValue(diagUp25ToLeftBank)] = trackDiag25DegUpToLeftBank<SPR_TRACKS_BM_INVERT_GENTLE_TO_LEFT_BANK_DIAG>;
        fns[EnumValue(diagUp25ToRightBank)] = trackDiag25DegUpToRightBank<SPR_TRACKS_BM_INVERT_GENTLE_TO_RIGHT_BANK_DIAG>;
        fns[EnumValue(diagLeftBankToDown25)] = trackDiagLeftBankTo25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_TO_RIGHT_BANK_DIAG>;
        fns[EnumValue(diagRightBankToDown25)] = trackDiagRightBankTo25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_TO_LEFT_BANK_DIAG>;
        fns[EnumValue(diagDown25ToLeftBank)] = trackDiag25DegDownToLeftBank<SPR_TRACKS_BM_INVERT_RIGHT_BANK_TO_GENTLE_DIAG>;
        fns[EnumValue(diagDown25ToRightBank)] = trackDiag25DegDownToRightBank<SPR_TRACKS_BM_INVERT_LEFT_BANK_TO_GENTLE_DIAG>;
        fns[EnumValue(diagLeftBank)] = trackDiagLeftBank<SPR_TRACKS_BM_INVERT_LEFT_BANK_DIAG>;
        fns[EnumValue(diagRightBank)] = trackDiagRightBank<SPR_TRACKS_BM_INVERT_LEFT_BANK_DIAG>;
        fns[EnumValue(leftLargeHalfLoopUp)] = trackLeftLargeHalfLoopUp<SPR_TRACKS_BM_INVERT_LARGE_HALF_LOOP_LEFT>;
        fns[EnumValue(rightLargeHalfLoopUp)] = trackRightLargeHalfLoopUp<SPR_TRACKS_BM_INVERT_LARGE_HALF_LOOP_RIGHT>;
        fns[EnumValue(leftLargeHalfLoopDown)] = trackLeftLargeHalfLoopDown<SPR_TRACKS_BM_INVERT_LARGE_HALF_LOOP_RIGHT>;
        fns[EnumValue(rightLargeHalfLoopDown)] = trackRightLargeHalfLoopDown<SPR_TRACKS_BM_INVERT_LARGE_HALF_LOOP_LEFT>;
        fns[EnumValue(blockBrakes)] = trackBlockBrakes<SPR_TRACKS_BM_INVERT_FLAT>; // needs sprite
        fns[EnumValue(leftBankedQuarterTurn3TileUp25)] = trackLeftBankedQuarterTurn325DegUp<SPR_TRACKS_BM_INVERT_SMALL_TURN_LEFT_BANK_GENTLE>;
        fns[EnumValue(rightBankedQuarterTurn3TileUp25)] = trackRightBankedQuarterTurn325DegUp<SPR_TRACKS_BM_INVERT_SMALL_TURN_RIGHT_BANK_GENTLE>;
        fns[EnumValue(leftBankedQuarterTurn3TileDown25)] = trackLeftBankedQuarterTurn325DegDown<SPR_TRACKS_BM_INVERT_SMALL_TURN_RIGHT_BANK_GENTLE>;
        fns[EnumValue(rightBankedQuarterTurn3TileDown25)] = trackRightBankedQuarterTurn325DegDown<SPR_TRACKS_BM_INVERT_SMALL_TURN_LEFT_BANK_GENTLE>;
        fns[EnumValue(leftBankedQuarterTurn5TileUp25)] = trackLeftBankedQuarterTurn525DegUp<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_LEFT_BANK_GENTLE>;
        fns[EnumValue(rightBankedQuarterTurn5TileUp25)] = trackRightBankedQuarterTurn525DegUp<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_RIGHT_BANK_GENTLE>;
        fns[EnumValue(leftBankedQuarterTurn5TileDown25)] = trackLeftBankedQuarterTurn525DegDown<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_RIGHT_BANK_GENTLE>;
        fns[EnumValue(rightBankedQuarterTurn5TileDown25)] = trackRightBankedQuarterTurn525DegDown<SPR_TRACKS_BM_INVERT_MEDIUM_TURN_LEFT_BANK_GENTLE>;
        fns[EnumValue(up25ToLeftBankedUp25)] = track25DegUpToLeftBanked25DegUp<SPR_TRACKS_BM_INVERT_GENTLE_TO_GENTLE_LEFT_BANK>;
        fns[EnumValue(up25ToRightBankedUp25)] = track25DegUpToRightBanked25DegUp<SPR_TRACKS_BM_INVERT_GENTLE_TO_GENTLE_RIGHT_BANK>;
        fns[EnumValue(leftBankedUp25ToUp25)] = trackLeftBanked25DegUpTo25DegUp<SPR_TRACKS_BM_INVERT_GENTLE_LEFT_BANK_TO_GENTLE>;
        fns[EnumValue(rightBankedUp25ToUp25)] = trackRightBanked25DegUpTo25DegUp<SPR_TRACKS_BM_INVERT_GENTLE_RIGHT_BANK_TO_GENTLE>;
        fns[EnumValue(down25ToLeftBankedDown25)] = track25DegDownToLeftBanked25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_RIGHT_BANK_TO_GENTLE>;
        fns[EnumValue(down25ToRightBankedDown25)] = track25DegDownToRightBanked25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_LEFT_BANK_TO_GENTLE>;
        fns[EnumValue(leftBankedDown25ToDown25)] = trackLeftBanked25DegDownTo25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_TO_GENTLE_RIGHT_BANK>;
        fns[EnumValue(rightBankedDown25ToDown25)] = trackRightBanked25DegDownTo25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_TO_GENTLE_LEFT_BANK>;
        fns[EnumValue(leftBankedFlatToLeftBankedUp25)] = trackLeftBankedFlatToLeftBanked25DegUp<SPR_TRACKS_BM_INVERT_LEFT_BANK_TO_GENTLE_LEFT_BANK>;
        fns[EnumValue(rightBankedFlatToRightBankedUp25)] = trackRightBankedFlatToRightBanked25DegUp<SPR_TRACKS_BM_INVERT_RIGHT_BANK_TO_GENTLE_RIGHT_BANK>;
        fns[EnumValue(leftBankedUp25ToLeftBankedFlat)] = trackLeftBanked25DegUpToLeftBankedFlat<SPR_TRACKS_BM_INVERT_GENTLE_LEFT_BANK_TO_LEFT_BANK>;
        fns[EnumValue(rightBankedUp25ToRightBankedFlat)] = trackRightBanked25DegUpToRightBankedFlat<SPR_TRACKS_BM_INVERT_GENTLE_RIGHT_BANK_TO_RIGHT_BANK>;
        fns[EnumValue(leftBankedFlatToLeftBankedDown25)] = trackLeftBankedFlatToLeftBanked25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_RIGHT_BANK_TO_RIGHT_BANK>;
        fns[EnumValue(rightBankedFlatToRightBankedDown25)] = trackRightBankedFlatToRightBanked25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_LEFT_BANK_TO_LEFT_BANK>;
        fns[EnumValue(leftBankedDown25ToLeftBankedFlat)] = trackLeftBanked25DegDownToLeftBankedFlat<SPR_TRACKS_BM_INVERT_RIGHT_BANK_TO_GENTLE_RIGHT_BANK>;
        fns[EnumValue(rightBankedDown25ToRightBankedFlat)] = trackRightBanked25DegDownToRightBankedFlat<SPR_TRACKS_BM_INVERT_LEFT_BANK_TO_GENTLE_LEFT_BANK>;
        fns[EnumValue(flatToLeftBankedUp25)] = trackFlatToLeftBanked25DegUp<SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE_LEFT_BANK>;
        fns[EnumValue(flatToRightBankedUp25)] = trackFlatToRightBanked25DegUp<SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE_RIGHT_BANK>;
        fns[EnumValue(leftBankedUp25ToFlat)] = trackLeftBanked25DegUpToFlat<SPR_TRACKS_BM_INVERT_GENTLE_LEFT_BANK_TO_FLAT>;
        fns[EnumValue(rightBankedUp25ToFlat)] = trackRightBanked25DegUpToFlat<SPR_TRACKS_BM_INVERT_GENTLE_RIGHT_BANK_TO_FLAT>;
        fns[EnumValue(flatToLeftBankedDown25)] = trackFlatToLeftBanked25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_RIGHT_BANK_TO_FLAT>;
        fns[EnumValue(flatToRightBankedDown25)] = trackFlatToRightBanked25DegDown<SPR_TRACKS_BM_INVERT_GENTLE_LEFT_BANK_TO_FLAT>;
        fns[EnumValue(leftBankedDown25ToFlat)] = trackLeftBanked25DegDownToFlat<SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE_RIGHT_BANK>;
        fns[EnumValue(rightBankedDown25ToFlat)] = trackRightBanked25DegDownToFlat<SPR_TRACKS_BM_INVERT_FLAT_TO_GENTLE_LEFT_BANK>;
        fns[EnumValue(diagBrakes)] = trackDiagBrakes<SPR_TRACKS_BM_INVERT_DIAG_BRAKES>;
        fns[EnumValue(diagBlockBrakes)] = trackDiagBrakes<SPR_TRACKS_BM_INVERT_DIAG_BRAKES>;
        fns[EnumValue(booster)] = trackBooster<SPR_TRACKS_BM_INVERT_BOOSTER_1>;
        fns[EnumValue(up90)] = trackUp90<SPR_TRACKS_BM_INVERT_VERTICAL>;
        fns[EnumValue(down90)] = trackDown90<SPR_TRACKS_BM_INVERT_VERTICAL>;
        fns[EnumValue(up60ToUp90)] = trackUp60ToUp90<SPR_TRACKS_BM_INVERT_STEEP_TO_VERTICAL>;
        fns[EnumValue(down90ToDown60)] = trackDown90ToDown60<SPR_TRACKS_BM_INVERT_STEEP_TO_VERTICAL>;
        fns[EnumValue(up90ToUp60)] = trackUp90ToUp60<SPR_TRACKS_BM_INVERT_VERTICAL_TO_STEEP>;
        fns[EnumValue(down60ToDown90)] = trackDown60ToDown90<SPR_TRACKS_BM_INVERT_VERTICAL_TO_STEEP>;
        fns[EnumValue(leftQuarterTurn1TileUp90)] = trackLeftQuarterTurn1TileUp90<SPR_TRACKS_BM_INVERT_VERTICAL_TWIST_LEFT>;
        fns[EnumValue(rightQuarterTurn1TileUp90)] = trackRightQuarterTurn1TileUp90<SPR_TRACKS_BM_INVERT_VERTICAL_TWIST_RIGHT>;
        fns[EnumValue(leftQuarterTurn1TileDown90)] = trackLeftQuarterTurn1TileDown90<SPR_TRACKS_BM_INVERT_VERTICAL_TWIST_RIGHT>;
        fns[EnumValue(rightQuarterTurn1TileDown90)] = trackRightQuarterTurn1TileDown90<SPR_TRACKS_BM_INVERT_VERTICAL_TWIST_LEFT>;
        return fns;
    }();
    // clang-format on
} // namespace

TrackPaintFunction GetTrackPaintFunctionInvertedRC(const TrackElemType trackType)
{
    return *paintFunctions[EnumValue(trackType)];
}
