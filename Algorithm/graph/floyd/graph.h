#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <memory>
#include <iostream>
#include <queue>

struct Edge
{
	int begin;
	int end;
	int wight;
};


template<typename T, int SIZE>
class graph
{
public:
	graph()
	{
		memset(vertex_type, 0, sizeof(vertex_type));
		memset(edge_type, 0, sizeof(edge_type));
	}

	graph(const T* v, int e[SIZE][SIZE])
	{
		memset(vertex_type, 0, sizeof(vertex_type));
		memset(edge_type, 0, sizeof(edge_type));
		for (int i = 0; i < SIZE; ++i)
		{
			vertex_type[i] = v[i];
		}
		for (int i = 0; i < SIZE; ++i)
		{
			for (int j = 0; j < SIZE; ++j)
			{
				edge_type[i][j] = e[i][j];
			}
		}
	}

	void print_param() const
	{
		std::cout << "vertex : " << std::endl;
		for (int i = 0; i < SIZE; ++i)
		{
			std::cout << vertex_type[i];
		}
		std::cout << std::endl << "adjacency metrix : " << std::endl;
		for (int i = 0; i < SIZE; ++i)
		{
			for (int j = 0; j < SIZE; ++j)
			{
				std::cout << edge_type[i][j] << "  ";
			}
			std::cout << std::endl;
		}
	}

	void DFS() const
	{
		bool visit[SIZE];
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < SIZE; ++i)
		{
			if (!visit[i])
			{
				do_DFS(i, visit);
			}
		}
		std::cout << std::endl;
	}

	void BFS() const
	{
		bool visit[SIZE];
		memset(visit, 0, sizeof(visit));
		std::queue<int> Queue;
		for (int i = 0; i < SIZE; ++i)
		{
			if (!visit[i])
			{
				std::cout << vertex_type[i];
				Queue.push(i);
				visit[i] = true;
				while (!Queue.empty())
				{
					int temp = Queue.front();
					Queue.pop();
					for (int j = 0; j < SIZE; ++j)
					{
						if (edge_type[temp][j] < 100  && !visit[j]) //100表示小于最大值，也就是没有路径的不符合
						{
							Queue.push(j);
							std::cout << vertex_type[j];
							visit[j] = true;
						}
					}
				}
			}
		}
		std::cout << std::endl;
	}

	void prim() const
	{
		//begin with the 0th element
		int k = -1;
		int j = 0;
		int shorter_index[SIZE];
		memset(shorter_index, 0, sizeof(shorter_index));
		int shorter_length[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			shorter_length[i] = edge_type[0][i];
		}
		for (int n = 1; n < SIZE; ++n)
		{
			int min = ~static_cast<unsigned int>(0) >> 1;
			for (int index = 0; index < SIZE; ++index)
			{
				if (shorter_length[index] && shorter_length[index] < min)
				{
					min = shorter_length[index];
					k = index;
				}
			}
			std::cout << "(" << vertex_type[shorter_index[k]] << ", " << vertex_type[k] << ")" << std::endl;
			shorter_length[k] = 0;
			j = k;
			for (int _index = 0; _index < SIZE; ++_index)
			{
				if (shorter_length[_index] && edge_type[j][_index] < shorter_length[_index])
				{
					shorter_length[_index] = edge_type[j][_index];
					shorter_index[_index] = j;
				}
			}
		}
	}

	void kruskal(const Edge* ordered_edge) const
	{
		int edge_index[SIZE];
		memset(edge_index, 0, sizeof(edge_index));
		for (int i = 0; i < SIZE ; ++i)
		{
			int m = find_next_vertex(edge_index, ordered_edge[i].begin);
			int n = find_next_vertex(edge_index, ordered_edge[i].end);
			if (m != n)
			{
				edge_index[m] = n;
				std::cout << "(" << vertex_type[ordered_edge[i].begin] << ", " 
								 << vertex_type[ordered_edge[i].end] << ")" << std::endl;
			}
		}
	}

	void dijkstra(int* shorter_length, int* shorter_index, int num) const
	{
		int flag[SIZE];
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < SIZE; ++i)
		{
			shorter_length[i] = edge_type[num][i];
			shorter_index[i] = num;
		}
		int j = num;
		int k = -1;
		flag[num] = 1;
		for (int n = 1; n < SIZE; ++n)
		{
			int min = ~static_cast<unsigned int>(0) >> 1;
			for (int index = 0; index < SIZE; ++index)
			{
				if (!flag[index] && shorter_length[index] < min)
				{
					min = shorter_length[index];
					k = index;
				}
			}
			flag[k] = 1;
			j = k;
			for (int _index = 0; _index < SIZE; ++_index)
			{
				if (!flag[_index] && shorter_length[j] + edge_type[j][_index] < shorter_length[_index])
				{
					shorter_length[_index] = shorter_length[j] + edge_type[j][_index];
					shorter_index[_index] = j;
				}
			}
		}
	}

	void floyd(int shorter_matrix[SIZE][SIZE], int shorter_num[SIZE][SIZE]) const
	{
		for (int i = 0; i < SIZE; ++i)
		{
			for (int j = 0; j < SIZE; ++j)
			{
				shorter_matrix[i][j] = edge_type[i][j];
				shorter_num[i][j] = j;
			}
		}
		for (int pass = 0; pass < SIZE; ++pass)
		{
			for (int i = 0; i < SIZE; ++i)
			{
				for (int j= 0; j < SIZE; ++j)
				{
					if (shorter_matrix[i][pass] + shorter_matrix[pass][j] < shorter_matrix[i][j])
					{
						shorter_matrix[i][j] = shorter_matrix[i][pass] + shorter_matrix[pass][j];
						shorter_num[i][j] = shorter_num[i][pass];
					}
				}
			}
		}
	}
	
private:
	void do_DFS(int i, bool* visit) const
	{
		std::cout << vertex_type[i];
		visit[i] = true;
		for (int j = 0; j < SIZE; ++j)
		{
			if (edge_type[i][j] < 100 && !visit[j])  //100表示小于最大值，也就是没有路径的不符合
			{
				do_DFS(j, visit);
			}
		}
	}

	int find_next_vertex(int* edge_index, int num) const
	{
		while (edge_index[num] > 0)
		{
			num = edge_index[num];
		}
		return num;
	}

	T    vertex_type[SIZE];
	int  edge_type[SIZE][SIZE];
};

#endif