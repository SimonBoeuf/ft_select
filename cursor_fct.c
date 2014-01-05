#include "./includes/ft_select.h"

t_cursor	*init_cursor(int x, int y)
{
	t_cursor	*c;

	c = (t_cursor*)malloc(sizeof(t_cursor));
	c->x = x;
	c->y = y;

	return (c);
}

void	move_cursor(t_cursor *cursor)
{
	char	*res;

	res = tgetstr("cm", NULL);
	tputs(tgoto(res, cursor->x, cursor->y), 1, ft_putchar);
	free(res);
}
