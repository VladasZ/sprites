//
//  Level.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/26/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Event.hpp"
#include "Sprite.hpp"
#include "BoxInclude.hpp"


namespace sprite {

	class Player;

	class Level {

    protected:

		Player* _player = nullptr;

#ifdef USING_BOX2D
        b2World* _world = nullptr;
#endif

        std::vector<Sprite*> _sprites;

	public:

		Level(Level&&) = delete;
    	Level(const Level&) = delete;
    	Level& operator=(const Level& other) = delete;
        Level& operator=(Level&& other) = delete;

	    Level();
		virtual ~Level() = default;

		void add_sprite(Sprite*);

		void set_gravity(float);

		virtual void update(float frame_time);
		virtual void setup() { }

		void draw();

		void add_box(const gm::Point&, const gm::Size& = { 1, 1 });

	public:

		cu::Event<gm::Point> on_click;

		virtual gm::Point convert_touch(const gm::Point&) = 0;

#ifdef DESKTOP_BUILD
		virtual gm::Point mouse_position() = 0;
#endif

	};

}
