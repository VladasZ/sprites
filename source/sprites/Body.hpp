//
//  Body.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 07/12/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Sprite.hpp"
#include "BoxInclude.hpp"


namespace sprite {

	class Body : public Sprite {

		friend Level;

	public:

		Body(const gm::Point&, const gm::Size&);

		const gm::Point& position() const override;
		void set_position(const gm::Point&) override;

		float rotation() const override;
		void set_rotation(float) override;
		void fix_rotation(bool);

		bool contains(const gm::Point&) const override;

		const gm::Point& velocity() const;

		void set_restitution(float);

		float mass() const;

		void add_impulse(const gm::Point&);

	protected:

#ifdef USING_BOX2D
		b2Body* _body = nullptr;
		b2BodyDef _body_def;
		b2Shape* _shape = nullptr;
		b2FixtureDef _fixture_def;
		b2Fixture* _fixture = nullptr;
#endif

	};

}
