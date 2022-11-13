/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_queue_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:11:44 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/13 14:46:50y yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lst_queue_clear(t_queue **queue)
{
	t_queue	*tmp;

	if (!queue || !*queue)
		return ;
	while (*queue)
	{
		tmp = (*queue)->next;
		free(*queue);
		*queue = tmp;
	}
	return ;
}

t_queue	*lst_queue_last(t_queue *queue)
{
	if (!queue)
		return (NULL);
	while (queue->next)
		queue = queue->next;
	return (queue);
}

void	lst_queue_dequeue(t_queue **queue)
{
	t_queue	*tmp;

	if (!queue || !*queue)
		return ;
	tmp = (*queue)->next;
	free(*queue);
	*queue = tmp;
	return ;
}

void	lst_queue_enqueue(t_queue **queue, t_queue *next)
{
	t_queue	*last;

	if (!queue || !next)
		return ;
	if (!*queue)
	{
		*queue = next;
		return ;
	}
	last = lst_queue_last(*queue);
	last->next = next;
	return ;
}

t_queue	*lst_queue_new(long long x, long long y)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->x = x;
	queue->y = y;
	queue->next = NULL;
	return (queue);
}


size_t	lst_queue_size(t_queue *queue)
{
	size_t	i;

	i = 0;
	while (queue)
	{
		i++;
		queue = queue->next;
	}
	return (i);
}
