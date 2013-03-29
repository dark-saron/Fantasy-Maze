#include "WorldIterator.h"
#include "WorldEntity.h"

#include <assert.h>

IWorldIterator::IWorldIterator(CWorldEntity* entity)
              : _start(entity),
                _current(entity),
                _loop(1)
{
    if (!entity)
        _loop = 0;
}

IWorldIterator::~IWorldIterator()
{
}

int IWorldIterator::FirstLoop() const
{
    return _loop == 1;
}

CWorldEntity* IWorldIterator::operator++()
{
    assert(_current != 0);
    assert(_start != 0);

    _current = _current->GetNext();
    _loop += (_current == _start);
    return _current;
}

CWorldEntity* IWorldIterator::operator++(int)
{
    assert(_current != 0);
    assert(_start != 0);

    CWorldEntity* prev = _current;
    _current = _current->GetNext();
    _loop += (_current == _start);
    return prev;
}

CWorldEntity* IWorldIterator::operator*()
{
    assert(_current != 0);
    
    return _current;
}

