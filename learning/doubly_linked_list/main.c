#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}	Node;

Node	*add_to_empty(Node *head, int new_data)
{
	Node *tmp = malloc(sizeof(Node));
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->data = new_data;
	head = tmp;
	return head;
}

Node	*add_at_beginning(Node *head, int new_data)
{
	Node *tmp = malloc(sizeof(Node));
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->data = new_data;
	tmp->next = head;
	head->prev = tmp;
	head = tmp;
	return head;
}

Node	*get_last(Node *head)
{
	Node *last;

	last = head;
	while (last->next != NULL)
		last = last->next;
	return last;
}

Node	*add_at_end(Node *head, int new_data)
{
	Node *tmp = malloc(sizeof(Node));
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->data = new_data;

	Node *last = get_last(head);
	last->next = tmp;
	tmp->prev = last;
	return head;
}

Node	*add_after_position(Node *head, int value, int position)
{
	Node *new_position = NULL;
	Node *tmp = head;
	Node *tmp2 = NULL;
	new_position = add_to_empty(new_position, value);

	while (position > 1)
	{
		tmp = tmp->next;
		position--;
	}
	tmp2 = tmp->next;
	tmp->next = new_position;
	tmp2->prev = new_position;
	new_position->prev = tmp;
	new_position->next = tmp2;
	return head;
}

int main(void)
{
	Node *head = NULL;
	Node *ptr;

	head = add_to_empty(head, 45);
	head = add_at_beginning(head, 10);
	head = add_at_end(head, 15);
	head = add_at_end(head, 22);
	head = add_after_position(head, 12, 3);
	head = add_after_position(head, 11, 1);
	
	ptr = head;
	while (ptr != NULL)
	{
		printf("value=%d\n", ptr->data);
		ptr = ptr->next;
	}
	return (0);
}
