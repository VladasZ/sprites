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
#include "Color.hpp"
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
        b2Shape* _shape = nullptr;
        b2FixtureDef _fixture;
#endif

        Image* _image = nullptr;

    public:

        Sprite(const gm::Point& position, const gm::Size& size);

        virtual ~Sprite() = default;

    public:

        gm::Color color;

        gm::Point position() const;
        gm::Size size() const;
		float rotation() const;

		void add_rotation(float);

        Sprite* set_image(Image*);
        Image* image() const;

        bool has_image() const;

        void fix_rotation(bool);

        float mass() const;

        void add_impulse(const gm::Point&);

    private:

        void draw();

    };

}
