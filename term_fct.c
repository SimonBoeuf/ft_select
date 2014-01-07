#include "./includes/ft_select.h"

void			init_sequence(void)
{
	t_list			*list;
	t_cursor		*cursor;
	struct winsize	w;
	struct termios	*term;

	list = ft_getlist(0, NULL);
	ioctl(0, TIOCGWINSZ, &w);
	term = init_term(list->fd);
	cursor = init_cursor(0, 0);
	ft_print_list(list, w.ws_row - 1, w.ws_col);
	move_cursor(cursor);
	readkeys(list, cursor);
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
