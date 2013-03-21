#pragma once

#include "json/elements.h"
#include "2DPosition.h"
#include "CharactereLogic.h"
#include "Phase.h"
#include <list>

class CCellTypeLogic;
class CMonsterAI;
class CPlayer;


class CLogic
{
public:

    bool GetExit() const;
    void SetExit(bool exit);
    
    bool ComputeRound(int timeLeft);
    void EventManager();
    void RemoveDeadEntities();
    void Reset();

    CPlayer* GetPlayer(int player);
    int GetNPCAmount();

    void Start();
    bool StartLevel(int level, int maxPlayers, bool clearPlayers = true);
    
    void MoveToTrash(CWorldEntity* worldEntity);

    void InitializeCellTypes(const json::Array& cellTypes);
    void InitializeDungeon(const json::Array& regions, int level);
    void InitializeNPCs(const json::Array& npcs);
    void InitializePlayers(const json::Array& players, int maxPlayers);
    
    CMonsterAI& CreateNPC(const std::string& typeID, const C2DPosition& pos);
    CPlayer& CreatePlayer(const std::string& typeID, const C2DPosition& pos, int playerNr);
    
    void ClearTrash();
    void ClearCellTypes();
    void ClearNPCs();
    void ClearPlayers();

    //singleton functions
    static void CreateInstance();
    static CLogic& GetInstance();
    static void DestroyInstance();
    static bool IsValid();

private:
    static const int MAX_PLAYERS = 2;

    CLogic();
    ~CLogic();
    static CLogic* _singleton;

    CPlayer* _players[MAX_PLAYERS];
    std::list<CMonsterAI*> _npcs;
    std::list<CWorldEntity*> _trash;

    bool _exit;
};

