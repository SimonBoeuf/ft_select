#include "ft_select.h"

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

int		is_bgreq(char *buf)
{
	if (buf[0] == 26)
		return (1);
	else
		return (0);
}