

#include "../libft/libft.h"
#define COMMAND_CHAR '#'

typedef struct s_room
{
	char		*room_name;
	int		x;
	int		y;
	char		visited;
	struct s_room	**linked_rooms;
	int		num_of_links;
	char		end;
	char		start;
	struct s_room	*next;
}		t_room;
