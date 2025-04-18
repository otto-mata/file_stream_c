/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:17:16 by ottomata          #+#    #+#             */
/*   Updated: 2025/03/29 22:32:19 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_H
# define STREAM_H

typedef struct s_stream			t_stream;
typedef unsigned char			t_byte;
typedef unsigned char			*t_bytes;
typedef long					t_offset;
typedef long					t_size;
typedef unsigned long			t_pos;
typedef enum e_seek_reference	t_seek_ref;
typedef enum e_endianness		t_endian;
typedef enum e_options			t_opt;
typedef char					t_i8;
typedef short					t_i16;
typedef int						t_i32;
typedef long					t_i64;

enum e_seek_reference
{
	STREAM_START = 0,
	STREAM_CURRENT,
	STREAM_END
};

enum e_endianness
{
	LITTLE,
	BIG
};

enum	e_options
{
	ENDIANNESS
};

struct	s_stream
{
	t_bytes		buffer;
	t_pos		start;
	t_pos		end;
	t_pos		current;
	t_endian	endianess;
};

t_pos			stream_seek(t_stream *stream, t_offset pos, t_seek_ref whence);
t_bytes			stream_read(t_stream *stream, t_size size);
t_size			stream_write(t_stream *stream, t_bytes data, t_size size);
t_stream		stream_open(const char *path);
int				stream_setopt(t_stream *stream, t_opt optname, void *optval, t_size optsz);

t_i8			stream_read8(t_stream *stream);
t_i16			stream_read16(t_stream *stream);
t_i32			stream_read32(t_stream *stream);
t_i64			stream_read64(t_stream *stream);

t_size			stream_write8(t_stream *stream, t_i8 value);
t_size			stream_write16(t_stream *stream, t_i16 value);
t_size			stream_write32(t_stream *stream, t_i32 value);
t_size			stream_write64(t_stream *stream, t_i64 value);

#endif
