#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void deleteList(struct Node** head)
{
   struct Node* prev = *head;

   while (*head)
   {
	   *head = (*head)->next;
	   printf("Deleting %d\n", prev->data);
	   free(prev);
	   prev = *head;
   }
}

int main(void)
{
	int keys[] = {1, 2, 3, 4, 5};
	int n = sizeof(keys) / sizeof(int);

	struct Node* head = NULL;
	for (int i = n - 1; i >= 0; i--)
    {
		push(&head, keys[i]);
    }

	deleteList(&head);

	if (head == NULL)
    {
		printf("List deleted");
    }

	return 0;
}