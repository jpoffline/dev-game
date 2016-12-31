//
//  Bob.h
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "utils.h"
#include <iostream>
#include "Collider.h"

using namespace sf;




class MoveDirection
{
    private:
        bool pressed;
    public:
        bool is_pressed()
        {
            return pressed;
        }
        
        void move()
        {
            pressed = true;
        }
        void stop()
        {
            pressed = false;
        }
    
};

class Directions
{
    public:
        MoveDirection left;
        MoveDirection right;
        MoveDirection up;
        MoveDirection down;
};




class Bob
{
        // All the private variables can only be accessed internally
    private:
        
        // Where is Bob
        Vector2f m_Position;
        int m_y_ground;
    
        // Of course we will need a sprite
        RectangleShape m_Sprite;
        
        // And a texture
        // Bob has been working out and he is now a bit more muscular than before
        // Furthermore, he fancies himself in lumberjack attire
        Texture m_Texture;
    
    
        Directions move;
    
        // Bob's speed in pixels per second
        float m_Speed;
    
        Vector2f screen_dims;    
    
        UTILS::GETSET<int> score;
    
    
        Vector2f get_move_amount(const float&);
    
    public:
        
        // We will set Bob up in the constructor
        Bob();
    
        void set_bob_speed(float s);
    
        // Send a copy of the sprite to main
        RectangleShape getSprite();
    
        // Move Bob in a specific direction
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
    
        // Stop Bob moving in a specific direction
        void stopLeft();
        void stopRight();
        void stopUp();
        void stopDown();
    
        // We will call this function once every frame
        void update(float elapsedTime);
    
        void draw(RenderWindow& window);
        //m_Window.draw(m_Bob.getSprite());
    
        std::string get_bob_hud_text();
    
        void increment_bob_score();
        void increment_bob_score(int);

    
        Collider getCollider(){return Collider(m_Sprite);}

    
};

