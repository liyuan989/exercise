#include <iostream>
#include "graph.h"

int main(int argc, char const *argv[])
{
	const char* vertex_array = "ABCD";
	int edge_array[4][4] = {{0,1,1,1}, {1,0,1,1}, {1,1,0,1}, {1,1,1,0}};
	graph<char, 4> obj(vertex_array, edge_array);
	obj.print_param();
	obj.BFS();
	obj.DFS();
	return 0;
}