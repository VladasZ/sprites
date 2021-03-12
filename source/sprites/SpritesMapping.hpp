//
//  SpritesMapping.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 12/03/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#pragma once

#include "Sprite.hpp"
#include "GmMapping.hpp"
#include "JsonMapper.hpp"
#include "ImageMapping.hpp"


namespace sprite {

	MAKE_CLASS_INFO(Sprite,
		MAKE_PROPERTY(Sprite, is_selected),
		MAKE_PROPERTY(Sprite, color),
        MAKE_GETTER_PROPERTY(Sprite, position),
        MAKE_GETTER_PROPERTY(Sprite, rotation),
        MAKE_GETTER_PROPERTY(Sprite, image)
    );

	MAKE_MAPPER(mapper,
		gm::InfoOfPoint,
		gm::InfoOfColor,
		image::InfoOfImage,
		InfoOfSprite
	);

	static constexpr auto json_mapper = mapping::JSONMapper<mapper>();

}
