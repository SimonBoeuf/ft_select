#include "./includes/ft_select.h"

struct winsize		ft_get_winsize(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w);
}

void				init_sequence(void)
{
	t_list				*list;
	t_cursor			*cursor;
	struct winsize		w;
	struct termios		*term;
	t_elem				*tmp;

	list = ft_getlist(0, NULL);
	tmp = list->curr_elem;
	term = init_term(list->fd);
	w = ft_get_winsize();
	ft_print_list(list, w.ws_row - 1);
	list->curr_elem = tmp;
	cursor = init_cursor(list->curr_elem->posx, list->curr_elem->posy);
	move_cursor(cursor);
}

struct termios		*init_term(int fd)
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

void				closeterm(void)
{
	struct termios	*term;

	term = (struct termios*)malloc(sizeof(struct termios));
	tcgetattr(0, term);
	term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, term);
	tputs(tgetstr("cl", NULL), 1, ft_putchar);
	tputs(tgetstr("te", NULL), 1, ft_putchar);
	tputs(tgetstr("ve", NULL), 1, ft_putchar);
}
