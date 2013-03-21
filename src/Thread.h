#pragma once

#include <windows.h>


class CThread
{

public:
        //constructor/destructor
        ~CThread();
        CThread();        
        bool IsAlive();
        static void RunThread(CThread* _pThread);
        void Start();
        
private:
        
		virtual int Run() = 0;
    
        bool _alive;
        HANDLE _handle;
		DWORD _thread;
        
};