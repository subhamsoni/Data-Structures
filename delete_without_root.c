/* Program to delete a node in a Single Linked List without using the head pointer */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node 
{
	int data;
	struct node *next;
}*head=NULL;

/* Function to delete a node using the corresponding pointer */
void delete_node(struct node *ptr)
{
	// Point to the next node
	struct node *ptrnext = ptr->next;
	// Copy its data to the current node
	ptr->data = ptrnext->data;
	//Point to the next node in the list
	ptr->next = ptrnext->next;
	//Delete
	free(ptrnext); 
}

void get_data()
{
	struct node *new, *temp;
	int i = 5;
	if(head == NULL)
	{
		head = (struct node*)malloc(sizeof(struct node));
		head->data = rand() % 10;
		head->next = NULL;
		i--;
	}
	while(i-- > 0)
	{
		new = (struct node*)malloc(sizeof(struct node));
		new->data = rand() % 10;
		new->next = NULL;	
		temp = head;
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void print_list()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf(" %d ", temp->data);
		temp = temp->next;
	}
}

int main(void)
{
	get_data();
	printf("\n Before Deleton: ");
	print_list();
	delete_node(head->next->next);
	printf("\n After Deletion: ");
	print_list();
	return 0;
}


