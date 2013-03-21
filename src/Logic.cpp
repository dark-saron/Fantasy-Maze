#include "Logic.h"
#include "Player.h"
#include "MonsterAI.h"
#include "Dungeon.h"
#include "CharactereWorld.h"
#include "CharactereLogic.h"
#include "WorldIterator.h"
#include "Config.h"
#include "CellTypeLogic.h"
#include "json/reader.h"

#include <assert.h>
#include <fstream>

CLogic::CLogic()
      : _npcs(std::list<CMonsterAI*>()),
        _trash(std::list<CWorldEntity*>()),
        _exit(false)
{
    for (int player = 0; player < MAX_PLAYERS; ++player)
        _players[player] = 0;

    const json::Array& cellTypes = CConfig::GetInstance().GetCellTypes();
    InitializeCellTypes(cellTypes);
}

void CLogic::ClearNPCs()
{
    CMonsterAI* ai = 0;
    CCharactereLogic* charLogic = 0;

    while (!_npcs.empty())
    {
        ai = *_npcs.begin();
        charLogic = &ai->GetCharactere();
        _npcs.pop_front();
        delete ai;
        delete charLogic;
    }
}

void CLogic::ClearPlayers()
{
    for (int playerNr = 0; playerNr < MAX_PLAYERS; ++playerNr)
    {
        if (_players[playerNr])
        {
            CCharactereLogic* charLogic = &_players[playerNr]->GetCharactere();
            delete _players[playerNr];
            _players[playerNr] = 0;
            charLogic->SetHealth(0);
            MoveToTrash(charLogic->GetWorldEntity());
        }
    }
}

void CLogic::ClearCellTypes()
{
    CCellTypeWorld* cellTypeWorld = CDungeon::GetInstance().GetAllCellTypes();
    IWorldIterator iter = IWorldIterator(cellTypeWorld);

    for (; iter.FirstLoop(); ++iter)
    {
        delete (*iter)->GetLogicEntity();
    }
}

void CLogic::MoveToTrash(CWorldEntity* worldEntity)
{
    if (worldEntity->GetGraphicEntity())
        _trash.push_back(worldEntity);
    else
        delete (CCharactereLogic*) worldEntity->GetLogicEntity();

}

void CLogic::Start()
{

}

void CLogic::Reset()
{
    ClearPlayers();
    ClearNPCs();
}

CLogic::~CLogic()
{
    Reset();
    ClearCellTypes();
}

// goes through the trash and removes everything with no graphic entity
void CLogic::ClearTrash()
{
    CWorldEntity* worldEntity;
    std::list<CWorldEntity*>::const_iterator it = _trash.begin(); 
    
    while(it != _trash.end())
    {
        worldEntity = (*it);
        if (!worldEntity->GetGraphicEntity())
        {
            it = _trash.erase(it);
            delete (CCharactereLogic*) worldEntity->GetLogicEntity();
        }
        else
            ++it;
    }
}

void CLogic::RemoveDeadEntities()
{
    CCharactereWorld* charWorld = 0;
    CCharactereLogic* charLogic = 0;

    for (int player = 0; player < MAX_PLAYERS; ++player)
    {
        if (!_players[player])
            continue;

        charLogic = &_players[player]->GetCharactere();
        charWorld = (CCharactereWorld*) charLogic->GetWorldEntity();
        if (charWorld->IsDead())
        {
            delete _players[player];
            _players[player] = 0;
            MoveToTrash(charWorld);
        }
    }

    std::list<CMonsterAI*>::const_iterator it = _npcs.begin(); 
    while(it != _npcs.end())
    {
        charLogic  = &(*it)->GetCharactere();
        charWorld = (CCharactereWorld*) charLogic->GetWorldEntity();
        
        if (charWorld->IsDead())
        {
            delete *it;
            it = _npcs.erase(it);
            MoveToTrash(charWorld);
        }
        else
            ++it;
    }
}

bool CLogic::ComputeRound(int timeLeft)
{
    for (int player = 0; player < MAX_PLAYERS; ++player)
    {
        if (_players[player])
            _players[player]->Update(timeLeft);
    }

    std::list<CMonsterAI*>::const_iterator it = _npcs.begin(); 
    for(;it != _npcs.end(); ++it)
    {
        CMonsterAI* player = (*it);
        player->Update(timeLeft);
    }
    return true;
}

CPlayer* CLogic::GetPlayer(int player)
{
    assert(player == 0 || player == 1);

    return _players[player];
}


bool CLogic::StartLevel(int level, int maxPlayers, bool clearPlayers)
{
    ClearNPCs();
    if (clearPlayers)
        ClearPlayers();

    const json::Object& dungeon = CConfig::GetInstance().GetDungeon(level);

    InitializeDungeon(dungeon["Regions"], level);
    InitializeNPCs(dungeon["NPCs"]);
    InitializePlayers(dungeon["Players"], maxPlayers);

    return true;
}

void CLogic::InitializeCellTypes(const json::Array& cellTypes)
{

    for (int index = 0; index < cellTypes.Size(); ++index)
    {
        const json::Object& cellType = cellTypes[index];
        std::string type = (json::String) cellType["Type"];

        CCellTypeLogic* cellTypeLogic = new CCellTypeLogic();
        CCellTypeWorld* cellTypeWorld = (CCellTypeWorld*) cellTypeLogic->GetWorldEntity();
        cellTypeWorld->SetLogicEntity(cellTypeLogic);
        
        cellTypeWorld->SetTypeID((json::String) cellType["ID"]);
        cellTypeWorld->SetType(type[0]);
        cellTypeWorld->SetSolid((json::Boolean) cellType["Solid"]);
        
        if ((json::Boolean) cellType["Standard"])
            CDungeon::GetInstance().SetStandardCellType(*cellTypeWorld);
    }
}

 void CLogic::InitializeDungeon(const json::Array& regions, int level)
 {
    CDungeon::GetInstance().Load(regions, level);
 }

void CLogic::InitializePlayers(const json::Array& players, int maxPlayers)
{
    int playerNr = 0;
    json::Array::const_iterator iter(players.Begin());
    json::Array::const_iterator iterEnd(players.End());
    for (; iter != iterEnd && playerNr < maxPlayers; ++iter)
    {
        const json::Object& data = *iter;
        C2DPosition pos((json::Number) data ["X"], (json::Number) data ["Y"]);

        CreatePlayer((json::String) data["ID"], pos, playerNr);
        ++playerNr;
    }
}

void CLogic::InitializeNPCs(const json::Array& npcs)
{
    json::Array::const_iterator iter(npcs.Begin());
    json::Array::const_iterator iterEnd(npcs.End());
    for (; iter != iterEnd; ++iter)
    {
        const json::Object& data = *iter;
        C2DPosition pos((json::Number) data ["X"], (json::Number) data ["Y"]);

        CreateNPC((json::String) data["ID"], pos);
    }
}


// creates and returns a player
// if the playerNr is already taken, it will set the position and return the existing player instead of creating a new one
CPlayer& CLogic::CreatePlayer(const std::string& typeID, const C2DPosition& pos, int playerNr)
{
    CCharactereLogic* charLogic = 0;
    CCharactereWorld* charWorld = 0;
    CPlayer* player = 0;
    if (_players[playerNr])
    {
        player = _players[playerNr];
        charLogic = &_players[playerNr]->GetCharactere();
        charWorld = (CCharactereWorld*) charLogic->GetWorldEntity();
    }
    else
    {
        charLogic = new CCharactereLogic();

        CPlayer* player = new CPlayer();
        player->SetCharactere(*charLogic);

        charWorld = (CCharactereWorld*) charLogic->GetWorldEntity();
        const json::Object& obj = CConfig::GetInstance().GetCharactereType(typeID);
        charWorld->Load(obj);
        charWorld->SetTeam(CCharactereWorld::player0);

        _players[playerNr] = player;
    }
    charWorld->SetPosition(pos);
    return *player;
}

// creates and returns an AI for an NPC
CMonsterAI& CLogic::CreateNPC(const std::string& typeID, const C2DPosition& pos)
{
    const json::Object& obj = CConfig::GetInstance().GetCharactereType(typeID);
    CCharactereLogic* charLogic = 0;
    CCharactereWorld* charWorld = 0;

    charLogic = new CCharactereLogic();
    charWorld = (CCharactereWorld*) charLogic->GetWorldEntity();
    charWorld->SetTeam(CCharactereWorld::monster);

    CMonsterAI* ai = new CMonsterAI();
    ai->SetCharactere(*charLogic);
    _npcs.push_back(ai);
    

    charWorld->Load(obj);
    charWorld->SetPosition(pos);
    
    return *ai;
}


void CLogic::SetExit(bool exit)
{
    _exit = exit;
}

bool CLogic::GetExit() const
{
    return _exit;
}


int CLogic::GetNPCAmount()
{
    return _npcs.size();
}



void CLogic::EventManager()
{
    if(!CLogic::GetInstance().GetPlayer(0))
    {
        ClearNPCs();
        // TODO: Go to Menu
    }
    if(CLogic::GetInstance().GetNPCAmount() == 0)
    {
        CLogic& logic = CLogic::GetInstance();
        int players = (logic.GetPlayer(0) != 0) + (logic.GetPlayer(1) != 0);
        StartLevel(CDungeon::GetInstance().GetLevel(), players, false);
    }
}


///////////////////////////////////////////////////////////////
/// _singleton functions
//////////////////////////////////////////////////////////////

CLogic* CLogic::_singleton =  0;

//gets the instance of the singleton
CLogic& CLogic::GetInstance()
{
    assert(_singleton != 0);

    return *_singleton;
}

//creates the instance of the singleton
void CLogic::CreateInstance()
{
    assert(_singleton == 0);

    CLogic::_singleton = new CLogic();
}

//gives the memory free from the singleton and sets it back 0
void CLogic::DestroyInstance()
{
    assert(_singleton != 0);

    delete _singleton;
    _singleton = 0;
}

//gives true back if singleton is set
bool CLogic::IsValid()
{
    return _singleton != 0;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
