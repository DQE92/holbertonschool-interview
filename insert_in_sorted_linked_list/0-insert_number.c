/* 0-insert_number.c */
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insère un entier dans une liste simplement chaînée triée (asc)
 * @head: adresse du pointeur vers la tête de liste
 * @number: valeur à insérer
 *
 * Return: adresse du nouveau nœud, ou NULL en cas d'échec
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *curr;

    if (head == NULL)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL || number <= (*head)->n)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    curr = *head;
    while (curr->next != NULL && curr->next->n < number)
        curr = curr->next;

    new_node->next = curr->next;
    curr->next = new_node;

    return (new_node);
}
