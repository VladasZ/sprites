//
//  Level.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/26/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Sprite.hpp"


namespace sprite {

	class Level {

    protected:

#ifdef USING_BOX2D
        b2World* _world;
#endif

        std::vector<Sprite*> _sprites;
        std::vector<Sprite*> _platforms;

	public:

	    Level();

		void add_sprite(Sprite*);
        void add_platform(Sprite*);

		virtual void update();
		void draw();

	};

}
