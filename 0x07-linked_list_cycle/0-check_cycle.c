#include "lists.h"

/**
 * check_cycle - checks a linked list for cyclical redundancy
 * @list: head of linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *tortoise = list, *hare = list;

	while (hare->next && hare->next->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
			return (1);
	}
	return (0);
}
