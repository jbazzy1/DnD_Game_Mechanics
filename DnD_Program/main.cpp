#include <iostream>
#include <ctime>
#include "stats.h"
#include "enemy_stats.h"
#include "combat.h"

int main() {
    std::srand(std::time(nullptr));
    EnemyStats enemyStats;
    Stats characterStats;

    std::string name;
    std::cout << "Welcome to D&D (Demo Edition)" << std::endl;
    std::cout << "Let's create a character." << std::endl;

    // Character name
    bool characterLoop = false;
    do {
        std::cout << "Enter a NAME: ";
        std::cin >> name;
        characterStats.setCharacterName(name);
        std::cout << "Hello, " << characterStats.getCharacterName() << std::endl;

        // Character class

        int classSelect;
        std::cout << "Enter the number of the class you want." << std::endl;
        std::cout << "1. Warrior" << std::endl;
        std::cout << "2. Mage" << std::endl;
        std::cout << "3. Rogue" << std::endl;

        bool validInput = false; // Stays false if no proper input is made, looping until otherwise
        do {
            std::cin >> classSelect;
            switch (classSelect) {
                case 1:
                    characterStats.setCharacterClass("Warrior");
                    characterStats.setMaxHP(15); // Sets maxHP to 15
                    validInput = true;
                    break;
                case 2:
                    characterStats.setCharacterClass("Mage");
                    characterStats.setMaxHP(9); // Sets maxHP to 9
                    validInput = true;
                    break;
                case 3:
                    characterStats.setCharacterClass("Rogue");
                    characterStats.setMaxHP(12); // Sets maxHP to 12
                    validInput = true;
                    break;
                default:
                    std::cout << "Invalid input." << std::endl;
                    std::cout << "Enter the number of the class you want." << std::endl;
                    std::cout << "1. Warrior" << std::endl;
                    std::cout << "2. Mage" << std::endl;
                    std::cout << "3. Rogue" << std::endl;
            }
        } while (!validInput);

        std::cout << "You have chosen to be a " << characterStats.getCharacterClass() << std::endl;

        int userInput, totalPoints = 60;

        while (totalPoints > 0 || totalPoints < 0)
        {
            totalPoints = 60; // Resets totalPoints to 60 if any points are remaining
            std::cout << std::endl;

            // STR stat

            validInput = false;
            while (!validInput) // validInput is true, running indefinitely until correct input entered
            {
                std::cout << "Enter a number between 8 and 15 for STR: ";
                std::cin >> userInput;
                if (userInput >= 8 && userInput <= 15) {
                    validInput = true;
                    characterStats.setStrength(userInput);
                    totalPoints -= userInput;
                    std::cout << "Points remaining: " << totalPoints << std::endl;
                } else {
                    std::cout << "Invalid input. Try again.\n";
                }
            }

            // DEX stat

            validInput = false; // Resets while loop for next stat
            while (!validInput) {
                std::cout << "Enter a number between 8 and 15 for DEX: ";
                std::cin >> userInput;
                if (userInput >= 8 && userInput <= 15) {
                    validInput = true;
                    characterStats.setDexterity(userInput);
                    totalPoints -= userInput;
                    std::cout << "Points remaining: " << totalPoints << std::endl;
                } else {
                    std::cout << "Invalid input. Try again.\n";
                }
            }

            // CHAR stat

            validInput = false;
            while (!validInput) {
                std::cout << "Enter a number between 8 and 15 for CHAR: ";
                std::cin >> userInput;
                if (userInput >= 8 && userInput <= 15) {
                    validInput = true;
                    characterStats.setCharisma(userInput);
                    totalPoints -= userInput;
                    std::cout << "Points remaining: " << totalPoints << std::endl;
                } else {
                    std::cout << "Invalid input. Try again.\n";
                }
            }

            // CONST stat

            validInput = false;
            while (!validInput) {
                std::cout << "Enter a number between 8 and 15 for CONST: ";
                std::cin >> userInput;
                if (userInput >= 8 && userInput <= 15) {
                    validInput = true;
                    characterStats.setConstitution(userInput);
                    totalPoints -= userInput;
                    std::cout << "Points remaining: " << totalPoints << std::endl;
                } else {
                    std::cout << "Invalid input. Try again.\n";
                }
            }

            // WIS stat

            validInput = false;
            while (!validInput) {
                std::cout << "Enter a number between 8 and 15 for WIS: ";
                std::cin >> userInput;
                if (userInput >= 8 && userInput <= 15) {
                    validInput = true;
                    characterStats.setWisdom(userInput);
                    totalPoints -= userInput;
                    std::cout << "Points remaining: " << totalPoints << std::endl;
                } else {
                    std::cout << "Invalid input. Try again.\n";
                }
            }

            // INT stat

            validInput = false; // Resets while loop for next stat
            while (!validInput) {
                std::cout << "Enter a number between 8 and 15 for INT: ";
                std::cin >> userInput;
                if (userInput >= 8 && userInput <= 15) {
                    validInput = true;
                    characterStats.setIntelligence(userInput);
                    totalPoints -= userInput;
                    std::cout << "Points remaining: " << totalPoints << std::endl;
                } else {
                    std::cout << "Invalid input. Try again.\n";
                }
            }
            if (totalPoints > 0) {
                std::cout << "You have unspent points. Please try again." << std::endl;
            }
            else if(totalPoints < 0)
            {
                std::cout << "Spent too many points. Please try again." << std::endl;
            }
            else
            {
                break;
            }
        }
        std::cout << "\n--Character Sheet--\n";
        std::cout << "Character Name: " << characterStats.getCharacterName() << std::endl;
        std::cout << "Character Class: " << characterStats.getCharacterClass() << std::endl;
        std::cout << "HP: " << characterStats.getMaxHP() << std::endl;
        std::cout << "STR: " << characterStats.getStrength() << std::endl;
        std::cout << "DEX: " << characterStats.getDexterity() << std::endl;
        std::cout << "CHAR: " << characterStats.getCharisma() << std::endl;
        std::cout << "CONST: " << characterStats.getConstitution() << std::endl;
        std::cout << "WIS: " << characterStats.getWisdom() << std::endl;
        std::cout << "INT: " << characterStats.getIntelligence() << std::endl;
        characterStats.setCurrentHP(characterStats.getMaxHP()); // Initializes currentHP

        std::string continueInput;

        std::cout << "\nContinue with this character? Enter 'Y' or 'N': ";
        std::cin >> continueInput;
        bool continueLoop = false;
        do {
            if (continueInput == "y" || continueInput == "Y") {
                std::cout << "Continuing with character." << std::endl << std::endl;
                continueLoop = true; // Sets continueLoop to true to break out of do-while loop
                characterLoop = true; // Sets characterLoop to true to break out of character creation loop
            } else if (continueInput == "n" || continueInput == "N") {
                std::cout << "Resetting... " << std::endl << std::endl;
                break;
            } else {
                std::cout << "Invalid input. Try again.";
                std::cin >> continueInput;
            }
        } while(!continueLoop);
    } while(!characterLoop);

    std::cout << "You awaken in a cave." << std::endl;

    // Example of combat

    enemyStats.setEnemyName("Goblin");
    enemyStats.setMaxHP(20);
    enemyStats.setAttack(1);

    std::cout << "You see an enemy ahead of you." << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << enemyStats.getEnemyName() << std::endl;
    std::cout << enemyStats.getMaxHP() << " HP" << std::endl;

    Combat::startCombat(characterStats, enemyStats);

    std::cout << "END DEMO" << std::endl;


    return 0;
}
