/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:13:16 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/03 17:31:05 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = b;
	while (i < len)
		copy[i++] = c;
	return (copy);
}
