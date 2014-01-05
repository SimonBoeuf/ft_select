#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <termcap.h>
# include <unistd.h> /* write */
# include <stdlib.h> /* getenv */
# include <stdio.h>

# define KEYUP 1
# define KEYDOWN 2
# define KEYRIGHT 3
# define KEYLEFT 4

typedef struct		s_list
{
	struct s_elem	*first_elem;
	struct s_elem	*curr_elem;
	int				nb_elem;
}					t_list;

typedef struct		s_elem
{
	char			*data;
	unsigned int	index;
	struct s_elem	*next;
	struct s_elem	*prev;
	int				cursor;
	int				selected;
}					t_elem;

typedef struct		s_cursor
{
	int				pos_x;
	int				pos_y;
}					t_cursor;

/*
** error_fct.c
*/
void		ft_error(int err);

/*
** list_fct.c
*/
void			ft_initialize(int ac, char **av, t_list *init);
t_elem		*ft_elem_init(char *data);
void		ft_elem_add(t_elem *elem_list, t_elem *elem_to_add);

/*
** str_fct.c
*/
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *s1, const char *s2);
int			ft_strcmp(const char *s1, const char *s2);

/*
** put_fct.c
*/
int			ft_putchar(int c);
void		ft_putstr(char *str);
void		printelems(t_list *list);

/*
** sighandler_fct.c
*/

/*
** keyhandler_fct.c
*/
int			is_rtn(char *buf);
int        	is_arrow(char *buf);
int			is_bgreq(char *buf);

#endif /* !FT_SELECT_H */
