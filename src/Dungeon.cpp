#include "Dungeon.h"
#include "CharactereWorld.h"

#include <assert.h>


CDungeon* CDungeon::_singleton = 0;

CDungeon::CDungeon()
         : _standardCellType(0),
           _level(0)
{
    //sets the regions in the array
    for (int regionX = 0; regionX< AMOUNT_REGION_X; ++regionX)
    {
        for (int regionY = 0; regionY < AMOUNT_REGION_Y; ++regionY)
        {
            _regions[regionX][regionY] = CRegion(regionX, regionY);
        }
    }

    
}

//calls the destroy for the singleton
CDungeon::~CDungeon()
{
}

//gives the amount of regions back in the Y
int CDungeon::GetAmountRegionX() const
{
    return AMOUNT_REGION_X;
}

//gives the amount of regions back in the Y
int CDungeon::GetAmountRegionY() const
{
    return AMOUNT_REGION_Y;
}

//gets the ref of a specific cell from a given position out of the region_array
const CCellTypeWorld& CDungeon::GetCell(const C2DPosition& pos) const
{
    int regionX = pos.GetXPos() / CRegion::GetSizeX();
    int regionY = pos.GetYPos() / CRegion::GetSizeY();
    const CCellTypeWorld* ret = 0;
    
    if (pos.GetXPos() >= 0 && GetSizeX() > pos.GetXPos() &&
        pos.GetYPos() >= 0 && GetSizeY() > pos.GetYPos() &&
        regionX >= 0 && regionX < AMOUNT_REGION_X &&
        regionY >= 0 && regionY < AMOUNT_REGION_Y)
        ret = _regions[regionX][regionY].GetCell(pos);
    
    if (!ret)
        ret = _standardCellType;
    
    return *ret;
}

CCharactereWorld* CDungeon::GetCharacters(const C2DPosition& pos)
{
    return GetCharactersInArea(pos, pos);
}

//the characters in a specific region get read out
CCharactereWorld* CDungeon::GetCharactersInArea(const C2DPosition& start, const C2DPosition& end)
{
    int startRegionX = start.GetXPos() / CRegion::GetSizeX();
    int startRegionY = start.GetYPos() / CRegion::GetSizeY();

    int endRegionX = end.GetXPos() / CRegion::GetSizeX();
    int endRegionY = end.GetYPos() / CRegion::GetSizeY();
    
    CWorldEntity* first = 0;
    CWorldEntity* temp = 0;


    for (int regionX = startRegionX; regionX <= endRegionX; ++regionX)
    {
        for (int regionY = startRegionY; regionY <= endRegionY; ++regionY)
        {
            if ((regionX >= 0 && regionX < AMOUNT_REGION_X) &&
                (regionY >= 0 && regionY < AMOUNT_REGION_Y))
            {
                temp = _regions[regionX][regionY].GetCharactersInArea(start, end);
                if (!temp) continue;
                if (first)
                {
                    CWorldEntity* next1 = first->GetNext();
                    CWorldEntity* last2 = temp->GetPrev();
                    first->SetNext(temp);
                    temp->SetPrev(temp);

                    last2->SetNext(next1);
                    next1->SetPrev(last2);
                }
                else
                {
                    first = temp;
                    temp = 0;
                }
            }
        }
    }

    return (CCharactereWorld*) first;
}

CCharactereWorld* CDungeon::GetAllCharacters()
{
    return GetCharactersInArea(C2DPosition(0,0), GetSize());
}

//get dungeon level
int CDungeon::GetLevel() const
{
    return _level;
}

const C2DPosition CDungeon::GetSize()
{
    return C2DPosition(GetSizeX(), GetSizeY());
}

//size of the dungeons in X
int CDungeon::GetSizeX()
{
    return AMOUNT_REGION_X * CRegion::GetSizeX();
}

//size of the dungeon in Y
int CDungeon::GetSizeY()
{
    return AMOUNT_REGION_Y * CRegion::GetSizeY();
}

//loads the dungeon depending on the level in the initial state
bool CDungeon::Load(const json::Array& regions, int level) //file read how the level should look like
{
    _level = level;
    
    json::Array::const_iterator iter(regions.Begin());
    json::Array::const_iterator iterEnd(regions.End());
    for (; iter != iterEnd; ++iter)
    {
        const json::Object& region = *iter;
        const json::Number& posX   = region["X"];
        const json::Number& posY   = region["Y"];

        int regionX = posX;
        int regionY = posY;

        if (!_regions[regionX][regionY].Load(region))
            return false;
    }

    return true;
}

void CDungeon::AddCharactere(CCharactereWorld& charactere)
{
    const C2DPosition& pos = charactere.GetPosition();
    int regionX = pos.GetXPos() / CRegion::GetSizeX();
    int regionY = pos.GetYPos() / CRegion::GetSizeY();
    
    _regions[regionX ][regionY].AddCharactere(charactere);
}

void CDungeon::RemoveCharactere(CCharactereWorld& charactere)
{
    const C2DPosition& pos = charactere.GetPosition();
    int regionX = pos.GetXPos() / CRegion::GetSizeX();
    int regionY = pos.GetYPos() / CRegion::GetSizeY();
    
    _regions[regionX ][regionY].RemoveCharactere(charactere);
}

//moves player from one region to the next if player gets out of the current region s/he is in
void CDungeon::CharactereMove(CCharactereWorld& charactere, const C2DPosition& oldPos, const C2DPosition& newPos)
{
    int oldRegionX = oldPos.GetXPos() / CRegion::GetSizeX();
    int oldRegionY = oldPos.GetYPos() / CRegion::GetSizeY();

    int newRegionX = newPos.GetXPos() / CRegion::GetSizeX();
    int newRegionY = newPos.GetYPos() / CRegion::GetSizeY();

    if (oldRegionX != newRegionX || oldRegionY != newRegionY)
    {
        // In case, the charactere is not on the field, we dont need to remove it from another region
        if ((oldRegionX >= 0 && oldRegionX < AMOUNT_REGION_X) &&
            (oldRegionY >= 0 && oldRegionY < AMOUNT_REGION_Y))
        {
            _regions[oldRegionX][oldRegionY].RemoveCharactere(charactere);
        }
        _regions[newRegionX][newRegionY].AddCharactere(charactere);
    }
}

CCellTypeWorld* CDungeon::GetCellType(char type)
{
    if (_cellTypes.find(type) != _cellTypes.end())
        return _cellTypes[type];
    return 0;
}

void CDungeon::AddCellType(CCellTypeWorld& cellType)
{
    assert(_cellTypes.find(cellType.GetType()) == _cellTypes.end());
    _cellTypes[cellType.GetType()] = &cellType;
}

void CDungeon::RemoveCellType(const CCellTypeWorld& cellType)
{
    if (_cellTypes.find(cellType.GetType()) != _cellTypes.end())
        _cellTypes.erase(cellType.GetType());
}

void CDungeon::SetStandardCellType(CCellTypeWorld& cellType)
{
    _standardCellType = &cellType;
}

CCellTypeWorld& CDungeon::GetStandardCellType()
{
    assert(_standardCellType != 0);
    return *_standardCellType;
}

// returns a cylic list of all CCellTypeWorld's
CCellTypeWorld* CDungeon::GetAllCellTypes()
{
    CCellTypeWorld* first = 0;
    CCellTypeWorld* prev = 0;
    CCellTypeWorld* last = 0;
    std::map<char, CCellTypeWorld*>::const_iterator iter = _cellTypes.begin();
    for (; iter != _cellTypes.end(); ++iter)
    {
        last = (*iter).second;
        if (!first)
        {
            first = last;
            prev = last;
        }

        prev->SetNext(last);
        last->SetPrev(prev);
        
        prev = last;
    }
    if (first)
    {
        first->SetPrev(last);
        last->SetNext(first);
    }
    return first;
}


///////////////////////////////////////////////////////////////
/// _singleton functions
//////////////////////////////////////////////////////////////

//gets the instance of the singleton
CDungeon& CDungeon::GetInstance()
{
    assert(_singleton != 0);

    return *_singleton;
}

//creates the instance of the singleton
void CDungeon::CreateInstance()
{
    assert(_singleton == 0);

    CDungeon::_singleton = new CDungeon();
}

//gives the memory free from the singleton and sets it back 0
void CDungeon::DestroyInstance()
{
    assert(_singleton != 0);

    delete _singleton;
    _singleton = 0;
}

//gives true back if singleton is set
bool CDungeon::IsValid()
{
    return _singleton != 0;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
