#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <memory.h>
#include <iostream>
#include <queue>

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
				std::cout << edge_type[i][j];
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
						if (edge_type[temp][j] && !visit[j])
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
	
private:
	void do_DFS(int i, bool* visit) const
	{
		std::cout << vertex_type[i];
		visit[i] = true;
		for (int j = 0; j < SIZE; ++j)
		{
			if (edge_type[i][j] && !visit[j])
			{
				do_DFS(j, visit);
			}
		}
	}

	T    vertex_type[SIZE];
	int  edge_type[SIZE][SIZE];
};

#endif