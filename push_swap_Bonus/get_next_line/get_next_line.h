/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:27:43 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/13 13:36:03 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strdup_(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, char c);
int		ft_strlen(const char *str, char c);
char	*ft_strcpy(const char *src, char c);

#endif
