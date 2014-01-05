#include "ft_select.h"

int					tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}



void				ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
