#include "src/App/GamePhase.h"

#include "src/Data/Dungeon.h"
#include "src/Logic/Logic.h"
#include "src/Graphics/Graphic.h"
#include "src/Logic/Player.h"
#include "src/Graphics/Connector.h"

CGamePhase::CGamePhase()
{
    
}


CGamePhase::~CGamePhase()
{
}


CPhase::EType CGamePhase::GetPhase() const 
{
    return CPhase::game;
}

//draw phase of the game (supposed to call the grafic draw the dungeon during the game)
void CGamePhase::Draw()
{
    CGraphic::GetInstance().Draw();
}

//calls the Start functions of the Logic/Dungeons/Graphic
void CGamePhase::Begin()
{
    CGraphic::GetInstance().SetWidget(CWindowGraphic::game);
}

//ending the Phase, calls all resets of the singletons to set them back to start init
void CGamePhase::End()
{
}


//Run Phase let one round go with actions before removing the dead entities and redrawing the new dungeon grafic
CPhase::EType CGamePhase::Run(int timeLeft)
{

    CLogic::GetInstance().ComputeRound(timeLeft);
    
    //remove the killed/taken entities from the game
    CLogic::GetInstance().RemoveDeadEntities();
    CGraphic::GetInstance().RemoveDeadEntities();
    CLogic::GetInstance().ClearTrash();
     
    //call of the Draw to refresh the dungeon grafic
    Draw();
    

    switch (CConnector::GetInstance().TakeAction())
    {
    case (CConnector::exit):
        return CPhase::exit;

    case (CConnector::back):
        return CPhase::menu;

    }

    if(!CLogic::GetInstance().GetPlayer(0) && !CLogic::GetInstance().GetPlayer(0))
    {
        return CPhase::menu;
    }
    else if(CLogic::GetInstance().GetNPCAmount() == 0)
    {
        CLogic& logic = CLogic::GetInstance();
        int players = (logic.GetPlayer(0) != 0) + (logic.GetPlayer(1) != 0);
        CLogic::GetInstance().StartLevel(CDungeon::GetInstance().GetLevel(), players, false);
    }

     return CPhase::game;
}

