# KelvanBrandt_CSCI2270_FinalProject
Using data structures for the greater good
Kelvan Brandt
Animal Hangman Project
Project Summary:
I made a hangman game that runs off a “txt” file full of animal names. You are displayed a menu with 4 options when you open the program. The options are “New Game”, “Multi-Player”, “View Word-Bank”, and “Quit”. “New Game” chooses a random animal name from a HashTable that is created from the “txt” file. The HashTable is organized by difficulty of word. Difficulty of word is determined by counting the amount of unique letters in the animal’s name. You are given 6 lives to guess letters if you guess a correct letter it will display the animal name as blanks and the correct letters. This process is repeated until you guess incorrectly 6 times or you complete the word. In both cases a message is displayed according to whether you Won or Lost, then you will be shot back to the menu. “Multi-Player” works exactly the same except a player can set the word as opposed to it being randomly generated. “View Word-Bank” lets you cheat and view all the animals in the HashTable. “Quit” exits the program.
How to Run:
At the starting menu select 1-3 to execute “New Game”, “Multi-Player”, and “View Word-Bank” respectively. Any other character will exit the program. I’ll explain Multi-Player because it also explains New Game. Player 1 enters a word such as “Hello.” Then the program runs 100 “\n” so Player 2 cannot see the word. Player 2 will now see. Lives=6 Correct Letters=0 and     “_ _ _ _ _” say player 2 guesses a “L”. Console will now display Lives=6 Correct Letters = 2 and “_ _ l l _”. Now say player 2 guesses “T” Console: Lives=5 Correct Letters = 2 “_ _ l l _”. If player 2 completes the word without losing all 6 lives then a win statement will be displayed, and on the flip side if player 2 runs out of lives a losing message will be displayed.
Dependencies:
In order to use “New Game” and “View Word-Bank” you must download “animalList.txt” to your machine and save it in the same folder as the “exe” or “app” file.
System Requirements:
Your System must have a way to run .cpp files.
Group Members:
Me, myself, and I.
Contributors
Me, myself, and I.
Open Issues/ Bugs
There are things that could be optimized like UI but, there are no known bugs present, I also went through the effort to limit the amount of allowed Ascii values and switch upper case inputs to lower case.

-As far as I could tell there were no bugs, or issues.

-A recommendation is that when playing, there is constant print statement listing the words already guessed that way players don't have to scroll up.
-Another would be, is to allow player to add words into the bank as well.
-Of course these are just reccomendations and you don't have to do it, all up to you.

