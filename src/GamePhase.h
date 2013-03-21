#pragma once

#include "Phase.h"

class CGamePhase : public CPhase
{

public:
   
	//Functions
    ~CGamePhase();
    CGamePhase();
	void Begin();
    void Draw();
    void End();
    CPhase::EType Run(int timeLeft);

    //Setter/Getter
    CPhase::EType GetPhase() const;
    
};

