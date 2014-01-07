#include "./includes/ft_select.h"

int					main(int argc, char **argv)
{
	char			*buffer;
	t_list			*list;

	if (argc == 1)
		return (-1);
	list = ft_getlist(--argc, ++argv);
	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	init_sequence();
	closeterm();
	return (0);
}
