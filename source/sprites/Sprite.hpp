//
//  Sprite.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "Size.hpp"
#include "Point.hpp"
#include "Image.hpp"

namespace sprites {

class Sprite {

protected:

	Image* _image;

public:

	gm::Size size = { 100, 100 };
	gm::Point position;
	gm::Point velocity;

	Sprite(Image* image);
	virtual ~Sprite();

	Image* image() const;

	virtual void update();

	void draw();

};

}
