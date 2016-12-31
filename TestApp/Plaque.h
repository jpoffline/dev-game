//
//  Plaque.h
//  TestApp
//
//  Created by Jonathan Pearson on 18/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

struct POINT{
    float x, y;
};

class Plaque{
    public:
        

        Plaque(float w, float h) : 
            _width(w), 
            _height(h)
        {
            _color = sf::Color::Green;
        }

        void set_mid_point(float x, float y)
        {
            _mid_point.x = x;
            _mid_point.y = y;            
        }

        ~Plaque(){}

        void draw(sf::RenderWindow& window)
        {
            _draw(window);
        }

    private:
        float _width;
        float _height;
        sf::Color _color;
        POINT _mid_point;
        
        sf::RectangleShape _body;

        void _setup()
        {
            _body.setSize(sf::Vector2f(_width,_height));
            _body.setFillColor(_color);
            _body.setPosition(_mid_point.x, _mid_point.y);
            _body.setOrigin(_body.getSize()/2.0f);
        }

        void _draw(sf::RenderWindow& window)
        {
            window.draw(_body);
        }

};