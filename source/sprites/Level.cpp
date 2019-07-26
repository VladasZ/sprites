//
//  Level.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/26/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Level.hpp"

using namespace sprites;

void Level::add_sprite(Sprite* sprite) {
	_sprites.push_back(sprite);
}

void Level::update() {
	for (auto sprite : _sprites)
		sprite->update();
}

void Level::draw() {
	for (auto sprite : _sprites)
		sprite->draw();
}
