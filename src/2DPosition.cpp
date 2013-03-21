#include "2DPosition.h"


C2DPosition::C2DPosition()
            : _posX(0), _posY(0)
{
}

C2DPosition::C2DPosition(int x,int y)
            : _posX(x), _posY(y)
{
}

C2DPosition::~C2DPosition()
{
}

int C2DPosition::GetXPos() const
{
    return _posX;
}

int C2DPosition::GetYPos() const
{
    return _posY;
}

void C2DPosition::SetXPos(int x)
{
    _posX = x;
}

void C2DPosition::SetYPos(int y)
{
    _posY = y;
}

C2DPosition C2DPosition::operator+(const C2DPosition& value) const
{
    return C2DPosition(GetXPos() + value.GetXPos(),
                       GetYPos() + value.GetYPos());
}

C2DPosition C2DPosition::operator+(const int value) const
{
    return C2DPosition(GetXPos() + value,
                       GetYPos() + value);
}

C2DPosition C2DPosition::operator-(const int value) const
{
    return C2DPosition(GetXPos() - value,
                       GetYPos() - value);
}
