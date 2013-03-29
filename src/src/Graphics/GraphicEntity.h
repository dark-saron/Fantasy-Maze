#pragma once

#include "src/Data/WorldEntity.h"

class CGraphicEntity
{
public:
    CGraphicEntity();
    ~CGraphicEntity();

    CWorldEntity* GetWorldEntity();
    void SetWorldEntity(CWorldEntity* worldEntity);

private:
    CWorldEntity* _worldEntity;
};

