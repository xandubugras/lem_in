#include "../include/lem_in.h"

t_room	*new_room()
{
	t_room	*new;

	if (!(new = malloc(sizeof(t_room))))
		return (0);
	new->room_name = 0;
	new->x = 0;
	new->y = 0;
	new->visited = -1;
	new->end = 0;
	new->start = 0;
	new->next = 0;
	new->prev = 0;
	new->code = 0;
	new->len = 0;
	return (new);
}

t_room	*add_room(t_room **root, char **cord, char start_end)
{
	t_room	*new;
	t_room	*tmp;

	if (!root)
		return (0);
	tmp = *root;
	new = new_room();
	new->next = tmp;
	new->room_name = cord[0];
	new->x = cord[1] ? ft_atoi(cord[1]) : 0;
	new->y = cord[2] ? ft_atoi(cord[2]) : 0;
	new->end = start_end == -1 ? 1 : 0;
	new->start = start_end == 1 ? 1 : 0;
	if (tmp)
		new->code = tmp->code + 1;
	*root = new;
	return (new);
}

t_room	*find_room(t_room **rooms, char *name)
{
	int		i;

	if (!*rooms)
		return (0);
	i = 0;
	while (rooms[i])
	{
		if (!ft_strcmp(rooms[i]->room_name, name))
			return (rooms[i]);
		i++;
	}
	return (0);
}

void	print_rooms(t_room *root)
{
	t_room	*buf;

	buf = root;
	ft_printf("\nrooms:\n");
	while (buf)
	{
		if (buf->start)
			ft_printf("start: ");
		if (buf->end)
			ft_printf("end: ");
		ft_printf(" code: %d\n", buf->code);
		buf = buf->next;
	}
}
