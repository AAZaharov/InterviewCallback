#include <iostream>
#include <list>
#include <algorithm>
#include "Manipulator.h"


//
//Задача:
//Определите, каким манипулятором оптимальнее дойти до точки P1.
//Если оба манипулятора не могут достать, то вывести сообщение : “OUT OF RANGE”.
//Если точка доступна одному манипулятору – использовать его.
//

struct Point
{
public:
	Point(float X = 0, float Y = 0) : X(X), Y(Y) {};
	float X, Y;
};

Manipulator* FindCloset(std::list<Manipulator>& ManList, Point & P1)
{
	Manipulator* CloseMan = &ManList.front();
	for (auto & m : ManList) {
		if (m.FindRange(P1.X, P1.Y) < CloseMan->FindRange(P1.X, P1.Y)) {
			CloseMan = &m;
		}
	}

	return CloseMan;
}

int main()
{

	std::list<Manipulator> ManipList;
	std::list<Point> PointList;

	/*Uncomment for test*/

	//ManipList.push_back(Manipulator(0, 1, 1, 6));
	//ManipList.push_back(Manipulator(1, 13, 15, 6));

	//PointList.push_back(Point(3, 3));

	//



	int ManCount(0), Pointcount(0);
	std::cout << "How many manipulators will you use? ";
	std::cin >> ManCount;

	for (int i = 0; i < ManCount; ++i)
	{
		float x, y, r;
		std::cout << "\nEnter the coordinates of the manipulator\nX:";
		std::cin >> x;
		std::cout << "Y:";
		std::cin >> y;
		std::cout << "Rad:";
		std::cin >> r;

		ManipList.push_back(Manipulator(i, x, y, r));
	}

	std::cout << "\nHow many points will you use? ";
	std::cin >> Pointcount;

	for (int i = 0; i < Pointcount; ++i)
	{
		float x, y;
		std::cout << "\nEnter the coordinates of the point\nX:";
		std::cin >> x;
		std::cout << "Y:";
		std::cin >> y;

		PointList.push_back(Point(x,y));
	}


	for (auto& m : ManipList) {
		std::cout << "\nManipulator id " << m.GetID() << std::endl;
		for (auto& p : PointList)
		{
			std::cout << "Point (" << p.X << "," << p.Y << ")\n";

			if (m.IsInRange(p.X, p.Y)) {
				std::cout << "Range to point " << m.FindRange(p.X, p.Y) << std::endl;
			}
			else std::cout << "OUT OF RANGE.\n";
		}
	}

	for (auto& p : PointList)
	{
		std::cout << "\nFor point (" << p.X << "," << p.Y << ")\n";
		std::cout << "Closest manipulator: id " << FindCloset(ManipList, p)->GetID();
	}
	


	return 0;
}

