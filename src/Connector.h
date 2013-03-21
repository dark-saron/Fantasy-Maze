#pragma once

class CConnector
{
public:



    //singleton functions
    static void CreateInstance();
    static CConnector& GetInstance();
    static void DestroyInstance();
    static bool IsValid();

private:
    CConnector();
    ~CConnector();

    static CConnector* _singleton;

};

