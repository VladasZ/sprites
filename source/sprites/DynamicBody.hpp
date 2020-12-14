//
//  DynamicBody.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 9/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Body.hpp"


namespace sprite {

    class DynamicBody : public Body {

    public:

        DynamicBody(const gm::Point& position, const gm::Size& size);

    };

}
