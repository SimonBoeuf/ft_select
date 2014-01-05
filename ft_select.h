#ifndef FT_SELECT_H
# define FT_SELCT_H

# include <termios.h>
# include <termcap.h>
# include <unistd.h> /* write */
# include <stdlib.h> /* getenv */
# include <stdio.h>

typedef struct		s_list
{
	struct s_elem	*first_elem;
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

void		ft_error(int err);
char		*ft_strdup(const char *s1);
t_elem		*ft_elem_init(char *data);
void		ft_elem_add(t_elem *elem_list, t_elem *elem_to_add);
size_t		ft_strlen(const char *str);
int			tputs_putchar(int c);
void		ft_putstr(char *str);
char		*ft_strcpy(char *s1, const char *s2);
int			ft_strcmp(const char *s1, const char *s2);

#endif /* !FT_SELECT_H */
