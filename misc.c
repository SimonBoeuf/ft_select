#include "./includes/ft_select.h"


void	catch(int s)
{
	if (s == SIGTSTP)
		catch_controle();
	if (s == SIGCONT)
		catch_cont();
	if (s == SIGINT)
		catch_int();
	if (s == SIGWINCH)
		catch_resize();
}

void	ft_check_signal(void)
{
	signal(SIGTSTP, catch);
	signal(SIGCONT, catch);
	signal(SIGINT, catch);
	signal(SIGWINCH, catch);
}

void	readkeys(t_list *list, t_cursor *cur)
{
	char	*read_char;
	int		key;
	int		to_small;

	ft_check_signal();
	read_char = ft_strnew(4);
	while (read(0, read_char, 3))
	{
		to_small = is_win_too_small(list);
		if (is_esc(read_char))
			launch_esc();
		else if ((key = is_del(read_char)) && !to_small)
			launch_del(list, cur);
		else if ((key = is_arrow(read_char)) && !to_small)
			launch_arrow(key, list, cur);
		else if ((key = is_space(read_char)) && !to_small)
			launch_space(list, cur);
		else if ((key = is_rtn(read_char)))
			launch_rtn(list);
		ft_bzero(read_char, ft_strlen(read_char));
	}
}

int		is_win_too_small(t_list *list)
{
	struct winsize		w;
	int					nb_col;

	w = ft_get_winsize();
	nb_col = (list->nb_elem / w.ws_row) + 1;
	if ((list->nb_elem % w.ws_row) != 0)
		nb_col++;
//	printf("                                nb_col = %d\n", nb_col);
//	printf("                                list_total = %d\n", (nb_col * (((int)list->longest) + 4) - 4));
//	printf("                                ws_col = %d\n", (w.ws_col));
	return ((nb_col * (((int)list->longest) + 4)) - 4 > (w.ws_col));
}
