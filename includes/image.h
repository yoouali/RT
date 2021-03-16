/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:23:39 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/16 14:50:36 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include <math.h>
# include <time.h>
# include <stdlib.h>

typedef	struct	s_vec
{
	float x;
	float y;
	float z;
}				t_vec;

typedef	struct	s_clr
{
	int	r;
	int	g;
	int	b;
}				t_clr;

typedef	struct	s_z
{
	int	i;
	int	j;
	int	d;
	int	dd;
}				t_z;

typedef	struct	s_ind
{
	int		i;
	int		j;
}				t_ind;


typedef	struct	s_col
{
	double	r;
	double	g;
	double	b;
}				t_col;


typedef struct	s_image
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_image;

int         rgb_to_int_yatak(t_col col);
t_col       int_to_rgb_yatak(int val);
t_col       alpha_compositing(t_col c1, t_col c2, double a1, double a2);
void			image_create(int *img);
void			img_sepia(int *img);
void			img_noise(int *img);
void			img_neg(int *img);
void			img_grey(int *img);
void			antialiasing(int *img);
void			ft_cartoon(int *img);
void			img_ddd(int *img);
void			blurr(int *img);
#endif
