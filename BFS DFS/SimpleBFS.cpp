#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX_VERTEX_COUNT = 100;

std::vector<int> graph[MAX_VERTEX_COUNT];
std::queue<int> spis;

int vertexCount, edgeCount;
int startNode, finishNode;
bool visited[MAX_VERTEX_COUNT];

bool bfs()
{
	spis.push(startNode);
	int node; // current node
	while(!spis.empty())
	{
		node = spis.front();
		visited[node] = 1;
		spis.pop();
		for(int i = 0; i < graph[node].size(); i++)
		{
			if(!visited[graph[node][i]])
			{
				if(graph[node][i] == finishNode) return 1;
				spis.push(graph[node][i]);
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d",&vertexCount, &edgeCount);
	int vertexFrom, vertexTo;
	for(int i = 0; i < edgeCount; i++)
	{
		scanf("%d%d", &vertexFrom,&vertexTo);
		graph[vertexFrom].push_back(vertexTo);
		graph[vertexTo].push_back(vertexFrom);
	}
	scanf("%d%d",&startNode,&finishNode);
	std::cout<<bfs()<<std::endl;
}

/*
5 6 
1 2
2 3
4 5
3 4
1 3
2 4
*/
