//
//  Sprite.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Sprite.hpp"
#include "Sprites.hpp"

using namespace gm;
using namespace sprites;

Sprite::Sprite(Image* image, const gm::Size& size, const gm::Point& position) : _image(image), _size(size) {
    _body_def.position = { position.x, position.y };
    _shape.SetAsBox(size.width / 2, size.height / 2);
    _fixture.shape = &_shape;
}

Sprite::~Sprite() {

}

gm::Point Sprite::position() const {
    return gm::Point { _body->GetPosition() };
}

gm::Size Sprite::size() const {
    return _size;
}

float Sprite::rotation() const {
	return _body->GetAngle();
}

Image* Sprite::image() const {
	return _image;
}

void Sprite::draw() {
	config::drawer()->draw(this);
}
