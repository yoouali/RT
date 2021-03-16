/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:17:59 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/16 15:20:35 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

/*void	img_red(int *red, int *img)
{
	t_vec	rgb;
	int		i;

	i = 0;
	while (i < W * H)
	{
		rgb.x = 255 / 2;
		rgb.y = ((img[i] >> 8) % 256) / 2;
		rgb.z = (img[i] % 256) / 2;
		red[i] = ((int)rgb.x << 16) + ((int)rgb.y << 8) + rgb.z;
		i++;
	}
}

void	img_green(int *gren, int *img)
{
	t_vec	rgb;
	int		i;

	i = 0;
	while (i < W * H)
	{
		rgb.x = (img[i] >> 16) / 2;
		rgb.y = 255 / 2;
		rgb.z = (img[i] % 256) / 2;
		gren[i] = ((int)rgb.x << 16) + ((int)rgb.y << 8) + rgb.z;
		i++;
	}
}

void	merge_3d(int *img, int *green, int *red)
{
	int		i;

	i = 0;
	while (i < W * H)
	{
		if (i % 2 == 0)
			img[i] = green[i];
		else if (img[i - 10])
			img[i - 10] = red[i];
		i++;
	}
	free(green);
	free(red);
}

void	img_ddd(int *img)
{
	int *red;
	int *green;
	int	k;
	int	i;

	k = W;
	i = 0;
	red = (int *)malloc(W * H * 4);
	green = (int *)malloc(W * H * 4);
	img_green(green, img);
	img_red(red, img);
	merge_3d(img, green, red);
	while (i < W * H)
	{
		if (i > k - 10 && i < k + 10)
			img[i] = 0;
		if (i > k + 10)
			k = k + W;
		i++;
	}
}*/

void		img_ddd(int *img)
{
	t_ind		ind;
	t_col		col;
	int			*data1;
	int			*data2;

	data1 = malloc(sizeof(int) * W * H);
	data2 = malloc(sizeof(int) * W * H);
	ind.i = 0;
	while (ind.i < W *H)
	{
		data1[ind.i]  = rgb_to_int_yatak(alpha_compositing(int_to_rgb_yatak(img[ind.i]), (t_col){0.00,0.00,255.00}, 1.0, 0.5));
		data2[ind.i]  = rgb_to_int_yatak(alpha_compositing(int_to_rgb_yatak(img[ind.i]), (t_col){255.00,0.00,0.00}, 1.0, 0.5));
		ind.i++;
	}
	ind.j = 0;
	while (ind.j < H)
	{
		ind.i = 0;
		while (ind.i < W)
		{
			col = int_to_rgb_yatak(img[W * ind.j + ind.i]);
			if (ind.i < 20 || ind.i > W -  20)
			{
				img[W * ind.j + ind.i] = 0;
			}
			else if (ind.i % 2 == 0)
			{
				img[W * ind.j + ind.i] = data2[W * ind.j + ind.i - 10];
			}
			else if (ind.i + 20 < W)
			{	
				img[W * ind.j + ind.i] = data1[W * ind.j + ind.i + 10];
			}
			ind.i++;
		}
		ind.j++;
	}
}
