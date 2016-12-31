//
//  Blocks.h
//  TestApp
//
//  Created by Jonathan Pearson on 29/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Block.h"
#include "Hitter.h"


using namespace sf;

class Blocks{
    
    private:
        std::vector<Block> _blocks;
    
    public:
    
        Blocks(){};
    
    
        void
        add_block(Block b)
        {
            _blocks.push_back(b);
        }
    
    
        void
        draw(RenderWindow& window)
        {
            for(auto& b : _blocks)
            {
                b.draw(window);
            }
        }
    
        
        template<typename PLAYER>
        int
        check_player_hit_with_blocks(PLAYER player)
        {
            int hits = 0;
            Hitter<PLAYER, sf::RectangleShape> hitter;
            for(auto& b : _blocks)
            {
                if(hitter.has_hit(player, b.get_body()))
                {
                    if(b.is_block_fresh())
                    {
                        b.set_hit(sf::Color::Red);
                        hits++;
                    }
                }
            }
            return hits;
            
        }
    
        template<typename PLAYER>
        int
        check_player_ontop_blocks(PLAYER player)
        {

            Hitter<PLAYER, sf::RectangleShape> hitter;
            for(auto& b : _blocks)
            {
                if(hitter.is_block_on_top(player, b.get_body()))
                {
                    
                }
            }
            return 0;
            
        }
    
    
    
};