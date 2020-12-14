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
#include "Image.hpp"
#include "Color.hpp"


namespace sprite {

    class Level;

    class Sprite {

        friend Level;

    public:

        Sprite(const gm::Point&, const gm::Size&);
        virtual ~Sprite() = default;

        virtual const gm::Point& position() const;
        virtual void set_position(const gm::Point&);

        const gm::Size& size() const;

        virtual float rotation() const;
        void set_rotation(float);

        bool has_image() const;
        Sprite* set_image(Image*);
        Image* image() const;

        bool contains(const gm::Point&) const;

        std::string to_string() const;

    private:

        void draw();

    public:

        bool is_selected = false;
        gm::Color color = gm::Color::white;

    protected:

        gm::Point _position;
        gm::Size _size;
        float _rotation = 0;
        Image* _image = nullptr;

    };

}
