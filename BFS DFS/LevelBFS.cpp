#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX_VERTEX_COUNT = 100;

std::vector<int> graph[MAX_VERTEX_COUNT];
std::queue<int> spis;

int vertexCount, edgeCount;
bool visited[MAX_VERTEX_COUNT];

void bfs(int startNode)
{
	visited[startNode] = 1;
	spis.push(startNode);
	int node; // current node
	
	int level = 1;
	int nodesOfLevel = 1;
	int nodesOfNextLevel = 0;
	
	while(!spis.empty())
	{
		node = spis.front();
		printf("node = %d level = %d\n", node, level);
		nodesOfLevel--;
		spis.pop();
		
		for(int i = 0; i < graph[node].size(); i++)
		{
			if(!visited[graph[node][i]])
			{
				visited[graph[node][i]] = 1;
				nodesOfNextLevel++;
				spis.push(graph[node][i]);
			}
		}
		
		if(nodesOfLevel == 0)
		{
			level++;
			nodesOfLevel = nodesOfNextLevel;
			nodesOfNextLevel = 0;
		}
	}
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
	bfs(1);
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
