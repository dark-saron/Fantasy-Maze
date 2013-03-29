#pragma once

#include "src/Data/WorldEntity.h"
class CLogicEntity
{
public:
    CLogicEntity(void);
    ~CLogicEntity(void);

    void SetWorldEntity(CWorldEntity* worldEntity);
    CWorldEntity* GetWorldEntity();

private:

    CWorldEntity* _worldEntity;

};

