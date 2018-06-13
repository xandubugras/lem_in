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
	char		full;
	struct s_room	*next;
	struct s_room	*prev;
}		t_room;

typedef struct	s_queue
{
	struct s_room	*rear;
	struct s_room	*front;
}		t_queue;
/*
**	LOAD_AND_LINK.c
*/
t_room		**load_rooms();

int			link_rooms(int **graph, t_room **rooms, char *str);
/*
**	CONSTRUCTORS.c
*/
t_room		*add_room(t_room **root, char **cord, char start_end);

t_room		*new_room();

t_room		*find_room(t_room **rooms, char *name);

void		print_rooms(t_room *root);
/*
**	FIND_PATHS.c
*/
int			*find_paths(int **room_graph, t_room **rooms);

int			find_start_end(t_room **start, t_room **end, t_room **rooms);
/*
**	HELPER.c
*/
int			check_paths(int *paths);

int			handle_empty_str(char *str, char *tmp);

int			free_tmp_str_split(char **splt, char *str, char *tmp);
/*
**	SEND_ANTS.c
*/
int			send_ants(int *paths, t_room **rooms, int ants);


/*
**-------------------------QUEUES----------------------
*/

t_queue			*create_queue(void);

void			print_queue(t_queue *queue, char order);

t_room			*dequeue(t_queue *queue);

t_room			*enqueue(t_queue *queue, t_room *new);
