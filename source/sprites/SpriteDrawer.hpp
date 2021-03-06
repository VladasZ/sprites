//
//  SpriteDrawer.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Sprite.hpp"


namespace sprite {

	class SpriteDrawer {

	public:

		virtual ~SpriteDrawer();

		virtual void set_camera_position(const gm::Point&) = 0;
		virtual void draw(Sprite* sprite) = 0;

	};

}
