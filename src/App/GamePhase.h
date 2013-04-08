#pragma once

#include "Phase.h"

class CGamePhase : public CPhase
{
public:
    CGamePhase();
    ~CGamePhase();
    
    //Setter/Getter
    CPhase::EType GetPhase() const;
    
    //Functions
    void Begin();
    void Draw();
    void End();
    CPhase::EType Run(int timeLeft);

    
private:

};

