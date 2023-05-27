#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberGuesser {
private:
    int secretNumber;
    int minRange;
    int maxRange;
    int numAttempts;

public:
    NumberGuesser(int rangeMin, int rangeMax, int attempts) {
        minRange = rangeMin;
        maxRange = rangeMax;
        numAttempts = attempts;
        srand(time(0));
        secretNumber = rand() % (maxRange - minRange + 1) + minRange;
    }

    void playGame() {
        int guess;
        bool found = false;

        cout << "Welcome to Number Guesser!" << endl;
        cout << "I'm thinking of a number between " << minRange << " and " << maxRange << "." << endl;

        while (numAttempts > 0 && !found) {
            cout << "Attempts left: " << numAttempts << endl;
            cout << "Enter your guess: ";
            cin >> guess;

            if (guess < secretNumber) {
                cout << "Too low! Try guessing a higher number." << endl;
                minRange = guess + 1;
            } else if (guess > secretNumber) {
                cout << "Too high! Try guessing a lower number." << endl;
                maxRange = guess - 1;
            } else {
                cout << "Congratulations! You guessed the number: " << secretNumber << endl;
                found = true;
            }

            numAttempts--;
        }

        if (!found) {
            cout << "Game over! You ran out of attempts. The number was: " << secretNumber << endl;
        }
    }
};

int main() {
    // Create a NumberGuesser object with a range from 1 to 100 and 10 attempts
    NumberGuesser game(1, 100, 10);
    
    // Start the game
    game.playGame();
    
    return 0;
}
