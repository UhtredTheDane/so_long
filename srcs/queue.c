/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:23:34 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 18:55:31 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/queue.h"

/*
 * Description:
 *
 * Allocates and returns a new node.
 * The member variable content is initialized with the value of the parameter
 * content. The variable next is initialized to NULL.
 */

t_queue	*ft_queuenew(char *content)
{
	t_queue	*res;

	res = malloc(sizeof(t_queue));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

void	queue_add(t_queue **queue, t_queue *new)
{
	t_queue	*elem;

	if (queue)
	{
		if (!*queue)
			*queue = new;
		else
		{
			elem = *queue;
			while (elem->next)
				elem = elem->next;
			elem->next = new;
		}
	}
}

void	queue_pop(t_queue **queue)
{
	t_queue	*elem;

	if (queue && *queue)
	{
		elem = (*queue)->next;
		free((*queue)->content);
		free(*queue);
		*queue = elem;
	}
}

/*
 * Description:
 *
 * Counts the number of nodes in a list.
 */

int	ft_queuesize(t_queue *queue)
{
	int	size;

	size = 0;
	while (queue)
	{
		size++;
		queue = queue->next;
	}
	return (size);
}
