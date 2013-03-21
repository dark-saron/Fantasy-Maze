#pragma once

#include "CharactereLogic.h"

class CMonsterAI
{

public:

    //functions
    ~CMonsterAI();
    CMonsterAI();
    void Update(int timeLeft);

    //getter/setter
    void SetCharactere(CCharactereLogic& charactere);
    CCharactereLogic& GetCharactere();
    
private:

	CCharactereLogic* _charactere;
    int _lastAction;
    
};

