//
//  Game.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 14/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}



void Game::_init_objects_on_screen_fall(ScreenObjects& screen)
{
    screen.add_player(Player(100.0f));    
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<float> rn_h(0.0f, GF.get_screen_height());
    std::uniform_real_distribution<float> rn_s(10.0f, 150.f);
    std::uniform_int_distribution<uint8_t> rn_8(0,255);
    
    
    for(int i = 0; i < 10; i ++)
    {
        auto h = rn_h(gen);
        auto s = rn_s(gen);
        auto col = sf::Color(rn_8(gen), rn_8(gen), rn_8(gen));
        auto size = sf::Vector2f(s,s);
        auto pos = sf::Vector2f(h,h);
        screen.add_platform(Platform(size, pos, col));
    }

}

void Game::_init_objects_on_screen_snake(ScreenObjects& screen)
{
     screen.add_player(Player(100.0f));
    int ntiles_x = 50;
    int ntiles_y = 50;
    auto sw_x = GF.get_screen_width();
    auto sw_y = GF.get_screen_height();

    float tile_size_x =  sw_x / (float)ntiles_x;
    float tile_size_y =  sw_y / (float)ntiles_y;
    auto size = sf::Vector2f(tile_size_x,tile_size_y);

    for(int tx = 0; tx < ntiles_x; tx++)
    {
        auto pos_x = tx * tile_size_x + tx;
        for(int ty = 0; ty < ntiles_y; ty ++)
        {   
            auto pos_y = ty * tile_size_y + ty;
            screen.add_platform(Platform(size, sf::Vector2f(pos_x,pos_y), sf::Color(125,0,128)));

        }
    }

}


void Game::play_fall()
{
    sf::RenderWindow window(sf::VideoMode(GF.get_screen_width(), GF.get_screen_height()), "SFML works!", sf::Style::Default);
    ScreenObjects screen(window, GF);
   // _init_objects_on_screen_fall(screen);
    _init_objects_on_screen_snake(screen);
    while(window.isOpen() && screen.play())
    {

        GF.restart_deltaTime();
        GF.check_window_events(window);        
        screen.updatePlayers(GF.get_deltaTime());
        screen.doCollisions();
        screen.redrawScreen();

    }

}

void Game::play_snake()
{


}