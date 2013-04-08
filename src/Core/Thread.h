#pragma once




class CThread
{

public:
        //constructor/destructor
        CThread();
        ~CThread();
        
        bool IsAlive();
        void Start();
        static void* RunThread(CThread* _pThread);
        
private:
        virtual int Run() = 0;
        
        bool _alive;
        long unsigned int _thread;
        void* _handle;
};
