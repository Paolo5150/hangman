#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <charconv>
#include <algorithm>
#include <iterator>
#include <stdio.h>

using namespace std;

void print(int guesses = 0) { // print the hangman
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

void printoptions() { //print options
    cout << "\nSelect One The Following Option:" <<
            "\n[1] Guess a letter" <<
            "\n[2] Guess the word" <<
            "\n[3] Check guessed letters" <<
            "\n[4] View options again" <<
            "\n[5] Quit game" << endl <<
            "[6] Check Current Word (FOR TESTING ONLY)\n";
}

int main(){
    char input{}; //for user's letter guesses
    int choice{}; //for user choice
    string wordinput{}; //for when user wants to guess the entire word
    vector<char> guessedchar{}; //array for all the letters the user have guessed
    vector<string> list{"special", "random", "roast", "firetruck", "throw", "trend", "blast", "gasoline"};
    
    srand (time(NULL));
    int random = rand() % list.size(); //randomise the word
    string word = list[random-1];
    
    int guesses{}; // number of guesses by the user
    printoptions();

    while (guesses <= 10) { 
        cout << "Remaining Guesses: " << 10 - guesses << endl;
        print(guesses); //print hangman

        if (guesses == 10) { //if user has lost the game
            cout << "\nMission Failed. We'll get them next time." << endl;
        }

        else if (guesses < 10) //if user still has guesses remaining
        
        cout << "\nChoose your option: ";
        cin >> choice;

        while (cin.fail()) //check for valid input
            {
                cout << "Invalid Input. Please enter a valid number. Enter '4' to view options again" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
            }

        switch (choice) 
        {

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
                input = ' '; //resets the char 'input'
                cout << "Would you like to play again? (Y/N)" << endl;
                while (input != 'y' || input != 'Y') {
                cin >> input;
                if (input == 'y' || input == 'Y') 
                {
                    guesses = 0;
                    guessedchar.clear();
                    srand (time(NULL));
                    int random = rand() % list.size(); //randomise the word
                    string word = list[random-1];
                    printoptions();
                    break;
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

        case 5:
            printoptions();
        break;

        case 6: //FOR TESTING ONLY, checks current word
            cout << word<< "\n" << endl;
        break;

        default:
            cout << "Invalid option. Please enter a valid number. Enter '5' to view options again" << endl;
        break;
        }
        }
    }
