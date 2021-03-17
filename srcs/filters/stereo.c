/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:17:59 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/17 07:32:33 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"



void		anaglyph_effect(int *img)
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
