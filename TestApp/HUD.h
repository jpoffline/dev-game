//
//  HUD.h
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "Bob.h"
#include "Platform.h"
#include <string>
#include <iostream>
#include <vector>

using namespace sf;

class HUD
{
    private:
        std::vector<std::string> hud_lines;
        std::string hud_text;
    
        Text hud;
        Font font;
        std::string render_hud_text();
    public:
    
        HUD();
        
        void set_hud_text(std::string s);
        std::string get_hud_string();
        void draw(RenderWindow& window);
        Text& get_hud(){return hud;}
        void add_line(std::string s);
        void add_line_num(int idx, std::string s);

    
};


