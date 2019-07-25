//
//  Sprites.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Sprite.hpp"
#include "SpriteDrawer.hpp"

namespace sprites {

	struct config {
		static void set_drawer(SpriteDrawer*);
		static SpriteDrawer* drawer();
	};

}
