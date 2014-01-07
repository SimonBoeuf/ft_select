#include "./includes/ft_select.h"

t_elem				*ft_elem_init(char *data)
{
	t_elem			*new_elem;

	if (!(new_elem = (t_elem*)malloc(sizeof(t_elem))))
		ft_error(1, 2);
	if (!(new_elem->data = ft_strdup(data)))
		ft_error(1, 2);
	new_elem->prev = new_elem;
	new_elem->next = new_elem;
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

t_elem				*ft_elem_del(t_elem *elem_to_del)
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
	return (ptr_next);
}

t_list				*ft_initialize(int ac, char **av)
{
	t_list			*list;
	t_elem			*ptr;
	int				i;
	char			*name;

	list = (t_list*)malloc(sizeof(t_list));
	name = ttyname(0);
	list->fd = open(name, O_WRONLY);
	list->first_elem = ft_elem_init(*av);
	list->first_elem->index = 1;
	list->longest = 0;
	av++;
	i = 1;
	while (i < ac)
	{
		if (list->longest < ft_strlen(*av))
			list->longest = ft_strlen(*av);
		ptr = ft_elem_init(*(av++));
		ft_elem_add(list->first_elem, ptr);
		i++;
		ptr->index = i;
	}
	list->curr_elem = list->first_elem->prev;
	list->nb_elem = ac + 1;
	return (list);
}

void	ft_print_list(t_list *list, int tr, int tc)
{
	int	i;
	t_cursor	*cursor;

	cursor = init_cursor(0, 0);
	list->curr_elem = list->first_elem;
	i = 1;
	if (list->nb_elem * (int)(list->longest + 4) > tc * tr)
		ft_putstr_fd("window too small", list->fd);
	else
	{
		while (i < list->nb_elem)
		{
			if (cursor->y == tr)
			{
				cursor->y = 0;
				cursor->x += list->longest + 4;
			}
			tputs(tgoto(cursor->res, cursor->x, cursor->y), 1, ft_putchar);
			ft_putstr_fd(list->curr_elem->data, list->fd);
			list->curr_elem = list->curr_elem->next;
			cursor->y++;
			i++;
		}
	}
}
