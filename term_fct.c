#include "./includes/ft_select.h"

struct termios	*init_term()
{
	struct termios *term;
	char			*name;

	name = ttyname(0);
	fd = open(name, O_WRONLY);
	term = (struct termios*)malloc(sizeof(struct termios));
	tcgetattr(fd, term);
	term->c_lflag &= ~(ICANON | ECHO);
	tcsetattr(fd, 0, term);
	tputs(tgetstr("ti", NULL), 1, ft_putchar);
	return (term);
}

void	closeterm(struct termios *term)
{
	term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, term);
}
