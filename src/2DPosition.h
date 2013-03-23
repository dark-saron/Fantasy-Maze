#pragma once

template <typename T = int>
class C2DPosition
{
public:

	static const int ARRAY_SIZE = 2;

    //constructor/destructor
    C2DPosition(void);
    C2DPosition(T x, T y);
    ~C2DPosition(void);
   
    //operator

	const T& operator[](const int index) const;
	T& operator[](const int index);

	C2DPosition<T>& operator  = (const C2DPosition<T>& pos);          ///< Assignment operator.
	C2DPosition<T>& operator += (const C2DPosition<T>& pos);
	C2DPosition<T>& operator -= (const C2DPosition<T>& pos);
	C2DPosition<T>& operator *= (float scalar);                      ///< Stretch or shrink the vector along its direction.

	C2DPosition<T> operator+(const C2DPosition<T>& value) const;
    C2DPosition<T> operator-(const C2DPosition<T>& value) const;
	C2DPosition<T> operator+(const T value) const;
	C2DPosition<T> operator-(const T value) const;
	C2DPosition<T> operator*(float scalar) const;

private:
    T _pos[ARRAY_SIZE];
};


