//
// Created by Bazzy on 6/13/2023.
//

#include "enemy_stats.h"

EnemyStats::EnemyStats(): attack(0), maxHP(0), currentHP(0) {}

int EnemyStats::getAttack() const {
    return attack;
}
int EnemyStats::getMaxHP() const {
    return maxHP;
}
int EnemyStats::getCurrentHP() const {
    return currentHP;
}
std::string EnemyStats::getEnemyName() const {
    return enemyName;
}

void EnemyStats::setAttack(int attack) {
    this->attack = attack;
}
void EnemyStats::setMaxHP(int maxHP) {
    this->maxHP = maxHP;
}
void EnemyStats::setCurrentHP(int currentHP) {
    this->currentHP = currentHP;
}
void EnemyStats::setEnemyName(const std::string &name) {
    enemyName = name;
}