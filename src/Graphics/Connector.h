#pragma once

#include "src/Data/Direction.h"

class CCharactereWorld;

class CConnector
{
public:
    enum EType
    {
        none,
        menu,
        game,
        exit,
        back,
        sizeOf

    };

    void ContinueGame();
    void Exit();
    CCharactereWorld* GetPlayerCharactere(int playerNr);
    void StartGame(bool multiplayer);
    void ShowMenu();
    EType TakeAction();
    void ToggleMenu();
    void Input(int playerNr, SDirection::EType);

    //singleton functions
    static void CreateInstance();
    static CConnector& GetInstance();
    static void DestroyInstance();
    static bool IsValid();

private:
    EType _action;

    //singleton
    CConnector();
    ~CConnector();

    static CConnector* _singleton;

};

