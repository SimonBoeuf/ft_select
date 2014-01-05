#include "ft_select.h"

void				ft_error(int err)
{
	if (err == 1)
		ft_putstr("Error : Insuffisant memory.\n");
	exit(0);
}

char				*ft_strcpy(char *s1, const char *s2)
{
	char	*temp_s1;

	temp_s1 = s1;
	while (*s2 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
	return (temp_s1);
}

char				*ft_strdup(const char *s1)
{
	char	*copy;

	if (s1 == NULL)
		return (NULL);
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy == NULL)
		ft_error(1);
	return (ft_strcpy(copy, s1));
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		if (*as != NULL)
			free(*as);
		*as = NULL;
	}
}

size_t				ft_strlen(const char *str)
{
	size_t			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int					tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int					ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

void				ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int					is_rtn(char *buf)
{
	return (buf[0] == 10);
}

int					is_arrow(char *buf, t_elem *ptr)
{
	unsigned int				rslt;

	printf("[?] %s\n", ptr->data);
	tputs(tgetstr("up", NULL), 1, tputs_putchar);
	if (buf[0] != 27 || buf[1] != 91)
		return (0);
	if (buf[2] == 65)
	{
		if (ptr->index - ptr->prev->index != 1)
		{
			rslt = ptr->prev->index;
			while (ptr->index != rslt)
			{
				tputs(tgetstr("do", NULL), 1, tputs_putchar);
				ptr = ptr->next;
			}
		}
		else
		{
			tputs(tgetstr("up", NULL), 1, tputs_putchar);
			tputs(tgetstr("cr", NULL), 1, tputs_putchar);
		}
		return (8);
	}
	if (buf[2] == 66)
	{
		if (ptr->next->index - ptr->index != 1)
		{
			rslt = ptr->next->index;
			while (ptr->index != rslt)
			{
				tputs(tgetstr("up", NULL), 1, tputs_putchar);
				ptr = ptr->prev;
			}
		}
		else
		{
			tputs(tgetstr("do", NULL), 1, tputs_putchar);
			tputs(tgetstr("cr", NULL), 1, tputs_putchar);
		}
		return (2);
	}
	if (buf[2] == 67)
	{
		//ft_putstr("Droite.");
		return (6);
	}
	if (buf[2] == 68)
	{
		//ft_putstr("Gauche.");
		return (4);
	}
	else
		return (0);
}

int					is_bgreq(char *buf)
{
	if (buf[0] == 26)
		return (1);
	else
		return (0);
}

t_elem				*ft_elem_init(char *data)
{
	t_elem			*new_elem;

	if (!(new_elem = (t_elem*)malloc(sizeof(t_elem))))
		ft_error(1);
	if (!(new_elem->data = ft_strdup(data)))
		ft_error(1);
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

/*
**	Initiliaze the list and return the nb_elem of the list.
*/

int					ft_initialize(int ac, char **av, t_list *init)
{
	t_elem			*ptr;
	int				i;

	init->first_elem = ft_elem_init(*av);
	ac--;
	printf("premier ->%s\n", *av);
	av++;
	printf("deuxieme ->%s\n", *av);
	i = 0;
	while (i < ac)
	{
		ptr = ft_elem_init(*av);
		ft_elem_add(init->first_elem, ptr);
		i++;
		ptr->index = i;
		av++;
	}
	return (ac + 1);
}

int					main(int argc, char **argv)
{
	char			*buffer;
	struct termios	term;
	//char			read_char[4] = {0};
	t_list			init;
	t_elem			*ptr;
	int				i;

	if (argc == 1)
		return (-1);

	init.nb_elem = ft_initialize(--argc, ++argv, &init);
	ptr = init.first_elem->prev;

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON); //mode non canonique
	term.c_lflag &= ~(ECHO); //mode echo off
	tcsetattr(0, 0, &term);
	//tputs(tgetstr("do", NULL), 1, tputs_putchar); /* cursor down one line */
	i = 0;
	while (i < init.nb_elem)
	{
		printf("[%d] %s\n", i + 1, init.first_elem->data);
		init.first_elem = init.first_elem->next;
		i++;
	}
	printf("fin affichage liste\n");
	//tputs(tgetstr("up", NULL), 1, tputs_putchar); /* cursor up one line */
	/*while (1)
	{
		read(0, read_char, 3);
		if (is_bgreq(read_char))
		{
			printf("Todo : put in background");*/
			/*
			term.c_lflag |= ICANON;
			term.c_lflag |= ECHO;
			tcsetattr(0, 0, &term);
			tputs(tgetstr("ti", NULL), 1, tputs_putchar);
			*/
		/*}
		if (is_rtn(read_char))
		{
			term.c_lflag |= ICANON;
			term.c_lflag |= ECHO;
			tcsetattr(0, 0, &term);*/ /* back to default values */
			/*tputs(tgetstr("ti", NULL), 1, tputs_putchar);
			tputs(tgetstr("ve", NULL), 1, tputs_putchar);
			return (1);
		}
		if ((i = is_arrow(read_char, ptr)) != 0)
		{
			if (i == 8)
			{
				ptr = ptr->prev;
			}
			if (i == 2)
			{
				ptr = ptr->next;
			}
			tputs(tgetstr("us", NULL), 1, tputs_putchar);
			printf("[?] %s\n", ptr->data);
			tputs(tgetstr("up", NULL), 1, tputs_putchar);
			tputs(tgetstr("ue", NULL), 1, tputs_putchar);
		}*/
		/*else
			printf("%d %d %d\n", read_char[0], read_char[1], read_char[2]);
		*/
	//}
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	return (0);
}
