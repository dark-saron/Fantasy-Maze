#pragma once

#include "WorldEntity.h"
#include "2DPosition.h"

#include "json/elements.h"



class CCharactereWorld : public CWorldEntity
{
public:

    enum EType
    {
        monster,
        player0,
        player1,
        sizeOf
    };
    
    //constructor/destructors
    CCharactereWorld();
    CCharactereWorld(const C2DPosition<> &pos, int health, int mana, CCharactereWorld::EType team);
    ~CCharactereWorld();
    
    //setter/getter
    int GetAttack() const;
    int GetDefense() const;
    int GetGainedExp() const;
    int GetHealth() const;
    int GetIncAttack() const;
    int GetIncDefence() const;
    int GetIncHealth() const;
    int GetIncMana() const;
    int GetLevel() const;
    int GetMana() const;
    int GetMaxHealth() const;
    int GetMaxMana() const;
    int GetNeedExpTillLvlUp() const;
    const C2DPosition<>& GetPosition() const;
    int GetViewRange() const;
    EType GetTeam() const;

    void SetMana(int manaPoints);
    void SetHealth(int healthPoints);
    void SetNeedExpTillLvlUp(int exp);
    void SetIncAttack(int incAtk);
    void SetIncDefence(int incDef);
    void SetIncHealth(int incHealth);
    void SetIncMana(int incMana);
    void SetPosition(const C2DPosition<>& pos);
    void SetViewRange(int view);
    void SetTeam(EType team);
    
    void Load(const json::Object& charData);
    
    //functions
    void AddAttack(int strength);
    void AddDefense(int defence);
    void AddHealth(int healPoints);
    void AddGainedExp(int exp);
    void AddLevel(int level);
    void AddMana(int manaPoints);
    void AddMaxHealth(int health);
    void AddMaxMana(int mana);
    void AddNeedExpTillLvlUp(int exp);
    bool IsDead() const;
    bool InArea(const C2DPosition<>& start, const C2DPosition<>& end) const;
    CCharactereWorld* GetVisibleCharacters();

private:
    
    C2DPosition<> _pos;

    int _currentHealth;
    int _currentMana;
    
    //start_stats
    int _attack;
    int _defense;
    int _expTillNextLevel;
    int _gainedExp;
    int _incAttack;
    int _incDefence;
    int _incHealth;
    int _incMana;
    int _level;
    int _maxHealth;
    int _maxMana;
    int _viewRange;
    
    EType _team;

};

