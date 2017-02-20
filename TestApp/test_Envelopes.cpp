//
//  test_Envelopes.cpp
//  TestApp
//
//  Created by Jonathan Pearson on 20/02/2017.
//  Copyright (c) 2017 Jonathan Pearson. All rights reserved.
//

#include "test_Envelopes.h"

void dump_envelope()
{
    JP_sound::EnvelopeParams eps;
    
    eps.attackDuration = 1.0;
    eps.decayDuration = 2.0;
    eps.sustainLevel = 0.7;
    eps.releaseTime = 7.0;
    eps.releaseRate = 1.0;

    auto envelope = JP_sound::Envelopes(eps);
    std::ofstream out("/Users/jap/env.txt");
    for(double t = 0; t < 10; t += 0.1)
    {
        out << t << " " << envelope.get(t) << "\n";
    }
    out.close();
}
