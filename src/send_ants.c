#include "../include/lem_in.h"

int		send_ants(int *paths, t_room **rooms, int ants)
{
	int		i;

	while (ants > 0)
	{
		i = -1;
		while (paths[i + 1] != -2)
		{
			i++;
			if (paths[i] == -1)
				continue ;
			if (send_ants(rooms, paths[i]), ants)	
				ants--;
		}
	}
}
