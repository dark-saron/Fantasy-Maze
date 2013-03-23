#include "MenuPhase.h"

#include "Dungeon.h"
#include "Connector.h"
#include "Logic.h"
#include "Graphic.h"
#include "MenuGraphic.h"


CMenuPhase::CMenuPhase()
{

}


CMenuPhase::~CMenuPhase()
{
}

CPhase::EType CMenuPhase::GetPhase() const
{
    return CPhase::menu;
}

//calls the Start functions of the Logic/Graphic
void CMenuPhase::Begin()
{
    CGraphic::GetInstance().SetWidget(CWindowGraphic::menu);
}

//draw phase of the menu (supposed to call the grafic draw the menu buttons (where later the dungeon will be displayed)
void CMenuPhase::Draw()
{
    CGraphic::GetInstance().Draw();
}

//ending the Phase, calls the remove of the widget for the menu and sets phase parameter of the game which phase will be set next
void CMenuPhase::End()
{
}

//Run Phase goes till the user will chose either exit oder one of the game options 
CPhase::EType CMenuPhase::Run(int timeLeft)
{
    switch(CConnector::GetInstance().TakeAction())
    {    
    case CConnector::game:
        return CPhase::game;
        
    case CConnector::exit:
        return CPhase::exit;
    
    case CConnector::back:
        if (CLogic::GetInstance().GetPlayer(0))
            return CPhase::game;
    }

    return CPhase::menu;
}