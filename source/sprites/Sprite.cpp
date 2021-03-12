//
//  Sprite.cpp
//  sprites
//
//  Created by Vladas Zakrevskis on 14/12/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Sprite.hpp"
#include "Sprites.hpp"
#include "LogUtils.hpp"

using namespace gm;
using namespace sprite;


Sprite::Sprite(const gm::Size& size) : _size(size) {

}

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

Image* Sprite::image() const {
	return _image;
}

Sprite* Sprite::set_image(Image* image) {
	_image = image;
	return this;
}

bool Sprite::contains(const Point& point) const {
	const Size s = _size / 2;
	return point.x >= _position.x - s.width &&
		   point.y >= _position.y - s.height &&
		   point.x <= _position.x + s.width &&
		   point.y <= _position.y + s.height;
}

std::string Sprite::to_string() const {
	return VarString(_position) + VarString(_size);
}

void Sprite::draw() {
	config::drawer()->draw(this);
}
