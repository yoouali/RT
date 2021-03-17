/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartoon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:09:12 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/17 16:19:25 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int	*ft_tableu_color()
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 50);
	tab[0] = 0x78281f;
	tab[1] = 0xa93226;
	tab[2] = 0xc0392b;
	tab[3] = 0xcd6155;
	tab[4] = 0xfdedec;
	tab[5] = 0x4a235a;
	tab[6] = 0x884ea0;
	tab[7] = 0x9b59b6;
	tab[8] = 0x9d7ac5;
	tab[9] = 0xf4ecf7;
	tab[10] = 0x1b4f72;
	tab[11] = 0x884ea0;
	tab[12] = 0x2980b9;
	tab[13] = 0x5499c7;
	tab[14] = 0xebf5fb;
	tab[15] = 0x0b5345;
	tab[16] = 0x884ea0;
	tab[17] = 0x1abc9c;
	tab[18] = 0x48c9b0;
	tab[19] = 0xe8f6f3;
	tab[20] = 0x186a3b;
	tab[21] = 0x884ea0;
	tab[22] = 0x27ae60;
	tab[23] = 0x52be80;
	tab[24] = 0xeafaf1;
	tab[25] = 0xfef5e7;
	tab[26] = 0xd4ac0d;
	tab[27] = 0xf1c40f;
	tab[28] = 0xf4d03f;
	tab[29] = 0x7e5109;
	tab[30] = 0xfbeee6;
	tab[31] = 0xca6f1e;
	tab[32] = 0xe67e22;
	tab[33] = 0xeb984e;
	tab[34] = 0x6e2c00;
	tab[35] = 0xf8f9f9;
	tab[36] = 0xd0d3d4;
	tab[37] = 0xecf0f1;
	tab[38] = 0xf0f3f4;
	tab[39] = 0x626567;
	tab[40] = 0xf2f4f4;
	tab[41] = 0x839192;
	tab[42] = 0x95a5a6;
	tab[43] = 0xaab7b8;
	tab[44] = 0x424949;
	tab[45] = 0xeaecee;
	tab[46] = 0x2e4053;
	tab[47] = 0x2c3e50;
	tab[48] = 0x5d6d7e;
	tab[49] = 0x17202a;
	return (tab);
}

void	cartoon_effect(int *img)
{
	int		*tab;
	t_ind	ind;
	t_ind	dist;
	t_col	col1;
	t_col	col2;

	tab =ft_tableu_color();
	ind.i = -1;
	while (++ind.i < W * H)
	{
		if (img[ind.i] == 0)
			continue;
		col1 = int_to_rgb_yatak(img[ind.i]);
		dist.i = INFINITY;
		ind.j = 0;
		img[ind.i] = tab[ind.j];
		while (ind.j < 50)
		{
			col2 = int_to_rgb_yatak(tab[ind.j]);
			dist.j = sqrt(pow(col1.r - col2.r, 2) + pow(col1.g - col2.g, 2) + pow(col1.b - col2.b, 2));
			if (dist.j < dist.i)
			{
				dist.i = dist.j;
				img[ind.i] = tab[ind.j];
			}
			ind.j++;
		}
	}
	free(tab);
}