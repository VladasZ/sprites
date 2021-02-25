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

using namespace sprite;

void Player::fire() {
    auto bullet = new DynamicBody(position(), { 1, 1 });

}

void Player::setup() {
	weapon = new Sprite({2, 0.5});
	weapon->color = gm::Color::green;
	_level->add_sprite(weapon);
}

void Player::update() {
	Unit::update();
	weapon->set_position(position());
#ifdef DESKTOP_BUILD
	weapon_angle = (_level->mouse_position() - position()).angle();
	weapon->set_rotation(weapon_angle);
#endif
}
