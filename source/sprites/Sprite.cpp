//
//  Sprite.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Sprite.hpp"

using namespace gm;
using namespace sprites;

Point Sprite::position() const {
	return _position;
}

void Sprite::set_position(const Point& position) {
	_position = position;
}