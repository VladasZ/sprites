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

        std::vector<Sprite*> _sprites;
        std::vector<Sprite*> _platforms;

	public:

		void add_sprite(Sprite*);
        void add_platform(Sprite*);

		void update();
		void draw();

	};

}
