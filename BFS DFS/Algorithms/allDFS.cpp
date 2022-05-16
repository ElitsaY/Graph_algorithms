#include<iostream>
#include<vector>

const int MAX_VERTEX_COUNT = 100;

std::vector<int> graph[MAX_VERTEX_COUNT];
bool visited[MAX_VERTEX_COUNT]; 
int vertexCount, edgeCount;
std::vector<int> path;

void print()
{
	int pathSize = path.size();
	printf("%d",path[0]);
	for(int i = 1; i < pathSize; i++)
	{
		printf(" %d",path[i]);
	}
	printf("\n");
}

void dfs(int node)
{
	visited[node] = 1;
	path.push_back(node);
	for(int i = 0; i < graph[node].size(); i++)
	{
		if(!visited[graph[node][i]])
		{
			dfs(graph[node][i]);
		}
	}
	visited[node] = 0;
	print();
	path.pop_back();
	
}

int main()
{
	scanf("%d%d",&vertexCount, &edgeCount);
	int vertexFrom, vertexTo;
	for(int i = 0; i < edgeCount; i++)
	{
		scanf("%d%d",&vertexFrom,&vertexTo);
		graph[vertexFrom].push_back(vertexTo);
		graph[vertexTo].push_back(vertexFrom);
	}
	
	for(int vertex = 1; vertex <= vertexCount; vertex++)
	{
		if(visited[vertex] == false)
		{
			dfs(vertex);
		}
	}	
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
