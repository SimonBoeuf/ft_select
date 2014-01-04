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

int					ft_initialize(int ac, char **av, t_list *init)
{
	t_elem			*ptr;
	int				i;

	init->first_elem = ft_elem_init(*av);
	ac--;
	*av++;
	i = 0;
	while (i < ac)
	{
		ptr = ft_elem_init(*av);
		ft_elem_add(init->first_elem, ptr);
		i++;
		*av++;
	}
	return (ac + 1);
}

int					main(int argc, char **argv)
{
	char			*buffer;
	struct termios	term;
	char			read_char[4] = {0};
	t_list			init;
	int				i;


	argc--;
	*argv++;
	if (!(argc > 0))
		return (-1);
	init.nb_elem = ft_initialize(argc, argv, &init);
	printf("Number of elem stocked on the list : %d.\n", init.nb_elem);
	while (init.nb_elem != 0)
	{
		printf("Debug\n");
		i = 0;
		while (i < init.nb_elem)
		{
			printf("[%d] %s\n", i + 1, init.first_elem->data);
			init.first_elem = init.first_elem->next;
			i++;
		}
		ft_elem_del(init.first_elem->prev);
		init.nb_elem--;
		printf("\n");
	}
	printf("No more elem.\n");
//	if (tgetent(buffer, getenv("TERM")) < 1)
//		return (-1);
//	tcgetattr(0, &term);
//	term.c_lflag &= ICANON; /* each char is treated independently */
//	term.c_lflag &= ECHO; /* prevents a char from being output when pressed*/
//	tcsetattr(0, 0, &term);
//	tputs(tgetstr("do", NULL), 1, tputs_putchar); /* cursor down one line */
//	while (*argv)
//	{
//		printf("%s\n", *argv);
//		*argv++;
//	}
	return (0);
}
