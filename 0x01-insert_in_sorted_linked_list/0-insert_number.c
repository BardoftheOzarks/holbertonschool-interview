#include "lists.h"
#include <stdlib.h>
/**
 * insert_node - inserts a node into a sorted linked list
 * @head: head of the list
 * @number: int to be inserted
 * Return: address of new node
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *scanner = *head, *new = malloc(sizeof(listint_t));
    new->n = number;
    while (scanner->next && scanner->next->n < number)
        scanner = scanner->next;
    new->next = scanner->next;
    scanner->next = new;
    return new;
}
