/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:42:02 by agengemb          #+#    #+#             */
/*   Updated: 2022/09/30 00:09:59 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_contains_nl(char	*str)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (*(str + i) == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*create_stash(char *buffer, t_list *stash, int octetsRead)
{
	int	i;
	t_list	*new;
	
	i = 0;
	while (i < octetsRead)
	{
		new = ft_lstnew(*(buffer + i));
		push_back(&stash, new);
		i++;	
	}
	return (stash);
}

char *create_line(t_list **stash)
{
	char	*line;
	int	size_stash;
	int	i;
	t_list	*elem;
	
	size_stash = ft_lstsize(*stash);
	line = malloc(sizeof(char) * (size_stash + 1));
	if (!line)
		return (NULL);
	elem = *stash;
	i = 0;
	while (i < size_stash && elem->content != '\n')
	{
		*(line + i++) = elem->content;
		pop_front(stash);
		elem = *stash;
	}	
	if (elem && elem->content == '\n')
	{
		*(line + i++) = '\n';
		pop_front(stash);
	}
	*(line + i) = '\0';
	return (line);
}

char	*create_buffer()
{
	size_t i;
	char	*buffer;
	
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
		*(buffer + i++) = '0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static	t_list *stash = NULL;
	char	*buffer;
	char	*line;
	int	octetsRead;
	
	if (fd < 0)
		return (NULL);
	buffer = create_buffer();
	if (!buffer)
		return (NULL);
	octetsRead = 1;
	while (octetsRead > 0 && !is_contains_nl(buffer))
	{
		octetsRead = read(fd, buffer, BUFFER_SIZE);	
		if (octetsRead < 0)
		{
			free(buffer);
			return (NULL);
		}
		stash = create_stash(buffer, stash, octetsRead);
	}
	line = NULL;
	if (stash && (is_contains_nl(buffer) || octetsRead == 0))
		line = create_line(&stash);
	free(buffer);
	return (line);
}
