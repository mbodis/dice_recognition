

#include "InputFacade.h"

void InputFacade::keyInput(char input) {
    switch(input){
        //esc
        case 27:
            move->quit();
            break;
            // left
        case 'Q':
        case 68:
            move->left();
            break;
            // right
        case 'S':
        case 67:
            move->right();
            break;
    }
}
