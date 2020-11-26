//
//  Level.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/26/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Unit.hpp"
#include "Event.hpp"
#include "Sprite.hpp"


namespace sprite {

	class Level {

    protected:

		Unit* _player = nullptr;

#ifdef USING_BOX2D
        b2World* _world = nullptr;
#endif

        std::vector<Sprite*> _sprites;

	public:

	    Level();

		void add_sprite(Sprite*);

		void set_gravity(float);

		virtual void update(float frame_time);
		virtual void setup() { }

		void draw();

		void add_box(const gm::Point&, const gm::Size&);

	};

}
