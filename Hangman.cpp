#include "Hangman.h"
#include "fstream"
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Hangman::Hangman()
{
    string data;
    ifstream dataFile;
    dataFile.open("animalList.txt");

    for(int i=0; i < tableSize; i++){
        animalTable[i] = NULL;
    }

    while(getline(dataFile,data)){
        insertAnimal(data);
    }
}

char Hangman::menu(){
    char option;
    cout << "+------Animal Hangman------+" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Multi-Player" << endl;
    cout << "3. View Word-Bank" << endl;
    cout << "4. Quit" << endl;

    cin >> option;
    return option;
}

int Hangman::uniqueLetters(string word){
    vector<char> uniqueLetters;
    bool uni;
    int score;
    for(int i=0; i<word.size(); i++){
        char letter = word[i];
        uni = true;
        for(int j=0; j<uniqueLetters.size(); j++){
            if(letter == uniqueLetters[j]){
                uni = false;
            }
        }
        if(uni == true){
            uniqueLetters.push_back(letter);
        }
    }
    score = uniqueLetters.size();
    return score;
}

void Hangman::insertAnimal(string word){
    int index = uniqueLetters(word);

    if(index > 9){
        index = 9;
    }

    HangNode *node = new HangNode;
    node->previous = NULL;
    node->next = NULL;
    node->animal = word;

    if(index != 0){
        HangNode *tmp = animalTable[index];
        if(tmp == NULL){
            //cout << node->animal << endl;
            //cout << node->previous << endl;
            animalTable[index] = node;
        }
        else{
            HangNode *prev = new HangNode;
            while(tmp != NULL){
                prev = tmp;
                tmp = tmp->next;
            }

            tmp = node;
            tmp->previous = prev;
            prev->next = tmp;

            //cout << node->animal << endl;
            //cout << node->previous->animal << endl;
        }
    }
}


void Hangman::deleteAnimal(string word){
    int index = uniqueLetters(word);

    HangNode *tmp = animalTable[index];
    HangNode *prev = NULL;
    bool found = false;

    if(tmp->animal == word){
        animalTable[index] = tmp->next;
        if(tmp->next != NULL){
            tmp->next->previous = NULL;
        }
        delete tmp;
    }else{
        while(tmp != NULL && found == false){
            if(tmp->animal == word){
                found = true;
            }else{
                prev = tmp;
                tmp = tmp->next;
            }
        }
        //after while
        if(found == false){
            cout << "I did something wrong" << endl;
        } else {
            prev->next = tmp->next;
            tmp->next->previous = prev;
            delete tmp;
            //cout << prev->title << endl;
            //cout << prev->next->title << endl;
        }
    }
}

string Hangman::selectAnimal(){
    srand(time(NULL));
    int index = rand() % 9 + 1;
    while(animalTable[index] == NULL){
        index = rand() % 9 + 1;
    }
    HangNode *node = animalTable[index];

    int randBound = 0;
    while(node->next != NULL){
        node = node->next;
        randBound++;
    }

    int rando = rand() % randBound + 0;

    HangNode *x = animalTable[index];
    for(int i=0; i<rando; i++){
        x = x->next;
    }
    return x->animal;
}

void Hangman::printAnimals(){
    bool found = false;
    for(int i=0; i<tableSize; i++){
        HangNode *tmp = animalTable[i];
        if(animalTable[i] != NULL){
            found = true;
            while(tmp != NULL){
                cout << tmp->animal << endl;
                tmp = tmp->next;
            }
        }
    }
    if(found == false){
        cout << "empty" << endl;
    }
}

void Hangman::play(){
    string goldAnimal = selectAnimal();
    deleteAnimal(goldAnimal);

    int lives = 6;
    bool win = false;
    string letter1;

    cout << "\n\n\n";
    //cout << goldAnimal << endl;

    vector<char> guesses;
    vector<string> blankWord;

    int vectSize = goldAnimal.size();
    int lettersCorrect = vectSize;

    for(int i=0; i<vectSize; i++){
        blankWord.push_back("_ ");
    }
    for(int i=0; i<blankWord.size(); i++){
        cout << blankWord[i];
    }
    cout << endl;
    while(lives > 0 && win == false){
        cout << "Lives: " << lives << endl;
        cout << "Letters Correct: " << vectSize - lettersCorrect << endl;
        cout << "Enter a letter: " << endl;
        cin >> letter1;
        char letter = letter1[0];
        letter = tolower(letter);
        if(goodAscii(letter)){
            if(!alreadyGuessed(guesses,letter)){
                guesses.push_back(letter);
                display(guesses,blankWord,goldAnimal,lives,lettersCorrect);
            }else{
                cout << "Already Guessed" << endl;
            }
        }else{
            cout << "Invalid input" << endl;
        }

        if(lettersCorrect == 0){
            win = true;
        }

        cout << "\n\n\n";
    }
    if(lives == 0){
        cout << "YOU RAN OUT OF LIVES :( THE CORRECT ANSWER WAS: " << goldAnimal <<"\n\n\n";
    }else{
        cout << "YOU HAVE DONE THE UN-DOABLE, YOU HAVE WON!!!!!!!!\n\n\n";
    }

}

void Hangman::playMultiplayer(){
    string valid[1];

    cout << "Player One Enter a Word(With Valid Characters): " << endl;
    cin >> valid[0];

    for(int i=0; i<valid[0].size(); i++){
        char letter = valid[0][i];
        letter = tolower(letter);
        if(!goodAscii(letter)){
            valid[0] = "";
            playMultiplayer();
        }else{
            valid[0][i] = letter;
        }
    }

    string goldAnimal = valid[0];

    int lives = 6;
    bool win = false;
    string letter1;

    for(int i=0; i<100; i++){
        cout << "\n";
    }
    //cout << goldAnimal << endl;
    cout << "Player Two Begin Guessing" << endl;

    vector<char> guesses;
    vector<string> blankWord;

    int vectSize = goldAnimal.size();
    int lettersCorrect = vectSize;

    for(int i=0; i<vectSize; i++){
        blankWord.push_back("_ ");
    }
    for(int i=0; i<blankWord.size(); i++){
        cout << blankWord[i];
    }
    cout << endl;
    while(lives > 0 && win == false){
        cout << "Lives: " << lives << endl;
        cout << "Letters Correct: " << vectSize - lettersCorrect << endl;
        cout << "Enter a letter: " << endl;
        cin >> letter1;
        char letter = letter1[0];
        letter = tolower(letter);
        if(goodAscii(letter)){
            if(!alreadyGuessed(guesses,letter)){
                guesses.push_back(letter);
                display(guesses,blankWord,goldAnimal,lives,lettersCorrect);
            }else{
                cout << "Already Guessed" << endl;
            }
        }else{
            cout << "Invalid input" << endl;
        }

        if(lettersCorrect == 0){
            win = true;
        }

        cout << "\n\n\n";
    }
    if(lives == 0){
        cout << "YOU RAN OUT OF LIVES :( THE CORRECT ANSWER WAS: " << goldAnimal <<"\n\n\n";
    }else{
        cout << "YOU HAVE DONE THE UN-DOABLE, YOU HAVE WON!!!!!!!!\n\n\n";
    }
}

bool Hangman::alreadyGuessed(vector<char> guesses, char letter){
    bool x = false;
    for(int i=0; i<guesses.size(); i++){
        if(letter == guesses[i]){
            x = true;
        }
    }
    return x;
}

void Hangman::display(vector<char> guesses, vector<string> &blankWord, string goldAnimal, int &lives, int &lettersCorrect){
    bool correct = false;
    for(int j=0; j<blankWord.size(); j++){
        if(guesses[guesses.size()-1] == goldAnimal[j]){
            correct = true;
            blankWord[j] = goldAnimal[j];
            lettersCorrect = lettersCorrect - 1;
        }
    }
    if(correct == false){
        cout << "Incorrect" << endl;
        lives = lives - 1;
    } else {
        cout << "Correct!" << endl;
    }
    for(int i=0; i<blankWord.size(); i++){
        cout << blankWord[i];
    }
    cout << endl;
}

bool Hangman::goodAscii(char letter){
    bool good = false;
    int ascii = int(letter);
    if(ascii >= 97 && ascii <= 122){
        good = true;
    }
    return good;
}

