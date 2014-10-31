#include <iostream>
#include <vector>
#include "graph.h"

int main(int argc, char const *argv[])
{
	const char *vertex_array = "ABCDEFGHIJ";
	int a0[] = {2,1};
	int a1[] = {4,3};
	int a2[] = {5,3};
	int a3[] = {4};
	int a4[] = {7,6};
	int a5[] = {7};
	int a6[] = {9};
	int a7[] = {8};
	int a8[] = {9};
	int a9[] = {};
	std::vector<int> edge_array[10] = {std::vector<int>(a0, a0 + 2), 
									   std::vector<int>(a1, a1 + 2), 
						               std::vector<int>(a2, a2 + 2), 
						               std::vector<int>(a3, a3 + 1),
						           	   std::vector<int>(a4, a4 + 2),
						           	   std::vector<int>(a5, a5 + 1),
						           	   std::vector<int>(a6, a6 + 1),
						           	   std::vector<int>(a7, a7 + 1),
						           	   std::vector<int>(a8, a8 + 1),
						           	   std::vector<int>()};
	int b0[] = {4,3};
	int b1[] = {6,5};
	int b2[] = {7,8};
	int b3[] = {3};
	int b4[] = {4,9};
	int b5[] = {6};
	int b6[] = {2};
	int b7[] = {5};
	int b8[] = {3};
	int b9[] = {};
	std::vector<int> wieght_array[10] = {std::vector<int>(b0, b0 + 2), 
									     std::vector<int>(b1, b1 + 2), 
						                 std::vector<int>(b2, b2 + 2), 
						                 std::vector<int>(b3, b3 + 1),
						           	     std::vector<int>(b4, b4 + 2),
						           	     std::vector<int>(b5, b5 + 1),
						           	     std::vector<int>(b6, b6 + 1),
						           	     std::vector<int>(b7, b7 + 1),
						           	     std::vector<int>(b8, b8 + 1),
						           	     std::vector<int>()};
	int in[] = {0,1,1,2,2,1,1,2,1,2};	           	   
	graph<char, 10> obj(vertex_array, edge_array, wieght_array, in);
	obj.print();
	obj.DFS();
	obj.BFS();
	std::cout << "=================== topological sorting =================" << std::endl;
	if (!obj.topological_sort())
	{
		std::cout << "error! AOV has loop!" << std::endl;
	}
	std::cout << "===================== critical path ======================" << std::endl;
	obj.critical_path();
	return 0;
}