/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkabelko <jkabelko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:42:40 by jkabelko          #+#    #+#             */
/*   Updated: 2023/03/24 10:42:45 by jkabelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*my_string;
	char	*my_s;
	int		len;
	int		i;

	my_s = (char *)(s);
	i = 0;
	len = ft_strlen(my_s);
	my_string = (char *)malloc(sizeof(char) * (len + 1));
	if (my_string == NULL)
		return (0);
	i = 0;
	while (my_s[i] != '\0')
	{
		my_string[i] = my_s[i];
		i++;
	}
	my_string[i] = '\0';
	return (my_string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*my_s;
	char	*my_string;

	if (s == 0)
		return (0);
	my_s = (char *)(s);
	if (start > (unsigned int)(ft_strlen(my_s)))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	my_string = (char *)malloc(sizeof(char) * (len + 1));
	if (my_string == NULL)
		return (0);
	i = 0;
	while (my_s[i] != '\0' && i < len)
	{
		my_string[i] = my_s[i + start];
		i++;
	}
	my_string[i] = '\0';
	return (my_string);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	char	*my_src;

	i = 0;
	len = 0;
	my_src = (char *)(src);
	len = ft_strlen(my_src);
	if (size == 0 || dst == 0)
		return (len);
	while (my_src[i] != '\0' && i < (size - 1))
	{
		dst[i] = my_src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}




char	*get_next_line(int fd)
{
	static char	*buff[1048576];
	char	*line;
	int	pos;
	
	if (fd < 0 || fd > 1048576 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if(strchr(buff[fd], '\n') == -1)
	
	temp = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if(!temp)
		return (NULL);
	while (!(ft_strchr(line, '\n')) && pos !=0)
	{
		pos = read(fd, temp, BUFFER_SIZE);
		if (pos == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[pos] = '\0';
		line = ft_strjoin(line, temp);
	}
	free(temp);
	
	
	retrun(temp);
}
	
/* returns a line read from the file descriptor of an open file or the standard input (if fd=0)
or null if either an error occurred or reached EOF (End Of File)

a “line” is a succession of characters that end with ’\n’ (ascii code 0x0a) or with End Of File (EOF).

The returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.

Every time the function runs, it checks if there's a newline in the static variable buff.
If there isn't one, a new read is performed, increasing the size of the static variable.
When a line is found, the line is returned and the static variable has that line removed from it (it shrinks).
If no newline is found the program starts again, recursively. Eventually, when nothing new is read, the remains of the static variable are returned and the function lastly returns null.

 */
