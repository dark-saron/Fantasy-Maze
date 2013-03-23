#pragma once

#include "CharactereLogic.h"

class CMonsterAI
{

public:

    //constructor/destructor
    CMonsterAI();
    ~CMonsterAI();

    //getter/setter
    void SetCharactere(CCharactereLogic& charactere);
    CCharactereLogic& GetCharactere();
    
    //functions
    void Update(int timeLeft);
    
private:
    int _lastAction;
    CCharactereLogic* _charactere;
    
};

