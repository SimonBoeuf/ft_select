#include "./includes/ft_select.h"

t_elem				*ft_elem_init(char *data, int cursor)
{
	t_elem			*new_elem;

	if (!(new_elem = (t_elem*)malloc(sizeof(t_elem))))
		ft_error(1, 2);
	if (!(new_elem->data = ft_strdup(data)))
		ft_error(1, 2);
	new_elem->prev = new_elem;
	new_elem->next = new_elem;
	new_elem->cursor = cursor;
	new_elem->selected = 0;
	return (new_elem);
}

void				ft_elem_add(t_elem *first_elem, t_elem *elem_to_add)
{
	t_elem			*tmp;

	tmp = first_elem->prev;
	if (!tmp)
	{
		first_elem->prev = elem_to_add;
		first_elem->next = elem_to_add;
		elem_to_add->prev = first_elem;
		elem_to_add->next = first_elem;
	}
	else
	{
		first_elem->prev = elem_to_add;
		elem_to_add->next = first_elem;
		elem_to_add->prev = tmp;
		tmp->next = elem_to_add;
	}
}

t_elem				*ft_elem_del(t_list *list, t_elem *elem_to_del)
{
	t_elem			*ptr_next;

	ptr_next = elem_to_del->next;
	if (elem_to_del == list->first_elem)
		list->first_elem = ptr_next;
	elem_to_del->prev->next = ptr_next;
	ptr_next->prev = elem_to_del->prev;
	list->nb_elem--;
	free(elem_to_del->data);
	free(elem_to_del);
	elem_to_del = NULL;
	ptr_next->cursor = 1;
	return (ptr_next);
}