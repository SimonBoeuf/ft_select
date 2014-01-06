#include "./includes/ft_select.h"

void			init_sequence(t_list *list)
{
	int			i;
	t_elem		*ptr;

	i = 0;
	ptr = list->first_elem;
	while (i < list->nb_elem)
	{
		if (ptr != list->curr_elem)
			set_effect(ptr, 0, list->fd);
		else
			set_effect(ptr, 1, list->fd);
		i++;
		ptr = ptr->next;
	}
}

struct termios	*init_term(int	fd)
{
	struct termios *term;

	term = (struct termios*)malloc(sizeof(struct termios));
	tcgetattr(fd, term);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
    term->c_cc[VTIME] = 0;
	tcsetattr(fd, 0, term);
	tputs(tgetstr("ti", NULL), 1, ft_putchar);
	tputs(tgetstr("vi", NULL), 1, ft_putchar);
	return (term);
}

void	closeterm(void)
{
	struct termios	*term;

	term = (struct termios*)malloc(sizeof(struct termios));
	tcgetattr(0, term);
	term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, term);
	tputs(tgetstr("te", NULL), 1, ft_putchar);
	tputs(tgetstr("ve", NULL), 1, ft_putchar);
}
