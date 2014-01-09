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
	t_list				*list;
	t_cursor			*cursor;
	struct winsize		w;
	t_elem				*tmp;

	tputs(tgetstr("cl", NULL), 1, ft_putchar);
	list = ft_getlist(0, NULL);
	tmp = list->curr_elem;
	w = ft_get_winsize();
	ft_print_list(list, w.ws_row - 1);
	list->curr_elem = tmp;
	cursor = init_cursor(list->curr_elem->posx, list->curr_elem->posy);
	move_cursor(cursor);
}

void	catch_terminate(void)
{
	closeterm();
	ft_del_list(ft_getlist(0, NULL));
	ft_putstr_fd("Program received a kill command and terminated\n", 1);
	exit(0);
}
