#include "./includes/ft_select.h"

t_cursor	*init_cursor(int x, int y)
{
	t_cursor	*c;

	c = (t_cursor*)malloc(sizeof(t_cursor));
	c->x = x;
	c->y = y;
	c->res = tgetstr("cm", NULL);
	return (c);
}

void	move_cursor(t_cursor *cursor)
{
	tputs(tgoto(cursor->res, cursor->x, cursor->y), 1, ft_putchar);
}

t_cursor	*seek_cursor(t_list *list)
{
	t_cursor	*cursor;
	t_elem		*ptr;
	int			i;

	cursor = init_cursor(0, 0);
	ptr = list->first_elem;
	i = 0;
	while (i < list->nb_elem)
	{
		if (ptr->cursor)
		{
			cursor->x = ptr->posx;
			cursor->y = ptr->posy;
			break ;
		}
		ptr = ptr->next;
		i++;
	}
	return (cursor);
}