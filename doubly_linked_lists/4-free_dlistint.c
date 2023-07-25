#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: a pointer to the head of the dlistint_t list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
