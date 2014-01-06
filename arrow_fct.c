#include "./includes/ft_select.h"

void	launch_arrow(int arrow, t_list *list, t_cursor *cursor)
{
	if (arrow == KEYDOWN)
	{
		set_effect(list->curr_elem, 0);
		//move_cursor(cursor);
		if (list->curr_elem->next == list->first_elem)
			cursor->y = 0;
		else
			cursor->y++;
		list->curr_elem = list->curr_elem->next;
	}
	if (arrow == KEYUP)
	{
		set_effect(list->curr_elem, 0);
		//move_cursor(cursor);
		if (list->curr_elem == list->first_elem)
		{
			cursor->y = list->nb_elem;
		}
		else
			cursor->y--;
		//set_effect(list->curr_elem, 1);
		list->curr_elem = list->curr_elem->prev;
	}
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
