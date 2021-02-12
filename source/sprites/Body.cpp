//
//  Body.cpp
//  sprites
//
//  Created by Vladas Zakrevskis on 07/12/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Body.hpp"
#include "ForceConvert.hpp"

using namespace gm;
using namespace sprite;


Body::Body(const Point& position, const Size& size) : Sprite(position, size) {
#ifdef USING_BOX2D
    _body_def.position = { position.x, position.y };
    auto poly_shape = new b2PolygonShape();
    poly_shape->SetAsBox(size.width / 2, size.height / 2);
    _shape = poly_shape;
    _fixture_def.shape = _shape;
#endif
}

const Point& Body::position() const {
#ifdef USING_BOX2D
	return cu::cast<Point>(_body->GetPosition());
#else
	return Point::zero;
#endif
}

void Body::set_position(const Point&) {
    Fatal("Not implemented");
}

float Body::rotation() const {
#ifdef USING_BOX2D
    return _body->GetAngle();
#else
    return 0;
#endif
}

void Body::set_rotation(float angle) {
    Sprite::set_rotation(angle);
#ifdef USING_BOX2D
#endif
}

void Body::fix_rotation(bool fixed) {
#ifdef USING_BOX2D
    _body->SetFixedRotation(fixed);
#endif
}

bool Body::contains(const gm::Point& point) const {
#ifdef USING_BOX2D
    return _fixture->TestPoint(cu::cast<const b2Vec2&>(point));
#else
    return false;
#endif
}

const Point& Body::velocity() const {
#ifdef USING_BOX2D
    return reinterpret_cast<const Point&>(_body->GetLinearVelocity());
#else 
    return Point::zero;
#endif
}

void Body::set_restitution(float res) {
#ifdef USING_BOX2D
    _fixture->SetRestitution(res);
#endif
}

float Body::mass() const {
#ifdef USING_BOX2D
    return _body->GetMass();
#else
    return 0;
#endif
}

void Body::add_impulse(const Point& impulse) {
#ifdef USING_BOX2D
    _body->ApplyLinearImpulseToCenter({ impulse.x, impulse.y }, true);
#endif
}
