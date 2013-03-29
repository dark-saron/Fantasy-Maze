#pragma once

template <typename T = int>
class C2DPosition
{
public:

	static const int ARRAY_SIZE = 2;

    //constructor/destructor
	// -----------------------------------------------------------------------------

	C2DPosition(void)
	{
		_pos[0] = 0;
		_pos[1] = 0;
	}

	// -----------------------------------------------------------------------------

    C2DPosition(T x, T y)
	{
		_pos[0] = x;
		_pos[1] = y;
	}

	// -----------------------------------------------------------------------------

    ~C2DPosition(void)
	{
	}

	// -----------------------------------------------------------------------------
   
    //operator

	// -----------------------------------------------------------------------------

	const T& operator[](const int index) const
	{
		return _pos[index];
	}

	// -----------------------------------------------------------------------------

	T& operator[](const int index)
	{
		return _pos[index];
	}


	// -----------------------------------------------------------------------------

	C2DPosition<T>& operator  = (const C2DPosition<T>& pos)          ///< Assignment operator.
	{
		_pos[0] = pos._pos[0];
		_pos[1] = pos._pos[1];

		return *this;
	}
	
	// -----------------------------------------------------------------------------
	
	C2DPosition<T>& operator += (const C2DPosition<T>& pos)
	{
		_pos[0] += pos._pos[0];
		_pos[1] += pos._pos[1];

		return *this;
	}

	// -----------------------------------------------------------------------------
	
	C2DPosition<T>& operator -= (const C2DPosition<T>& pos)
	{
		_pos[0] -= pos._pos[0];
		_pos[1] -= pos._pos[1];

		return *this;
	}

	// -----------------------------------------------------------------------------

	C2DPosition<T>& operator *= (float scalar)                      ///< Stretch or shrink the vector along its direction.
	{
		_pos[0] *= scalar;
		_pos[1] *= scalar;

		return *this;
	}

	// -----------------------------------------------------------------------------

	C2DPosition<T> operator+(const C2DPosition<T>& value) const
	{
		return C2DPosition<T>(_pos[0] + value._pos[0], _pos[1] + value._pos[1]);
	}

	// -----------------------------------------------------------------------------
    C2DPosition<T> operator-(const C2DPosition<T>& value) const
	{
		return C2DPosition<T>(_pos[0] - pos._pos[0], _pos[1] - pos._pos[1]);
	}

	// -----------------------------------------------------------------------------
	
	C2DPosition<T> operator+(const T value) const
	{
		return C2DPosition(_pos[0] + value, _pos[1] + value);
	}

	// -----------------------------------------------------------------------------
	
	C2DPosition<T> operator-(const T value) const
	{
		return C2DPosition(_pos[0] - value, _pos[1] - value);
	}

	// -----------------------------------------------------------------------------
	C2DPosition<T> operator*(float scalar) const
	{
		return C2DPosition(_pos[0] * scalar, _pos[1] * scalar);
	}

	// -----------------------------------------------------------------------------
	
	C2DPosition<T> operator / (const C2DPosition<T>& value) const
	{
		return C2DPosition<T>(_pos[0] / value._pos[0],
			_pos[1] / value._pos[1] );
	}
	
	// -----------------------------------------------------------------------------
	
	C2DPosition<T>& operator /= (const C2DPosition<T>& value)
	{
		_pos[0] /= value._pos[0];
		_pos[1] /= value._pos[1];
		return *this;

	}

private:
    T _pos[ARRAY_SIZE];
};


