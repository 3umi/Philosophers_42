/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:28:41 by ohalim            #+#    #+#             */
/*   Updated: 2022/11/03 18:16:59 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*read_and_dyallocate(int fd, char *tmp)
{
	char		*buff;
	ssize_t		bytes_read;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(tmp, '\n') && bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = 0;
		tmp = ft_strjoin(tmp, buff);
	}
	free(buff);
	return (tmp);
}

char	*extract_line(char *tmp)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = (char *) ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i] = tmp[i];
	return (line);
}

char	*initialize_tmp(char *tmp)
{
	char	*new_tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	new_tmp = (char *) ft_calloc(ft_strlen(tmp) - i + 1, sizeof(char));
	if (!new_tmp)
		return (NULL);
	i++;
	while (tmp[i])
		new_tmp[j++] = tmp[i++];
	free(tmp);
	return (new_tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp[512];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	tmp[fd] = read_and_dyallocate(fd, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	line = extract_line(tmp[fd]);
	tmp[fd] = initialize_tmp(tmp[fd]);
	return (line);
}
