#include "./includes/ft_select.h"

void				readkeys(struct termios *term, t_list *list, t_cursor *cur)
{
	char	*read_char;
	int		key;

	read_char = ft_strnew(4);
	while (1)
	{
		read(0, read_char, 3);
		if (is_rtn(read_char))
		{
			term->c_lflag |= ICANON;
			term->c_lflag |= ECHO;
			tcsetattr(list->fd, 0, term);
			tputs(tgetstr("te", NULL), 1, ft_putchar);
			tputs(tgetstr("ve", NULL), 1, ft_putchar);
			exit(1);
		}
		if ((key = is_arrow(read_char)) != 0)
		{
			launch_arrow(key, list, cur);
		}
	}
}


