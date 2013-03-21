#pragma once

#include "CellTypeWorld.h"
#include "Region.h"
#include "2DPosition.h"

#include <map>

class CCharactereWorld;

class CDungeon
{

public:
 
    //functions
    bool Load(const json::Array& regions, int level); //file read how the level should look like    
    void CharactereMove(CCharactereWorld& charactere, const C2DPosition& oldPos, const C2DPosition& newPos);
    void AddCharactere(CCharactereWorld& charactere);
    void AddCellType(CCellTypeWorld& cellType);
    void RemoveCharactere(CCharactereWorld& charactere);
    void RemoveCellType(const CCellTypeWorld& cellType);

	//getter/setter
    CCellTypeWorld* GetAllCellTypes();
    CCellTypeWorld* GetCellType(char typeID);
    CCellTypeWorld& GetStandardCellType();
    CCharactereWorld* GetAllCharacters();
    CCharactereWorld* GetCharacters(const C2DPosition& pos);
    CCharactereWorld* GetCharactersInArea(const C2DPosition& start, const C2DPosition& end);
    const CCellTypeWorld& GetCell(const C2DPosition& pos) const;
    int GetAmountRegionX() const;
    int GetAmountRegionY() const;
    int GetLevel() const;
    static const C2DPosition GetSize();
    static int GetSizeX();
    static int GetSizeY();
    void SetStandardCellType(CCellTypeWorld& cellType);
     
    //singleton functions
    static bool IsValid();
	static CDungeon& GetInstance();
    static void CreateInstance();
    static void DestroyInstance();
    

private:

	//constructor/destructor
    ~CDungeon();
	CDungeon();
    
    CCellTypeWorld* _standardCellType;
    const static int AMOUNT_REGION_X = 1; 
    const static int AMOUNT_REGION_Y = 1;
    CRegion _regions[AMOUNT_REGION_X][AMOUNT_REGION_Y];
    
	int _level;
    std::map<char, CCellTypeWorld*> _cellTypes;
	
	static CDungeon* _singleton;

    
    
};

