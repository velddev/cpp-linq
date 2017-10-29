#include <vector>

#include "../include/Linq.h"

using namespace std;
using namespace linq;

int main()
{
	vector<int> testVec;

	testVec.push_back(1);
	testVec.push_back(2);
	testVec.push_back(3);

	// add vector
	Linq<vector<int>> x(&testVec);
	x.add(3)
		.add(4);
	
	// where constraint
	std::vector<int> y = x.where<int>([](int i) -> bool { return i == 3; })->toList();

	int i = 0;
}