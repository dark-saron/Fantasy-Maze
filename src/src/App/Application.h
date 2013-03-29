#pragma once

#include "src/App/Phase.h"
#include "src/Core/Thread.h"

class CApplication : public CThread
{
public:

    CApplication();
    ~CApplication();

    // getter / setter
    CPhase& GetPhase() const;

    int Run();
    void DrawPhase();
    CPhase::EType RunPhase(int timeLeft);
    
    // changes to another phase
    void Transition(CPhase::EType newPhase);

private:
    
    CPhase* _phase;
    
};

