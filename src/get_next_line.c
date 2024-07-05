#include "map.h"

int	ft_count_len(char *next_line)
{
	int	i;

	i = 0;
	if (next_line == NULL || next_line == 0)
		return (0);
	else
	{
		while (next_line[i] != '\0')
		{
			if (next_line[i] == '\n')
				return (i);
			i++;
		}
		return (i);
	}
}

char	*ft_get_line(char *next_line)
{
	int		i;
	char	*line;
	int		len_line;

	len_line = ft_count_len(next_line);
	line = ft_calloc((len_line + 2), 1);
	i = 0;
	while (next_line[i] != '\0' && next_line[i] != '\n')
	{
		line[i] = next_line[i];
		i++;
	}
	if (next_line[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

char	*ft_create_next_line(char *next_line)
{
	int		i;
	int		j;
	int		len;
	char	*new_line;

	i = 0;
	while (next_line[i] != '\n' && next_line[i] != '\0')
		i++;
	if (next_line[i] == '\0')
	{
		free(next_line);
		return (NULL);
	}
	i++;
	j = i;
	while (next_line[i] != '\0')
		i++;
	len = i - j + 1;
	new_line = ft_calloc(len, 1);
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		new_line[i++] = next_line[j++];
	return (new_line);
}

char	*ft_read_file(char *buffer, char *next_line, int fd)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (ft_strchr(buffer, '\n') == 0 && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((!*next_line && !*buffer && bytes_read == 0) || bytes_read < 0)
		{
			free(next_line);
			next_line = NULL;
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = next_line;
		next_line = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*next_line;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (next_line == 0)
		next_line = ft_strdup("");
	buffer = ft_calloc((BUFFER_SIZE + 1), 1);
	if (buffer == NULL)
		return (NULL);
	next_line = ft_read_file(buffer, next_line, fd);
	if (next_line == NULL)
		return (NULL);
	line = ft_get_line(next_line);
	temp = next_line;
	next_line = ft_create_next_line(temp);
	if (next_line != NULL)
		free(temp);
	return (free(buffer), line);
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int i;
	int fd;
	char *res;

	i = 0;

	fd = open("teste.txt", O_RDWR);
	//1
	res = get_next_line(fd);
	printf("1: %s", res);
	free(res);
	//2
	res = get_next_line(fd);
	printf("1: %s", res);
	free(res);

	close(fd);
	fd = open("teste.txt", O_RDWR);
	//1
	res = get_next_line(fd);
	printf("1: %s", res);
	free(res);
	//2
	res = get_next_line(fd);
	printf("2: %s", res);
	free(res);
	//3
	res = get_next_line(fd);
	printf("3: %s", res);
	free(res);
	//4
	res = get_next_line(fd);
	printf("4: %s", res);
	free(res);
	//5
	res = get_next_line(fd);
	printf("5: %s", res);
	free(res);
	//6
	res = get_next_line(fd);
	printf("6: %s", res);
	free(res);
} */

/* #include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("file", O_RDWR);
    if(fd < 0)
        printf("error\n");
    
    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    
    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    return (0);
} */