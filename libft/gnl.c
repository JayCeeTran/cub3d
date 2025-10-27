/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:44:38 by jtran             #+#    #+#             */
/*   Updated: 2024/12/12 09:17:47 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static int	findn(char *buffer, int c)
{
	while (*buffer)
	{
		if (*buffer == c)
			return (1);
		buffer++;
	}
	return (0);
}

static char	*get_line(char *buffer)
{
	int		i;
	int		len;
	char	*temp;

	len = 0;
	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[len] != '\n' && buffer[len])
		len++;
	temp = ft_calloc(len + 2, sizeof(char));
	while (i < len)
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[len] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

static char	*readfile(int fd, char *buffer, int byteread, char *nbuff)
{
	char	*temp;

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (byteread > 0)
	{
		byteread = read(fd, temp, BUFFER_SIZE);
		if (byteread == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		temp[byteread] = '\0';
		nbuff = ft_strjoin(buffer, temp);
		free(buffer);
		buffer = nbuff;
		if (findn(buffer, '\n'))
			break ;
	}
	free(temp);
	return (buffer);
}

static char	*restoffile(char *buffer)
{
	int		i;
	char	*temp;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	temp = ft_strdup(&buffer[i + 1]);
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = readfile(fd, buffer[fd], 1, NULL);
	if (!buffer[fd] || buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = get_line(buffer[fd]);
	buffer[fd] = restoffile(buffer[fd]);
	return (line);
}
