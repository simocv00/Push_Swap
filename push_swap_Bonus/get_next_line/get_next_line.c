/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:02:31 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/13 14:04:52 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1, '\0') + ft_strlen(s2,
				'\0') + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

static char	*ft_new_line_detector(char *str)
{
	char	*newline;

	if (!str)
		return (NULL);
	newline = ft_strchr(str, '\n');
	if (newline)
		return (ft_strdup_(newline + 1));
	return (NULL);
}

static char	*read_until_newline(int fd, char *buffer)
{
	char	*here;
	ssize_t	bytes_read;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	here = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!here)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, here, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(here), NULL);
		if (bytes_read == 0)
			break ;
		here[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, here);
	}
	free(here);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*here;
	char		*temp;
	char		*tt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_until_newline(fd, buffer);
	if (!buffer || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	here = ft_strcpy(buffer, '\n');
	temp = ft_new_line_detector(buffer);
	free(buffer);
	buffer = temp;
	tt = ft_strjoin_(here, buffer);
	free(here);
	free(buffer);
	here = NULL;
	buffer = NULL;
	return (tt);
}
