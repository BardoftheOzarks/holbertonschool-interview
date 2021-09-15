#ifndef PALINDROME_H
#define PALINDROME_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - doubly linked list
 * @n: int
 * @next: pointer to next node
 * @prev: pointer to previous node
 * Description: doubly linked list node struct
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
	struct listint_s *prev;
} listint_t;

int is_palindrome(unsigned long n);
listint_t *add_node(listint_t **prev, int n);
void free_list(listint_t *head);

#endif
