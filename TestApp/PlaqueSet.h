    //
//  PlaqueSet.h
//  TestApp
//
//  Created by Jonathan Pearson on 18/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Plaque.h"
#include <vector>

class PlaqueSet{

    public:

        PlaqueSet()
        {
            
        }

        PlaqueSet(float sh, float sw) 
        {
            _set_nplaques(100);
            _set_plaque_height(sh); 
            _set_plaque_width(sw) ;
        }

        ~PlaqueSet()
        {

        }
        
        void fill_screen_with_plaques()
        {

        }

    private:

        int _nplaques;
        float _plaque_h;
        float _plaque_w;
        std::vector<Plaque> _plaques;

        void _set_nplaques(int n)
        {
            _nplaques = n;
        }

        void _set_plaque_height(float screen_height)
        {
            _plaque_h =  screen_height / (float)_nplaques;
        }

        void _set_plaque_width(float screen_width)
        {
            _plaque_w =  screen_width / (float)_nplaques;
        }
        
        



};