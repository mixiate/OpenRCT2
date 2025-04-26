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

static constexpr TrackPaintFunction kDinghySlideCoveredTrackPaintFunctions[] = {
    trackPaintSprites2,      TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprites2,
    trackPaintSprites2,      trackPaintSprites2,      trackPaintSprites2,      trackPaintSprites2,      trackPaintSprites2,
    trackPaintSprites2,      trackPaintSprites2,      trackPaintSprites2,      trackPaintSprites2,      trackPaintSprites2,
    trackPaintSprites2,      trackPaintSprites2,      trackPaintSprites2,      TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprites2,      trackPaintSprites2,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprites2,      trackPaintSprites2,      TrackPaintFunctionDummy,
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
static_assert(std::size(kDinghySlideCoveredTrackPaintFunctions) == EnumValue(TrackElemType::Count));

TrackPaintFunction GetTrackPaintFunctionDinghySlideCovered(OpenRCT2::TrackElemType trackType)
{
    return kDinghySlideCoveredTrackPaintFunctions[EnumValue(trackType)];
}
