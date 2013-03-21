#pragma once

#include "Phase.h"
#include "Thread.h"

class CApplication : public CThread
{

public:

    ~CApplication();
	CApplication();
    CPhase::EType RunPhase(int timeLeft);
    int Run();
    void DrawPhase();
    void Transition(CPhase::EType newPhase);

    // getter / setter
    CPhase& GetPhase() const;
    
private:
    
    CPhase* _phase;
    
};

