#include "./includes/ft_select.h"

void	launch_arrow(int arrow, t_list *list, t_cursor *cursor)
{
	if (arrow == KEYDOWN)
	{
		set_effect(list->curr_elem, 0, list->fd);
		//move_cursor(cursor);
		//if (list->curr_elem->next == list->first_elem)
		if (cursor->y == list->nb_elem - 1)
			cursor->y = 0;
		else
			cursor->y++;
		//move_cursor(cursor);
		list->curr_elem = list->curr_elem->next;
	}
	else if (arrow == KEYUP)
	{
		set_effect(list->curr_elem, 0, list->fd);
		//move_cursor(cursor);
		//if (list->curr_elem == list->first_elem)
		if (cursor->y == 0)
			cursor->y = list->nb_elem - 1;
		else
			cursor->y--;
		//move_cursor(cursor);
		list->curr_elem = list->curr_elem->prev;
	}

	//set_effect(list->curr_elem, 1, list->fd);
	move_cursor(cursor);


		//tputs(tgetstr("us", NULL), 1, ft_putchar);
	//ft_putstr(list->curr_elem->data);

		//tputs(tgetstr("ue", NULL), 1, ft_putchar);
	//set_effect(list->curr_elem, 1);




	/*tputs(tgetstr("us", NULL), 1, ft_putchar);
	ft_putendl(list->curr_elem->data);
	tputs(tgetstr("ue", NULL), 1, ft_putchar);*/
	//cursor->y--;
	//move_cursor(cursor);





}
