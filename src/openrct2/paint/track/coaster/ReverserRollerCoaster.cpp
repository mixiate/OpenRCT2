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

static constexpr TrackPaintFunction kReverserRollerCoasterTrackPaintFunctions[] = {
    trackPaintSpriteChain,   trackPaintSpriteStation, trackPaintSpriteStation, trackPaintSpriteStation, trackPaintSpriteChain,
    TrackPaintFunctionDummy, trackPaintSpriteChain,   TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSpriteChain,
    trackPaintSpriteChain,   TrackPaintFunctionDummy, trackPaintSpriteChain,   TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    trackPaintSpriteChain,   trackPaintSprite,        trackPaintSprite,        TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprite,        trackPaintSprite,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprite,        trackPaintSprite,        TrackPaintFunctionDummy,
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
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprite,
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
    TrackPaintFunctionDummy, trackPaintSprite,        trackPaintSprite,        TrackPaintFunctionDummy, TrackPaintFunctionDummy,
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
static_assert(std::size(kReverserRollerCoasterTrackPaintFunctions) == EnumValue(TrackElemType::Count));

TrackPaintFunction GetTrackPaintFunctionReverserRC(OpenRCT2::TrackElemType trackType)
{
    return kReverserRollerCoasterTrackPaintFunctions[EnumValue(trackType)];
}
