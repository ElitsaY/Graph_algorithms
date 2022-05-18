#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define PAIR std::pair<int, int>

const int VERTEX_COUNT = 1000;
const int INF = 1000;

struct Edge
{
	int to;
	int cost;
	Edge(int to, int cost)
	{
		this->to = to;
		this->cost = cost;
	}
};

std::vector<Edge> graph[VERTEX_COUNT];
std::priority_queue<PAIR, std::vector<PAIR>, std::greater<PAIR> > spis;
bool visited[VERTEX_COUNT];
int minPath[VERTEX_COUNT];
int vertexCount, edgeCount;

void nullify()
{
	std::fill(minPath, minPath + VERTEX_COUNT, INF);
	std::fill(visited, visited + VERTEX_COUNT, false);
	while(!spis.empty()) spis.pop();
}

void minPathFrom(int startVertex)
{
	nullify();
	
	minPath[startVertex] = 0;
	spis.push({0,startVertex});
	
	int vertex;
	while(!spis.empty())
	{
		vertex = spis.top().second;
		spis.pop();
		visited[vertex] = true;
		
		for(int i = 0; i < graph[vertex].size(); i++)
		{
			Edge nextVertex = graph[vertex][i];
			if(visited[nextVertex.to] == false)
			{
				if(minPath[nextVertex.to] > minPath[vertex] + nextVertex.cost)
				{
					minPath[nextVertex.to] = minPath[vertex] + nextVertex.cost;
					spis.push({minPath[nextVertex.to], nextVertex.to});
				}
			}
		}
	}
	//for example
	int finishVertex;
	scanf("%d",&finishVertex);
	printf("%d\n",minPath[finishVertex]);
}

void input()
{
	scanf("%d%d",&vertexCount, &edgeCount);
	int f, t, c;
	for(int i = 0; i < edgeCount; i++)
	{
		scanf("%d%d%d",&f, &t, &c);
		graph[f].push_back(Edge(t,c));
	}	
	int startVertex;
	scanf("%d",&startVertex);
	minPathFrom(startVertex);
}

int main()
{
	input();
}

/*
The graph is directed
6 8 
1 3 10
1 2 15
3 5 12
3 4 15
5 4 1
4 6 5
5 6 2
2 6 10
1 6

expected output = 24
*/
