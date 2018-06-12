#include "../include/lem_in.h"

int		find_min(t_room **rooms, int *paths)
{
	int		i;
	int		min;

	min = paths[0];
	i = 1;
	while (paths[i] > 0)
	{
		if (rooms[paths[i]]->len < rooms[min]->len)
			min = paths[i];
		i++;
	}
	return (min);
}

void	move_up(t_room *fill, t_room *empty, int *counter, int count)
{
	if (fill && fill->end != 1)
		fill->full = count;
	if (empty && !empty->start)
		empty->full = 0;
	if (fill && empty)
		ft_printf("L%d-%s ", count, fill->room_name);
	if (counter)
		*counter += 1;
}

int		choose_path(t_room **rooms, int *paths, int ants, int min)
{
	int		i;
	int		ants_sent;
	static int	count;

	count++;
	if (!rooms || !paths || ants <= 0 || min < 0)
		return (0);
	ants_sent = 0;
	i = 0;
	while (paths[i] >= 0)
	{
		if (!rooms[paths[i]]->full && ants - ants_sent > rooms[paths[i]]->len)
			move_up(rooms[paths[i]], rooms[paths[i]]->prev, &ants_sent, count);
		else if (!rooms[min]->full)
			move_up(rooms[min], rooms[min]->prev, &ants_sent, count);
		i++;
	}
	return (ants_sent);
}

int		walk_paths(t_room **rooms, int *paths)
{
	int		i;
	int		reached_end;
	t_room	*buf;

	if (!rooms[0] || paths[0] < 0)
		return (0);
	i = 0;
	reached_end = 0;
	while (paths[i] >= 0)
	{
		buf = rooms[paths[i]];
		while (buf && buf->next && buf->next->full)
			buf = buf->next;
		while (buf && !buf->start && buf->full)
		{
			if (buf->next && buf->next->end == 1)
				move_up(buf->next, buf, &reached_end, buf->full);
			else
				move_up(buf->next, buf, 0, buf->full);
			if (buf->prev)
				buf = buf->prev;
		}
		i++;
	}
	return (reached_end);
}

int		send_ants(int *paths, t_room **rooms, int ants)
{
	int		min;
	int		ants_in_start;
	t_room	*end;
	t_room	*start;

	min = find_min(rooms, paths);
	ants_in_start = ants;
	if (paths[0] == -3)
	{
	find_start_end(&start, &end, rooms);
		while (ants > 0)
		{
			move_up(end, start, 0, ants_in_start - ants + 1);
			ft_printf("\n");
			ants--;
		}
	}
	while (ants > 0)
	{
		ants -= walk_paths(rooms, paths);	
		ants_in_start -= choose_path(rooms, paths, ants_in_start, min);
		ft_printf("\n");
	}
	return (ants_in_start);
}
