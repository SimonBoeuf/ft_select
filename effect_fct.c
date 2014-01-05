#include "./includes/ft_select.h"

void	set_effect(t_elem *elem, int underline)
{

	if (elem->selected)
		tputs(tgetstr("mr", NULL), 1, ft_putchar);
	if (underline)
		tputs(tgetstr("us", NULL), 1, ft_putchar);
	ft_putendl(elem->data);
	if (underline)
		tputs(tgetstr("ue", NULL), 1, ft_putchar);
	if (elem->selected)
		tputs(tgetstr("me", NULL), 1, ft_putchar);
}
