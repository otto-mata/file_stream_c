/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 02:03:51 by tblochet          #+#    #+#             */
/*   Updated: 2025/04/22 02:19:21 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stream.h>

static t_pos	get_total_file_size(const char *path, int *o_flag)
{
	int		fd;
	t_pos	sz;
	int		offset;
	char	buffer[RD_DFL_SZ];

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		*o_flag = 1;
		return (0);
	}
	sz = 0;
	offset = -1;
	while (offset)
	{
		offset = read(fd, buffer, RD_DFL_SZ);
		if (offset < 0)
		{
			*o_flag = 2;
			return (0);
		}
		sz += offset;
	}
	close(fd);
	return (sz);
}

static void	*local_destroy(t_stream **fstream)
{
	if (*fstream && (*fstream)->buffer)
		free((*f)->buffer);
	free(*fstream);
	return (0);
}

t_stream	*stream_open(const char *path)
{
	t_stream	*f;
	int			fd;
	int			flag;

	f = new_stream();
	if (!f)
		return (0);
	flag = 0;
	f->end = get_total_file_size(path, &flag);
	if (flag)
		return (local_destroy(&f));
	f->buffer = malloc((f->end + 1) * sizeof(t_byte));
	if (!f->buffer)
		return (local_destroy(&f));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (local_destroy(&f));
	if (read(fd, f->buffer, f->end) < 0)
		return (local_destroy(&f));
	f->buffer[f->end] = 0;
	return (f);
}
