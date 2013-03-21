#pragma once

#include "CellTypeWorld.h"
#include "2DPosition.h"

#include <list>
#include "CharactereWorld.h"


class CRegion
{

public:

		//functions
        ~CRegion();
		CRegion(int regionX = 0, int regionY = 0);
        bool Load(const json::Object& region);
        void AddCharactere(CCharactereWorld& charactere);
        void RemoveCharactere(CCharactereWorld& charactere);
        
        //getter/setter
        const CCellTypeWorld* GetCell(const C2DPosition& pos) const;
        CCharactereWorld* GetCharacters(const C2DPosition& pos);
        CCharactereWorld* GetCharactersInArea(const C2DPosition& start, const C2DPosition& end);
        static int GetSizeX();
        static int GetSizeY();

private:
 
	static const int MAX_X = 17;
    static const int MAX_Y = 17;

     int _regionX;
     int _regionY;

    const CCellTypeWorld* _cells[MAX_X][MAX_Y];

    std::list<CCharactereWorld*> _characters;

};

