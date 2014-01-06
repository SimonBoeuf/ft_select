#include "./includes/ft_select.h"

int					main(int argc, char **argv)
{
	char			*buffer;
	struct termios	*term;
	t_list			*list;
	t_cursor		*cursor;

	if (argc == 1)
		return (-1);
	list = ft_initialize(--argc, ++argv);
	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	term = init_term(list->fd);
	cursor = init_cursor(0, 0);
	ft_print_list(list);
	move_cursor(cursor);
	readkeys(term, list, cursor);
	closeterm(term);
	return (0);
}
