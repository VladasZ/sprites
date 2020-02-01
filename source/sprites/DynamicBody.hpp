//
//  DynamicBody.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 9/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#ifdef USING_BOX2D

#include "Sprite.hpp"

namespace sprites {

class DynamicBody : public Sprite {

public:

    DynamicBody(Image* image, const gm::Size& size, const gm::Point& position);


};

}

#endif
