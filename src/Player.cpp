#include "Player.h"
#include "CharactereLogic.h"

#include <assert.h>

CPlayer::CPlayer(): 
        _charactere(0),
        _input(SDirection::none)
{
}

void CPlayer::SetCharactere(CCharactereLogic& charactere)
{
    _charactere = &charactere;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Update(int timeLeft)
{
    C2DPosition move;
    switch(_input)
    {
        case(SDirection::east):  move = C2DPosition(0,-1); break;
        case(SDirection::west):  move = C2DPosition(0,1); break;
        case(SDirection::north): move = C2DPosition(-1,0); break;
        case(SDirection::south): move = C2DPosition(1,0); break;
        default: return;
    }
    CCharactereWorld* charWorld = static_cast<CCharactereWorld*> (_charactere->GetWorldEntity());
    _charactere->Move(charWorld->GetPosition() + move);
    _input = SDirection::none;
}

void CPlayer::SetInput(SDirection::EType input)
{
    _input = input;
}

CCharactereLogic& CPlayer::GetCharactere()
{
    assert(_charactere != 0);
    return *_charactere;
}
