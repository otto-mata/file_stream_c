/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 02:03:43 by tblochet          #+#    #+#             */
/*   Updated: 2025/04/22 03:17:19 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stream.h>

static void	seek_from_start(t_stream *f, t_offset pos)
{
	if (!f)
		return ;
	if (f->wrapping)
		pos = pos % f->end;
	f->current = pos;
}

static void	seek_from_current(t_stream *f, t_offset pos)
{
	if (!f)
		return ;
	if (f->wrapping)
	{
		if (f->current + pos > f->end)
			pos -= f->end;
		else if (f->current + pos < 0)
			pos = f->end - pos;
		else
			pos = f->current + pos;
	}
	else
	{
		if (f->current + pos > f->end)
			pos = f->end;
		else if (f->current + pos < 0)
			pos = f->start;
		else
			pos = f->current->pos;
	}
	f->current = pos;
}

static void	seek_from_end(t_stream *f, t_offset pos)
{
	if (!f)
		return ;
	if (f->wrapping)
	{
		if (pos > 0)
			pos = pos % f->end;
	}
	else
	{
		if (pos > 0)
			pos = 0;
		pos = f->end + pos;
	}
	f->current = pos;
}

t_pos	stream_seek(t_stream *stream, t_offset pos, t_seek_ref whence)
{
	if (!stream)
		return (0);
	if (whence == STREAM_START)
	{
		if (pos < 0)
			pos = 0;
		if (pos > stream->end)
			pos = stream->end;
		stream->current = pos;
	}
	else if (whence == STREAM_CURRENT)
	{
		if (stream->current + pos < 0)
			stream->current = stream->start;
		else if (stream->current + pos > stream->end)
			stream->current = stream->end;
		else
			stream->current += pos;
	}
	else
	{
		if (pos > 0)
			pos = 0;
		else if (stream->end + pos < stream->start)
			stream->current = stream->start;
		else
			stream->current = stream->end + pos;
	}
	return (stream->current);
}
