#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V   (9)
#define INF (0x0FFFFFFF)

struct node
{
    int vertex;
    struct node *next;
};

typedef struct
{
    struct node  *head;
    struct node  *tail;
    int     count;
}queue_t;

queue_t q = {NULL, NULL, 0};

void add_to_queue(struct node *node)
{
    if (q.head == NULL)
    {
        q.head = node;
    }
    else
    {
        q.tail->next = node;
    }
    
    q.tail = node;
    node->next = NULL;
    
    q.count++;
}

void add_to_head(struct node *node)
{
    if (q.tail == NULL)
    {
        q.tail = node;
    }
    
    node->next = q.head;
    q.head = node;
    
    q.count++;
}

struct node* pop_head_node()
{
    if (q.head == NULL)
    {
        return NULL;
    }
    
    struct node *node = q.head;
    q.head = q.head->next;
    q.count--;
    
    return node;
}

void BFS(int graph[V][V], int start_vertex)
{
    // setup tracking array.
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    
    struct node *start_node = (struct node*)malloc(sizeof(struct node));
    start_node->vertex = start_vertex;
    add_to_queue(start_node);
    visited[start_vertex] = true;

    struct node *cur_node;
    while ((cur_node = pop_head_node()) != NULL)
    {
        printf("BFS - Visiting vertex %u\n",cur_node->vertex);
        for (int i =0; i < V; i++)
        {
            if (!visited[i] && graph[cur_node->vertex][i])
            {
                // Haven't been to this vertex yet & vertices are connected.
                struct node *node = (struct node*)malloc(sizeof(struct node));
                node->vertex = i;
                add_to_queue(node);
                visited[i] = true;
            }
        }
        free(cur_node);
    }
}

void DFS(int graph[V][V], int start_vertex)
{
    // setup tracking array.
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    
    struct node *start_node = (struct node*)malloc(sizeof(struct node));
    start_node->vertex = start_vertex;
    add_to_head(start_node);
    visited[start_vertex] = true;

    struct node *cur_node;
    while ((cur_node = pop_head_node()) != NULL)
    {
        printf("DFS - Visiting vertex %u\n",cur_node->vertex);
        for (int i =0; i < V; i++)
        {
            if (!visited[i] && graph[cur_node->vertex][i])
            {
                // Haven't been to this vertex yet & vertices are connected.
                struct node *node = (struct node*)malloc(sizeof(struct node));
                node->vertex = i;
                add_to_head(node);
                visited[i] = true;
            }
        }
        free(cur_node);
    }
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
    
    BFS(graph, 0);
    DFS(graph, 0);
    
    return 0;
}