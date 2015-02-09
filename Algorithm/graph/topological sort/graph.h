#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <memory.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

struct edge_base
{
	int 		vertex_num;
	edge_base*  next;
};

template<typename T>
struct vertex_base
{
	T 			data;
	int 		in;
	edge_base*  first_edge;
};

template<typename T, int SIZE>
class graph
{
public:
	graph()
	{
		memset(vertex_type, 0, sizeof(vertex_type));
	}

	graph(const T* vertex_array, const std::vector<int> edge_array[SIZE], const int* in_degree)
	{
		memset(vertex_type, 0, sizeof(vertex_type));
		for (int i = 0; i < SIZE; ++i)
		{
			vertex_type[i].data = vertex_array[i];
			vertex_type[i].in = in_degree[i];
			for (int j = 0; j < edge_array[i].size(); ++j)
			{
				edge_base* temp = new edge_base;
				temp->vertex_num = edge_array[i][j];
				temp->next = vertex_type[i].first_edge;
				vertex_type[i].first_edge = temp;
			}
		}
	}

	~graph()
	{
		for (int i = 0; i < SIZE; ++i)
		{
			if (vertex_type[i].first_edge)
			{
				edge_base* temp = vertex_type[i].first_edge;
				vertex_type[i].first_edge = vertex_type[i].first_edge->next;
				delete temp;
			}
		}
	}

	void print() const
	{
		for (int i = 0; i < SIZE; ++i)
		{
			std::cout << vertex_type[i].data << " " << vertex_type[i].first_edge 
					  << " " << vertex_type[i].in << "    ";
			edge_base* temp = vertex_type[i].first_edge;
			while (temp)
			{
				std::cout << temp->vertex_num << " " <<temp->next << "  ";
				temp = temp->next;
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
				std::cout << vertex_type[i].data;
				visit[i] = true;
				Queue.push(i);
				while(!Queue.empty())
				{
					int index_temp = Queue.front();
					Queue.pop();
					for (edge_base* temp = vertex_type[index_temp].first_edge; temp != NULL; temp = temp->next)
					{
						if (!visit[temp->vertex_num])
						{
							std::cout << vertex_type[temp->vertex_num].data;
							visit[temp->vertex_num] = true;
							Queue.push(temp->vertex_num);
						}
					}
				}
			}
		}
		std::cout << std::endl;
	}

	bool topological_sort() const
	{
		std::stack<int> Stack;
		int in_degree[SIZE];
		memset(in_degree, 0, sizeof(in_degree));
		int count = 0;
		for (int i = 0; i < SIZE; ++i)
		{
			in_degree[i] = vertex_type[i].in;
			if (!in_degree[i])
			{
				Stack.push(i);
			}
		}
		while(!Stack.empty())
		{
			int pop_num = Stack.top();
			Stack.pop();
			++count;
			std::cout << vertex_type[pop_num].data << " ";
			for (edge_base* temp = vertex_type[pop_num].first_edge; temp; temp = temp->next)
			{
				--in_degree[temp->vertex_num];
				if (!in_degree[temp->vertex_num])
				{
					Stack.push(temp->vertex_num);
				}
			}
		}
		std::cout << std::endl;
		if (count != SIZE)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

private:
	void do_DFS(int i, bool* visit) const
	{
		std::cout << vertex_type[i].data;
		visit[i] = true;
		edge_base* temp = vertex_type[i].first_edge;
		while(temp)
		{
			if (!visit[temp->vertex_num])
			{
				do_DFS(temp->vertex_num, visit);
			}
			temp = temp->next;
		}
	}

	vertex_base<T>  vertex_type[SIZE];
};

#endif