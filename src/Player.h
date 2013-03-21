#pragma once
#include "CharactereLogic.h"
#include "UserInput.h"

class CPlayer
{
public:
    CPlayer();
    ~CPlayer();

    CCharactereLogic& GetCharactere();
    SUserInput::EType GetInput() const;
    void SetCharactere(CCharactereLogic& charactere);

    void Update(int timeLeft);
    void SetInput(SUserInput::EType input);

private:
    CCharactereLogic* _charactere;
    SUserInput::EType _input;
};

