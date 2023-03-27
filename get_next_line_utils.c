/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkabelko <jkabelko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:28:13 by jkabelko          #+#    #+#             */
/*   Updated: 2023/03/27 10:28:13 by jkabelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(char *s)
{
	size_t	len;
	
	if (!s)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char my_c;
	int	i;

	if (!s)
		return(-1);
	my_c = (unsigned char) c;
	while (s[i] = != '\0')
	{
		if (s[i] == my_c)
			return (i);
		i++;
	}
	if (my_c == '\0')
		return (i);
	return (-1);
}

char	*ft_strjoin(char *start, char *buff)
{
	char	*str;
	
	if (!start)
	{
		start =(char *)malloc(sizeof(char));
		start[0] = '\0';
	}
	if (!buff)
		return(NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(start) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	str = ft_join(str, start, buff);
	free(start);
	return (str);
}

char	*ft_join(char *dest, char *start, char *buff)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (start && start[i])
	{
		dest[i] = start[i];
		i++;
	}
	j = 0;
	while (buff && buff[j]
	{
		dest[i + j] = buff[j];
		j++;
	}
	dest [i + j ] = '\0';
	return (dest);
}

char	*new_line_read(int fd)
{
	char	*buff;
	int	n;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n = read(fd, buff, BUFFER_SIZE);
	if (n < 0)
	{
		free(buff);
		return (NULL);
	}
	buff[n] = '\0';
	return (buff);
}
