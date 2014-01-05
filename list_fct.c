#include "ft_select.h"

t_elem				*ft_elem_init(char *data)
{
	t_elem			*new_elem;

	if (!(new_elem = (t_elem*)malloc(sizeof(t_elem))))
		ft_error(1);
	if (!(new_elem->data = ft_strdup(data)))
		ft_error(1);
	new_elem->prev = NULL;
	new_elem->next = NULL;
	new_elem->cursor = 0;
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

void				ft_elem_del(t_elem *elem_to_del)
{
	t_elem			*ptr_prev;
	t_elem			*ptr_next;

	ptr_prev = elem_to_del->prev;
	ptr_next = elem_to_del->next;
	if (ptr_prev && ptr_next)
	{
		ptr_prev->next = ptr_next;
		ptr_next->prev = ptr_prev;
	}
	free(elem_to_del);
}

/*
**	Initiliaze the list and return the nb_elem of the list.
*/

void				ft_initialize(int ac, char **av, t_list *init)
{
	t_elem			*ptr;
	int				i;

	init->first_elem = ft_elem_init(*av);
	ac--;
	av++;
	i = 0;
	while (i < ac)
	{
		ptr = ft_elem_init(*av);
		ft_elem_add(init->first_elem, ptr);
		i++;
		ptr->index = i;
		av++;
	}
	init->nb_elem = ac;
}
