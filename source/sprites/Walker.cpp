//
//  Walker.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Walker.hpp"

using namespace gm;
using namespace sprites;


void Walker::walk_right() {
	velocity = Point(Direction::Right, walking_speed);
}

void Walker::walk_left() {
	velocity = Point(Direction::Left, walking_speed);
}

void Walker::jump() {

}

