#include "2DPosition.h"


C2DPosition<>::C2DPosition()
{
	_pos[0] = 0;
	_pos[1] = 0;
}

C2DPosition<>::C2DPosition(int x,int y)
{
	_pos[0] = x;
	_pos[1] = y;
}

C2DPosition<>::~C2DPosition()
{
}

// -----------------------------------------------------------------------------

C2DPosition<>& C2DPosition<>::operator = (const C2DPosition<>& pos)
{
	_pos[0] = pos._pos[0];
	_pos[1] = pos._pos[1];
	
	return *this;
}

// -----------------------------------------------------------------------------

int& C2DPosition<>::operator[](const int Index)
{
	return _pos[Index];
}

const int& C2DPosition<>::operator[](const int Index) const
{
	return _pos[Index];
}

C2DPosition<> C2DPosition<>::operator+(const C2DPosition& value) const
{
    return C2DPosition(_pos[0] + value._pos[0], _pos[1] + value._pos[1]);
}

C2DPosition<> C2DPosition<>::operator+(const int value) const
{
    return C2DPosition(_pos[0] + value,
                       _pos[1] + value);
}

C2DPosition<> C2DPosition<>::operator-(const int value) const
{
    return C2DPosition(_pos[0] - value,
                       _pos[1] - value);
}

// -----------------------------------------------------------------------------

C2DPosition<>& C2DPosition<>::operator += (const C2DPosition<>& pos)
{
	_pos[0] += pos._pos[0];
	_pos[1] += pos._pos[1];
	
	return *this;
}

// -----------------------------------------------------------------------------

C2DPosition<>& C2DPosition<>::operator -= (const C2DPosition<>& pos)
{
	_pos[0] -= pos._pos[0];
	_pos[1] -= pos._pos[1];
	
	return *this;
}

// -----------------------------------------------------------------------------

C2DPosition<>& C2DPosition<>::operator *= (float scalar)
{
	_pos[0] *= scalar;
	_pos[1] *= scalar;
	
	return *this;
}


// -----------------------------------------------------------------------------

C2DPosition<> C2DPosition<>::operator - (const C2DPosition<>& pos) const
{
	return C2DPosition<>(_pos[0] - pos._pos[0], _pos[1] - pos._pos[1]);
}

// -----------------------------------------------------------------------------

C2DPosition<> C2DPosition<>::operator * (float scalar) const
{
	return C2DPosition(_pos[0] * scalar, _pos[1] * scalar);
}

