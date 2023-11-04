/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:59 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/16 16:27:29 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[i] != '\0')
	{
		len++;
		i++;
	}
	if (size > 0)
	{
		i = 0;
		while (i < len && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>
// int	main()
// {
// 	char	str1[] = "abcde78";
// 	char	str2[6];
// 	char	str3[6];
// 	unsigned int	l = ft_strlcpy(&str2[0], &str1[0], 6);
// 	unsigned int	m = strlcpy(&str3[0], &str1[0], 6);
// 	printf("%s\n", str2);
// 	write(1, (char[1]){l + '0'}, 1);
// 	printf("\n");
// 	printf("%s\n", str3);
// 	write(1, (char[1]){m + '0'}, 1);
// }
