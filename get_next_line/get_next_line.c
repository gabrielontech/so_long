/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:40:36 by gkitoko           #+#    #+#             */
/*   Updated: 2022/05/23 14:46:20 by gkitoko          ###   ########.fr       */
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
		return (ft_free(save), NULL);
	buffer = malloc(sizeof(char) * (strlen(save) - i + 1));
	if (!buffer)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		buffer[j++] = save[i++];
	buffer[j] = '\0';
	ft_free(save);
	return (buffer);
}

char	*read_line(int fd, char *save, int *v_read)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*v_read = 1;
	while (!ft_strchr(save, '\n') && *v_read != 0)
	{	
		*v_read = read(fd, buffer, BUFFER_SIZE);
		if (*v_read == -1)
		{
			ft_free(buffer);
			return (NULL);
		}
		buffer[*v_read] = '\0';
		if (*v_read)
			save = ft_strjoin(save, buffer);
	}
	ft_free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save = (char *)0;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_free(save);
		return (NULL);
	}
	save = read_line(fd, save, &ret);
	if (!save)
		return (NULL);
	buffer = ft_get_line(save);
	if (!buffer)
		return (ft_free(buffer), NULL);
	save = ft_save(save);
	if (!ret)
		ft_free(save);
	return (buffer);
}
