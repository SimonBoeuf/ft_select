#include "ft_select.h"

int					ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void				ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void				ft_putendl(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}
