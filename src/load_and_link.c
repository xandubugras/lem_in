#include "../include/lem_in.h"
#define START 2
#define END 3

static int	handle_command(char *start_end, char *str)
{
	if (!str)
		return (1);
	if (!ft_strcmp(str + 1, "#start"))
		*start_end = 1;
	else if (!ft_strcmp(str + 1, "#end"))
		*start_end = -1;
	else
		*start_end = 0;
	free(str);
	return (0);
}


t_room		**room_list_to_arr(t_room *root, int size)
{
	int		i;
	t_room	**arr;
	t_room	*buf;

	if (!root || size < 1)
		return (0);
	arr = malloc(sizeof(t_room *) * (size + 1));
	arr[size] = 0;
	i = size;
	buf = root;
	while (--i >= 0)
	{
		arr[i] = buf;
		buf = buf->next;
	}
	return (arr);
}

t_room		**load_rooms(int *room_nbr, char **str)
{
	char	start_end;
	char	**splt;
	t_room	*root;
	t_room	**rooms;

	start_end = 0;
	root = 0;
	while (get_next_line(0, str) == 1)
	{
		(*str) = ft_strtrim((*str)); // free prev string at some point
		if (!(*str))
			break ;
		ft_printf("input: %s.\n", (*str));
		if ((*str)[0] == COMMAND_CHAR && !handle_command(&start_end, *str))
			continue ;
		if ((splt = ft_strsplit(*str, ' ')) == 0 || (splt[0] && !splt[1]))
			break ;
		if (splt[0] && splt[1] && splt[2] && (*room_nbr += 1))
			add_room(&root, splt, start_end);
		start_end = 0;
		//free((*str));
	}
	rooms = room_list_to_arr(root, *room_nbr);
	return (rooms);
}

int		add_link(t_room **rooms, int **graph, char *str)
{
	char	*room_name_1;
	char	*room_name_2;
	t_room	*room_1;
	t_room	*room_2;
	int		i;

	if (!*rooms || !str || !ft_strchr(str, '-'))
		return (ft_printf("invalid input: %s\n", str));
	i = 0;
	while (str[i] != '-')
		i++;
	room_name_1 = ft_strndup(str, i);
	room_name_2 = ft_strdup(&str[i + 1]);
	room_1 = find_room(rooms, room_name_1);
	room_2 = find_room(rooms, room_name_2);
	if (!room_1 || !room_2)
		return (ft_printf_err("Unknown room\n"));
	ft_printf("linking %s and %s\n", room_1->room_name, room_2->room_name);
	graph[room_1->code][room_2->code] = 1;
	graph[room_2->code][room_1->code] = 1;
	return (0);
}

int		link_rooms(int **graph, t_room **rooms, char *str)
{
	while (1)
	{
		add_link(rooms, graph, str);
		if (get_next_line(0, &str) != 1)
			break;
	}
	return (0);
}














