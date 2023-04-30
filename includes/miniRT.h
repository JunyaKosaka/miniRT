/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:49 by jkosaka           #+#    #+#             */
/*   Updated: 2023/04/30 15:47:50 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# define WIN_SIZE 700
# define WIN_MID 350
# define DELTA_RATIO 0.6
# define WHITE 0xEEDDDD
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

/*  vector components include color  */
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	int		color;
	int		origin_color;
}	t_vector;

/*  minilibx image data  */
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/*  fdf information  */
typedef struct s_miniRT {
	t_data		img;
	void		*mlx;
	void		*win;
}	t_miniRT;

#endif  // MINIRT_H
