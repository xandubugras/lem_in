#include "../include/lem_in.h"

t_queue	*create_queue(void)
{
	t_queue	*new;

	new = malloc(sizeof(t_queue));
	new->rear = 0;
	new->front = 0;
	return (new);
}

t_room	*enqueue(t_queue *queue, t_room *new)
{
	if (!queue || !new)
		return (0);
	if (!(queue->front))
		queue->front = new;
	if (!(queue->rear))
		queue->rear = new;
	else
	{
		queue->rear->prev = new;
		new->next = queue->rear;
		queue->rear = new;
	}
	return (new);
}

t_room	*dequeue(t_queue *queue)
{
	t_room	*tmp;

	if (!queue || !(queue->front))
		return (0);
	if (queue->front->prev)
	{
		queue->front->prev->next = 0;
		tmp = queue->front;
		queue->front = queue->front->prev;
		if (queue->front->prev == 0)
			queue->rear = queue->front;
	}
	else
	{
		queue->front = 0;
		queue->rear = 0;
	}
	return (queue->front);
}

void	print_queue(t_queue *queue, char order)
{
	t_room	*buf;
	int		i;

	if (!queue || !(queue->rear))
		return ;
	buf = order == 'R' ? queue->front : queue->rear;
	i = 0;
	while (buf)
	{
		ft_printf("%s\n", buf->room_name);
		buf = order == 'R' ? buf->prev : buf->next;
		i++;
	}
}
