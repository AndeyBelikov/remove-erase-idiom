// vectorErace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>

int genRand()
{
	int minVal = 0;
	int maxVal = 9;

	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_int_distribution<int> generateValue(minVal, maxVal);

	return generateValue(mt);
}

void vectorFunc()
{
	const int VAL_EIGHT = 8;

	std::vector<int> myVec;

	for (int j = 0; j < 100; j++) {
		myVec.push_back(genRand());
	}

	myVec.erase(std::remove(myVec.begin(), myVec.end(), VAL_EIGHT), myVec.end());

	std::ostream_iterator<int> out_it(std::cout, ", ");
	std::copy(myVec.begin(), myVec.end(), out_it);
}

void mapFunc()
{
	const int VAL_EIGHT = 8;

	std::map<int, int> myMap;

	for (int i = 0; i < 100; i++){
		myMap[i] = genRand();
	}

	std::map<int, int>::iterator it = myMap.begin();

	while (it != myMap.end()) {
		it->second == VAL_EIGHT ? myMap.erase(it++) : it++;
	}

	std::cout << "\nafter remove\n";

	for (int i = 0, c = ' '; i < 100; ++i) {
		if (i != 0 && (i % 9) == 0)
			c = '\n';
		else
			c = ' ';
		try {
			std::cout << myMap.at(i) << (char)c;
		}
		catch (std::out_of_range& re) {
			std::cout << ' ' << (char)c;
		}
	}
}

int main()
{
	vectorFunc();

	std::cout << std::endl;

	mapFunc();
	system("pause");
    return 0;
}

