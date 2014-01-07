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
	free(elem_to_del);
	ptr_next->cursor = 1;
	return (ptr_next);
}

t_list				*ft_getlist(int ac, char **av)
{
	static t_list	*list = NULL;
	t_elem			*ptr;
	int				i;

	if (list == NULL)
	{
		list = (t_list*)malloc(sizeof(t_list));
		list->fd = open(ttyname(0), O_WRONLY);
		list->first_elem = ft_elem_init(*av, 1);
		list->longest = 0;
		av++;
		i = 1;
		while (i < ac)
		{
			if (list->longest < ft_strlen(*av))
				list->longest = ft_strlen(*av);
			ptr = ft_elem_init(*(av++), 0);
			ft_elem_add(list->first_elem, ptr);
			i++;
		}
		list->curr_elem = list->first_elem;
		list->nb_elem = ac;
	}
	return (list);
}

int					ft_print_list(t_list *list, int tr, int tc)
{
	int				i;
	t_cursor		*cursor;

	cursor = init_cursor(0, 0);
	list->curr_elem = list->first_elem;
	i = 0;
	if (list->nb_elem * (int)(list->longest + 4) > tc * tr)
	{
		ft_putstr_fd("window too small", list->fd);
		return (0);
	}
	else
	{
		while (i++ < list->nb_elem)
		{
			if (cursor->y == tr)
			{
				cursor->y = 0;
				cursor->x += list->longest + 4;
			}
			list->curr_elem->posx = cursor->x;
			list->curr_elem->posy = cursor->y;
			move_cursor(cursor);
			set_effect(list->curr_elem, list->fd);
			list->curr_elem = list->curr_elem->next;
			cursor->y++;
		}
	}
	return (1);
}
