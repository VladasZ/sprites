//
//  Physical.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Physical.hpp"

using namespace gm;
using namespace sprites;

void Physical::add_force(const gm::Point& force) {
	velocity += force;
}

void Physical::update() {

	auto next_position = position + velocity;

	if (next_position.x < bounds.min_x() || 
		next_position.x > bounds.max_x())
		velocity.invert_x();

	if (next_position.y < bounds.min_y() || 
		next_position.y > bounds.max_y())
		velocity.invert_y();

	velocity.y += gravity;

	velocity.add_length(-1);

	Sprite::update();
}
