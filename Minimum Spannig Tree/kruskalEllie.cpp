//Kruskal
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

const int VERTEX_COUNT = 100;

struct Edge
{
	int from, to, cost;
};

std::vector<std::pair<int, int> > MST[VERTEX_COUNT];
std::vector<Edge> edges;
int n, m;
int uf[VERTEX_COUNT], depth[VERTEX_COUNT];

void nullify()
{
	for(int i = 0; i < n; i++)
	{
		uf[i] = i;
	}
	//fill(depth, depth + n, 0)
}

int getRoot(int node)
{
	while(node != uf[node])
	{
		node = uf[node];
	}
	return node;
}

void link(int root1, int root2)
{
	//wanted depth[root1] > depth[root2];
	//uf[root2] = root1;
	if(depth[root1] == depth[root2])
		depth[root1]++;
	else if(depth[root1] < depth[root2]) 
		std::swap(root1, root2);
	uf[root2] = root1;
}

void Kruskal()
{
	nullify();
	int totalSum = 0;
	for(int i = 0; i < m; i++)
	{
		int root1 = getRoot(edges[i].from);
		int root2 = getRoot(edges[i].to);
		
		if(root1 != root2)
		{
			link(root1, root2);
			totalSum += edges[i].cost;
			MST[edges[i].from].push_back({edges[i].to, edges[i].cost});
			MST[edges[i].to].push_back({edges[i].from, edges[i].cost});
		}
	}
	printf("%d\n", totalSum);
}

bool cmp(const Edge& e1, const Edge& e2)
{
	return e1.cost < e2.cost;
}

void input()
{
	scanf("%d%d",&n, &m);
	Edge temp;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d",&temp.from, &temp.to, &temp.cost);
		edges.push_back(temp);
	}
	std::sort(edges.begin(), edges.end(), cmp);
	Kruskal();
} 

int main()
{
	input();
}

/*
9 13
0 1 6 
0 2 10
1 4 11
2 4 5
2 7 9
3 5 2
3 6 1
4 7 12
4 8 8
5 6 4
6 7 13
7 8 7
2 8 9 


sorted list of edges
3 6 1  -> used
3 5 2  -> used
5 6 4
2 4 5  -> used
0 1 6  -> used
7 8 7  -> used
4 8 8  -> used
2 7 9
2 8 9
0 2 10 -> used
1 4 11
4 7 12
6 7 13 -> used

totalSum = 1 + 2 + 5 + 6 + 7 + 8 + 10 + 13 = 52 

*/
