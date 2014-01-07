#include "./includes/ft_select.h"

void	catch_controle(void)
{
	closeterm();
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, "\032");
}

void	catch_cont(void)
{
	init_sequence();
	signal(SIGTSTP, catch);
}

void	catch_int(void)
{
	closeterm();
	exit(1);
}

void	catch_resize(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	tputs(tgetstr("cl", NULL), 1, ft_putchar);
	init_sequence();
}
