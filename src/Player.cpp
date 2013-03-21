#include "Player.h"
#include "CharactereLogic.h"

#include <assert.h>

CPlayer::CPlayer(): 
        _charactere(0),
        _input(SUserInput::none)
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
        case(SUserInput::east):  move = C2DPosition(0,-1); break;
        case(SUserInput::west):  move = C2DPosition(0,1); break;
        case(SUserInput::north): move = C2DPosition(-1,0); break;
        case(SUserInput::south): move = C2DPosition(1,0); break;
        default: return;
    }
    CCharactereWorld* charWorld = (CCharactereWorld*) _charactere->GetWorldEntity();
    _charactere->Move(charWorld->GetPosition() + move);
    _input = SUserInput::none;
}

void CPlayer::SetInput(SUserInput::EType input)
{
    _input = input;
}

CCharactereLogic& CPlayer::GetCharactere()
{
    assert(_charactere != 0);
    return *_charactere;
}

SUserInput::EType CPlayer::GetInput() const
{
    return _input;
}