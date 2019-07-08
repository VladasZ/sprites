//
//  Sprite.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"

namespace sprites {

class Sprite {

    gm::Point _position;

public:

    gm::Point position() const;
    void set_position(const gm::Point&);

};

}
