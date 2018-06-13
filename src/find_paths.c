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

static int	bfs_graph(t_room *start, int **room_graph, t_room **rooms, t_queue *q)
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
					enqueue(q, rooms[i]);
				}
			}
		i++;
	}
	if (q->front)
		bfs_graph(q->front, room_graph, rooms, q);
	return (0);
}

static int	backtrack_path(t_room **rooms, int i, t_room *end, int size)
{
	if (!end || !rooms || i < 0)
		return (-1);
	size++;
	if (rooms[i]->len == 0)
		rooms[i]->len = size;
	if (rooms[i]->len >= size)
		rooms[i]->next = end;
	else
		return (-1);
	rooms[i]->next = end;
	rooms[i]->prev = rooms[i]->visited >= 0 ? rooms[(int)rooms[i]->visited] : 0;
	if (rooms[i]->prev && rooms[i]->prev->visited >= 0)
		return (backtrack_path(rooms, rooms[i]->visited, rooms[i], size));
	else
		return (rooms[i]->code);
}

static int	*write_paths(t_room **rooms, t_room *end)
{
	int	i;
	int	*paths;
	int	num_paths;

	paths = 0;
	i = 0;
	num_paths = 0;
	while (rooms[i])
		if (rooms[i++]->end == 2)
			num_paths++;
	paths = malloc(sizeof(int) * (num_paths + 1));
	paths[num_paths] = -2;
	i = 0;
	while (rooms[i] && num_paths > 0)
	{
		if (rooms[i]->end == 2)
		{
			num_paths--;
			paths[num_paths] = backtrack_path(rooms, i, end, 0);
		}
		i++;
	}
	return (paths);
}
/*
**In this function, it finds the start and end(find_start_end),
**the paths that lead to the end(bfs_graph)
**orders the list of possible paths and returns an array with their indexes(write_paths)
*/

int	*find_paths(int **room_graph, t_room **rooms)
{
	t_room	*start;
	t_room	*end;
	t_queue	*q;
	int	*paths;

	q = create_queue();
	if (!room_graph || !rooms)
		return (paths = (ft_printf_err_zero("find_paths empty args\n")));
	if (find_start_end(&start, &end, rooms))
		return ((ft_printf_err_zero("Please have one start and end\n")));
	if (room_graph[end->code][start->code])
	{
		paths = malloc(sizeof(int) * 2);
		paths[0] = -3;
		paths[1] = -2;
		return (paths);
	}
	start->visited = -2;
	if (bfs_graph(start, room_graph, rooms, q))
		return ((ft_printf_err_zero("BFS_ERR\n")));
	paths = write_paths(rooms, end);
	if (check_paths(paths))
		return ((ft_printf_err_zero("No possible solution\n")));
	free(q);
	return (paths);
}
