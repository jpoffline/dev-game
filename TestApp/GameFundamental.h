//
//  GameFundamental.h
//  TestApp
//
//  Created by Jonathan Pearson on 14/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>

class GameFundamental {

    private:
        const int SCREEN_WIDTH = 512;
        const int SCREEN_HEIGHT = 512;
        const float GRAVITY_STRENGTH = 50.0f;
        float deltaTime;
        sf::Clock clock;
        
    public:
        GameFundamental();
        ~GameFundamental();
        
        
        const int get_screen_width();
        const int get_screen_height();
        const float& get_gravity_strength();
        void restart_deltaTime();
        float get_deltaTime();
        
        void check_window_events(sf::RenderWindow&);
        bool is_object_in_screen(sf::RectangleShape& o);
    


};