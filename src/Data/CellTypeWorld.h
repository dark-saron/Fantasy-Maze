#pragma once

#include "src/Data/WorldEntity.h"
#include "src/Data/CellTypeWorld.h"
#include "src/Core/2DPosition.h"

class CCellTypeWorld : public CWorldEntity
{
public:
    //constructor/destructor
    CCellTypeWorld();
    ~CCellTypeWorld();

    //setter/getter
    char GetType() const;

    void SetSolid(bool value);
    void SetType(char value);
    
    bool IsSolid() const;


    

private:
    
    bool GetAttribute(int flag) const;
    int GetAttributes() const;
    void SetAttribute(int flag, bool value);
    void SetAttributes(int attributes);

    // Flags für die Attribute
    static const int SOLID = 1;
    static const int MOVABLE = 2;
    static const int BREAKABLE = 4;

    int _attributes;
    char _type;
};

