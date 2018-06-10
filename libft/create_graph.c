#include "libft.h"

int		**create_graph(int size)
{
	int		**graph;
	int		i;
	int		j;

	graph = malloc(sizeof(int *) * (size + 1));
	graph[size] = 0;
	i = 0;
	while (i < size)
	{
		graph[i] = malloc(sizeof(int) * (size + 1));
		graph[i][size] = MIN_INT;
		j = -1;
		while (++j < size)
			graph[i][j] = 0;
		i++;
	}
	return (graph);
}

void	free_graph(int **graph)
{
	int i;

	i = 0;
	while (graph[i])
	{
		free(graph[i]);
		i++;
	}
	free(graph);
}

void	print_graph(int **graph)
{
	int		i;
	int		j;

	i = 0;
	while (graph[i])
	{
		j = 0;
		while (graph[i][j] != MIN_INT)
		{
			ft_printf("%d ", graph[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
