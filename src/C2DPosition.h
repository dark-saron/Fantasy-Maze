//13_2_22 Sabine L.
#pragma once
class C2DPosition
{
public:
    //constructor/destructor
	C2DPosition(void);
    C2DPosition(int x,int y);
    ~C2DPosition(void);

	//getter/setter
    int GetXPos() const;
    int GetYPos() const;
    void SetXPos(int x);
    void SetYPos(int y);
   
	//operator
	C2DPosition C2DPosition::operator+(const C2DPosition& value) const;

private:
    int _posX;
    int _posY;
};

