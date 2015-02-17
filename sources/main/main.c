/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:31:40 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/17 15:28:20 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera.h"


int			main(void)
{
	t_camera	camera;

	camera = get_new_camera(800, 600, 90);
	ft_putnbr(camera.viewplane_width);
	return (0);
}
