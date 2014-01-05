#include "ft_select.h"

t_cursor	*init_cursor(int x, int y)
{
	t_cursor	*c;

	c = (t_cursor*)malloc(sizeof(t_cursor));
	c->x = x;
	c->y = y;

	return (c);
}
