#include "ft_select.h"

int					main(int argc, char **argv)
{
	char			*buffer;
	struct termios	term;
	char			read_char[4] = {0};
	t_list			*init;
	int				i;
	t_cursor		*cursor;

	if (argc == 1)
		return (-1);

	cursor = init_cursor(0,0);
	ft_initialize(--argc, ++argv, init);
	init->curr_elem = init->first_elem->prev;

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, ft_putchar);
	printelems(init);
	while (1)
	{
		read(0, read_char, 3);
		if (is_rtn(read_char))
		{
			term.c_lflag |= ICANON;
			term.c_lflag |= ECHO;
			tcsetattr(0, 0, &term);
			tputs(tgetstr("te", NULL), 1, ft_putchar);
			tputs(tgetstr("ve", NULL), 1, ft_putchar);
			return (1);
		}
		if ((i = is_arrow(read_char)) != 0)
		{
			if (i == 8)
			{
				init->curr_elem = init->curr_elem->prev;

			}
			if (i == 2)
			{
				init->curr_elem = init->curr_elem->next;
			}
			tputs(tgetstr("us", NULL), 1, ft_putchar);
			ft_putendl(init->curr_elem->data);
			tputs(tgetstr("ue", NULL), 1, ft_putchar);
		}
	}
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	return (0);
}

void	printelems(t_list *init)
{
	int	i;

	init->curr_elem = init->first_elem;
	i = 0;
	while (i <= init->nb_elem)
	{
		ft_putendl(init->curr_elem->data);
		init->curr_elem = init->curr_elem->next;
		i++;
	}
}
