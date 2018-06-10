#include "../libft/libft.h"
#include <stdio.h>
#define COMMAND_CHAR '#'

typedef struct s_room
{
	char		*room_name;
	int			x;
	int			y;
	char		visited;
	int			code;
	char		end;
	char		start;
	struct s_room	*next;
}		t_room;

t_room		**load_rooms();

t_room		*add_room(t_room **root, char **cord, char start_end);

t_room		*new_room();

t_room		*find_room(t_room **rooms, char *name);

void		print_rooms(t_room *root);

int			link_rooms(int **graph, t_room **rooms);
