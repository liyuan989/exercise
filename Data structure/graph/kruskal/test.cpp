#include <iostream>
#include <memory>
#include "graph.h"



int main(int argc, char const *argv[])
{
	const char* vertex_array = "ABCD";
	int edge_array[4][4] = {{0,2,3,3}, {2,0,3,4}, {3,3,0,2}, {3,4,2,0}};
	graph<char, 4> obj(vertex_array, edge_array);
	obj.print_param();
	std::cout << "BFS traverse : " << std::endl;
	obj.BFS();
	std::cout << "DFS traverse : " << std::endl;
	obj.DFS();
	std::cout << "prim algrithm : " << std::endl;
	obj.prim();
	std::cout << "kruskal algrithm : " << std::endl;
	Edge ordered_edge[6] = {{0,1,2}, {2,3,2}, {0,3,3}, {0,2,3}, {1,2,3}, {1,3,4}};
	obj.kruskal(ordered_edge);
	return 0;
}