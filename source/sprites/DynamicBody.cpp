//
//  DynamicBody.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 9/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "DynamicBody.hpp"

using namespace sprite;


DynamicBody::DynamicBody(const gm::Point& position, const gm::Size& size) : Sprite(position, size) {
#ifdef USING_BOX2D
    _body_def.type = b2_dynamicBody;
    _fixture.shape = &_shape;
    _fixture.density = 1.0f;
    _fixture.friction = 0.3f;
    _fixture.restitution = 1.0f;
#endif
}
