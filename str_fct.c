#include "./includes/ft_select.h"

char		*ft_strcpy(char *s1, const char *s2)
{
	char	*temp_s1;

	temp_s1 = s1;
	while (*s2 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
	return (temp_s1);
}

char		*ft_strdup(const char *s1)
{
	char	*copy;

	if (s1 == NULL)
		return (NULL);
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy == NULL)
		ft_error(1, 2);
	return (ft_strcpy(copy, s1));
}

void		ft_strdel(char **as)
{
	if (as != NULL)
	{
		if (*as != NULL)
			free(*as);
		*as = NULL;
	}
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}
