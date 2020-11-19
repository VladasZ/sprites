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
#include "BoxInclude.hpp"


namespace sprite {

    class Level;

    class Sprite {

        friend Level;

    protected:

        gm::Size _size;

#ifdef USING_BOX2D
        b2Body* _body = nullptr;
        b2BodyDef _body_def;
        b2PolygonShape _shape;
        b2FixtureDef _fixture;
#endif

        Image* _image;

    public:

        Sprite(Image* image, const gm::Point& position, const gm::Size& size);

        virtual ~Sprite() = default;

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
