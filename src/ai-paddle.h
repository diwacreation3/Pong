#pragma once 
#include "player.h"

// basic opponent ai 

class playerAi : public PlayerPaddle
{
    public:

    void updateAi(int ball_y);
};
