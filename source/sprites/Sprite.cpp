//
//  Sprite.cpp
//  sprites
//
//  Created by Vladas Zakrevskis on 14/12/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Sprite.hpp"
#include "Sprites.hpp"

using namespace gm;
using namespace sprite;


Sprite::Sprite(const Point& position, const Size& size) : _position(position), _size(size) {

}

const Point& Sprite::position() const {
	return _position;
}

void Sprite::set_position(const Point& position) {
	_position = position;
}

const gm::Size& Sprite::size() const {
	return _size;
}

float Sprite::rotation() const {
	return _rotation;
}

void Sprite::set_rotation(float rotation) {
	_rotation = rotation;
}

bool Sprite::has_image() const {
	return _image;
}

Sprite* Sprite::set_image(Image* image) {
	_image = image;
	return this;
}

Image* Sprite::image() const {
	return _image;
}

bool Sprite::contains(const Point& point) const {
	return point.x >= _position.x &&
		   point.y >= _position.y &&
		   point.x <= _position.x + _size.width &&
		   point.y <= _position.y + _size.height;
}

void Sprite::draw() {
	config::drawer()->draw(this);
}