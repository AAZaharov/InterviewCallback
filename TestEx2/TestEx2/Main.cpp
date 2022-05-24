#include <iostream>
#include <list>
#include <unordered_set>
#include <algorithm>
#include "Manipulator.h"
#include <unordered_map>


//
//Задача:
//Выведете две строки : какие точки обойдет каждый манипулятор.
//Замечание : Важно помнить, что до детали должен дойти “оптимальный” манипулятор
//на текущей итерации процесса.Оптимальность можно считать по длине пути до точки.
//Радиус не учитывается.
//

struct Point
{
public:
	Point(float X = 0, float Y = 0) : X(X), Y(Y) {};
	float X, Y;
};

Manipulator* FindCloset(std::list<Manipulator>& ManList)
{
	return &(std::min_element(ManList.begin(), ManList.end()).operator*());
}

Manipulator* FindCloset(std::list<Manipulator>& ManList, Point& P1)
{
	Manipulator* CloseMan = &ManList.front();
	for (auto& m : ManList) {
		if (m.FindRange(P1.X, P1.Y) < CloseMan->FindRange(P1.X, P1.Y)) {
			CloseMan = &m;
		}
	}
	CloseMan->SetX(P1.X);
	CloseMan->SetY(P1.Y);
	return CloseMan;
}

void SortPoints(std::list<Manipulator>& ManipList, std::list<Point>& PointList,
	std::unordered_multimap<Manipulator*, Point*>& SortPointMap)
{
	for (auto & p : PointList) {
		Manipulator* ptr = FindCloset(ManipList, p);
		SortPointMap.emplace(ptr, &p);
	}
}



int main()
{

	std::list<Manipulator> ManipList;
	std::list<Point> PointList;
	std::unordered_multimap<Manipulator*, Point*> SortPointMap;

	/*Uncomment for test*/

	//ManipList.push_back(Manipulator(0, 0, 0, 4));
	//ManipList.push_back(Manipulator(1, 2, 1, 3));

	//PointList.push_back(Point(1, 3));
	//PointList.push_back(Point(2, 1.41));
	//PointList.push_back(Point(0.2, -7));
	//PointList.push_back(Point(-5, -1));
	//PointList.push_back(Point(0, 9));

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

		PointList.push_back(Point(x, y));
	}

	SortPoints(ManipList, PointList, SortPointMap);

	for (auto& m : ManipList) {
		std::cout << "\nPoints for manipulator id" << m.GetID() << ":   ";
		for (auto& s : SortPointMap)
		{
			if (s.first == &m)
			{
				std::cout << "Point(" << s.second->X << "," << s.second->Y << ")   ";
			}
		}
	}

	return 0;
}

