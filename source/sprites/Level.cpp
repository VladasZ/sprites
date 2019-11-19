//
//  Level.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/26/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#ifndef NO_BOX2D

#include "Level.hpp"

using namespace sprites;

Level::Level() {
    b2Vec2 gravity(0.0f, -10.0f);
    _world = new b2World(gravity);
}

void Level::add_sprite(Sprite* sprite) {
    sprite->_body = _world->CreateBody(&sprite->_body_def);
    sprite->_body->CreateFixture(&sprite->_fixture);
	_sprites.push_back(sprite);
}

void Level::add_platform(Sprite *platform) {
    _platforms.push_back(platform);
}

void Level::update() {
    static const int32 velocityIterations = 6;
    static const int32 positionIterations = 2;

    _world->Step(1.0f / 30.0f, velocityIterations, positionIterations);
}

void Level::draw() {
	for (auto sprite : _sprites)
		sprite->draw();
    for (auto sprite : _platforms)
        sprite->draw();
}

#endif
