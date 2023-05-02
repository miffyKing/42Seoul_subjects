/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:07:41 by bcho              #+#    #+#             */
/*   Updated: 2022/12/08 15:33:10 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_backup(char *backup)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (backup[i] != '\n' && backup[i])
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	if (backup[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!dest)
		return (NULL);
	while (backup[i])
		dest[j++] = backup[i++];
	dest[j] = '\0';
	free(backup);
	return (dest);
}

char	*ft_read(int fd, char *backup)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_strchr(backup, '\n') && bytes > 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(backup);
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		backup = ft_strjoin(backup, temp);
	}
	free(temp);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	int			index;

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup)
		backup = ft_strdup("");
	backup = ft_read(fd, backup);
	if (!backup)
	{
		free(backup);
		return (NULL);
	}
	while (backup[index] != '\n' && backup[index])
		index++;
	line = ft_substr(backup, 0, index + 1);
	backup = update_backup(backup);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
