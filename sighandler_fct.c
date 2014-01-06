#include "./includes/ft_select.h"
int	keep_reading;

void	catch_cont(int s)
{
	s = s;
	init_term(0);
}

void	catch_int(int s)
{
	s = s;
	closeterm();
	exit(1);
}
