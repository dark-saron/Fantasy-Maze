#pragma once

class CWorldEntity;

class  IWorldIterator
{
public:
    //constructor/destructor
    IWorldIterator(CWorldEntity* charWorld);
    ~IWorldIterator();

    //functions
    int FirstLoop() const;
    
    //operators
    CWorldEntity* operator++();
    CWorldEntity* operator++(int add);
    CWorldEntity* operator*();

private:
    CWorldEntity* _start;
    CWorldEntity* _current;
    int _loop;
};

