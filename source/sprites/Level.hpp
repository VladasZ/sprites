//
//  Level.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/26/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Sprite.hpp"

namespace sprites {

	class Level {

		std::vector<Sprite *> _sprites;

	public:

		void add_sprite(Sprite*);

		void update();
		void draw();

	};

}
