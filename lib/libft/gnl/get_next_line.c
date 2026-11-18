/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:20:10 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/15 18:39:18 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(char *stash)
{
	int		i;
	char	*tmp;

	tmp = malloc(ft_strlen_gnl(stash) + 1);
	if (!tmp)
		return (free(stash), stash = NULL, NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	ft_strncpy_gnl(tmp, stash + i, ft_strlen_gnl(stash + i));
	tmp[ft_strlen_gnl(stash + i)] = '\0';
	free(stash);
	stash = NULL;
	return (tmp);
}

char	*get_next_line_2(char **stash, char **buffer, int *bytes_read, int fd)
{
	char	*result;
	size_t	len;

	while (!ft_verify(*stash))
	{
		*bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (*bytes_read <= 0)
			break ;
		(*buffer)[*bytes_read] = '\0';
		*stash = ft_strjoin_gnl(*stash, *buffer);
	}
	len = 0;
	while ((*stash)[len] != '\n' && (*stash)[len] != '\0')
		len++;
	if ((*stash)[len] != '\0')
		len++;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (free(*stash), free(*buffer), NULL);
	if ((*stash)[0] == '\n' && len == 0)
		result[len++] = '\n';
	ft_strncpy_gnl(result, *stash, len);
	result[len] = '\0';
	*stash = ft_clean(*stash);
	return (free(*buffer), (*buffer) = NULL, result);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			bytes_read;

	if (fd < 0)
		return (free(stash), stash = NULL, NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(buffer), buffer = NULL, free(stash), stash = NULL, NULL);
	buffer[bytes_read] = '\0';
	if (!stash)
	{
		stash = malloc(sizeof(char));
		if (!stash)
			return (free(buffer), NULL);
		*stash = '\0';
	}
	stash = ft_strjoin_gnl(stash, buffer);
	if (stash[0] == '\0')
		return (free(stash), stash = NULL, free(buffer), buffer = NULL, NULL);
	return (get_next_line_2(&stash, &buffer, &bytes_read, fd));
}
