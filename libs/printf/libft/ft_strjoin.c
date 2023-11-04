/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/16 16:22:36 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	len1 = 0;
	while (s1[len1])
	{
		result[len1] = s1[len1];
		len1++;
	}
	len2 = 0;
	while (s2[len2])
	{
		result[len1 + len2] = s2[len2];
		len2++;
	}
	result[len1 + len2] = '\0';
	return (result);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int	main(void)
// {
//     char *str1 = "Hello, ";
//     char *str2 = "World!";
//     char *str3 = "";
//     char *str4 = "12345";
//     char *str5 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
//     char *str7 = "0123456789";
//     char *str8 = "abcdefghijklmnopqrstuvwxyz";
//     char *str9 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     char *str10 = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
//     char *result1 = ft_strjoin(str1, str2);
//     char *result2 = ft_strjoin(str3, str3);
//     char *result3 = ft_strjoin(str4, str4);
//     char *result4 = ft_strjoin(str5, str6);
//     char *result5 = ft_strjoin(str7, str8);
//     char *result6 = ft_strjoin(str8, str9);
//     char *result7 = ft_strjoin(str9, str10);
//     char *result8 = ft_strjoin(str10, str1);
//     char *result9 = ft_strjoin(str2, str3);
//     char *result10 = ft_strjoin(str3, str2);
//     printf("ft_strjoin: expected output: Hello, World! | %s\n", result1);
//     printf("ft_strjoin: expected output:  | %s\n", result2);
//     printf("ft_strjoin: expected output: 1234512345 | %s\n", result3);
//     printf("ft_strjoin: expected output: World! | %s\n", result9);
//     printf("ft_strjoin: expected output: World! | %s\n", result10);
//     free(result1);
//     free(result2);
//     free(result3);
//     free(result4);
//     free(result5);
//     free(result6);
//     free(result7);
//     free(result8);
//     free(result9);
//     free(result10);
//     return (0);
// }
