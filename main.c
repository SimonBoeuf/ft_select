#include "./includes/ft_select.h"

int					main(int argc, char **argv)
{
	char			*buffer;
	t_list			*list;
	t_cursor		*cursor;

	if (argc == 1)
		return (-1);
	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	list = ft_getlist(--argc, ++argv);
	cursor = init_cursor(0, 0);
	init_sequence();
	move_cursor(cursor);
	readkeys(list, cursor);
	closeterm();
	return (0);
}
