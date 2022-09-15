#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

using namespace std;

HANDLE h0ut = GetStdHandle(STD_OUTPUT_HANDLE);

int mistakes = 0, points = 0, total_mistakes = 0;

string check(char user_guess, string password, string word_to_guess);
void show_the_hangman(int mistakes);
int check_if_done(string word, string coded_word);

/* ------------------------------------------------------------------ */

int main()
{

    char guess;
    int option, level = 1;
    string word = "HAMBURGER";
    string coded_word = "H--B---E-";

    while (true)
    {

        SetConsoleTextAttribute(h0ut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        cout << "         WELCOME TO THE HANGMAN GAME" << endl << endl;
        cout << "1. Play" << endl;
        cout << "2. Exit" << endl;
        cout << "3. How the game works? // Principles of operation" << endl << endl;
        cout << "Choose option: "; cin >> option;

        if (option == 1)
        {
            system("cls");

            while(true)
            {

                SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
                cout << "WARNING! Please write only UPPERCASE LETTERS or your answer will not be correct!" << endl;
                SetConsoleTextAttribute(h0ut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                cout << "------------------------------------------------------------" << endl;
                cout << "Mistakes: " << mistakes << "        Current Level: " << level << "       Your Points: " << points << endl;
                cout << "------------------------------------------------------------" << endl;
                show_the_hangman(mistakes);
                cout << "------------------------------------------------------------" << endl;

                if (mistakes == 9)
                {
                    SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
                    cout << "YOU LOST" << endl;
                    SetConsoleTextAttribute(h0ut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                    cout << "Total points: " << points << endl;
                    cout << "Total mistakes: " << total_mistakes << endl;
                    Sleep(1000);
                    cout << "Leaving the game..." << endl;
                    Sleep(3000);
                    exit(0);
                }

                cout << "Your word to guess: " << coded_word << endl;

                if (check_if_done(word, coded_word) == 1)
                {
                        if (level == 10)
                        {
                            cout << endl;
                            SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
                            cout << "YOU WON! You have completed all levels!" << endl;
                            cout << "Total points: " << points << endl;
                            cout << "Total mistakes: " << total_mistakes << endl;
                            Sleep(1000);
                            SetConsoleTextAttribute(h0ut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                            cout << "Leaving the game..." << endl;
                            Sleep(7500);
                            exit(0);
                        }
                        int aftergame_option;
                        cout << endl;
                        SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
                        cout << "Congratulations, you passed level " << level << endl;
                        level++;
                        SetConsoleTextAttribute(h0ut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                        cout << "Do you want to continue or EXIT the game?  " << endl;
                        cout << "1. Continue" << endl;
                        cout << "2. Exit" << endl;
                        cout << "Type number: "; cin >> aftergame_option;
                        system ("cls");

                        if(aftergame_option == 1)
                        {
                            switch (level)
                            {
                                case 1: { word = "HAMBURGER";   coded_word = "H--B---E-";       }    break;
                                case 2: { word = "PIZZA";       coded_word = "P---A";           }    break;
                                case 3: { word = "HEADPHONES";  coded_word = "HE---HO-E-";      }    break;
                                case 4: { word = "KEYBOARD";    coded_word = "--Y-O---";        }    break;
                                case 5: { word = "MONEY";       coded_word = "--N-Y";           }    break;
                                case 6: { word = "BLUEBERRIES"; coded_word = "B---B-RR--S";     }    break;
                                case 7: { word = "KRYSTIAN";    coded_word = "K--ST-AN";        }    break;
                                case 8: { word = "DISCORD";     coded_word = "DI--O-D";         }    break;
                                case 9: { word = "PROTEIN";     coded_word = "PRO----";         }    break;
                                case 10:{ word = "SPOON";       coded_word = "S-OO-";           }    break;
                            }
                            cout << "Generating..." << endl;
                            mistakes = 0;
                            Sleep(2000);
                            system("cls");
                            continue;
                        }


                    else if (aftergame_option == 2)
                    {
                        exit(0);
                    }

                    else
                    {
                        cout << "Wrong option!!!" << endl;
                    }

                    system("cls");

                }

                cout << "Your guess: "; cin >> guess;
                cout << endl;

                coded_word = check(guess, coded_word, word);

                system("cls");
            }
        }

        else if (option == 2)
            exit(0);

        else if (option == 3)   {
            int side_option;
            system("cls");
            SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "The game was made by Krystian Stanik, student of " << endl;
            cout << "Technical School in Zespol Szkol Elektronicznych im. Bohaterow Westerplatte w Radomiu in Poland" << endl << endl;
            cout << "How the game works? // (What you can do and consequences of that)" << endl;
            cout << "- You can guess more than 1 letter at the same time but be aware that if the word is guessed and" << endl;
            cout << "  there are still some letters that you entered, the game may not work how you would like to work" << endl;
            cout << "- If you enter lowercase letter the answer will not be correct" << endl;
            cout << "- If you enter a number instead of a letter the answer will not be correct " << endl;
            cout << "  (obvious but still I'm gonna write this here)" << endl << endl;
            cout << "Return to the menu - (1 - yes, 0 - no (exit the program) : "; cin >> side_option;
            if (side_option == 1)
            {
                system("cls");
                continue;
            }

            else if (side_option == 0)
                exit(0);
            else
            {
                cout << "Huh so you're funny, then we will end the game" << endl;
                exit(0);
            }
        }
        else    {
            cout << "Error!!! " << endl;
            Sleep(500);
            system("cls");

        }
    }
}


string check(char user_guess, string password, string word_to_guess) {

    int how_long = password.length();
    int letter_guessed;
    for (int i = 0; i < how_long; i++)
    {
        if (word_to_guess[i] == user_guess && password[i] == '-')
        {
            password[i] = word_to_guess[i];
            letter_guessed ++;
            points ++;
        }
    }
    if (letter_guessed == 1)
        cout << "Very good! +1 points!" << endl;
    else if (letter_guessed > 1)
        cout << "Very Good! +"<< letter_guessed << " points" << endl;
    else {
        cout << user_guess << " is not here, or you have already guessed that!" << endl;
        Sleep(1000);
        mistakes++;
        total_mistakes++;
    }

    Sleep(2000);

    return password;
}

int check_if_done(string word, string coded_word)
{
    int x = 0;
    int length = word.length();
    for (int i = 0; i < length; i++)
    {
        if (coded_word[i] == word[i])
            x++;
    }

    if (x == length)
        x = 1;
    else x = 0;

    return x;
}

void show_the_hangman(int mistakes) {

    if (mistakes == 0) {
        cout << endl;
        cout << "No hangman" << endl;
        cout << endl;
    }
    else if (mistakes == 1) {
        cout << "                  " <<endl;
        cout << "                  "<< endl;
        cout << "                  "<< endl;
        cout << "                  "<< endl;
        cout << "                  "<< endl;
        cout << "                  " <<endl;
        cout << "                  "<< endl;
        cout << "                  "<< endl;
        cout << "  O00O            " << endl;
    }
    else if (mistakes == 2) {
        cout << "                  " <<endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             " <<endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "  O00O            " << endl;
    }
    else if (mistakes == 3) {
        cout << "   _____________  " <<endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             " <<endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "  O00O            " << endl;
    }
    else if (mistakes == 4) {
        cout << "   _____________  " <<endl;
        cout << "   || /           "<< endl;
        cout << "   ||/            "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             " <<endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "  O00O            " << endl;
    }
    else if (mistakes == 5) {
        cout << "   _____________  " <<endl;
        cout << "   || /       |   "<< endl;
        cout << "   ||/        |   "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             " <<endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "  O00O            " << endl;
    }
    else if (mistakes == 6) {
        cout << "   _____________  " <<endl;
        cout << "   || /       |   "<< endl;
        cout << "   ||/        |   "<< endl;
        cout << "   ||         o   "<< endl;
        cout << "   ||             "<< endl;
        cout << "   ||             " <<endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "  O00O            " << endl;
    }
    else if (mistakes == 7) {
        cout << "   _____________  " <<endl;
        cout << "   || /       |   "<< endl;
        cout << "   ||/        |   "<< endl;
        cout << "   ||         o   "<< endl;
        cout << "   ||         O   "<< endl;
        cout << "   ||         O   " <<endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "  O00O            " << endl;
    }
    else if (mistakes == 8) {
        cout << "   _____________  " <<endl;
        cout << "   || /       |   "<< endl;
        cout << "   ||/        |   "<< endl;
        cout << "   ||         o   "<< endl;
        cout << "   ||       --O-- "<< endl;
        cout << "   ||         O   " <<endl;
        cout << "   ||             "<< endl;
        cout << "   ||             "<< endl;
        cout << "  O00O            " << endl;
    }
    else if (mistakes == 9) {
        cout << "   _____________  " <<endl;
        cout << "   || /       |   "<< endl;
        cout << "   ||/        |   "<< endl;
        cout << "   ||         o   "<< endl;
        cout << "   ||       --O-- "<< endl;
        cout << "   ||         O   " <<endl;
        cout << "   ||        /|   "<< endl;
        cout << "   ||             "<< endl;
        cout << "  O00O            " << endl;
    }
}



