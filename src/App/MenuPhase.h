#pragma once

#include "src/App/Phase.h"

//nicht im prototypen
class CMenuPhase : public CPhase
{

public:

    //constructor/destructor
    CMenuPhase();
    ~CMenuPhase();

    //setter/getter
    CPhase::EType GetPhase() const;

    //functions
    void Begin();
    void Draw();
    void End();
    CPhase::EType Run(int timeLeft);
};

