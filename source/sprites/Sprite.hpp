//
//  Sprite.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "Point.hpp"
#include "Image.hpp"

namespace sprites {

class Sprite {

	Image* _image;

	gm::Size _size;
    gm::Point _position;
	gm::Point _velocity;

public:

	Sprite(Image* image);
	virtual ~Sprite();

	Image* image() const;

	gm::Size size() const;
	void set_size(const gm::Size&);

    gm::Point position() const;
    void set_position(const gm::Point&);

	gm::Point velocity() const;
	void set_velocity(const gm::Point&);

	void update();

	void draw();
};

}
