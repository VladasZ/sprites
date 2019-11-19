//
//  SpriteDrawer.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#ifndef NO_BOX2D

#include "Sprite.hpp"

namespace sprites {

	class SpriteDrawer {

	public:

		virtual ~SpriteDrawer();

		virtual void draw(Sprite* sprite) = 0;

	};

}

#endif
