//
// Created by Bazzy on 6/7/2023.
//

#ifndef DND_PROGRAM_STATS_H
#define DND_PROGRAM_STATS_H

#include <string>

class Stats {
public:
    // Constructor
    Stats();
    Stats(int strength, int dexterity, int charisma, int constitution, int wisdom, int intelligence, int maxHP, int currentHP);

    // Getters

    int getStrength() const;
    int getDexterity() const;
    int getCharisma() const;
    int getConstitution() const;
    int getWisdom() const;
    int getIntelligence() const;
    int getMaxHP() const;
    int getCurrentHP() const;
    std::string getCharacterName() const;
    std::string getCharacterClass() const;

    // Setters
    void setStrength(int strength);
    void setDexterity(int dexterity);
    void setCharisma(int charisma);
    void setConstitution(int constitution);
    void setWisdom(int wisdom);
    void setIntelligence(int intelligence);
    void setMaxHP(int maxHP);
    void setCurrentHP(int currentHP);
    void setCharacterName(const std::string &name);
    void setCharacterClass(const std::string &charClass);

private:
    int strength;
    int dexterity;
    int charisma;
    int constitution;
    int wisdom;
    int intelligence;
    int maxHP{};
    int currentHP{};
    std::string characterName;
    std::string characterClass;
};

#endif //DND_PROGRAM_STATS_H
