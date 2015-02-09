#include <iostream>
#include <vector>
#include "graph.h"

int main(int argc, char const *argv[])
{
	const char *vertex_array = "ABCDEFGHIJKLMN";
	int a0[] = {4,5,11};
	int a1[] = {4,8,2};
	int a2[] = {5,6,9};
	int a3[] = {2,13};
	int a4[] = {7};
	int a5[] = {8,12};
	int a6[] = {5};
	int a7[] = {};
	int a8[] = {7};
	int a9[] = {10,11};
	int a10[] = {13};
	int a11[] = {};
	int a12[] = {9};
	int a13[] = {};
	int in[] = {0,0,2,0,2,3,1,2,2,2,1,2,1,2};
	std::vector<int> edge_array[14] = {std::vector<int>(a0, a0 + 3), 
									   std::vector<int>(a1, a1 + 3), 
						               std::vector<int>(a2, a2 + 3), 
						               std::vector<int>(a3, a3 + 2),
						           	   std::vector<int>(a4, a4 + 1),
						           	   std::vector<int>(a5, a5 + 2),
						           	   std::vector<int>(a6, a6 + 1),
						           	   std::vector<int>(),
						           	   std::vector<int>(a8, a8 + 1),
						           	   std::vector<int>(a9, a9 + 2),
						           	   std::vector<int>(a10, a10 + 1),
						           	   std::vector<int>(),
						           	   std::vector<int>(a12, a12 + 1),
						           	   std::vector<int>()};
	graph<char, 14> obj(vertex_array, edge_array, in);
	obj.print();
	obj.DFS();
	obj.BFS();
	std::cout << "=================== topological sorting =================" << std::endl;
	obj.topological_sort();
	return 0;
}