#include "MonsterAI.h"
#include "Dungeon.h"
#include "CharactereLogic.h"
#include "Random.h"
#include <assert.h>

CMonsterAI::CMonsterAI()
           : _charactere(0),
             _lastAction(0)
{
}

CCharactereLogic& CMonsterAI::GetCharactere()
{
    assert(_charactere != 0);
    return *_charactere;
}

CMonsterAI::~CMonsterAI()
{
}

void CMonsterAI::SetCharactere(CCharactereLogic& charactere)
{
    _charactere = &charactere;
}

void CMonsterAI::Update(int timeLeft)
{
    return;
    _lastAction = _lastAction + timeLeft;
    if (_lastAction < 1000)
        return;

    //random set for the AI to move in the dungeon around
    int move = CRandom::RandRange(0, 4);

    CCharactereWorld* charWorld = static_cast<CCharactereWorld*> (_charactere->GetWorldEntity());
    C2DPosition charPosition = charWorld->GetPosition();
    
    //switch control to set the next position for the monster if possible
    switch (move)
    {
        case(0):
            _charactere->Move(C2DPosition(0, 1) + charPosition);
            break;
        case(1):
            _charactere->Move(C2DPosition(0, -1) + charPosition);
            break;
        case(2):
            _charactere->Move(C2DPosition(1, 0) + charPosition);
            break;
        case(3):
            _charactere->Move(C2DPosition(-1, 0) + charPosition);
            break;
    }
    _lastAction = 0;
}

