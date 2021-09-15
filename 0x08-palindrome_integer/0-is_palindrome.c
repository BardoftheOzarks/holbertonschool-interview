#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned int is a palindrome
 * @n: unsigned int to be tested
 * Return: 1 if true, 0 if false
 */
int is_palindrome(unsigned long n)
{
	unsigned long x = n;
	listint_t *head = NULL, *tail = NULL, *current = NULL;

	while (x > 0)
	{
		tail = add_node(&tail, x % 10);
		if (head == NULL)
			head = tail;
		x = x / 10;
	}
	current = head;
	while (current->n == tail->n)
	{
		if (current->next == tail || current == tail)
		{
			free_list(head);
			return (1);
		}
		current = current->next;
		tail = tail->prev;
	}
	free_list(head);
	return (0);
}

/**
 * add_node - creates a node
 * @prev: previous node for linking
 * @n: int
 * Return: new node
 */
listint_t *add_node(listint_t **prev, int n)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	new->prev = *prev;
	if (*prev == NULL)
		*prev = new;
	else
		(*prev)->next = new;
	return (new);
}

/**
 * free_list - frees a list
 * @head: head node of list
 */
void free_list(listint_t *head)
{
	listint_t *current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
