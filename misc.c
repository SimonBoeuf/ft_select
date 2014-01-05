#include "./includes/ft_select.h"





void				readkeys(struct termios *term, t_list *list)
{
	char	*read_char;
	int		i;

	read_char = ft_strnew(4);
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
			//return (1);
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


