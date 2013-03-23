#pragma once

#include "logicentity.h"
#include "CharactereWorld.h"
#include "Dungeon.h"

#include "json/elements.h"

class CCharactereLogic : public CLogicEntity
{

public:
    //constructor/destructor
    CCharactereLogic();
    ~CCharactereLogic();

    //functions
    bool AddExp(int gainedExp);
    bool Attack(CCharactereWorld& enemy);
    bool Defend(int damage);
    int GetLevelExp();
    bool Killed(const CCharactereWorld& charactere);
    void LevelUp(int levelUp = 1);
    bool Move(const C2DPosition<>& newpos);

    void SetHealth(int health);
    void SetMana(int mana);
    void AddHealth(int healPoints);
    void AddMana(int manaPoints);
};

