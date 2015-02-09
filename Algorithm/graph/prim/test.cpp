#include <iostream>
#include <memory>
#include "graph.h"



int main(int argc, char const *argv[])
{
	const char* vertex_array = "ABCD";
	int edge_array[4][4] = {{0,2,3,3}, {2,0,3,4}, {3,3,0,2}, {3,4,2,0}};
	graph<char, 4> obj(vertex_array, edge_array);
	obj.print_param();
	obj.BFS();
	obj.DFS();
	obj.prim();
	return 0;
}