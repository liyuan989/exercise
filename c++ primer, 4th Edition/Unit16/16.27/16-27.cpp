#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include "16-27.h"

template <typename T> 
T find_middle(std::vector<T> &obj)
{
	std::sort(obj.begin(), obj.end());
	return obj[obj.size() / 2];
}