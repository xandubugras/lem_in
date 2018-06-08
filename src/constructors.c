#include "../include/lem_in.h"

t_room	*new_room()
{
	t_room	*new;

	if (!(new = malloc(sizeof(t_room))))
		return (0);
	new->room_name = 0;
	new->x = 0;
	new->y = 0;
	new->visited = 0;
	new->linked_rooms = 0;
	new->end = 0;
	new->start = 0;
	new->next = 0;
	return (new);
}

t_room	*add_room(t_room **root, char **cord, char start_end)
{
	t_room	*new;

	if (!root)
		return ;
	new = new_room();
	if (*root == 0)
		*root = new;
	else
	{
		new->next = (*root)->next;
		(*root)->next = new;
	}
	new->room_name = cord[0];
	new->x = ft_atoi(cord[1]);
	new->y = ft_atoi(cord[2]);
	new->end = start_end > 0 ? 0 : 1;
	new->start = start_end < 0 ? 1 : 0;
	
}
