#include "WorldEntity.h"


CWorldEntity::CWorldEntity()
             : _logicEntity(0),
               _graphicEntity(0),
               _next(0),
               _prev(0)
{
}

const std::string& CWorldEntity::GetTypeID() const
{
    return _typeID;
}

void CWorldEntity::SetTypeID(const std::string& typeID)
{
    _typeID = typeID;
}

CWorldEntity::~CWorldEntity()
{
}

void* CWorldEntity::GetGraphicEntity()
{
    return _graphicEntity;
}

void* CWorldEntity::GetLogicEntity()
{
    return _logicEntity;
}

CWorldEntity* CWorldEntity::GetNext()
{
    return _next;
}

CWorldEntity* CWorldEntity::GetPrev()
{
    return _prev;
}


void CWorldEntity::SetGraphicEntity(void* graphicEntity)
{
    _graphicEntity = graphicEntity;
}

void CWorldEntity::SetLogicEntity(void* logicEntity)
{
    _logicEntity = logicEntity;
}

void CWorldEntity::SetNext(CWorldEntity* next)
{
    _next = next;
}

void CWorldEntity::SetPrev(CWorldEntity* prev)
{
    _prev = prev;
}

