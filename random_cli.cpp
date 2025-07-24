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

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <min> <max>\n";
        return 1;
    }

    int min = std::atoi(argv[1]);
    int max = std::atoi(argv[2]);

    if (min > max) {
        std::cerr << "Error: min must be less than or equal to max.\n";
        return 1;
    }

    int number = getRandomNumber(min, max);
    std::cout << "🎲 Random Number between " << min << " and " << max << ": " << number << "\n";

    return 0;
}
