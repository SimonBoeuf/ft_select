#include "./includes/ft_select.h"
int		keep_reading;

void	readkeys(t_list *list, t_cursor *cur)
{
	char	*read_char;
	int		key;

	signal(SIGCONT, catch_cont);
	signal(SIGINT, catch_int);
	read_char = ft_strnew(4);
	keep_reading = 1;
	while (keep_reading)
	{
		read(0, read_char, 3);
		if (is_rtn(read_char))
		{
			closeterm();
			exit(1);
		}
		else if ((key = is_arrow(read_char)))
		{
			launch_arrow(key, list, cur);
		}
		else if ((key = is_space(read_char)))
		{
			launch_space(list, cur);
		}
		else if ((key = is_del(read_char)))
		{
			launch_del(list, cur);
		}
	}
}
