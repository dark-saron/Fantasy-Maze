#pragma once
#include "src/Logic/CharactereLogic.h"
#include "src/Data/Direction.h"

class CPlayer
{
public:
    CPlayer();
    ~CPlayer();

    CCharactereLogic& GetCharactere();
    void SetCharactere(CCharactereLogic& charactere);

    void Update(int timeLeft);
    void SetInput(SDirection::EType input);

private:
    CCharactereLogic* _charactere;
    SDirection::EType _input;
};

