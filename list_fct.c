#include "./includes/ft_select.h"

t_elem				*ft_elem_init(char *data)
{
	t_elem			*new_elem;

	if (!(new_elem = (t_elem*)malloc(sizeof(t_elem))))
		ft_error(1, 2);
	if (!(new_elem->data = ft_strdup(data)))
		ft_error(1, 2);
	new_elem->prev = NULL;
	new_elem->next = NULL;
	new_elem->cursor = 0;
	new_elem->selected = 0;
	return (new_elem);
}

void				ft_elem_add(t_elem *first_elem, t_elem *elem_to_add)
{
	t_elem			*tmp;

	tmp = first_elem->prev;
	if (!tmp)
	{
		first_elem->prev = elem_to_add;
		first_elem->next = elem_to_add;
		elem_to_add->prev = first_elem;
		elem_to_add->next = first_elem;
	}
	else
	{
		first_elem->prev = elem_to_add;
		elem_to_add->next = first_elem;
		elem_to_add->prev = tmp;
		tmp->next = elem_to_add;
	}
}

void				ft_elem_del(t_elem *elem_to_del)
{
	t_elem			*ptr_prev;
	t_elem			*ptr_next;

	ptr_prev = elem_to_del->prev;
	ptr_next = elem_to_del->next;
	if (ptr_prev && ptr_next)
	{
		ptr_prev->next = ptr_next;
		ptr_next->prev = ptr_prev;
	}
	free(elem_to_del);
}

t_list				*ft_initialize(int ac, char **av)
{
	t_list			*list;
	t_elem			*ptr;
	int				i;
	char			*name;

	list = (t_list*)malloc(sizeof(t_list));
	name = ttyname(0);
	list->fd = open(name, O_WRONLY);
	list->first_elem = ft_elem_init(*av);
	ac--;
	av++;
	i = 0;
	while (i < ac)
	{
		ptr = ft_elem_init(*av);
		ft_elem_add(list->first_elem, ptr);
		i++;
		ptr->index = i;
		av++;
	}
	list->curr_elem = list->first_elem->prev;
	list->nb_elem = ac + 1;
	return (list);
}

void	ft_print_list(t_list *list)
{
	int	i;

	list->curr_elem = list->first_elem;
	tputs(tgetstr("us", NULL), 1, ft_putchar);
	ft_putendl_fd(list->curr_elem->data, list->fd);
	tputs(tgetstr("ue", NULL), 1, ft_putchar);
	list->curr_elem = list->curr_elem->next;
	i = 1;
	while (i < list->nb_elem)
	{
		if (i == 0)
		{

		}
		ft_putendl_fd(list->curr_elem->data, list->fd);
		list->curr_elem = list->curr_elem->next;
		i++;
	}
}
