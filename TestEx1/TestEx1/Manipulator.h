#pragma once
#include <cmath>

class Manipulator
{
public:

	Manipulator(int id=0, float X=0, float Y=0, float r=0): 
		id(id), X(X), Y(Y), r(r){};

	float FindRange(float& dX, float& dY);

	bool IsInRange(float& dX, float& dY);

	void SetX(float&);
	void SetY(float&);
	void SetRad(float&);

	float GetRad();
	int GetID();

	friend bool operator< (const Manipulator& m1, const Manipulator& m2);

private:

	int id;
	float X, Y, r;

};

