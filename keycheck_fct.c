#include "./includes/ft_select.h"

int		is_rtn(char *buf)
{
	return (buf[0] == 10);
}

int		is_arrow(char *buf)
{
	if (buf[0] != 27 || buf[1] != 91 || buf[2] < 65 || buf[2] > 68)
		return (0);
	return (buf[2] - 64);
}

int		is_esc(char *buf)
{
	return ((buf[0] == 27 && buf[1] == 0 && buf[2] == 0)
			|| (buf[0] == 4 && buf[1] == 0 && buf[2] == 0));
}

int		is_space(char *buf)
{
	return (buf[0] == 32);
}

int		is_del(char *buf)
{
	return ((buf[0] == 27 && buf[1] == 91 && buf[2] == 51) ||
			(buf[0] == 127 && buf[1] == 0 && buf[2] == 0));
}
