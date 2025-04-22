/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:59:33 by tblochet          #+#    #+#             */
/*   Updated: 2025/04/22 02:19:52 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stream.h>

t_stream	*new_strean(void)
{
	t_stream	*obj;

	obj = malloc(sizeof(*obj));
	if (!obj)
		return (0);
	obj->buffer = 0;
	obj->start = 0;
	obj->end = 0;
	obj->current = 0;
	obj->endiannes = LITTLE;
	return (obj);
}
