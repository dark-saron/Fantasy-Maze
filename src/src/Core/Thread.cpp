#include "Thread.h"
#include <iostream>
#include <windows.h>
#include <assert.h>

CThread::CThread()
        : _alive(true),
          _thread(0)
{
}

CThread::~CThread()
{
}

// Return whether the thread is alive.
// This method returns true just before the Run() method starts until just after the Run() method terminates.
bool CThread::IsAlive()
{
    return _alive;
}

//creates new thread
void CThread::Start()
{
    _handle = CreateThread(
        0,      // default security attributes
        0,      // use default stack size  
        reinterpret_cast<LPTHREAD_START_ROUTINE> (CThread::RunThread), // thread function name
        static_cast<LPVOID> (this), // argument to thread function 
        0,       // use default creation flags 
        &_thread);      // returns the thread identifier 
}

// Start the thread’s activity.
void CThread::RunThread(CThread* _pThread)
{
    assert(_pThread != 0);

    _pThread->Run();
    _pThread->_alive = false;
}

