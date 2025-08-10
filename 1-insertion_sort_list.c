#include "sort.h"
/**
 * get - gets nth node in linked list
 * @list: root node of linked list
 * @n: number
 *
 * Return: pointer to nth node
 */
listint_t *get(listint_t *list, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		list = list->next;
	return (list);
}
/**
 * size - get size of linked list
 * @f: pointer to first node
 *
 * Return: size
 */
size_t size(listint_t *f)
{
	size_t l = 0;

	while (f)
	{
		f = f->next;
		l++;
	}
	return (l);
}
/**
 * swap - swaps two nodes of linked list
 * @list: linked list
 * @a: index to first
 * @b: index to second
 *
 * Return: returns new root node
 */
listint_t *swap(listint_t *list, size_t a, size_t b)
{
	if (a != b)
	{
		listint_t *f = get(list, a), *s = get(list, b);
		listint_t *t1 = f->prev, *t2 = f->next;

		if (f->prev)
			f->prev->next = s;
		else
			list = s;
		f->prev = s->prev;
		if (f->next)
			f->next->prev = s;
		f->next = s->next;
		if (s->prev)
			s->prev->next = f;
		else
			list = f;
		s->prev = t1;
		if (s->next)
			s->next->prev = f;
		s->next = t2;
	}
	return (list);
}
/**
 * insertion_sort_list - sorts a list with insertion sort
 * @list: pointer to root of linked list
 */
void insertion_sort_list(listint_t **list)
{
	size_t i = 1;

	while (i < size(*list))
	{
		listint_t *node = get(*list, i);
		size_t j = i;

		while (j > 0 && (node->n < node->prev->n))
		{
			*list = swap(*list, j, j - 1);
			j--;
			print_list(*list);
		}
		if (i == j)
			node = node->next;
		i++;
	}
}
