//
//  Sprite.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#ifndef NO_BOX2D

#include <vector>

#include "Box2D/Box2D.h"

#include "Size.hpp"
#include "Point.hpp"
#include "Image.hpp"

namespace sprites {

    class Level;

    class Sprite {

        friend Level;

    protected:

        gm::Size _size;

        b2Body* _body;
        b2BodyDef _body_def;
        b2PolygonShape _shape;
        b2FixtureDef _fixture;

        Image* _image;

    public:

        Sprite(Image* image, const gm::Size& size, const gm::Point& position);

        virtual ~Sprite() = 0;

    public:

        gm::Point position() const;
        gm::Size size() const;
		float rotation() const;

		void add_rotation(float);

        Image* image() const;

    public:

        void draw();

    };

}

#endif
