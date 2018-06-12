#include "../include/lem_in.h"

void	print_arr(int *arr)
{
	ft_printf("\n");
	while (*arr != -2)
	{
		ft_printf("%d ", *arr);
		arr++;
	}
	ft_printf("\n");
}

int		check_paths(int *paths)
{
	int	i;

	i = 0;
	while (paths[i] != -2)
	{
		if (paths[i] < paths[i + 1])
		{
			ft_swap(&paths[i], &paths[i + 1]);
			i = -1;
		}
		i++;
	}
	if (paths[0] < 0)
		return (1);
	return (0);
}
