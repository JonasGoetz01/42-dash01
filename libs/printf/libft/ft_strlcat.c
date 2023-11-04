/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:53 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/16 16:24:02 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	if (!dst && dstsize == 0)
		return (0);
	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	i = 0;
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	while (src[i] != '\0' && len_dst + i < dstsize - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return ((unsigned int)(len_dst + len_src));
}
// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>
// int	main(void)
// {
// 	char	dst1[20] = "Hello";
// 	char	dst2[20] = "Hello";
// 	char	*src = "34njnscjsn!";
// 	unsigned int	i = ft_strlcat(dst1, src, 20);
// 	printf("%d\n", i);
// 	printf("%s\n", dst1);
// 	unsigned int	j = strlcat(dst2, src, 20);
// 	printf("%d\n", j);
// 	printf("%s\n", dst2);
// 	return (0);
// }
