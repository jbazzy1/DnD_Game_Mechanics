//
// Created by Bazzy on 6/13/2023.
//

#ifndef DND_PROGRAM_ENEMY_STATS_H
#define DND_PROGRAM_ENEMY_STATS_H

#include <string>

class EnemyStats{
public:

    // Constructor

    EnemyStats();

    // Getters

    int getAttack() const;
    int getMaxHP() const;
    int getCurrentHP() const;
    std::string getEnemyName() const;

    // Setters

    void setAttack(int attack);
    void setMaxHP(int maxHP);
    void setCurrentHP(int currentHP);
    void setEnemyName(const std::string &name);

private:
    int attack;
    int maxHP;
    int currentHP;
    std::string enemyName;
};


#endif //DND_PROGRAM_ENEMY_STATS_H
