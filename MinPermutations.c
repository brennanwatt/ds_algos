#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue{
  struct node_t *head;
  struct node_t *tail;
  int count;
};

struct node_t{
  int *array;
  int level;
  int node_number;
  int parent;
  struct node_t *next;
};

void push_to_q(struct queue *q, struct node_t *node)
{
  if (q->head == NULL)
  {
    q->head = node;
  }
  else
  {
    q->tail->next = node;
  }
  
  q->tail = node;
  q->count += 1;
}

struct node_t* pop_from_head(struct queue *q)
{
  struct node_t *node = q->head;
  if (q->count == 1)
  {
    q->head = NULL;
    q->tail = NULL;
    q->count = 0;
  }
  else
  {
    q->head = q->head->next;
    q->count -= 1;
  }
  return node;
}

void reverse_and_copy(int *array, int *dest, int start, int end, int n)
{
  for (int i=0; i<start; i++)
  {
    dest[i] = array[i];
  }
  
  for (int i=end+1; i<n; i++)
  {
    dest[i] = array[i];
  }
  
  while (start <= end)
  {
    dest[start] = array[end];
    dest[end--] = array[start++];
  }
}

void print_array(int *array, int n)
{
  for (int i=0; i<n; i++)
  {
    printf("%u=%u\n",i,array[i]);
  }
  printf("\n");
}

bool is_asc(int *array, int n)
{
  for (int i=1; i<n; i++)
  {
    if (array[i] < array[i-1])
    {
      return false;
    }
  }
  
  return true;
}

bool arrays_equal(int *a, int *b, int n)
{
  for (int i=0; i<n; i++)
  {
    if (a[i] != b[i])
    {
      return false;
    }
  }
  
  return true;
}

bool exists(struct queue *q, struct node_t *node, int n)
{
  struct node_t *cur = q->head;
  for (int i=0; i<q->count; i++)
  {
    if (cur == NULL)
    {
      printf("looking at null node!\n");
      return false;
    }
    
    if (arrays_equal(cur->array, node->array, n))
    {
      return true;
    }
    cur = cur->next;
  }
  
  return false;
}

struct node_t* get_parent_node(struct node_t *child, struct queue *q)
{
  struct node_t *cur = q->head;
  for (int i=0; i<q->count; i++)
  {
    if (cur == NULL)
    {
      printf("looking at null node!\n");
      return NULL;
    }
    
    if (child->parent == cur->node_number)
    {
      return cur;
    }
    cur = cur->next;
  }
  
  return NULL;
}

void print_array_tree(struct node_t *cur, int n, struct queue *q)
{
    while(cur->parent >= 0)
    {
        print_array(cur->array, n);
        cur = get_parent_node(cur, q);
    }
}

int minOperations(int arr[], int n) {
  struct queue visited = {NULL, NULL, 0};
  struct queue to_visit = {NULL, NULL, 0};
  
  int node_number=0;
  struct node_t *root = (struct node_t*)malloc(sizeof(struct node_t));
  root->array = arr;
  root->level = 0;
  root->node_number = node_number;
  root->parent = -1;
  push_to_q(&to_visit, root);
  while (to_visit.count != 0)
  {
    struct node_t *cur = pop_from_head(&to_visit);
    push_to_q(&visited, cur);
    if (is_asc(cur->array, n))
    {
      print_array_tree(cur, n, &visited);
      print_array(arr, n);
      return cur->level;
    }
    else
    {
      for (int i=0; i<n; i++)
      {
        for (int j=i+1; j<n; j++)
        {
          struct node_t *next = (struct node_t*)malloc(sizeof(struct node_t));
          int *array_next = (int*)malloc(n*sizeof(int));
          reverse_and_copy(cur->array, array_next, i, j, n);
          next->array = array_next;
          next->level = cur->level + 1;
          if (!exists(&visited, next, n))
          {
            next->node_number = ++node_number;
            next->parent = cur->node_number;
            push_to_q(&to_visit, next);
          }
          else
          {
            free(array_next);
            free(next);
          }
        }
      }
    }
  }
  
  printf("exiting at to visit q count=%u, visited q count=%u\n", to_visit.count, visited.count);
  
  return 0;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
void printInteger(int n) {
  printf("[%d]", n);
}

int test_case_number = 1;

void check(int expected, int output) {
  int result = (expected == output);
  if (result) {
    printf("Pass Test #%d\n", test_case_number);
  }
  else {
    printf("Fail Test #%d: Expected ", test_case_number);
    printInteger(expected); 
    printf(" Your output: ");
    printInteger(output);
    printf("\n");
  }
  test_case_number++;
}

int main() {

  int n_1 = 5;
  int arr_1[] = {1, 2, 5, 4, 3};
  int expected_1 = 1;
  int output_1 = minOperations(arr_1, n_1);
  check(expected_1, output_1);

  int n_2 = 3;
  int arr_2[] = {3, 1, 2};
  int expected_2 = 2;
  int output_2 = minOperations(arr_2, n_2);
  check(expected_2, output_2);

  // Add your own test cases here
  int n_3 = 7;
  int arr_3[] = {3, 1, 2, 7, 4, 1, 5};
  int expected_3 = 4;
  int output_3 = minOperations(arr_3, n_3);
  check(expected_3, output_3);
}