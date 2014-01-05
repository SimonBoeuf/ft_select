#include "ft_select.h"

int					main(int argc, char **argv)
{
	char			*buffer;
	struct termios	term;
	char			read_char[4] = {0};
	t_list			*init;
	t_elem			*ptr;
	int				i;
	t_cursor		cursor;

	if (argc == 1)
		return (-1);

	cursor.pos_x = 0;
	cursor.pos_y = 0;
	ft_initialize(--argc, ++argv, init);
	ptr = init->first_elem->prev;

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
				ptr = ptr->prev;

			}
			if (i == 2)
			{
				ptr = ptr->next;
			}
			tputs(tgetstr("us", NULL), 1, ft_putchar);
			printf("[?] %s\n", ptr->data);
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
		ft_putchar('[');
		ft_putchar('1' + i);
		ft_putstr("] ");
		ft_putstr(init->first_elem->data);
		ft_putchar('\n');
		init->curr_elem = init->curr_elem->next;
		i++;
	}
}
