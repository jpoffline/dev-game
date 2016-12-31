//
//  HUD.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#include "HUD.h"

HUD::HUD()
{
    font.loadFromFile(resourcePath() +"DS-DIGIT.TTF");
    
    // Set the font to our message
    hud.setFont(font);
    
    // Make it really big
    hud.setCharacterSize(55);
    
    // Choose a color
    hud.setFillColor(sf::Color::Blue);
    
    hud.setOutlineColor(sf::Color::Black);
    hud.setOutlineThickness(1.0f);
    
    
    set_hud_text("Default text");
    
}

void
HUD::set_hud_text(std::string s)
{
    hud.setString(s);
}

std::string
HUD::get_hud_string()
{
    return hud.getString();
}


std::string
HUD::render_hud_text()
{
    std::string txt = "";
    for(auto& line : hud_lines)
    {
        txt += line + "\n";
    }
    return txt;
    
}


void
HUD::draw(RenderWindow& window)
{
    hud.setString(render_hud_text());
    hud_lines.clear();
    render_hud_text();
    window.draw(hud);
}


void
HUD::add_line(std::string s)
{
    hud_lines.push_back(s);
}


void
HUD::add_line_num(int idx, std::string s)
{
    hud_lines[idx] = s;
}

