#include "./includes/ft_select.h"

void	launch_space(t_list *list, t_cursor *cursor)
{
	if (list->curr_elem->selected)
		list->curr_elem->selected = 0;
	else
		list->curr_elem->selected = 1;
	set_effect(list->curr_elem, list->fd);
	move_cursor(cursor);
}

void	launch_del(t_list *list, t_cursor *cursor)
{
	t_elem				*tmp;
	char				*clear_screen;
	struct winsize		w;

	clear_screen = tgetstr("cl", NULL);
	tputs(clear_screen, 1, ft_putchar);
	list->curr_elem = ft_elem_del(list, list->curr_elem);
	if (!list->nb_elem)
	{
		closeterm();
		ft_putstr_fd("No more elements in the list.\n", 1);
		exit(0);
	}
	w = ft_get_winsize();
	tmp = list->curr_elem;
	ft_print_list(list, w.ws_row - 1, w.ws_col);
	if(!is_win_to_small(list))
	{
		list->curr_elem = tmp;
		cursor->x = list->curr_elem->posx;
		cursor->y = list->curr_elem->posy;
		move_cursor(cursor);
		set_effect(list->curr_elem, list->fd);
		move_cursor(cursor);
	}
}

void	launch_rtn(t_list *list)
{
	int		i;
	int		first_print;
	t_elem	*ptr;

	closeterm();
	i = 0;
	first_print = 0;
	ptr = list->first_elem;
	while (i < list->nb_elem)
	{
		if (ptr->selected == 1)
		{
			if (first_print == 1)
				ft_putchar(' ');
			ft_putstr(ptr->data);
			first_print = 1;
		}
		ptr = ptr->next;
		i++;
	}
	ft_putchar('\n');
	exit(0);
}

void	launch_esc()
{
	closeterm();
	exit(0);
}
