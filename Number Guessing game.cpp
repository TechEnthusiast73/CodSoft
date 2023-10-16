#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int random_number = rand() % 100 + 1;
    int guess;

    do {
        cout << "Enter a number between 1 and 100: ";

        
        if (!(cin >> guess)) {
            cout << "Invalid input. Please enter a number between 1 and 100." << endl;
            cin.clear(); 

            
            while (cin.get() != '\n') {
                continue;
            }

            continue; 
        }

        if (guess > 100) {
            cout << "Invalid input. Please enter a number between 1 and 100." << endl;
        }
        else if (guess > random_number) {
            cout << "The guess is too high. Try again." << endl;
        }
        else if (guess < random_number) {
            cout << "The guess is too low. Try again." << endl;
        }
    } while (guess != random_number);

    cout << "YOU HAVE GUESSED IT RIGHT! CONGRATULATIONS!" << endl;

    return 0;
}
