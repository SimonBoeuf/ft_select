#include "./includes/ft_select.h"
#include <fcntl.h>

int		ft_putchar(int c)
{
	int		fd;

	fd = open("/dev/tty", O_WRONLY);
	write(fd, &c, 1);
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}
