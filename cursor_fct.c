#include "ft_select.h"

void	move_cursor(t_cursor *cursor, int x, int y)
{
	char	*res;

	cursor->pos_x = x;
	cursor->pos_y = y;
	res = tgetstr("cm", NULL);
	tputs(tgoto(res, cursor->pos_x, cursor->pos_y), 1, ft_putchar);
	free(res);
}
