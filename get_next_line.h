#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strchr(char *str, int ch);
char	*ft_strjoin(char const *s1, char const *s2);
char	*read_line_file(char *sentense, char *files);
char	*read_file(int fd, char *files);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);

# define BUFFER_SIZE 1000

#endif