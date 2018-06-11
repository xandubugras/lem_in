#include "../include/lem_in.h"

int	find_start_end(t_room **start, t_room **end, t_room **rooms)
{
	int	i;

	i = 0;
	*start = 0;
	*end = 0;
	while (rooms[i])
	{
		if (rooms[i]->start)
		{
			if (!(*start))
				*start = rooms[i];
			else
				return (ft_printf_err("More than one start!!\n"));
		}
		else if (rooms[i]->end)
		{
			if (!(*end))
				*end = rooms[i];
			else
				return (ft_printf_err("More than one end!!\n"));
		}
		i++;
	}
	return (0);
}

int	bfs_graph(t_room *start, int **room_graph, t_room **rooms, t_queue *q)
{
	int	i;

	i = start->code == 0 ? 1 : 0;
	dequeue(q);
	while (room_graph[start->code][i] != MIN_INT)
	{
		if (room_graph[start->code][i])
			if (rooms[i]->visited == -1)
			{
				if (rooms[i]->end == 1)
					start->end = 2;
				else
				{
					rooms[i]->visited = start->code;
					ft_printf("visited room %s from %s\n", rooms[i]->room_name, start->room_name);
					enqueue(q, rooms[i]);
				}
			}
		i++;
	}
	if (q->front)
		bfs_graph(q->front, room_graph, rooms, q);
	return (0);
}


int	find_paths(int **room_graph, t_room **rooms)
{
	t_room	*start;
	t_room	*end;
	t_queue	*q;

	q = create_queue();
	if (!room_graph || !rooms)
		return (ft_printf_err("find_paths empty args\n"));
	if (find_start_end(&start, &end, rooms))
		return (ft_printf_err("Please have one start and end\n"));
	start->visited = -2;
	if (bfs_graph(start, room_graph, rooms, q))
		return (ft_printf_err("no possible solution\n"));
	ft_printf("start: %s end: %s\n", start->room_name, end->room_name);
	return (0);
}
