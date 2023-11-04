/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:33:56 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/16 16:33:34 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	s_len;
	char	*res;

	if (!s)
		return (NULL);
	j = 0;
	s_len = ft_strlen(s);
	while (j + start < s_len && s[j + start] && j < len)
		j++;
	res = (char *)malloc((j + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (start < s_len && s[start] && len > 0)
	{
		res[j++] = s[start++];
		len--;
	}
	res[j] = '\0';
	return (res);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char *res1 = ft_substr("Hello World!", 3, 5);
// 	char *res2 = ft_substr("Hello World!", 1, 20);
// 	char *res3 = ft_substr("", 3, 5);
// 	char *res4 = ft_substr("Hello World!", 0, 5);
// 	char *res5 = ft_substr("Hello World!", 0, 1);
// 	printf("1|%s|\n", res1);
// 	printf("2|%s|\n", res2);
// 	printf("3|%s|\n", res3);
// 	printf("4|%s|\n", res4);
// 	printf("5|%s|\n", res5);
// 	return (0);
// }
