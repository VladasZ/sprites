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


void Player::setup() {
	weapon = new Sprite({1, 2});
	weapon->color = gm::Color::green;
	_level->add_sprite(weapon);
	Log << "A";
}

void Player::update() {
	Unit::update();
	weapon->set_position(position());
	weapon->set_rotation(-_level->mouse_position().angle());
	Log << _level->mouse_position().angle();
}
