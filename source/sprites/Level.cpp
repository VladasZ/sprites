//
//  Level.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/26/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Level.hpp"

using namespace sprite;


Level::Level() {
#ifdef USING_BOX2D
    b2Vec2 gravity(0.0f, -10.0f);
    _world = new b2World(gravity);
#endif
}

void Level::add_sprite(Sprite* sprite) {
#ifdef USING_BOX2D
    sprite->_body = _world->CreateBody(&sprite->_body_def);
    sprite->_body->CreateFixture(&sprite->_fixture);
	_sprites.push_back(sprite);
#endif
}

void Level::add_platform(Sprite *platform) {
    _platforms.push_back(platform);
}

void Level::set_gravity(float gravity) {
    _world->SetGravity({ 0, -gravity });
}

void Level::update() {
    static const int32_t velocityIterations = 6;
    static const int32_t positionIterations = 2;

#ifdef USING_BOX2D
    _world->Step(1.0f / 30.0f, velocityIterations, positionIterations);
#endif
}

void Level::draw() {
    for (auto sprite : _sprites) {
        sprite->draw();
    }
    for (auto sprite : _platforms) {
        sprite->draw();
    }
}
