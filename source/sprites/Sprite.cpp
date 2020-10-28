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


Sprite::Sprite(Image* image, const gm::Size& size, const gm::Point& position) : _size(size), _image(image) {
#ifdef USING_BOX2D
    _body_def.position = { position.x, position.y };
    _shape.SetAsBox(size.width / 2, size.height / 2);
    _fixture.shape = &_shape;
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

Image* Sprite::image() const {
	return _image;
}

void Sprite::draw() {
	config::drawer()->draw(this);
}
