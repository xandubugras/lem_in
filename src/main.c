#include "../include/lem_in.h"

void	print_room_arr(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		ft_printf("name: %s code: %d\n", rooms[i]->room_name,
										rooms[i]->code);
		i++;
	}
}

int	main(void)
{
	t_room	**rooms;
	int		num_ants;
	char	*str;
	int		room_nbr;
	int		**room_graph;

	get_next_line(0, &str);
	if ((num_ants = ft_atoi(str)) == 0 || !ft_only_digits(str))
		return (ft_printf_err("Wrong farm size input\n"));
	ft_printf("\nants: %d\n", num_ants);
	room_nbr = 0;
	rooms = load_rooms(&room_nbr, &str);
	print_room_arr(rooms);
	room_graph = create_graph(room_nbr);
	link_rooms(room_graph, rooms, str);
	print_graph(room_graph);
	if (!find_paths(room_graph, rooms))
		return (1);
	//send_ants(
	//find_shortest_paths
	//send_paths and write paths
}

