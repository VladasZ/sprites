//
//  Platform.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 9/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#ifdef USING_BOX2D

#include "Platform.hpp"

using namespace sprites;

Platform::Platform(Image* image, const gm::Size& size, const gm::Point& position) : Sprite(image, size, position) {

}

#endif
