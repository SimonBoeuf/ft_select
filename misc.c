#include "ft_select.h"

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

struct termios	*init_term()
{
	struct termios *term;

	term = (struct termios*)malloc(sizeof(struct termios));
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0,0, term);
	tputs(tgetstr("ti", NULL), 1, ft_putchar);
	return (term);
}

void				ft_error(int err)
{
	if (err == 1)
		ft_putstr("Error : Insuffisant memory.\n");
	exit(0);
}

void				readkeys(struct termios *term, t_list *list)
{
	char	*read_char;
	int		i;

	readchar = ft_strnew(4);
	while (1)
	{
		read(0, read_char, 3);
		if (is_rtn(read_char))
		{
			term->c_lflag |= ICANON;
			term->c_lflag |= ECHO;
			tcsetattr(0, 0, term);
			tputs(tgetstr("te", NULL), 1, ft_putchar);
			tputs(tgetstr("ve", NULL), 1, ft_putchar);
			return (1);
		}
		if ((i = is_arrow(read_char)) != 0)
		{
			if (i == KEYUP)
				list->curr_elem = list->curr_elem->prev;
			if (i == KEYDOWN)
				list->curr_elem = list->curr_elem->next;
			if (i == KEYLEFT)
				list->curr_elem = list->curr_elem->prev;
			if (i == KEYRIGHT)
				list->curr_elem = list->curr_elem->next;
			tputs(tgetstr("us", NULL), 1, ft_putchar);
			ft_putendl(list->curr_elem->data);
			tputs(tgetstr("ue", NULL), 1, ft_putchar);
		}
	}
}

void	closeterm(struct termios *term)
{
	term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, term);
}
