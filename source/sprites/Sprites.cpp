//
//  Sprites.hpp
//  sprites
//
//  Created by Vladas Zakrevskis on 7/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Sprites.hpp"

using namespace sprite;
using namespace config;


static SpriteDrawer* _drawer = nullptr;

void config::set_drawer(SpriteDrawer* drawer) {
	if (_drawer != nullptr) {
        Fatal("Sprite drawer must be set only once");
    }
	if (drawer == nullptr) {
        Fatal("Sprite drawer must be nonnull");
    }
	_drawer = drawer;
}

SpriteDrawer* config::drawer() {
#ifdef DEBUG
	if (_drawer == nullptr) {
        Fatal("Sprite drawer is not set before first usage");
    }
#endif
	return _drawer;
}
