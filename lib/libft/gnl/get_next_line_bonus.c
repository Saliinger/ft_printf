/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:20:10 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/15 18:37:03 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_clean(char *stash)
{
	int		i;
	char	*tmp;

	tmp = malloc(ft_strlen_gnl(stash) + 1);
	if (!tmp)
		return (NULL);
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
	static char	*s[1024];
	char		*b;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (free(s[fd]), s[fd] = NULL, NULL);
	b = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!b)
		return (NULL);
	bytes_read = read(fd, b, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(s[fd]), s[fd] = NULL, free(b), b = NULL, NULL);
	b[bytes_read] = '\0';
	if (!s[fd])
	{
		s[fd] = malloc(sizeof(char));
		if (!s[fd])
			return (free(b), NULL);
		*s[fd] = '\0';
	}
	s[fd] = ft_strjoin_gnl(s[fd], b);
	if (s[fd][0] == '\0')
		return (free(s[fd]), s[fd] = NULL, free(b), b = NULL, NULL);
	return (get_next_line_2(&s[fd], &b, &bytes_read, fd));
}
