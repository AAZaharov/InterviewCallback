#include "Manipulator.h"

float Manipulator::FindRange(float& dX, float& dY)
{
    return sqrt((dX - X) * (dX - X) + (dY - Y) * (dY - Y));
}

bool Manipulator::IsInRange(float& dX, float& dY)
{
    if (r <= FindRange(dX, dY)) return 0;
    else return 1;
}

void Manipulator::SetX(float&x)
{
    X = x;
}

void Manipulator::SetY(float&y)
{
    Y = y;
}

void Manipulator::SetRad(float&Rad)
{
    r = Rad;
}

float Manipulator::GetRad()
{
    return r;
}

int Manipulator::GetID()
{
    return id;
}

bool operator<(const Manipulator& m1, const Manipulator& m2)
{
    return m1.r < m2.r;
}
