#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char	*ft_strcat_spec(char *dest, const char *src, char c);
int		ft_strlen_spec(const char *str, char c);
char	*ft_strcpy_spec(char *dest, char *src, char c);
int		increase_line_size(char **line, int size_sup);
void	update_previous_buffer(char *str);
int		get_next_line(int fd, char **line);

#endif
