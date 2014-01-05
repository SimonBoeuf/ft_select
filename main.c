#include "ft_select.h"

void				ft_error(int err)
{
	if (err == 1)
		ft_putstr("Error : Insuffisant memory.\n");
	exit(0);
}





int					is_rtn(char *buf)
{
	return (buf[0] == 10);
}

int					is_arrow(char *buf, t_elem *ptr)
{
	if (buf[0] != 27 || buf[1] != 91 || buf[2] < 65 || buf[2] > 68)
		return (0);
	return (buf[2] - 64);
}

void				move_cursor(int arrow)
{
	printf("[?] %s\n", ptr->data);
	tputs(tgetstr("up", NULL), 1, tputs_putchar);
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



int					main(int argc, char **argv)
{
	char			*buffer;
	struct termios	term;
	char			read_char[4] = {0};
	t_list			init;
	t_elem			*ptr;
	int				i;
	t_cursor		cursor;

	if (argc == 1)
		return (-1);

	cursor.pos_x = 0;
	cursor.pos_y = 0;
	init.nb_elem = ft_initialize(--argc, ++argv, &init);
	ptr = init.first_elem->prev;

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON); //mode non canonique
	term.c_lflag &= ~(ECHO); //mode echo off
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	//tputs(tgetstr("do", NULL), 1, tputs_putchar); /* cursor down one line */
	i = 0;
	while (i < init.nb_elem)
	{
		printf("[%d] %s\n", i + 1, init.first_elem->data);
		init.first_elem = init.first_elem->next;
		i++;
	}
	//tputs(tgetstr("up", NULL), 1, tputs_putchar); /* cursor up one line */
	while (1)
	{
		read(0, read_char, 3);
		if (is_bgreq(read_char))
		{
			printf("Todo : put in background");

		}
		if (is_rtn(read_char))
		{
			term.c_lflag |= ICANON;
			term.c_lflag |= ECHO;
			tcsetattr(0, 0, &term);
			tputs(tgetstr("te", NULL), 1, tputs_putchar);
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
			//tputs(tgetstr("up", NULL), 1, tputs_putchar);
			tputs(tgetstr("ue", NULL), 1, tputs_putchar);
		}
	}
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	return (0);
})
		return (0);
	if (buf[2] > 64 && buf[2] < 69

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



int					main(int argc, char **argv)
{
	char			*buffer;
	struct termios	term;
	char			read_char[4] = {0};
	t_list			init;
	t_elem			*ptr;
	int				i;
	t_cursor		cursor;

	if (argc == 1)
		return (-1);

	cursor.pos_x = 0;
	cursor.pos_y = 0;
	init.nb_elem = ft_initialize(--argc, ++argv, &init);
	ptr = init.first_elem->prev;

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON); //mode non canonique
	term.c_lflag &= ~(ECHO); //mode echo off
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	//tputs(tgetstr("do", NULL), 1, tputs_putchar); /* cursor down one line */
	i = 0;
	while (i < init.nb_elem)
	{
		printf("[%d] %s\n", i + 1, init.first_elem->data);
		init.first_elem = init.first_elem->next;
		i++;
	}
	//tputs(tgetstr("up", NULL), 1, tputs_putchar); /* cursor up one line */
	while (1)
	{
		read(0, read_char, 3);
		if (is_bgreq(read_char))
		{
			printf("Todo : put in background");

		}
		if (is_rtn(read_char))
		{
			term.c_lflag |= ICANON;
			term.c_lflag |= ECHO;
			tcsetattr(0, 0, &term);
			tputs(tgetstr("te", NULL), 1, tputs_putchar);
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
			//tputs(tgetstr("up", NULL), 1, tputs_putchar);
			tputs(tgetstr("ue", NULL), 1, tputs_putchar);
		}
	}
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	return (0);
}
