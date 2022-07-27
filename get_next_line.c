#include "get_next_line.h"

char	*read_line_file(char *sentense, char *files)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (files[len] != '\n' && files[len] != '\0')
		len++;
	sentense = (char *)malloc(sizeof(char) * (len + 1));
	if (!sentense)
		return (0);
	while (files[i] != '\n' && files[i] != '\0')
	{
		sentense[i] = files[i];
		i++;
	}
	sentense[i] = '\0';
	return (sentense);
}

char	*read_file(int fd, char *files)
{
	char	*buf;
	int		len;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	while (!ft_strchr(files, '\n') && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[len] = '\0';
		files = ft_strjoin(files, buf);
	}
	free(buf);
	return (files);
}

char	*next_line(char *sentense, char *files, int len, int fd)
{
	int	i;
	int	len2;

	i = 0;
	while (sentense[i])
	{
		if (sentense[i] == files[i])
			i++;
		else
			break;
	}
	len2 = ft_strlen(sentense);
	write (fd, &files[i], len - len2);
	return (&files[i]);
}

char	*get_next_line(int fd)
{
	char	*files;
	char	*sentense;
	int		len;

	if (fd < 0)
		return (0);
	files = read_file(fd, files);
	len = ft_strlen(files);
	//printf("%s\n", files);
	if (!files)
		return (NULL);
	sentense = read_line_file(sentense, files);
	files = next_line(sentense, files, len, fd);
	return (sentense);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	//int		fd2;
	//int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	//fd2 = open("tests/test2.txt", O_RDONLY);
	//fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		//line = get_next_line(fd2);
		//printf("line [%02d]: %s", i, line);
		//free(line);
		//line = get_next_line(fd3);
		//printf("line [%02d]: %s", i, line);
		//free(line);
		i++;
	}
	close(fd1);
	//close(fd2);
	//close(fd3);
	return (0);
}