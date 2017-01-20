

#ifndef INPUTFACADE_H
#define INPUTFACADE_H


#include "../keyboard/abstract/Move.h"

class InputFacade {
    Move* move;
public:
    InputFacade(Move* move): move(move){}

    void keyInput(char input);
};


#endif //INPUTFACADE_H
