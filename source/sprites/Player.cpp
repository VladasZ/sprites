//
//  Player.cpp
//  sprites
//
//  Created by Vladas Zakrevskis on 28/01/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Level.hpp"
#include "Player.hpp"

using namespace gm;
using namespace sprite;


void Player::fire(Point to) {
    auto impulse = (to - position()) + velocity();
	auto bullet = new DynamicBody(position() + Point { 0, 5 }, { 1, 1 });
	_level->add_sprite(bullet);
	bullet->add_impulse(impulse * 1000000);
}

void Player::setup() {
	weapon = new Sprite({2, 0.5});
	weapon->color = gm::Color::green;
	_level->add_sprite(weapon);
	_level->on_click = [this](Point pos) {
		fire(pos);
	};
}

void Player::update() {
	Unit::update();
	weapon->set_position(position());
#ifdef DESKTOP_BUILD
	weapon_angle = (_level->mouse_position() - position()).angle();
	weapon->set_rotation(weapon_angle);
#endif
}
