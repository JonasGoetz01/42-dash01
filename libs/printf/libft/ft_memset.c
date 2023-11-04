/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:31:50 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 11:31:51 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return ((void *)b);
}
// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	str[10] = "abcdefg";
// 	memset(str, '-', 5);
// 	printf("%s\n", str);
// 	char *old = ft_memset(str, '+', 5);
// 	printf("%s\n", old);
// 	return (0);
// }
