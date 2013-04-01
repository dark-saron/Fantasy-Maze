#pragma once

#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#endif

void Delay(int sleepMs)
{
#ifdef __linux__
    struct timespec req={0},rem={0};
    req.tv_sec=(sleepMs/1000);
    req.tv_nsec=(sleepMs - req.tv_sec*1000)*1000000;

    nanosleep(&req,&rem);
#endif
#ifdef _WIN32
    Sleep(sleepMs);
#endif
}
