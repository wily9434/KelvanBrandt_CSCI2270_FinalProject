#include <iostream>
#include <fstream>
#include "hangman.h"


using namespace std;

int main()
{
    Hangman hm;
    char option;
     do{
        option = hm.menu();
        switch(option){
            case '1':   hm.play();
                        break;

            case '2':   hm.playMultiplayer();
                        break;

            case '3':   hm.printAnimals();
                        break;

            default:    cout << "Thanks for Playing!\n";

        }
    }while(option != '4');

    return 0;
}
