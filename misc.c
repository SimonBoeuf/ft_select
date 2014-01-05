#include "ft_select.h"

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
