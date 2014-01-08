#include "./includes/ft_select.h"

void	ft_error(int err, int fd)
{
	if (err == 1)
		ft_putstr_fd("Error : Insuffisant memory.\n", fd);
	exit(0);
}

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *)s++ = 0;
}

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = (void *)malloc(size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size);
	return (result);
}
