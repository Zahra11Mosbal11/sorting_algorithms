#include "sort.h"
/**
 * cocktail_sort_list -  sorts a doubly linked list of integers
 * @list: the list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	bool swap = true;
	listint_t *current, *back;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = (*list);
	back = NULL;
	while (swap)
	{
		swap = false;
		while (current->next && current != back)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swap = true;
			}
			else
				current = current->next;
		}
		back = current;
		if (!swap)
			break;
		swap = false;
		while (current->prev && current != *list)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swap = true;
			}
			else
				current = current->prev;
		}
		*list = current;
	}
}
/**
 * swap_nodes - to swaping.
 * @list: the list
 * @node1: the first node
 * @node2: the secand node
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2 || node1 == node2)
		return;
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
