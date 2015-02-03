/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:06:25 by jibanez           #+#    #+#             */
/*   Updated: 2013/11/21 18:18:10 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*c;

	c = s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}