#include "lists.h"

/**
 * is_palindrome - determines if a linked list is a palindrome
 * @head: head node of a linked list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int *array, index = 0, max;

	max = loop_check(*head);
	if (max == -1 || !head)
		return (0);
	if (!*head)
		return (1);
	array = malloc(sizeof(int) * (max / 2) + 1);
	if (array == NULL)
		return (0);
	while (index <= max / 2)
	{
		array[index] = current->n;
		index++;
		current = current->next;
	}
	if (max % 2 == 0)
		index--;
	while (current->next)
	{
		index--;
		if (array[index] != current->n)
		{
			free(array);
			return (0);
		}
		current = current->next;
	}
	free(array);
	return (1);
}

/**
 * loop_check - detects if a linked list contains a loop
 * @head: head of the list
 * Return: -1 if loop detected, max index if not
 */
int loop_check(listint_t *head)
{
	listint_t *car1 = head, *car2 = head;
	int index = 0;

	while(car1->next)
	{
		car2 = car2->next;
		if (car1->next->next)
		{
			index += 2;
			car1 = car1->next->next;
			if (car1 == car2)
				return (-1);
		}
		else
		{
			index++;
			break;
		}
	}
	return index;
}
