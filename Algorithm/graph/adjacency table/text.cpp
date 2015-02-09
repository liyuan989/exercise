#include <iostream>
#include <vector>
#include "graph.h"

int main(int argc, char const *argv[])
{
	const char *vertex_array = "ABCD";
	int a0[] = {1,2,3};
	int a1[] = {0,2,3};
	int a2[] = {0,1,3};
	int a3[] = {0,1,2};
	std::vector<int> edge_array[4] = {std::vector<int>(a0, a0 + 3), std::vector<int>(a1, a1 + 3), 
						              std::vector<int>(a2, a2 + 3), std::vector<int>(a3, a3 + 3)};
	graph<char, 4> obj(vertex_array, edge_array);
	obj.print();
	obj.DFS();
	obj.BFS();
	return 0;
}