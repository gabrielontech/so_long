/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:40:36 by gkitoko           #+#    #+#             */
/*   Updated: 2022/02/25 13:27:45 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*buffer;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	buffer = malloc(sizeof(char) * i + 2);
	if (!buffer)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		buffer[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		buffer[i] = save[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!buffer)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		buffer[j++] = save[i++];
	buffer[j] = '\0';
	free(save);
	return (buffer);
}

char	*read_line(int fd, char *save)
{
	char	*buffer;
	int		v_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	v_read = 1;
	while (!ft_strchr(save, '\n') && v_read != 0)
	{	
		v_read = read(fd, buffer, BUFFER_SIZE);
		if (v_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[v_read] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_line(fd, save);
	if (!save)
		return (NULL);
	buffer = ft_get_line(save);
	save = ft_save(save);
	return (buffer);
}
