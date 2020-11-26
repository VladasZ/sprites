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


Sprite::Sprite(const Point& position, const Size& size) : _size(size) {
#ifdef USING_BOX2D
    _body_def.position = { position.x, position.y };
    auto poly_shape = new b2PolygonShape();
    poly_shape->SetAsBox(size.width / 2, size.height / 2);
    _shape = poly_shape;
    _fixture_def.shape = _shape;
#endif
}

const Point& Sprite::velocity() const {
#ifdef USING_BOX2D
    return reinterpret_cast<const Point&>(_body->GetLinearVelocity());
#else 
	return Point::zero;
#endif
}

Direction Sprite::velocity_direction() const {
    return velocity().directionX();
}

const Point& Sprite::position() const {
#ifdef USING_BOX2D
	return reinterpret_cast<const Point&>(_body->GetPosition());
#else
    return Point::zero;
#endif
}

Size Sprite::size() const {
    return _size;
}

float Sprite::rotation() const {
#ifdef USING_BOX2D
	return _body->GetAngle();
#else
    return 0;
#endif
}

void Sprite::set_restitution(float res) {
#ifdef USING_BOX2D
    _fixture->SetRestitution(res);
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

void Sprite::add_impulse(const Point& impulse) {
#ifdef USING_BOX2D
    _body->ApplyLinearImpulseToCenter({ impulse.x, impulse.y }, true);
#endif
}

void Sprite::draw() {
	config::drawer()->draw(this);
}
