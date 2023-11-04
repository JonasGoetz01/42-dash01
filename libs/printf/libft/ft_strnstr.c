/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:33:22 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/13 13:24:22 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_j;

	if (!haystack && len == 0)
		return (NULL);
	i = 0;
	len_j = 0;
	while (needle[len_j] != '\0')
		len_j++;
	if (len_j == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && i + j < len)
			j++;
		if (j == len_j)
			return ((char *)(&haystack[i]));
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
//     char str1[] = "Hello, World!";
//     char str2[] = "This is a test string";
//     char *result1_ft = ft_strnstr(str1, "World", sizeof(str1));
//     char *result1_str = strnstr(str1, "World", sizeof(str1));
//     char *result2_ft = ft_strnstr(str2, "test", sizeof(str2));
//     char *result2_str = strnstr(str2, "test", sizeof(str2));
//     printf("ft_strnstr: \"World!\" | \"%s\"\n", result1_ft);
//     printf("strnstr: \"World!\" | \"%s\"\n", result1_str);
//     printf("ft_strnstr: \"test string\" | \"%s\"\n", result2_ft);
//     printf("strnstr: \"test string\" | \"%s\"\n", result2_str);
//     return (0);
// }
