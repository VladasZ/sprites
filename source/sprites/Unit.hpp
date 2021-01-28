//
//  Unit.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 20/11/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "DynamicBody.hpp"


namespace sprite {

	class Unit : public DynamicBody {
		
	public:

		using DynamicBody::DynamicBody;

		void jump();
		void go_left();
		void go_right();

	protected:

		void update() override;

	};

}
