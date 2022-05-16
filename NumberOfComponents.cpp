#include<iostream>
#include<vector>

std::vector<int> graph[100];
bool visited[100]; 
int vertexCount, edgeCount;

void dfs(int node)
{
	visited[node] = 1;
	for(int i = 0; i < graph[node].size(); i++)
	{
		if(!visited[graph[node][i]])
		{
			dfs(graph[node][i]);
		}
	}
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
	int components = 0;
	for(int vertex = 1; vertex <= vertexCount; vertex++)
	{
		if(visited[vertex] == false)
		{
			dfs(vertex);
			components++;
		}
	}
	printf("%d\n",components);
	
}
