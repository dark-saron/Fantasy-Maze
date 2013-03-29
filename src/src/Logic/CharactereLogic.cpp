#include "src/Logic/CharactereLogic.h"

#include "src/Data/WorldIterator.h"

CCharactereLogic::CCharactereLogic()
{
    this->SetWorldEntity(new CCharactereWorld());
    this->GetWorldEntity()->SetLogicEntity(this);
}


CCharactereLogic::~CCharactereLogic()
{
    CCharactereWorld* charWorld = static_cast<CCharactereWorld*> (GetWorldEntity());
    CDungeon::GetInstance().RemoveCharactere(*charWorld);
    delete charWorld;
}


//TODO: code ordentlicher gestalten
//adds exp
bool CCharactereLogic::AddExp(int gainedExp)
{
    CCharactereWorld* character = static_cast<CCharactereWorld*> (this->GetWorldEntity());

    if(gainedExp + character->GetNeedExpTillLvlUp() < GetLevelExp())    
    {
        character->SetNeedExpTillLvlUp(character->GetNeedExpTillLvlUp() + gainedExp);
        character->AddGainedExp(gainedExp);
    }
    else    
    {
        gainedExp -= (GetLevelExp() - character->GetNeedExpTillLvlUp() );
        character->AddGainedExp(GetLevelExp() - character->GetNeedExpTillLvlUp());

        LevelUp();
        AddExp(gainedExp);
    }
    
    return true;
}

//attack enemy
bool CCharactereLogic::Attack(CCharactereWorld& enemy)
{
    if(enemy.IsDead())
        return false;
    
    CCharactereWorld* attacker = static_cast<CCharactereWorld*> (this->GetWorldEntity());
    CCharactereLogic* enemyLogic = static_cast<CCharactereLogic*> (enemy.GetLogicEntity());
    
    if(enemyLogic->Defend(attacker->GetAttack()))
        this->AddExp(enemy.GetLevel());
    
    return true;
}

//defend from incoming attack
bool CCharactereLogic::Defend(int damage)
{
    CCharactereWorld* defender = static_cast<CCharactereWorld*> (this->GetWorldEntity());
    AddHealth(std::min(0, defender->GetDefense() - damage));

    return defender->GetHealth() == 0;
}

//gets the exp which the level needs to be reached
int CCharactereLogic::GetLevelExp()
{
    CCharactereWorld* character = static_cast<CCharactereWorld*> (this->GetWorldEntity());

    return pow(character->GetLevel(), 2.0);
}

//calls functions to raid the killed character
bool CCharactereLogic::Killed(const CCharactereWorld& charactere)
{

    AddExp(charactere.GetLevel());
    return charactere.IsDead();

}

//true is only returned if the user changes position
bool CCharactereLogic::Move(const C2DPosition<>& newPos)
{
    CCharactereWorld* charWorld = static_cast<CCharactereWorld*> (this->GetWorldEntity());
    CCharactereWorld* regionChar = CDungeon::GetInstance().GetCharacters(newPos);

    IWorldIterator iter = IWorldIterator(regionChar);

    for (; iter.FirstLoop(); ++iter)
    {
        if (!regionChar->IsDead())
        {
            if (regionChar->GetTeam() != charWorld->GetTeam())
                this->Attack(*regionChar);

            return false;
        }
    }

    const CCellTypeWorld& cell = CDungeon::GetInstance().GetCell(newPos);
    if (cell.IsSolid())
        return false;

    charWorld->SetPosition(newPos);
    return true;

}

void CCharactereLogic::LevelUp(int levelUp)
{
    CCharactereWorld* character = static_cast<CCharactereWorld*> (this->GetWorldEntity());
    //increase all stats
    character->AddAttack(character->GetIncAttack() * levelUp);
    character->AddDefense(character->GetIncDefence() * levelUp);
    character->AddMaxHealth(character->GetIncHealth() * levelUp);
    character->AddMaxMana(character->GetIncMana() * levelUp);
    character->AddLevel(levelUp);

    character->SetNeedExpTillLvlUp(0);

    //recharge Mana and Health
    SetHealth(character->GetMaxHealth());
    SetMana(character->GetMaxMana());
}


void CCharactereLogic::SetHealth(int health)
{
    CCharactereWorld* charWorld = static_cast<CCharactereWorld*> (GetWorldEntity());
    int realHealth = std::max(0, std::min(health, charWorld->GetMaxHealth()));
    charWorld->SetHealth(realHealth);
}

void CCharactereLogic::SetMana(int mana)
{
    CCharactereWorld* charWorld = static_cast<CCharactereWorld*> (GetWorldEntity());
    int realMana = std::max(0, std::min(mana, charWorld->GetMaxMana()));
    charWorld->SetMana(realMana);
}

void CCharactereLogic::AddHealth(int healPoints)
{
    CCharactereWorld* charWorld = static_cast<CCharactereWorld*> (GetWorldEntity());
    SetHealth(charWorld->GetHealth() + healPoints);
}

void CCharactereLogic::AddMana(int manaPoints)
{
    CCharactereWorld* charWorld = static_cast<CCharactereWorld*> (GetWorldEntity());
    SetMana(charWorld->GetMana() + manaPoints);
}

