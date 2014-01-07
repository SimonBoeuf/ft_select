#include "./includes/ft_select.h"
int		keep_reading;

void	readkeys(t_list *list, t_cursor *cur)
{
	char	*read_char;
	int		key;
	int		to_small;

	signal(SIGCONT, catch_cont);
	signal(SIGINT, catch_int);
	signal(SIGWINCH, catch_resize);
	read_char = ft_strnew(4);
	keep_reading = 1;
	while (read(0, read_char, 3))
	{
		to_small = is_win_to_small(list);
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

int		is_win_to_small(t_list *list)
{
	struct winsize		w;

	w = ft_get_winsize();
	return ((list->nb_elem * (int)(list->longest + 4)) > (w.ws_row * w.ws_col));
}
