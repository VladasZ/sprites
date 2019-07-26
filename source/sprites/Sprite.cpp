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

Sprite::Sprite(Image* image) : _image(image) {

}

Sprite::~Sprite() {
	for (auto sprite : _subsprites)
		delete sprite;
}

Image* Sprite::image() const {
	return _image;
}

gm::Size Sprite::size() const {
	return _size;
}

void Sprite::set_size(const gm::Size& size) {
	_size = size;
}

Point Sprite::position() const {
	return _position;
}

void Sprite::set_position(const Point& position) {
	_position = position;

}
gm::Point Sprite::velocity() const {
	return _velocity;
}
void Sprite::set_velocity(const gm::Point& point) {
	_velocity = point;
}

void Sprite::add_subsprite(Sprite* sprite) {
	_subsprites.push_back(sprite);
}

void Sprite::update() {
	_position += _velocity;
}

void Sprite::draw() {
	config::drawer()->draw(this);
	for (auto sprite : _subsprites)
		config::drawer()->draw(sprite);
}
