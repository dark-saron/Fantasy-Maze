#include "CharactereWorld.h"

#include "Dungeon.h"

CCharactereWorld::CCharactereWorld()
                 : CWorldEntity(),
                   _pos(C2DPosition(0, 0)),
                   _currentHealth(1),
                   _currentMana(1),
                   _defense(0),
                   _attack(0),
                   _level(1), 
                   _expTillNextLevel(0),
                   _gainedExp(0),
                   _team(CCharactereWorld::monster),
                   _maxHealth(1),
                   _maxMana(1),
                   _viewRange(2)
{
    CDungeon::GetInstance().AddCharactere(*this);
}

CCharactereWorld::~CCharactereWorld()
{
    CDungeon::GetInstance().RemoveCharactere(*this);
}

//////////////////////////////////////////
///Data Setter/Getter
/////////////////////////////////////////

int CCharactereWorld::GetAttack() const
{
    return _attack;
}

int CCharactereWorld::GetDefense() const
{
    return _defense;
}

int CCharactereWorld::GetGainedExp() const
{
    return _gainedExp;
}

int CCharactereWorld::GetHealth() const
{
    return _currentHealth;
}

int CCharactereWorld::GetIncAttack() const
{
    return _incAttack;
}

int CCharactereWorld::GetIncDefence() const
{
    return _incDefence;
}

int CCharactereWorld::GetIncHealth() const
{
    return _incHealth;
}

int CCharactereWorld::GetIncMana() const
{
    return _incMana;
}

int CCharactereWorld::GetLevel() const
{
    return _level;
}

int CCharactereWorld::GetMana() const
{
    return _currentMana;
}

int CCharactereWorld::GetMaxHealth() const
{
    return _maxHealth;
}

int CCharactereWorld::GetMaxMana() const
{
    return _maxMana;
}

int CCharactereWorld::GetNeedExpTillLvlUp() const
{
    return _expTillNextLevel;
}

const C2DPosition& CCharactereWorld::GetPosition() const
{
    return _pos;
}

CCharactereWorld::EType CCharactereWorld::GetTeam() const
{
    return _team;
}

int CCharactereWorld::GetViewRange() const
{
    return _viewRange;
}

void CCharactereWorld::SetHealth(int health)
{
    _currentHealth = health;
}

void CCharactereWorld::SetMana(int mana)
{
    _currentMana = mana;
}

void CCharactereWorld::SetNeedExpTillLvlUp(int exp)
{
    _expTillNextLevel = exp;
}


void CCharactereWorld::AddAttack(int attack)
{
    _attack += attack;
}

void CCharactereWorld::AddDefense(int defense)
{
    _defense += defense;
}

void CCharactereWorld::AddGainedExp(int exp)
{
    _gainedExp += exp;
}

void CCharactereWorld::SetIncAttack(int incAtk)
{
    _incAttack = incAtk;
}

void CCharactereWorld::SetIncDefence(int incDef)
{
    _incDefence = incDef;
}

void CCharactereWorld::SetIncHealth(int incHP)
{
    _incHealth = incHP;
}

void CCharactereWorld::SetIncMana(int incMana)
{
    _incMana = incMana;
}

void CCharactereWorld::AddLevel(int level)
{
    _level += level;
}

void CCharactereWorld::AddMaxHealth(int health)
{
    _maxHealth += health;
}

void CCharactereWorld::AddMaxMana(int mana)
{
    _maxMana += mana;
}

void CCharactereWorld::AddNeedExpTillLvlUp(int exp)
{
    _expTillNextLevel += exp;
}

void CCharactereWorld::SetPosition(const C2DPosition& pos)
{
    CDungeon::GetInstance().CharactereMove(*this, _pos, pos);
    _pos = pos;
}

void CCharactereWorld::SetTeam(CCharactereWorld::EType team)
{
    _team = team;
}

void CCharactereWorld::SetViewRange(int view)
{
    _viewRange = view;
}

bool CCharactereWorld::IsDead() const
{
    return (_currentHealth <= 0);
}

bool CCharactereWorld::InArea(const C2DPosition& start, const C2DPosition& end) const
{
    return (start.GetXPos() <= _pos.GetXPos() && _pos.GetXPos() <= end.GetXPos() &&
            start.GetYPos() <= _pos.GetYPos() && _pos.GetYPos() <= end.GetYPos());
}

CCharactereWorld* CCharactereWorld::GetVisibleCharacters() 
{
    
    C2DPosition posBegin = this->GetPosition() - this->GetViewRange();
    C2DPosition posEnd   = this->GetPosition() + this->GetViewRange();
             
    return CDungeon::GetInstance().GetCharactersInArea(posBegin, posEnd); 
}

void CCharactereWorld::Load(const json::Object& charData)
{
    // TODO: Fehlerabfangen, falls Element nicht existieren sollt

    const json::Number& attack  = charData["Attack"];
    const json::Number& defense = charData["Defense"];
    const json::Number& health  = charData["Health"];
    const json::Number& mana    = charData["Mana"];
    const json::Number& incdef  = charData["IncDefense"];
    const json::Number& inchp   = charData["IncHealth"];
    const json::Number& incmp   = charData["IncMana"];
    const json::Number& incatk  = charData["IncAttack"];
    const json::String& typeID  = charData["ID"];

    _maxHealth   = _currentHealth = std::max(1, (int)health);
    _maxMana     = _currentMana   = std::max(1, (int)mana);
    
    _attack      = attack;
    _defense     = defense;
    _incAttack   = incatk;
    _incDefence  = incdef;
    _incHealth   = inchp;
    _incMana     = incmp;

    SetTypeID(typeID);
}