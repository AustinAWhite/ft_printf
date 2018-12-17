/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:29:19 by awhite            #+#    #+#             */
/*   Updated: 2018/10/26 13:29:21 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	while (*s2 && n > 0)
	{
		s1[i++] = *s2;
		s2++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}