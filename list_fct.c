#include "./includes/ft_select.h"

void				ft_del_list(t_list *list)
{
	while (list->nb_elem)
	{
		ft_elem_del(list, list->first_elem);
	}
	free(list);
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

void				ft_print_list(t_list *list, int tr)
{
	int				i;
	t_cursor		*cursor;

	cursor = init_cursor(0, 0);
	list->curr_elem = list->first_elem;
	i = 0;
	if (is_win_too_small(list) != 0)
		ft_putstr_fd("window too small", list->fd);
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
}
