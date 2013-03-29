#pragma once

#include <string>

class CWorldEntity
{

public:

    //constructor/destructor
    CWorldEntity();
    ~CWorldEntity();


    //getter/setter
    void* GetGraphicEntity();
    void* GetLogicEntity();
    const std::string& GetTypeID() const;

    CWorldEntity* GetNext();
    CWorldEntity* GetPrev();
    void SetTypeID(const std::string& typeID);

    void SetGraphicEntity(void* graphicEntity);
    void SetLogicEntity(void* logicEntity);

    void SetNext(CWorldEntity* next);
    void SetPrev(CWorldEntity* prev);

private:

    void* _graphicEntity;
    void* _logicEntity;
    CWorldEntity* _next;
    CWorldEntity* _prev;
    
    std::string _typeID;
    
};

