/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartoon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:09:12 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/16 17:15:14 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int	*ft_tableu_color()
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 50);
	tab[0] = 0xf2f7f5;
	tab[1] = 0xd98880;
	tab[2] = 0xc0392b;
	tab[3] = 0x922b21;
	tab[4] = 0x641e16;
	tab[5] = 0xe8daef;
	tab[6] = 0xBB8FCE;
	tab[7] = 0x8E44AD;
	tab[8] = 0x6C3483;
	tab[9] = 0x4A235A;
	tab[10] = 0xA9CCE3;
	tab[11] = 0x85C1E9;
	tab[12] = 0x3498DB;
	tab[13] = 0x2874A6;
	tab[14] = 0x154360;
	tab[15] = 0xD1F2EB;
	tab[16] = 0x76D7C4;
	tab[17] = 0x1ABC9C;
	tab[18] = 0x148F77;
	tab[19] = 0x0E6251;
	tab[20] = 0xD4EFDF;
	tab[21] = 0x58D68D;
	tab[22] = 0x2ECC71;
	tab[23] = 0x239B56;
	tab[24] = 0x186A3B;
	tab[25] = 0xFCF3CF;
	tab[26] = 0xF7DC6F;
	tab[27] = 0xF1C40F;
	tab[28] = 0xB7950B;
	tab[29] = 0x7D6608;
	tab[30] = 0xF6DDCC;
	tab[31] = 0xE59866;
	tab[32] = 0xD35400;
	tab[33] = 0xA04000;
	tab[34] = 0x6E2C00;
	tab[35] = 0xF2F3F4;
	tab[36] = 0xD7DBDD;
	tab[37] = 0xBDC3C7;
	tab[38] = 0x717D7E;
	tab[39] = 0xBFC9CA;
	tab[40] = 0x717D7E;
	tab[41] = 0x4D5656;
	tab[42] = 0x85929E;
	tab[43] = 0x34495E;
	tab[44] = 0x283747;
	tab[45] = 0x212F3C;
	tab[46] = 0x273746;
	tab[47] = 0x212F3D;
	tab[48] = 0x0B5345;
	tab[49] = 0xD68910;
	return (tab);
}

void	ft_cartoon(int *img)
{
	int		*tab;
	t_ind	ind;
	t_ind	dist;
	t_col	col1;
	t_col	col2;

	tab =ft_tableu_color();
	ind.i = 0;
	while (ind.i < W * H)
	{
		col1 = int_to_rgb_yatak(img[ind.i]);
		dist.i = INFINITY;
		ind.j = 0;
		img[ind.i] = tab[0];
		while (ind.j < 50)
		{
			col2 = int_to_rgb_yatak(tab[ind.j]);
			dist.j = pow(col1.r - col2.r, 2) + pow(col1.g - col2.g, 2) + pow(col1.b - col2.b, 2);
			dist.j = sqrt(dist.j);
			if (dist.j < dist.i)
			{
				dist.i = dist.j;
				img[ind.i] = tab[ind.j];
			}
			ind.j++;
		}
		ind.i++;
	}
}