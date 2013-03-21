#include "Connector.h"

#include "Logic.h"

#include <assert.h>

CConnector::CConnector()
{
}


CConnector::~CConnector()
{
}





///////////////////////////////////////////////////////////////
/// _singleton functions
//////////////////////////////////////////////////////////////

CConnector* CConnector::_singleton =  0;

//gets the instance of the singleton
CConnector& CConnector::GetInstance()
{
    assert(_singleton != 0);

    return *_singleton;
}

//creates the instance of the singleton
void CConnector::CreateInstance()
{
    assert(_singleton == 0);

    CConnector::_singleton = new CConnector();
}

//gives the memory free from the singleton and sets it back 0
void CConnector::DestroyInstance()
{
    assert(_singleton != 0);

    delete _singleton;
    _singleton = 0;
}

//gives true back if singleton is set
bool CConnector::IsValid()
{
    return _singleton != 0;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
