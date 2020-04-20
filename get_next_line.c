#include "get_next_line.h"

void	ft_bzero(char *buffer, int size)
{
	if (!buffer)
		return ;
	while (size--)
	{
		((char *)buffer)[size] = '\0';
	}
}

int char_is_in_str(char *str, char c)
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

int put_buff_in_line(int fd, char *previous_buff, char **line)
{
	int read_return;

	while (1)
	{
		ft_bzero(previous_buff, BUFFER_SIZE + 1);  // to delete
		read_return = read(fd, previous_buff, BUFFER_SIZE);
		if (read_return == -1)
			return (-1);
		else
		{
			if (!(increase_line_size(line, ft_strlen_char(previous_buff, '\n'))))
				return (-1);
			ft_strcat_char(*line, previous_buff, '\n');
			if (char_is_in_str(previous_buff, '\n') >= 0)
			{
				update_previous_buffer(previous_buff);
				if (read_return)
					return (1);
			}
		if (!read_return)
			return (0);
		}
	}
}

int fill_line(int fd, char *previous_buff, char **line)
{
	if (char_is_in_str(previous_buff, '\n') >= 0)
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
		return (put_buff_in_line(fd, previous_buff, line));
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char previous_buff[BUFFER_SIZE + 1];

	if (line == NULL || fd == -1)
		return (-1);
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	ft_bzero(*line, 1);
	return fill_line(fd, &previous_buff[0], line);
}

int main ()
{
	char *line;
	int fd;
	int result;

	fd = open("test.txt", O_RDONLY);
	if (fd != -1)
	{
		while (1)
		{
			result = get_next_line(fd, &line);
			if (result != -1)
				printf("ligne = -%s-\n", line);
			if (line)
			{
				free(line);
				line = NULL;
			}
			if (result == -1 || !result)
				break;
		}
	}
	return (0);
}
