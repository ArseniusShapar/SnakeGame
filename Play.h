#pragma once
#include "consts.h"
#include <stdio.h>


direction Input(direction d) {
    if (_kbhit()) {
        switch (getch()) {

        case 'd':
            return right;
            break;
        case 'a':
            return left;
            break;
        case 'w':
            return up;
            break;
        case 's':
            return down;
            break;
        default:
            return d;
        }
        
    }
    
    else {
        return d;
    }
}
