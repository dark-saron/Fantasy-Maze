#include "GamePhase.h"

#include "Dungeon.h"
#include "Logic.h"
#include "Graphic.h"
#include "Player.h"

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
    CLogic::GetInstance().EventManager();
    
    if (CLogic::GetInstance().GetExit())
        return CPhase::exit;
    else if(CLogic::GetInstance().GetPlayer(0)->GetInput() ==  SUserInput::back)
    {
        //TODO: change so the actions gets away
        CGraphic::GetInstance().SetAction();
        
        return CPhase::menu;
    }
    else
        return CPhase::game;

}

