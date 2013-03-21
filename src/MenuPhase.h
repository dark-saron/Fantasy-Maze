#pragma once
#include "phase.h"

//nicht im prototypen
class CMenuPhase : public CPhase
{

public:

    //functions
    ~CMenuPhase();
    CMenuPhase();
    void Begin();
    void Draw();
    void End();
    CPhase::EType Run(int timeLeft);

    //setter/getter
    CPhase::EType GetPhase() const;

};

