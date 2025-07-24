#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max) {
    static bool seed_initialized = false;
    if (!seed_initialized) {
        std::srand(std::time(0));
        seed_initialized = true;
    }
    return (std::rand() % (max - min + 1)) + min;
}

int main() {
    int min = 1, max = 100;
    int numberToGuess = getRandomNumber(min, max);
    int guess;
    int attempts = 0;

    std::cout << "🎯 Welcome to the Number Guessing Game!\n";
    std::cout << "Guess a number between " << min << " and " << max << ".\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > numberToGuess)
            std::cout << "Too high! Try again.\n";
        else if (guess < numberToGuess)
            std::cout << "Too low! Try again.\n";
        else
            std::cout << "🎉 Correct! You guessed it in " << attempts << " attempts.\n";

    } while (guess != numberToGuess);

    return 0;
}
