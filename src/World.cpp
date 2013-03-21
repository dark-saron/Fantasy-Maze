#include "World.h"
#include "Dungeon.h"
#include <assert.h>

CWorld* CWorld::_singleton = 0;

CWorld::CWorld()
{
}

//creates the instance of the singleton
void CWorld::CreateInstance()
{

    assert(_singleton == NULL);

    _singleton = new CWorld();

}

//gets the instance of the singleton
CWorld& CWorld::GetInstance()
{

    assert(_singleton != NULL);

    return *_singleton;
}

//gives the memory free from the singleton and sets it back NULL
void CWorld::DestroyInstance()
{

    assert(_singleton != NULL);

    delete _singleton;
    _singleton = NULL;

}

//valid singleton if singleton is set
bool CWorld::IsValid()
{
    if(_singleton == NULL)
        return false;
    return true;
}


CWorld::~CWorld()
{

    DestroyInstance();

}

//remove dead entities in the dungeon
void CWorld::RemoveDeadEntities()
{
    CDungeon::GetInstance().RemoveDeadEntities();
}
