//
//  Engine.h
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "Bob.h"
#include "Platform.h"
#include "HUD.h"
#include <sstream>
#include <string>
#include "utils.h"
#include "Block.h"
#include "Blocks.h"
#include "Hitter.h"

using namespace sf;

class RunState{
    private:
        bool keep_running;
    public:
        RunState() : keep_running(true){}
        void kill(){keep_running = false;}
        bool is_ok(){return keep_running;}
};




class Engine
{
private:
    
    // A regular RenderWindow
    RenderWindow m_Window;
    
    // Declare a sprite and a Texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    
    // An instance of Bob
    Bob m_Bob;
    
    // Private functions for internal use only
    void input();
    void update(float dtAsSeconds);
    void draw();
    void display();
    
    HUD hud;
    Blocks blocks;
    RunState run_state;
    

    
public:
    // The Engine constructor
    Engine();
    
    // start will call all the private functions
    void start();
    
    
};