#pragma once

#include "CellTypeWorld.h"
#include "Region.h"
#include "2DPosition.h"

#include <map>

class CCharactereWorld;

class CDungeon
{
public:
    //getter/setter
    int GetAmountRegionX() const;
    int GetAmountRegionY() const;
    const CCellTypeWorld& GetCell(const C2DPosition& pos) const;
    CCharactereWorld* GetCharacters(const C2DPosition& pos);
    CCharactereWorld* GetCharactersInArea(const C2DPosition& start, const C2DPosition& end);
    CCharactereWorld* GetAllCharacters();
    int GetLevel() const;

    static const C2DPosition GetSize();
    static int GetSizeX();
    static int GetSizeY();
    CCellTypeWorld& GetStandardCellType();
    CCellTypeWorld* GetCellType(char typeID);
    CCellTypeWorld* GetAllCellTypes();
    void SetStandardCellType(CCellTypeWorld& cellType);
 
    //functions
    bool Load(const json::Array& regions, int level); //file read how the level should look like    
    void CharactereMove(CCharactereWorld& charactere, const C2DPosition& oldPos, const C2DPosition& newPos);
    void AddCharactere(CCharactereWorld& charactere);
    void AddCellType(CCellTypeWorld& cellType);
    void RemoveCharactere(CCharactereWorld& charactere);
    void RemoveCellType(const CCellTypeWorld& cellType);
    
    //singleton functions
    static void CreateInstance();
    static CDungeon& GetInstance();
    static void DestroyInstance();
    static bool IsValid();


private:
    //constructor/destructor
    CDungeon();
    ~CDungeon();

    const static int AMOUNT_REGION_X = 1; 
    const static int AMOUNT_REGION_Y = 1;
    static CDungeon* _singleton;

    int _level;
    CRegion _regions[AMOUNT_REGION_X][AMOUNT_REGION_Y];
    
    CCellTypeWorld* _standardCellType;
    std::map<char, CCellTypeWorld*> _cellTypes;
};

