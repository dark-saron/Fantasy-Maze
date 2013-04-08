#include "src/Graphics/GraphicEntity.h"

#include "src/App/Config.h"

CGraphicEntity::CGraphicEntity()
{
}

CGraphicEntity::~CGraphicEntity()
{
    if (_worldEntity)
        _worldEntity->SetGraphicEntity(0);
}

CWorldEntity* CGraphicEntity::GetWorldEntity()
{
    return _worldEntity;
}

void CGraphicEntity::SetWorldEntity(CWorldEntity* worldEntity)
{
    _worldEntity = worldEntity;
    if (_worldEntity)
        _worldEntity->SetGraphicEntity(this);
}

