//
//  Unit.cpp
//  sprites
//
//  Created by Vladas Zakrevskis on 20/11/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Unit.hpp"

using namespace sprite;


void Unit::jump() {
	float impulse = mass() * 10;
	add_impulse({0, impulse});
}

void Unit::go_left() {
	add_impulse({ -mass() * 10, 0 });
}

void Unit::go_right() {
	add_impulse({ mass() * 10, 0 });
}

void Unit::update() {
	
	_direction = velocity().directionX();

}
