#pragma once

#include <windows.h>


class CThread
{

public:
        //constructor/destructor
        CThread();
        ~CThread();
        
        bool IsAlive();
        void Start();
        static void RunThread(CThread* _pThread);
        
private:
        virtual int Run() = 0;
        
        bool _alive;
        DWORD _thread;
        HANDLE _handle;
};