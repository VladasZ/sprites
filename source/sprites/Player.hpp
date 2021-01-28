//
//  Player.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 28/01/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#pragma once

#include "Unit.hpp"


namespace sprite {

	class Player : public Unit {
		
	public:

		using Unit::Unit;


	protected:

		void setup() override;
		void update() override;

	protected:

		Sprite* weapon = nullptr;

	};

}
