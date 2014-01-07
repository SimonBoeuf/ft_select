#include "./includes/ft_select.h"

void	launch_arrow(int arrow, t_list *list, t_cursor *cursor)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	if (arrow == KEYDOWN)
	{
		set_effect(list->curr_elem, 0, list->fd);
		if (cursor->y == list->nb_elem - 1)
			cursor->y = 0;
		else
			cursor->y++;
		list->curr_elem = list->curr_elem->next;
	}
	else if (arrow == KEYUP)
	{
		set_effect(list->curr_elem, 0, list->fd);
		if (cursor->y == 0)
			cursor->y = list->nb_elem - 1;
		else
			cursor->y--;
		list->curr_elem = list->curr_elem->prev;
	}
	move_cursor(cursor);
	set_effect(list->curr_elem, 1, list->fd);
	move_cursor(cursor);
}

void	launch_space(t_list *list, t_cursor *cursor)
{
	if (list->curr_elem->selected)
		list->curr_elem->selected = 0;
	else
		list->curr_elem->selected = 1;
	set_effect(list->curr_elem, 1, list->fd);
	move_cursor(cursor);
}

void	launch_del(t_list *list, t_cursor *cursor)
{

	char		*clear_screen;

	clear_screen = tgetstr("cl", NULL);
	tputs(clear_screen, 1, ft_putchar);
	if (list->curr_elem == list->first_elem)
		list->first_elem = list->first_elem->next;
	else if (list->curr_elem == list->first_elem->prev)
	{
		cursor->x = 0;
		cursor->y = 0;
	}
	list->curr_elem = ft_elem_del(list->curr_elem);
	list->nb_elem--;
	init_sequence(list);
	move_cursor(cursor);
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
