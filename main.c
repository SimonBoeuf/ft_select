#include "ft_select.h"

int					main(int argc, char **argv)
{
	char			*buffer;
	struct termios	term;
	char			read_char[4] = {0};
	t_list			*list;
	int				i;
	t_cursor		*cursor;

	if (argc == 1)
		return (-1);

	cursor = init_cursor(0,0);
	list = ft_initialize(--argc, ++argv);
	list->curr_elem = list->first_elem->prev;

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, ft_putchar);
	printelems(list);
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
				list->curr_elem = list->curr_elem->prev;

			}
			if (i == 2)
			{
				list->curr_elem = list->curr_elem->next;
			}
			tputs(tgetstr("us", NULL), 1, ft_putchar);
			ft_putendl(list->curr_elem->data);
			tputs(tgetstr("ue", NULL), 1, ft_putchar);
		}
	}
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	return (0);
}

void	printelems(t_list *list)
{
	int	i;

	list->curr_elem = list->first_elem;
	i = 0;
	while (i <= list->nb_elem)
	{
		ft_putendl(list->curr_elem->data);
		list->curr_elem = list->curr_elem->next;
		i++;
	}
}
