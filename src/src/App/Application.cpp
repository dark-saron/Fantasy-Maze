#include "src/App/Application.h"

#include "src/App/Config.h"
#include "src/Graphics/Connector.h"
#include "src/Data/Dungeon.h"
#include "src/Graphics/Graphic.h"
#include "src/Logic/Logic.h"

#include "src/App/GamePhase.h"
#include "src/App/MenuPhase.h"

#include <assert.h>
#include <iostream>
#include <time.h>


CApplication::CApplication()
             : CThread(),
               _phase(0)
               
{
    //calling the inits from all singletons
    CConfig::CreateInstance();
    CConfig::GetInstance().LoadConfig();

    CConnector::CreateInstance();

    CDungeon::CreateInstance();
    CLogic::CreateInstance();
    CGraphic::CreateInstance();

    CLogic::GetInstance().Start();
    CGraphic::GetInstance().Start();

    Transition(CPhase::menu);
}


CApplication::~CApplication()
{
    _phase->End();
    delete _phase;

    CGraphic::DestroyInstance();
    CLogic::DestroyInstance();
    CDungeon::DestroyInstance();
    
    CConnector::DestroyInstance();
    CConfig::DestroyInstance();

}

CPhase& CApplication::GetPhase() const
{
    assert(_phase != 0);
    return *_phase;
}

void CApplication::DrawPhase()
{
    assert(_phase != 0);
    _phase->Draw();
}

// Run phase will go in a endless loop which calls the drawing and change phase every 100 miliseconds
int CApplication::Run()
{
    CPhase::EType newPhase = CPhase::unknown;

    // TODO: change timeLeft to the real difference between two times
    // but will require platform dependent code
    int timeLeft = 100;
    while (true)
    {
        newPhase = RunPhase(timeLeft);
        if (newPhase == CPhase::exit) break;

        DrawPhase();
        Transition(newPhase);
        
        Sleep(timeLeft);
    }
    
    return 0;

}

// call of the current Run method from the set phase
CPhase::EType CApplication::RunPhase(int timeLeft)
{
    assert(_phase != 0);
    return _phase->Run(timeLeft);
}

void CApplication::Transition(CPhase::EType newPhase)
{
    assert(CPhase::exit != newPhase);
    assert(CPhase::unknown != newPhase);

    if(_phase != 0)
    {
        if (newPhase == _phase->GetPhase()) return;

        _phase->End();
        delete _phase;
        _phase = 0;
    }

    switch(newPhase)
    {
    case(CPhase::game):
        _phase = new CGamePhase(); break;

    case (CPhase::menu):
        _phase = new CMenuPhase(); break;
    }

    assert(_phase != 0);
    _phase->Begin();
}