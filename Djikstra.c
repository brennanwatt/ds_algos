#include <stdio.h>

#define V   (9)
#define INF (0x0FFFFFFF)

void printPath(int parent[V])
{
    for (int i = 0; i < V; i++)
    {
        printf("Printing path for node %d\n",i);
        int parentNode = parent[i];
        while (parentNode !=V)
        {
            printf("\tNode %d\n", parentNode);
            parentNode = parent[parentNode];
        }
    }
}

void printShortestPaths(int dist[V])
{
    for (int i = 0; i < V; i++)
    {
        printf("Node %d is %d from root\n",i,dist[i]);
    }
}

int pickNextNode(int visited[V], int dist[V])
{
    int minDist = INF;
    int minNode = V;
    
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dist[i] < minDist)
            {
                minNode = i;
                minDist = dist[i];
            }
        }
    }
    
    return minNode;
}

void djikstra(int graph[V][V], int startNode)
{
    // setup tracking arrays.
    int dist[V];
    int visited[V];
    int parent[V];
    
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = V;
    }
    
    dist[startNode] = 0;
    int curNode = startNode;

    while (curNode != V)
    {
        visited[curNode] = 1;
        for (int i =0; i < V; i++)
        {
            if (!visited[i])
            {
                // Haven't been to this node yet.
                if(graph[curNode][i])
                {
                    // There is a connection to this node.
                    if (dist[i] > (dist[curNode] + graph[curNode][i]))
                    {
                        // Found new shorter path.
                        dist[i] = dist[curNode] + graph[curNode][i];
                        parent[i] = curNode;
                    }
                }
            }
        }
        curNode = pickNextNode(visited, dist);
    }
    
    printShortestPaths(dist);
    printPath(parent);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
                        
    djikstra(graph, 0);
    
    return 0;
}