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
	ft_del_list(ft_getlist(0, NULL));
	exit(0);
}

void	catch_resize(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_putchar);
	init_sequence();
}

void	catch_terminate(void)
{
	closeterm();
	ft_del_list(ft_getlist(0, NULL));
	ft_putstr_fd("Program received a kill command and terminated\n", 1);
	exit(0);
}
