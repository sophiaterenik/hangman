#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;


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

int printWord(string guessedLetters, string randomWord) {
    int counter = 0;
    int rightLetters = 0;
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
    srand(time(NULL));
    string randomWord = dictionary[rand() % 5];

    for (unsigned int i = 0; i < randomWord.length(); i++) {
        cout << "_ ";
    }
    cout << endl;

    unsigned int lengthOfWordToGuess = randomWord.length();
    int amountOfTimesWrong = 0;
    int currGuessIndex = 0;
    string currLettersGuessed;
    int currLettersRight = 0;
    char letterGuessed;
    string input;

    while (amountOfTimesWrong != 6 && currLettersRight != lengthOfWordToGuess) {
        cout << "Letters guessed so far: " << endl;
        for (int i = 0; i < currLettersGuessed.length(); i++){
            cout << currLettersGuessed[i] << " ";
        }
        cout << endl;
        cout << "Guess a letter: " << endl;
        getline(cin, input);
        letterGuessed = input[0];
        if (randomWord[currGuessIndex] == letterGuessed) {
            print_hangman(amountOfTimesWrong);
            currGuessIndex++;
            currLettersGuessed += letterGuessed;
            currLettersRight = printWord(currLettersGuessed, randomWord);
            
        }
        else {
            amountOfTimesWrong++;
            currLettersGuessed += letterGuessed;
            print_hangman(amountOfTimesWrong);
            currLettersRight = printWord(currLettersGuessed, randomWord);
        }
    }
    cout << "Game is over! Thank you for playing :)" << endl;
}