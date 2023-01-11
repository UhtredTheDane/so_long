/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:23:43 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 05:13:24 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct s_queue
{
	char			*content;
	struct s_queue	*next;
}			t_queue;

t_queue	*ft_queuenew(char *content);
void	queue_add(t_queue **queue, t_queue *new);
void	queue_pop(t_queue **queue);
int		ft_queuesize(t_queue *queue);

#endif
