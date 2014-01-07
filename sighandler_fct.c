#include "./includes/ft_select.h"

void	catch_cont(int s)
{
	s = s;
	init_sequence();
}

void	catch_int(int s)
{
	s = s;
	closeterm();
	exit(1);
}

void	catch_resize(int s)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	s = s;
	tputs(tgetstr("cl", NULL), 1, ft_putchar);
	init_sequence();
}
