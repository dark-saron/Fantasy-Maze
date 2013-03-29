#include "CellTypeWorld.h"

#include "Dungeon.h"


CCellTypeWorld::CCellTypeWorld()
         : CWorldEntity(),
          _type('?'),
           _attributes(0)
{

    CDungeon::GetInstance().AddCellType(*this);
}


CCellTypeWorld::~CCellTypeWorld()
{
    CDungeon::GetInstance().RemoveCellType(*this);
}




bool CCellTypeWorld::IsSolid() const
{
    return GetAttribute(CCellTypeWorld::SOLID);
}

bool CCellTypeWorld::GetAttribute(int flag) const
{
   return _attributes && flag;
}

void CCellTypeWorld::SetSolid(bool value)
{
    SetAttribute(CCellTypeWorld::SOLID, value);
}

void CCellTypeWorld::SetAttribute(int flag, bool value)
{
    // TODO: it should be possible in one line
    if (value)
        _attributes = _attributes | flag;
    else
        _attributes = _attributes & ~flag;

}

int CCellTypeWorld::GetAttributes() const
{
    return _attributes;
}

void CCellTypeWorld::SetAttributes(int attributes)
{
    _attributes = attributes;
}

char CCellTypeWorld::GetType() const
{
    return _type;
}

void CCellTypeWorld::SetType(char value)
{
    CDungeon::GetInstance().RemoveCellType(*this);
    _type = value;
    CDungeon::GetInstance().AddCellType(*this);
}