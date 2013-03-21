#include "LogicEntity.h"


CLogicEntity::CLogicEntity()
{
}


CLogicEntity::~CLogicEntity()
{
}

void CLogicEntity::SetWorldEntity(CWorldEntity* worldEntity)
{
    _worldEntity = worldEntity;
}

CWorldEntity* CLogicEntity::GetWorldEntity()
{
    return _worldEntity;
}