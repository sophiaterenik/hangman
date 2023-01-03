#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

/**
 * @param wrong- number of wrong guesses
 * prints the hangman depending on how many wrong guesses
*/
void print_hangman(int wrong) {
    if (wrong == 0) {
        cout << "+---+" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "   ===" << endl;
    }
    if (wrong == 1) {
        cout << "+---+" << endl;
        cout << "O   |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "   ===" << endl;
    }
    if (wrong == 2) {
        cout << "+---+" << endl;
        cout << "O   |" << endl;
        cout << "|   |" << endl;
        cout << "    |" << endl;
        cout << "   ===" << endl;
    }
    if (wrong == 3) {
        cout << "+---+" << endl;
        cout << " O  |" << endl;
        cout << "/|  |" << endl;
        cout << "    |" << endl;
        cout << "   ===" << endl;
    }
    if (wrong == 4) {
        cout << "+---+" << endl;
        cout << " O  |" << endl;
        cout << "/|\\ |" << endl;
        cout << "    |" << endl;
        cout << "   ===" << endl;
    }
    if (wrong == 5) {
        cout << "+---+" << endl;
        cout << " O  |" << endl;
        cout << "/|\\ |" << endl;
        cout << "/   |" << endl;
        cout << "   ===" << endl;
    }
    if (wrong == 6) {
        cout << "+---+" << endl;
        cout << " O  |" << endl;
        cout << "/|\\ |" << endl;
        cout << "/ \\ |" << endl;
        cout << "   ===" << endl;
    }
}
/**
 * @param guessedLetters- string of letters guessed
 * @param randomWord- word that is to be guessed
 * @return int value of number of right letters guessed
 * prints the correct letters in the word
*/
int printWord(string guessedLetters, string randomWord) {
    int counter = 0;
    int rightLetters = 0;
    //find guessed letters in random word
    for (int i = 0; i < randomWord.length(); i++){
        if (guessedLetters.find(randomWord[i]) != -1) {
            cout << randomWord[counter];
            rightLetters++;
        }
        else {
            cout << " ";
            counter++;
        }
    }
    cout << endl;
    return rightLetters;
}

int main() {
    cout << "Welcome to hangman" << endl;
    cout << "---------------------------" << endl;
    string dictionary[5] = { "sunflower", "house", "diamond", "memes", "hellow" };
    //generate random word
    srand(time(NULL));
    string randomWord = dictionary[rand() % 5];

//print empty spaces
    for (unsigned int i = 0; i < randomWord.length(); i++) {
        cout << "_ ";
    }
    cout << endl;

//initialize values
    unsigned int lengthOfWordToGuess = randomWord.length();
    int amountOfTimesWrong = 0;
    int currGuessIndex = 0;
    string currLettersGuessed;
    int currLettersRight = 0;
    char letterGuessed;
    string input;

//while game is still going
    while (amountOfTimesWrong != 6 && currLettersRight != lengthOfWordToGuess) {
        //print letters guessed
        cout << "Letters guessed so far: " << endl;
        for (int i = 0; i < currLettersGuessed.length(); i++){
            cout << currLettersGuessed[i] << " ";
        }
        cout << endl;
        //read in letter guessed
        cout << "Guess a letter: " << endl;
        getline(cin, input);
        letterGuessed = input[0];
        //if letter guessed in word
        if (randomWord[currGuessIndex] == letterGuessed) {
            //print data and update variables
            print_hangman(amountOfTimesWrong);
            currGuessIndex++;
            currLettersGuessed += letterGuessed;
            currLettersRight = printWord(currLettersGuessed, randomWord);
            
        }
        //if letter guessed not in word
        else {
            //print data and update variables
            amountOfTimesWrong++;
            currLettersGuessed += letterGuessed;
            print_hangman(amountOfTimesWrong);
            currLettersRight = printWord(currLettersGuessed, randomWord);
        }
    }
    cout << "Game is over! Thank you for playing :)" << endl;
}