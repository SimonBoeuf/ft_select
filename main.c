#include "./includes/ft_select.h"

int					main(int argc, char **argv)
{
	char			*buffer;
	struct termios	*term;
	t_list			*list;
	t_cursor		*cursor;
	struct winsize w;

	if (argc == 1)
		return (-1);
	list = ft_initialize(--argc, ++argv);
	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	ioctl(0, TIOCGWINSZ, &w);
	term = init_term(list->fd);
	cursor = init_cursor(0, 0);
	ft_print_list(list, w.ws_row, w.ws_col);
	move_cursor(cursor);
	readkeys(list, cursor);
	closeterm();
	return (0);
}
