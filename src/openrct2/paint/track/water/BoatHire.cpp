/*****************************************************************************
/*****************************************************************************
 * Copyright (c) 2014-2025 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../../../core/EnumUtils.hpp"
#include "../../../ride/TrackData.h"
#include "../../../ride/TrackPaint.h"
#include "../../../world/tile_element/TrackElement.h"

using namespace OpenRCT2;

static constexpr TrackPaintFunction kBoatHireTrackPaintFunctions[] = {
    trackPaintSprites2,      trackPaintStationPier,   trackPaintStationPier,   trackPaintStationPier,   TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, trackPaintSprites2,      trackPaintSprites2,      TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprites2,      trackPaintSprites2,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprites2,      trackPaintSprites2,      TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    trackPaintSprites2,      trackPaintSprites2,      TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprites2,      trackPaintSprites2,
    trackPaintSprites2,      trackPaintSprites2,      TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, trackPaintSprites2,      TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
};
static_assert(std::size(kBoatHireTrackPaintFunctions) == EnumValue(TrackElemType::Count));

/**
 * rct2: 0x008B0D60
 */
TrackPaintFunction GetTrackPaintFunctionBoatHire(OpenRCT2::TrackElemType trackType)
{
    return kBoatHireTrackPaintFunctions[EnumValue(trackType)];
}
