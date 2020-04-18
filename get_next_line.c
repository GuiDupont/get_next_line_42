#include "get_next_line.h"


int c_is_in_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int put_buff_in_line(int fd, char *buff, char **line, char *previous_buff)
{
	int read_return;

	while (1)
	{
		read_return = read(fd, buff, BUFFER_SIZE);
		if (read_return == -1)
			return (-1);
		else
		{
			if (!(increase_line_size(line, ft_strlen_spec(buff, '\0'))))
				return (-1);
			ft_strcat_spec(*line, buff, '\n');
			if (c_is_in_str(buff, '\n') >= 0)
			{
				ft_strcpy_spec(previous_buff, buff, '\0');
				update_previous_buffer(previous_buff);
				if (read_return)
					return (1);
			}
		if (!read_return)
			return (0);
		}
	}
}

int	get_next_line(int fd, char **line)
{
	char buff[BUFFER_SIZE + 1];
	static char previous_buff[BUFFER_SIZE + 1];

	*line = malloc(sizeof(**line));
	if (c_is_in_str(previous_buff, '\n') >= 0)
	{
		if (!(increase_line_size(line, ft_strlen_spec(previous_buff, '\0'))))
			return (-1);
		ft_strcpy_spec(*line, previous_buff, '\n');
		update_previous_buffer(previous_buff);
		return (1);
	}
	else
	{
		if (!(increase_line_size(line, ft_strlen_spec(previous_buff, '\0'))))
			return (-1);
		ft_strcpy_spec(*line, previous_buff, '\0');
		return (put_buff_in_line(fd, buff, line, previous_buff));
	}
	return (-1);
}

int main ()
{
	char *line;
	int fd;

	line = NULL;
	fd = open("test.txt", O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &line))
		{
		printf("ligne = -%s-\n", line);
		free(line);
		}
	}
	return (0);
}
