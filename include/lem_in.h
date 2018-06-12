#include "../libft/libft.h"
#include <stdio.h>
#define COMMAND_CHAR '#'

typedef struct s_room
{
	int		len;
	char		*room_name;
	int			x;
	int			y;
	char		visited;
	int			code;
	char		end;
	char		start;
	struct s_room	*next;
	struct s_room	*prev;
}		t_room;

typedef struct	s_queue
{
	struct s_room	*rear;
	struct s_room	*front;
}		t_queue;

t_room		**load_rooms();

t_room		*add_room(t_room **root, char **cord, char start_end);

t_room		*new_room();

t_room		*find_room(t_room **rooms, char *name);

void		print_rooms(t_room *root);

int			link_rooms(int **graph, t_room **rooms, char *str);

int	*find_paths(int **room_graph, t_room **rooms);

/*
**-------------------------QUEUES----------------------
*/

t_queue			*create_queue(void);

void			print_queue(t_queue *queue, char order);

t_room			*dequeue(t_queue *queue);

t_room			*enqueue(t_queue *queue, t_room *new);
