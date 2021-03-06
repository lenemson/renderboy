/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 11:08:39 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/15 15:01:24 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "mlx.h"

t_env		init_gfx(float res_x, float res_y, char *win_name)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, res_x, res_y, win_name);
	env.img = mlx_new_image(env.mlx, res_x, res_y);
	env.img_addr = mlx_get_data_addr(env.img, &(env.pixel_size),
			&(env.line_size), &(env.endian));
	env.pixel_size /= 8;
	if (env.endian == 0)
		env.put_pixel = put_pixel_l_endian;
	else
		env.put_pixel = put_pixel_b_endian;
	return (env);
}
