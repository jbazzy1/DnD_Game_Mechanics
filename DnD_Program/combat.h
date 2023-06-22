//
// Created by Bazzy on 6/13/2023.
//

#ifndef DND_PROGRAM_COMBAT_H
#define DND_PROGRAM_COMBAT_H
#include <cstdlib>
#include <ctime>
#include "stats.h"
#include "enemy_stats.h"

// Randomized dice roll

int rollDice(int numDice, int numSides)
{
    int total = 0;
    for(int i = 0; i < numDice; i++)
    {
        total += (rand() % numSides) + 1;
    }
    return total;
}

// Combat class

class Combat{
public:
    static void startCombat(Stats &characterStats, EnemyStats &enemyStats){
        bool playerTurn = true;

        // Sets the Current HP to Max HP before combat starts
        characterStats.setCurrentHP(characterStats.getMaxHP()); // MaxHP for character declared by user input
        enemyStats.setCurrentHP(enemyStats.getMaxHP()); // MaxHP for enemy declared in main

        // Stays in loop until player or enemy HP hits 0

        while(characterStats.getCurrentHP() > 0 && enemyStats.getCurrentHP() > 0)
        {
            if(playerTurn) // Player goes first
            {
                // Checks for class to determine which stat to use as attackBonus, then determines attackBonus
                int attackBonus = 0;
                int playerAttack;
                std::string characterClass = characterStats.getCharacterClass();
                if(characterClass == "Warrior")
                {
                    int strength = characterStats.getStrength();
                    if(strength >= 10 && strength <= 12)
                    {
                        attackBonus = 1;
                    }
                    else if(strength >= 13 && strength <= 14)
                    {
                        attackBonus = 2;
                    }
                    else if(strength >= 15)
                    {
                        attackBonus = 3;
                    }
                    else
                    {
                        attackBonus = 0;
                    }
                }
                else if(characterClass == "Mage")
                {
                    int intelligence = characterStats.getIntelligence();
                    if(intelligence >= 10 && intelligence <= 12)
                    {
                        attackBonus = 1;
                    }
                    else if(intelligence >= 13 && intelligence <= 14)
                    {
                        attackBonus = 2;
                    }
                    else if(intelligence >= 15)
                    {
                        attackBonus = 3;
                    }
                    else
                    {
                        attackBonus = 0;
                    }
                }
                else if(characterClass == "Rogue")
                {
                    int dexterity = characterStats.getDexterity();
                    if(dexterity >= 10 && dexterity <= 12)
                    {
                        attackBonus = 1;
                    }
                    else if(dexterity >= 13 && dexterity <= 14)
                    {
                        attackBonus = 2;
                    }
                    else if(dexterity >= 15)
                    {
                        attackBonus = 3;
                    }
                    else
                    {
                        attackBonus = 0;
                    }
                }
                else
                {
                    std::cout << "Invalid class. Self-destructing.";
                }

                // Enemy defense determines how much of the attack is absorbed before removing HP
                int playerRoll = rollDice(1,6);
                playerAttack = playerRoll + attackBonus;
                int enemyDefense = rollDice(1,6);
                int damageDealt = playerAttack - enemyDefense;

                std::string combatInput;
                std::cout << "Attack or Flee? (A/F): ";
                std::cin >> combatInput;
                std::cin.ignore();
                if(combatInput == "A" || combatInput == "a")
                {
                    std::cout << "------------" << std::endl;
                    std::cout << "You attack the " << enemyStats.getEnemyName() << std::endl; // Set name in main program
                    std::cout << "You roll a " << playerRoll << " with an Attack Bonus of " << attackBonus << std::endl;
                    std::cout << "The enemy rolls a " << enemyDefense << std::endl;
                    std::cout << "------------" << std::endl;
                    if(damageDealt > 0)
                    {
                        std::cout << "You hit the " << enemyStats.getEnemyName() << " for " << damageDealt << std::endl;
                        enemyStats.setCurrentHP(enemyStats.getCurrentHP() - damageDealt);
                    }
                    else
                    {
                        std::cout << "You missed!" << std::endl;
                    }
                    std::cout << "Press Enter to Continue" << std::endl;
                    std::cout << "------------";
                    std::cin.ignore();
                    playerTurn = !playerTurn;
                }
                else if(combatInput == "F" || combatInput == "f") // If player wants to flee, check dex and roll die
                {
                    int dexterity = characterStats.getDexterity();
                    int fleeTotal = dexterity + playerRoll;
                    std::cout << "------------" << std::endl;
                    std::cout << "In an attempt to flee, you roll a " << playerRoll << std::endl;
                    std::cout << "------------" << std::endl;
                    if(fleeTotal >= 15)
                    {
                        break; // Breaks out of combatLoop
                    }
                    else
                    {
                        std::cout << "You trip and fall, taking 1 damage to HP." << std::endl;
                        characterStats.setCurrentHP(characterStats.getCurrentHP() - 1);
                        playerTurn = !playerTurn;
                    }
                }
                else
                {
                    std::cout << "Invalid input. Try again." << std::endl << std::endl;
                    std::cout << "------------" << std::endl;
                }
            }
            else // Enemy's turn (need to set enemyAttack in main program)
            {
                int enemyAttack = rollDice(1,6) + enemyStats.getAttack();
                int playerDefense = rollDice(1,6);
                int damageDealt = enemyAttack - playerDefense;

                // Calculations

                std::cout << enemyStats.getEnemyName() << " rolls a " << enemyAttack - enemyStats.getAttack() <<
                          " with a Base Attack of " << enemyStats.getAttack() << std::endl;
                std::cout << "You roll a " << playerDefense << std::endl;
                if(damageDealt > 0)
                {
                    std::cout << enemyStats.getEnemyName() << " hits you for " << damageDealt << std::endl;
                    characterStats.setCurrentHP(characterStats.getCurrentHP() - damageDealt);
                }
                else
                {
                    std::cout << "The enemy misses!" << std::endl;
                }
                std::cout << "Press Enter to Continue" << std::endl;
                std::cout << "------------";
                std::cin.ignore();
                playerTurn = !playerTurn;
            }

            // Prints HP of player and enemy

            std::cout << "Player HP: " << characterStats.getCurrentHP() << std::endl;
            std::cout << enemyStats.getEnemyName() << " HP: " << enemyStats.getCurrentHP() << std::endl;
            std::cout << "------------" << std::endl;
        }
        if(characterStats.getCurrentHP() > 0 && enemyStats.getCurrentHP() <= 0)
        {
            std::cout << "You won!" << std::endl;
        }
        else if(characterStats.getCurrentHP() <= 0 && enemyStats.getCurrentHP() > 0)
        {
            std::cout << "You lose!" << std::endl;
        }
        else if(characterStats.getCurrentHP() > 0 && enemyStats.getCurrentHP() > 0)
        {
            std::cout << "Fled successfully!" << std::endl;
        }
        else
        {
            std::cout << "Stalemate..?" << std::endl;
        }
    }
};

#endif //DND_PROGRAM_COMBAT_H
