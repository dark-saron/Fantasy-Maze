#pragma once

#include <string>

class CWorldEntity
{

public:

    //constructor/destructor
    ~CWorldEntity();
    CWorldEntity();


    //getter/setter
    const std::string& GetTypeID() const;
    CWorldEntity* GetNext();
    CWorldEntity* GetPrev();
    void* GetGraphicEntity();
    void* GetLogicEntity();

    void SetGraphicEntity(void* graphicEntity);
    void SetNext(CWorldEntity* next);
    void SetPrev(CWorldEntity* prev);
    void SetLogicEntity(void* logicEntity);
    void SetTypeID(const std::string& typeID);

private:

    CWorldEntity* _next;
    CWorldEntity* _prev;    
    std::string _typeID;
    void* _graphicEntity;
    void* _logicEntity;

};

