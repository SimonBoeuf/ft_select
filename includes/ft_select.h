#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h> /* getenv */
# include <unistd.h> /* write */
# include <stdio.h>
# include <termios.h>
# include <termcap.h>
# include <fcntl.h>
# include <sys/ioctl.h>

# define KEYUP 1
# define KEYDOWN 2
# define KEYRIGHT 3
# define KEYLEFT 4

typedef struct		s_list
{
	struct s_elem	*first_elem;
	struct s_elem	*curr_elem;
	int				nb_elem;
	unsigned int	longest;
	int				fd;
}					t_list;

typedef struct		s_elem
{
	char			*data;
	struct s_elem	*next;
	struct s_elem	*prev;
	int				cursor;
	int				selected;
	int				posx;
	int				posy;
}					t_elem;

typedef struct		s_cursor
{
	int				x;
	int				y;
	char			*res;
}					t_cursor;

/*
** cursor_fct.c
*/
t_cursor			*init_cursor(int x, int y);
void				move_cursor(t_cursor *cursor);
t_cursor			*seek_cursor(t_list *list);

/*
** elem_fct.c
*/
t_elem				*ft_elem_init(char *data, int cursor);
void				ft_elem_add(t_elem *elem_list, t_elem *elem_to_add);
t_elem				*ft_elem_del(t_list *list, t_elem *elem_to_del);

/*
** list_fct.c
*/
t_list				*ft_getlist(int ac, char **av);
void				ft_print_list(t_list *list, int tr);
void				ft_del_list(t_list *list);

/*
** str_fct.c
*/
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);

/*
** put_fct.c
*/
int					ft_putchar(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char *str, int fd);

/*
** keycheck_fct.c
*/
int					is_rtn(char *buf);
int        			is_arrow(char *buf);
int					is_esc(char *buf);
int					is_bgreq(char *buf);
int					is_space(char *buf);
int					is_del(char *buf);

/*
** keyhandler_fct.c
*/
void				launch_space(t_list *list, t_cursor *cursor);
void				launch_del(t_list *list, t_cursor *cursor);
void				launch_rtn(t_list *list);
void				launch_esc();

/*
** term_fct.c
*/
struct termios		*init_term(int fd);
void				closeterm(void);
void				init_sequence(void);
struct winsize		ft_get_winsize(void);

/*
** divers_fct.c
*/
void				ft_error(int err, int fd);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);

/*
** arrow_fct.c
*/
void				launch_arrow(int arrow, t_list *list, t_cursor *cursor);
void				mvleft(t_list *l, t_cursor *c, int y);
void				mvright(t_list *l, t_cursor *c, int y);

/*
** effect_fct.c
*/
void				set_effect(t_elem *elem, int fd);

/*
** misc.c
*/
void				readkeys(t_list *list, t_cursor *cur);
int					is_win_too_small(t_list *list);

/*
** sighandler_fct.c
*/
void				catch(int s);
void				catch_controle(void);
void				catch_cont(void);
void				catch_int(void);
void				catch_resize(void);

#endif /* !FT_SELECT_H */
