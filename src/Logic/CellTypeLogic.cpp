#include "src/Logic/CellTypeLogic.h"

#include "src/Data/CellTypeWorld.h"

CCellTypeLogic::CCellTypeLogic()
               : CLogicEntity() 
{
    this->SetWorldEntity(new CCellTypeWorld());
    this->GetWorldEntity()->SetLogicEntity(this);
}


CCellTypeLogic::~CCellTypeLogic()
{
    delete this->GetWorldEntity();
}
