#include "src/Graphics/Connector.h"

#include "src/Logic/Logic.h"
#include "src/Graphics/Graphic.h"
#include "src/Data/CharactereWorld.h"
#include "src/Logic/Player.h"

#include <assert.h>

CConnector::CConnector()
{
}


CConnector::~CConnector()
{
}

void CConnector::ContinueGame()
{
    _action = game;
}

void CConnector::StartGame(bool multiplayer)
{
    CLogic::GetInstance().StartLevel(1, 1 + multiplayer, true);
    ContinueGame();
}

CCharactereWorld* CConnector::GetPlayerCharactere(int playerNr)
{
    CPlayer* player = CLogic::GetInstance().GetPlayer(playerNr);
    if (!player) return 0;
    
    return static_cast<CCharactereWorld*> (player->GetCharactere().GetWorldEntity());
}

CConnector::EType CConnector::TakeAction()
{
    CConnector::EType ret = _action;
    _action = CConnector::none;
    return ret;
}

void CConnector::ToggleMenu()
{
    _action = back;
}

void CConnector::Exit()
{
    _action = exit;
}

void CConnector::Input(int playerNr, SDirection::EType input)
{
    if (CLogic::GetInstance().GetPlayer(playerNr))
        CLogic::GetInstance().GetPlayer(playerNr)->SetInput(input);
}

///////////////////////////////////////////////////////////////
/// _singleton functions
//////////////////////////////////////////////////////////////

CConnector* CConnector::_singleton =  0;

//gets the instance of the singleton
CConnector& CConnector::GetInstance()
{
    assert(_singleton != 0);

    return *_singleton;
}

//creates the instance of the singleton
void CConnector::CreateInstance()
{
    assert(_singleton == 0);

    CConnector::_singleton = new CConnector();
}

//gives the memory free from the singleton and sets it back 0
void CConnector::DestroyInstance()
{
    assert(_singleton != 0);

    delete _singleton;
    _singleton = 0;
}

//gives true back if singleton is set
bool CConnector::IsValid()
{
    return _singleton != 0;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
