//
// Created by Bazzy on 6/7/2023.
//
#include "stats.h"

Stats::Stats(): strength(0), dexterity(0), charisma(0), constitution(0), wisdom(0), intelligence(0) {}

Stats::Stats(int strength, int dexterity, int charisma, int constitution, int wisdom, int intelligence, int maxHP, int currentHP)
    : strength(strength), dexterity(dexterity), charisma(charisma), constitution(constitution), wisdom(wisdom),
    intelligence(intelligence), maxHP(maxHP), currentHP(currentHP){}

// Getters

int Stats::getStrength() const {
    return strength;
}
int Stats::getDexterity() const {
    return dexterity;
}
int Stats::getCharisma() const {
    return charisma;
}
int Stats::getConstitution() const {
    return constitution;
}
int Stats::getWisdom() const {
    return wisdom;
}
int Stats::getIntelligence() const {
    return intelligence;
}
int Stats::getMaxHP() const {
    return maxHP;
}
int Stats::getCurrentHP() const {
    return currentHP;
}
std::string Stats::getCharacterName() const {
    return characterName;
}
std::string Stats::getCharacterClass() const {
    return characterClass;
}
// Setters

void Stats::setStrength(int strength) {
    this->strength = strength;
}
void Stats::setDexterity(int dexterity) {
    this->dexterity = dexterity;
}
void Stats::setCharisma(int charisma) {
    this->charisma = charisma;
}
void Stats::setConstitution(int constitution) {
    this->constitution = constitution;
}
void Stats::setWisdom(int wisdom) {
    this->wisdom = wisdom;
}
void Stats::setIntelligence(int intelligence) {
    this->intelligence = intelligence;
}
void Stats::setMaxHP(int maxHP) {
    this->maxHP = maxHP;
}
void Stats::setCurrentHP(int currentHP) {
    this->currentHP = currentHP;
}
void Stats::setCharacterName(const std::string &name) {
    characterName = name;
}
void Stats::setCharacterClass(const std::string &charClass) {
    characterClass = charClass;
}