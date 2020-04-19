#include "get_next_line.h"

void	ft_double_bzero(char *buffer, char *buffer2, int size, int size2)
{
	while (size--)
	{
		((char *)buffer)[size] = '\0';
	}
	while (size2--)
	{
		((char *)buffer2)[size2] = '\0';
	}
}


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
		ft_double_bzero(buff, buff, BUFFER_SIZE + 1, BUFFER_SIZE + 1);
		read_return = read(fd, buff, BUFFER_SIZE);
		if (read_return == -1)
			return (-1);
		else
		{
			if (!(increase_line_size(line, ft_strlen_char(buff, '\n'))))
				return (-1);
			ft_strcat_char(*line, buff, '\n');
			if (c_is_in_str(buff, '\n') >= 0)
			{
				ft_strcpy_char(previous_buff, buff, '\0');
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
	ft_double_bzero(&buff[0], *line, BUFFER_SIZE + 1, 1);
	if (c_is_in_str(previous_buff, '\n') >= 0)
	{
		if (!(increase_line_size(line, ft_strlen_char(previous_buff, '\n'))))
			return (-1);
		ft_strcpy_char(*line, previous_buff, '\n');
		update_previous_buffer(previous_buff);
		return (1);
	}
	else
	{
		if (!(increase_line_size(line, ft_strlen_char(previous_buff, '\0'))))
			return (-1);
		ft_strcpy_char(*line, previous_buff, '\0');
		return (put_buff_in_line(fd, buff, line, previous_buff));
	}
	return (-1);
}

int main ()
{
	char *line;
	int fd;
	int result;

	line = NULL;
	fd = open("test2.txt", O_RDONLY);
	if (fd != -1)
	{
		while (1)
		{
			result = get_next_line(fd, &line);
			printf("ligne = -%s-\n", line);
			free(line);
			if (result == -1 || !result)
				break;
		}
	}
	return (0);
}
