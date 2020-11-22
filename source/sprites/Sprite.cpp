//
//  Sprite.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Sprite.hpp"
#include "Sprites.hpp"
#include "ForceConvert.hpp"

using namespace gm;
using namespace sprite;


Sprite::Sprite(const gm::Point& position, const gm::Size& size) : _size(size) {
#ifdef USING_BOX2D
    _body_def.position = { position.x, position.y };

    auto poly_shape = new b2PolygonShape();
    poly_shape->SetAsBox(size.width / 2, size.height / 2);
    _shape = poly_shape;
    _fixture.shape = _shape;
#endif
}

gm::Point Sprite::position() const {
#ifdef USING_BOX2D
    return cu::force_convert<Point>(_body->GetPosition());
#else
    return { };
#endif
}

gm::Size Sprite::size() const {
    return _size;
}

float Sprite::rotation() const {
#ifdef USING_BOX2D
	return _body->GetAngle();
#else
    return 0;
#endif
}

void Sprite::add_rotation(float rot) {
#ifdef USING_BOX2D
    _body->SetAngularVelocity(rot);
#endif
}

Sprite* Sprite::set_image(Image* image) {
    _image = image;
    return this;
}

Image* Sprite::image() const {
	return _image;
}

bool Sprite::has_image() const {
    return _image;
}

void Sprite::fix_rotation(bool fixed) {
#ifdef USING_BOX2D
    _body->SetFixedRotation(fixed);
#endif
}

float Sprite::mass() const {
#ifdef USING_BOX2D
    return _body->GetMass();
#else
    return 0;
#endif
}

void Sprite::add_impulse(const gm::Point& impulse) {
#ifdef USING_BOX2D
    _body->ApplyLinearImpulseToCenter({ impulse.x, impulse.y }, true);
#endif
}

void Sprite::draw() {
	config::drawer()->draw(this);
}
