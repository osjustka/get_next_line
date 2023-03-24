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

# include <unistd.h>
# include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	pos;
	static int	len;
	char	*line;
	int	n;
	int	eol_count;
	
	pos = 0;
	len = 0;
	line = NULL;
	eol_count = 0;
		
	while (eol_count = 0)
	{
		if (pos == len)
		{
			len = read(fd, buf, BUFFER_SIZE);
			pos = 0;
			if (len == 0)
			{
				if(line && line[0] == '\0')
				{
					free (line);
					line = NULL;
				}	
				return (line);
			}
		}
		if (buf[pos] == '\n')
			eol_count = 1;
		else
		{
			
		}
		
	}
