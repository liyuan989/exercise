#include <iostream>
#include <memory>
#include "graph.h"

int main(int argc, char const *argv[])
{
	int max =  ~static_cast<unsigned int>(0) >> 3;
	const char* vertex_array = "ABCDEFGHI";
	int edge_array[9][9] = {{0,1,5,max,max,max,max,max,max}, 
							{1,0,3,7,5,max,max,max,max}, 
							{5,3,0,max,1,7,max,max,max}, 
							{max,7,max,0,2,max,3,max,max},
							{max,5,1,2,0,3,6,9,max},
							{max,max,7,max,3,0,max,5,max},
							{max,max,max,3,6,max,0,2,7},
							{max,max,max,max,9,5,2,0,4},
							{max,max,max,max,max,max,7,4,0}};
	graph<char, 9> obj(vertex_array, edge_array);
	obj.print_param();
	std::cout << "BFS traverse : " << std::endl;
	obj.BFS();
	std::cout << "DFS traverse : " << std::endl;
	obj.DFS();
	std::cout << "prim algorithm : " << std::endl;
	obj.prim();
	std::cout << "kruskal algorithm : " << std::endl;
	Edge ordered_edge[16] = {{0,1,1}, {2,4,1}, {1,3,2}, {3,4,2}, {6,7,2}, {1,2,3}, {4,5,3}, {3,6,3},
							 {7,8,4}, {0,2,5}, {1,4,5}, {5,7,5}, {4,6,6}, {2,5,7}, {6,8,7}, {4,7,9}};
	obj.kruskal(ordered_edge);
	int shorter_index[9];
	int shorter_length[9];
	std::cout << "shorter_index : " << std::endl;
	obj.dijkstra(shorter_index, shorter_length, 0);
	for (int i = 0; i < 9; ++i)
	{
		std::cout << "f(" << vertex_array[i] << ") = " << vertex_array[shorter_index[i]] << std::endl;
	}
	std::cout << "shorter_length :" << std::endl;
	for (int i = 0; i < 9; ++i)
	{
		std::cout << "A" << vertex_array[i] << " = " << shorter_length[i] << std::endl;
	}
	return 0;
}