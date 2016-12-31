//
//  Hitter.h
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class HitterReturnsData{
public:
    float dx;
    float dy;
    float ix;
    float iy;
    HitterReturnsData(float idx, float idy, float iix, float iiy)
        : dx(idx), dy(idy), ix(iix), iy(iiy)
    {
        
    };
};

template< typename OBJ1, typename OBJ2>
class Hitter
{
    
public:
    
    bool has_hit(OBJ1& obj1, OBJ2& obj2)
    {
        auto intersections = gen_intersections(obj1, obj2);
        if(intersections.ix < 0.0f && intersections.iy < 0.0f)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    
    bool is_block_on_top(OBJ1& obj1, OBJ2& obj2)
    {
        auto ints = gen_intersections(obj1, obj2);
        
        if(ints.ix < 0.0f && ints.iy < 0.0f)
        {
            if(ints.ix > ints.iy)
            {
                if(ints.dx > 0.0f)
                {
                        // CASE 1
                }
                else
                {
                        // CASE 2
                }
            }
            else
            {
                if(ints.dy > 0.0f)
                {
                    std::cout << "case 3" << std::endl;
                }
                else
                {
                    return true;
                    std::cout << "case 4" << std::endl;
                }
            }
            
            //return true;
        }
        
        
        return false;
        
    }
    
    Hitter(){};
    
private:
    
    template<typename BODY>
    sf::Vector2f
    getPosition(BODY& b)
    {
        return b.getPosition();
    }
    
    template<typename BODY>
    sf::Vector2f
    getHalfSize(BODY& b)
    {
        return b.getSize() / 2.0f;
    }
    
    
    float
    clamp(float push, const float min, const float max)
    {
        return std::min(std::max(push, min), max);
    }
    
    
    HitterReturnsData
    gen_intersections(OBJ1& obj1, OBJ2& obj2)
    {
        
        auto position1 = getPosition<OBJ1>(obj1);
        auto position2 = getPosition<OBJ2>(obj2);
        auto halfsize1 = getHalfSize<OBJ1>(obj1);
        auto halfsize2 = getHalfSize<OBJ2>(obj2);
        
        float deltaX = position1.x - position2.x;
        float deltaY = position1.y - position2.y;
        
        float intersectX = abs(deltaX) - (halfsize2.x + halfsize1.x);
        float intersectY = abs(deltaY) - (halfsize2.y + halfsize1.y);
        
        return HitterReturnsData(deltaX, deltaY, intersectX, intersectY);
        
    }
    
    
};
