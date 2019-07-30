//
//  Physical.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Rect.hpp"
#include "Sprite.hpp"

namespace sprites {

	class Physical : public Sprite {

		static inline const gm::Rect bounds = { 500, 500 };
		static inline const float gravity = 2.0f;

	public:

		using Sprite::Sprite;

		void add_force(const gm::Point&);
	
		void update() override;

	};

}
