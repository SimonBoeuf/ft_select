#include "ft_select.h"

void				ft_error(int err)
{
	if (err == 1)
		ft_putstr("Error : Insuffisant memory.\n");
	exit(0);
}
