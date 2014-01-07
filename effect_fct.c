#include "./includes/ft_select.h"

void	set_effect(t_elem *elem, int fd)
{

	if (elem->selected)
		tputs(tgetstr("mr", NULL), 1, ft_putchar);
	if (elem->cursor)
		tputs(tgetstr("us", NULL), 1, ft_putchar);
	ft_putendl_fd(elem->data, fd);
	if (elem->cursor)
		tputs(tgetstr("ue", NULL), 1, ft_putchar);
	if (elem->selected)
		tputs(tgetstr("me", NULL), 1, ft_putchar);
}
