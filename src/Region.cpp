#include "Region.h"

#include "CharactereWorld.h"
#include "CellTypeWorld.h"
#include "Dungeon.h"

CRegion::CRegion(int regionX, int regionY)
        : _characters(std::list<CCharactereWorld*> ()),
          _regionX(regionX),
          _regionY(regionY)
{
    for (int x = 0; x < MAX_X; ++x)
    {
        for (int y = 0; y < MAX_Y; ++y)
        {
            _cells[x][y] = 0;
        }
    }
}

CRegion::~CRegion()
{

}

//return specific cell in the array
const CCellTypeWorld* CRegion::GetCell(const C2DPosition& pos) const
{
    int cellX = pos.GetXPos() % MAX_X;
    int cellY = pos.GetYPos() % MAX_Y;
    
    return _cells[cellX][cellY];
}

//gets all characters in the area(regions) of the given positions
CCharactereWorld* CRegion::GetCharactersInArea(const C2DPosition& start, const C2DPosition& end)
{
    CCharactereWorld* first = 0;
    CCharactereWorld* last = 0;
    CCharactereWorld* charactere = 0;
    
    std::list<CCharactereWorld*>::const_iterator it = _characters.begin(); 
    
    for(;it != _characters.end(); ++it)
    {
        charactere = (*it);
        if (charactere->InArea(start, end))
        {
            if (!first) 
            {
                last = first = *it;
            }
            charactere->SetNext(first);
            charactere->SetPrev(last);
            first->SetPrev(charactere);
            last->SetNext(charactere);
            last = charactere;
        }
    }   

   return first;
}

//init setting of the level region
bool CRegion::Load(const json::Object& region)
{
	//todo static cast
    _regionX = (const json::Number) region["X"];
    _regionY = (const json::Number) region["Y"];

    std::string cells = (const json::String) region["Cells"];
    if (cells.length() < MAX_X * MAX_Y)
        return false;
    
    int index = 0;
    for (int x = 0; x < MAX_X; ++x)
    {
        for (int y = 0; y < MAX_Y; ++y)
        {
            _cells[x][y] = CDungeon::GetInstance().GetCellType(cells[index]);
            index++;
        }
    }

    return true;
}

//removes specific character from the character list
void CRegion::RemoveCharactere(CCharactereWorld& charactere)
{
    _characters.remove(&charactere);
}

//add character to the character list
void CRegion::AddCharactere(CCharactereWorld& charactere)
{
    _characters.push_back(&charactere);
}

int CRegion::GetSizeX()
{
    return CRegion::MAX_X;
}

int CRegion::GetSizeY()
{
    return CRegion::MAX_Y;
}