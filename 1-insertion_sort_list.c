#include "sort.h"
/**
 * insertion_sort_list - orts a doubly linked list
 * @list: the list of integer.
 * Return: voide
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *curnt;
	bool swap = false;

	if (!list || !(*list) || !(*list)->next)
		return;
	curnt = *list;
	while (curnt->next)
	{
		if (curnt->n > curnt->next->n)
		{
			curnt->next->prev = curnt->prev;
			if (curnt->next->prev)
				curnt->prev->next = curnt->next;
			else
				*list = curnt->next;

			curnt->prev = curnt->next;
			curnt->next = curnt->next->next;
			curnt->prev->next = curnt;
			if (curnt->next)
				curnt->next->prev = curnt;

			curnt = curnt->prev;
			print_list(*list);

			if (curnt->prev && curnt->prev->n > curnt->n)
			{
				if (!swap)
					node = curnt->next;
				swap = true;
				curnt = curnt->prev;
				continue;
			}
		}
		if (!swap)
			curnt = curnt->next;
		else
			curnt = node, swap = false;
	}
}
