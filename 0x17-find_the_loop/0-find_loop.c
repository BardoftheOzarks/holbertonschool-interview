#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - finds a loop withing a linked list
 * @head: head of the linked list
 * Return: the address of the node where the loop starts, NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head, *hare = head;

	if (head == NULL)
		return (NULL);
	while (hare->next && hare->next->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		printf("Tort: %d, Hare: %d\n", tortoise->n, hare->n);
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
				printf("Tort: %d, Hare: %d\n", tortoise->n, hare->n);
			}
			return (tortoise);
		}
	}
	return (NULL);
}
