#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct HangNode{
	std::string animal;
	HangNode *next;
    HangNode *previous;
};

class Hangman
{
    public:
        Hangman();
        char menu();
        void printAnimals();
        void play();
        void playMultiplayer();
    private:
        int tableSize = 10;
        int uniqueLetters(string word);
        void insertAnimal(string word);
        void deleteAnimal(string word);
        //string setWord(bool &sett);
        void display(vector<char> guesses, vector<string> &blankWord,string goldAnimal,int &lives,int &lettersCorrect);
        bool alreadyGuessed(vector<char> guesses, char letter);
        bool goodAscii(char letter);
        string selectAnimal();
        HangNode* animalTable[10];
};

#endif // HANGMAN_H
