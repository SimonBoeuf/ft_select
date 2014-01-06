#include "./includes/ft_select.h"

void	launch_arrow(int arrow, t_list *list, t_cursor *cursor)
{
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
	//t_cursor	tmp_cur;
	char		*clear_screen;

	clear_screen = tgetstr("cl", NULL);
	tputs(clear_screen, 1, ft_putchar);
	/*tmp_cur.x = cursor->x;
	tmp_cur.y = cursor->y;
	cursor->x = 0;
	cursor->y = 0;*/
	list->curr_elem = ft_elem_del(list->curr_elem);
	list->nb_elem--;
	//move_cursor(cursor); // to 0,0
	init_sequence(list);
	//cursor->x = tmp_cur.x;
	//cursor->y = tmp_cur.y;
	move_cursor(cursor);
}

void	launch_esc()
{
	closeterm();
	exit(0);
}
