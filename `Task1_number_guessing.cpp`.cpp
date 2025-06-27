#include <iostream>
#include <cstdlib>  
#include <ctime>   

int main() {
    
    srand(time(0));

  
    int numberToGuess = rand() % 100 + 1;
    int userGuess;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I'm thinking of a number between 1 and 100.\n";

   
    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess > numberToGuess) {
            std::cout << "Too high! Try again.\n";
        } else if (userGuess < numberToGuess) {
            std::cout << "Too low! Try again.\n";
        }
    } while (userGuess != numberToGuess);

    std::cout << "Congratulations! You guessed the correct number!\n";

    return 0;
}

