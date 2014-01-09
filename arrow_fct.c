#include "./includes/ft_select.h"

void	launch_arrow(int arrow, t_list *list, t_cursor *cursor)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	list->curr_elem->cursor = 0;
	set_effect(list->curr_elem, list->fd);
	if (arrow == KEYDOWN)
	{
		cursor->x = list->curr_elem->next->posx;
		cursor->y = list->curr_elem->next->posy;
		list->curr_elem = list->curr_elem->next;
	}
	else if (arrow == KEYUP)
	{
		cursor->x = list->curr_elem->prev->posx;
		cursor->y = list->curr_elem->prev->posy;
		list->curr_elem = list->curr_elem->prev;
	}
	else if (arrow == KEYLEFT)
		mvleft(list, cursor, w.ws_row - 1);
	else if (arrow == KEYRIGHT)
		mvright(list, cursor, w.ws_row - 1);
	list->curr_elem->cursor = 1;
	move_cursor(cursor);
	set_effect(list->curr_elem, list->fd);
	move_cursor(cursor);
}

void	mvleft(t_list *l, t_cursor *c, int y)
{
	int	nbcols;
	int	nbrows;
	int	i;
	int	last;

	nbrows = l->nb_elem > y ? y : l->nb_elem;
	nbcols = y > l->nb_elem ? 1 : (l->nb_elem / nbrows);
	nbcols = (l->nb_elem / nbrows);
	if ((l->nb_elem % nbrows) != 0)
		nbcols++;
	last = l->nb_elem % nbrows == 0 ? l->nb_elem : l->nb_elem % nbrows;
	if (nbcols > 1)
	{
		if (l->curr_elem->posy < last && l->curr_elem->posx == 0)
			nbrows = last;
		if (l->curr_elem->posy >= last && l->curr_elem->posx == 0)
			nbrows += last;
	}
	i = -1;
	while (++i < nbrows)
		l->curr_elem = l->curr_elem->prev;
	c->x = l->curr_elem->posx;
	c->y = l->curr_elem->posy;
}

void	mvright(t_list *l, t_cursor *c, int y)
{
	int	nbcols;
	int	nbrows;
	int	i;
	int	last;

	nbrows = l->nb_elem > y ? y : l->nb_elem;
	nbcols = y > l->nb_elem ? 1 : (l->nb_elem / nbrows);
	nbcols = (l->nb_elem / nbrows);
	if ((l->nb_elem % nbrows) != 0)
		nbcols++;
	last = l->nb_elem % nbrows == 0 ? l->nb_elem : l->nb_elem % nbrows;
	if (nbcols > 1)
	{
		if (l->curr_elem->posy < last &&
				l->curr_elem->posx == (nbcols - 1) * ((int)l->longest + 4))
			nbrows = last;
		if (l->curr_elem->posy >= last &&
				l->curr_elem->posx == (nbcols - 2) * ((int)l->longest + 4))
			nbrows += last;
	}
	i = -1;
	while (++i < nbrows)
		l->curr_elem = l->curr_elem->next;
	c->x = l->curr_elem->posx;
	c->y = l->curr_elem->posy;
}
