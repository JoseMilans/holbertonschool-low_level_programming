#include "lists.h"
/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: Pointer to the head of the list.
 * @idx: the index where the new node should be added, starting from 0.
 * @n: The data for the neww node.
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *visitor;
	unsigned int i;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	visitor = *h;
	for (i = 0; i < idx - 1 && visitor != NULL; i++)
		visitor = visitor->next;
	if (visitor == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = visitor->next;
	new->prev = visitor;
	if (visitor->next != NULL)
		visitor->next->prev = new;
	visitor->next = new;
	return (new);
}
