#pragma once


//database of the game

class CWorld
{

public:

    static void CreateInstance();
    static CWorld& GetInstance();
    static void DestroyInstance();
    static bool IsValid();

    ~CWorld(void);

    void RemoveDeadEntities();

private:

        CWorld(void);

        static CWorld* _singleton;

};

