#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <charconv>
#include <algorithm>
#include <iterator>

using namespace std;

void print(int guesses = 0) {
if (guesses >= 1) {cout << "  | ";}
if (guesses >= 2) {cout << "\n  | ";}
if (guesses >= 3) {cout << "\n  O ";}
if (guesses == 4) {cout << "\n /";}
if (guesses == 5) {cout << "\n /|";}
if (guesses >= 6) {cout << "\n /|\\";}
if (guesses == 7) {cout << "\n / ";}
if (guesses >= 8) {cout << "\n / \\";}
if (guesses >= 9) {cout << "\n ___";}
if (guesses == 10) {cout << "\n|   |\nYOU LOST!";}
}

string 

int main(){
    char input{}; //for user guess
    int choice{};
    string wordinput{}; //for when user wants to guess the entire word
    vector<char> guessedchar{}; //array for all the letters the user have guessed
    
    string word = "barcode"; //for testing
    int guesses{}; // number of guesses by the user
    
    while (guesses <= 10) { 
        cout << "Remaining Guesses: " << 10 - guesses << endl;
        print(guesses); //print hangman
        cout << endl;

        if (guesses == 10) { //if user has lost the game
            cout << "\nMission Failed. We'll get them next time." << endl;
        }

        else if (guesses < 10) //if user still has guesses remaining
        
        cout << "\nSelect One The Following Option:" <<
                "\n[1] Guess a letter" <<
                "\n[2] Guess the word" <<
                "\n[3] Check guessed letters" <<
                "\n[4] Quit game" << endl;
        cin >> choice;

        switch (choice) {

        case 1: //when user decides to guess a letter
        cin >> input;
        if (count(guessedchar.begin(), guessedchar.end(), input)) {
        cout << "You have chosen that letter. Please choose another." << endl;
        }
        else if (count(word.begin(), word.end(), input)) {
            guessedchar.push_back (input);
            cout << "\nYou are correct!" << endl;
        }
        else {
            guesses += 1;
            guessedchar.push_back (input);
            cout << "\nIncorrect letter! Try again." << endl;
        }
        break;

        case 2: //when user decides to guess a word
        cout << "WARNING: You lose 2 tries if you fail to guess the word.\nUse lowercase ONLY." << endl;
        cin >> wordinput;
        if (wordinput == word) {
            cout << "Congratulations! You won." << endl;
            input = " "; //resets the char 'input'
            cout << "Would you like to play again? (Y/N)" << endl;
            while (input != 'y' || input != 'Y') {
            cin >> input;
            if (input == 'y' || input == 'Y') 
            {
                guesses = 0;
                guessedchar.clear();
            }
            else if (input == 'n' || input == 'N')
            return 0;
            else {
                cout << "Invalid option please type either 'y' or 'n'" << endl;
            }
            }
        }
        else {
            cout << "\nCorrect...NOT. Try again." << endl;
            guesses += 2;
        }
        break;

        case 3: //when user wants to view all the guessed letter
        if (guessedchar.size() == 0) {
            cout << "\nYou have not guessed any letters" << endl;
        }
        else {
            cout << "\nguessed letters: ";
        copy(   guessedchar.begin(),
                guessedchar.end(),
                ostream_iterator<char>(cout," "));
                cout << endl;
        }
        break;

        case 4: //when user quits the game
        cout << "Quitting Game..."  << endl;
        return 0;
        break;

        default:
        cout << "Invalid option. Please input the correct option" << endl;
        }
        }
    }

    
