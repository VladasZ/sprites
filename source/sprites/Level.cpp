//
//  Level.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/26/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Level.hpp"
#include "Sprites.hpp"

using namespace sprite;


Level::Level() {
#ifdef USING_BOX2D
    b2Vec2 gravity(0.0f, -9.8f);
    _world = new b2World(gravity);
#endif

    _player = new Unit({ 0, 0 }, { 17.0 / 15.0, 28.0 / 15.0 });
    add_sprite(_player);
    _player->fix_rotation(true);
    _player->set_restitution(0);

}

void Level::add_sprite(Sprite* sprite) {
#ifdef USING_BOX2D
    sprite->_body = _world->CreateBody(&sprite->_body_def);
    sprite->_fixture = sprite->_body->CreateFixture(&sprite->_fixture_def);
	_sprites.push_back(sprite);
#endif
}

void Level::set_gravity(float gravity) {
#ifdef USING_BOX2D
    _world->SetGravity({ 0, -gravity });
#endif
}

void Level::update(float frame_time) {
    static const int32_t velocityIterations = 6;
    static const int32_t positionIterations = 2;

#ifdef USING_BOX2D
    _world->Step(frame_time, velocityIterations, positionIterations);
#endif
}

void Level::draw() {
    config::drawer()->set_camera_position(_player->position());
    for (auto sprite : _sprites) {
        sprite->draw();
    }
}
