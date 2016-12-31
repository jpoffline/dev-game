//
//  ObjectFundamental.h
//  TestApp
//
//  Created by Jonathan Pearson on 27/12/2016.
//  Copyright (c) 2016 Jonathan Pearson. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Interactions.h"
#include "GameFundamental.h"


class ObjectFundamental
{
    private:
        bool _is_obj_changed;

    public:
        ObjectFundamental() : 
            _is_obj_changed(false)
        {

        }

        bool should_obj_be_redrawn()
        {
            return _is_obj_changed;
        }

        void obj_has_changed()
        {
            _is_obj_changed = true;
        }

};