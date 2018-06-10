#include "libft.h"

void	*ft_realloc(void *curr, size_t new_size)
{
	void	*new;
	int		i;

	new = malloc(new_size);
	while (i < new_size)
	{
		new[i] = curr[i];
		i++;
	}
	free (curr);
	return (new);
}
