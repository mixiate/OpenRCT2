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

static constexpr TrackPaintFunction kWoodenWildMouseTrackPaintFunctions[] = {
    trackPaintSpriteChain,   trackPaintSpriteStation, trackPaintSpriteStation, trackPaintSpriteStation, trackPaintSpriteChain,
    trackPaintSpriteChain,   trackPaintSpriteChain,   trackPaintSprites2Chain, trackPaintSprites2Chain, trackPaintSpriteChain,
    trackPaintSpriteChain,   trackPaintSpriteChain,   trackPaintSpriteChain,   trackPaintSprites2Chain, trackPaintSprites2Chain,
    trackPaintSpriteChain,   TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprite,        trackPaintSprite,        TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    trackPaintSprite,        trackPaintSprite,        TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
    TrackPaintFunctionDummy, TrackPaintFunctionDummy, trackPaintSprites2Chain, trackPaintSprites2Chain, trackPaintSprites2Chain,
    trackPaintSprites2Chain, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy, TrackPaintFunctionDummy,
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
static_assert(std::size(kWoodenWildMouseTrackPaintFunctions) == EnumValue(TrackElemType::Count));

TrackPaintFunction GetTrackPaintFunctionWoodenWildMouse(OpenRCT2::TrackElemType trackType)
{
    return kWoodenWildMouseTrackPaintFunctions[EnumValue(trackType)];
}
