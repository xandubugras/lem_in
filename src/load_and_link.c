#include "../include/lem_in.h"

static int	handle_command(char *start_end, char *str)
{
	if (!ft_strcmp(str, "start"))
		*start_end += 1;
	if (!ft_strcmp(str, "end"))
		*start_end += -1;
	return (0);
}

t_room		*load_rooms()
{
	char	start_end;
	char	*str;
	int	i;
	char	**splt;
	t_room	*root;


	start_end = 0;
	root = 0;
	while (get_next_line(1, &str) > 0)
	{
		i = 0;
		while (WHITESPACE(str[i]))
			i++;
		if (str[i] == COMMAND_CHAR)
		{
			if (handle_command(&start_end, &str[i + 1]))
				return (0);
			continue ;
		}
		splt = ft_str_split(&str[i], ' ');
		add_room(&root, splt, start_end);
		start_end = 0;
	}
}


