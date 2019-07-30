//
//  Walker.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Physical.hpp"

namespace sprites {

	class Walker : public Physical {

	public:

		using Physical::Physical;

		float walking_speed = 0.1f;

		void walk_right();
		void walk_left();
		void jump();

	};

}
