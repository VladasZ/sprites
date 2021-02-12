//
//  Sprite.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 14/12/20.
//  Copyright © 20 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "Point.hpp"
#include "Color.hpp"


class Image;

namespace sprite {

    class Level;

    class Sprite {

        friend Level;

    public:

        Sprite(const gm::Size&);
        Sprite(const gm::Point&, const gm::Size&);
        virtual ~Sprite() = default;

        gm::Direction direction() const { return _direction; }

        virtual const gm::Point& position() const;
        virtual void set_position(const gm::Point&);

        const gm::Size& size() const;

        virtual float rotation() const;
        virtual void set_rotation(float);

        bool has_image() const;
        Sprite* set_image(Image*);
        Image* image() const;

        virtual bool contains(const gm::Point&) const;

        std::string to_string() const;

    private:

        void draw();

    protected:
    
        virtual void setup() { }
        virtual void update() { }

    public:

        bool is_selected = false;
        gm::Color color = gm::Color::white;

    protected:

        gm::Direction _direction = gm::Direction::Right;
        gm::Point _position;
        gm::Size _size;
        float _rotation = 0;
        Image* _image = nullptr;
        Level* _level = nullptr;

    };

}
