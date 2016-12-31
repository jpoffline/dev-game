//
//  Screen.h
//  TestApp
//
//  Created by Jonathan Pearson on 12/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "Player.h"
#include <vector>
#include "GameFundamental.h"

class ScreenObjects
{
    private:
        bool _play;
        const sf::Color _screen_bg_colour = sf::Color(150,150,150);
    
        sf::RenderWindow& _window;
        std::vector<Player> _players;
        std::vector<Platform> _platforms;
        GameFundamental& GF;

        void _collide_players_with_platforms();

    public:
        ScreenObjects(sf::RenderWindow& w, GameFundamental& g);
        ~ScreenObjects();
        void add_player(Player p);
        
        void add_platform(Platform p);
        void redrawScreen();
        void updatePlayers(float dt);
        void doCollisions();
        bool play();
};