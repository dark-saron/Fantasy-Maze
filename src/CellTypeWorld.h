#pragma once

#include "WorldEntity.h"
#include "CellTypeWorld.h"
#include "2DPosition.h"

class CCellTypeWorld : public CWorldEntity
{

public:

	//functions
	~CCellTypeWorld();
    CCellTypeWorld();
	bool IsSolid() const;

    //setter/getter
    char GetType() const;
    void SetSolid(bool value);
    void SetType(char value);
    
    
private:
    
    bool GetAttribute(int flag) const;
    int GetAttributes() const;
    void SetAttribute(int flag, bool value);
    void SetAttributes(int attributes);

    // Flags für die Attribute
    static const int BREAKABLE = 4;
	static const int MOVABLE = 2;
    static const int SOLID = 1;
    
    int _attributes;
    char _type;

};

