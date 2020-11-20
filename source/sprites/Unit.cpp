//
//  Unit.cpp
//  sprites
//
//  Created by Vladas Zakrevskis on 20/11/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Unit.hpp"

using namespace sprite;


Unit::Unit(const gm::Point& position, const gm::Size& size) : DynamicBody(position, size) {

}

void Unit::jump() {
	float impulse = mass() * 20;
	add_impulse({0, impulse});
}
