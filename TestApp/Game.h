//
//  game.h
//  TestApp
//
//  Created by Jonathan Pearson on 10/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Platform.h"
#include "Player.h"
#include "Screen.h"
#include "Plaque.h"
#include "PlaqueSet.h"
#include <vector>
#include "GameFundamental.h"
#include <random>


class Game{
    private:
        GameFundamental GF;
        void _init_objects_on_screen_fall(ScreenObjects& screen);    
        void _init_objects_on_screen_snake(ScreenObjects& screen);

    public:

        Game();
        ~Game();
        void play_fall();
        void play_snake();

    
};



