/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:33:28 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/16 16:29:57 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	rev_i;

	if (!s)
		return (NULL);
	rev_i = ft_strlen(s);
	while (rev_i >= 0)
	{
		if (s[rev_i] == (char)c)
			return ((char *)&s[rev_i]);
		rev_i--;
	}
	return (NULL);
}
