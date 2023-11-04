/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:33:36 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/16 16:33:18 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	if (ft_strlen(set) == 0)
		return (0);
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	rev_i;
	size_t	j;
	char	*res;
	size_t	total;

	if (!s1)
		return (NULL);
	i = 0;
	rev_i = ft_strlen(s1) - (ft_strlen > 0);
	while (s1[i] && in_set(s1[i], set))
		i++;
	while (rev_i > 0 && s1[rev_i] && in_set(s1[rev_i], set))
		rev_i--;
	total = 0;
	if (rev_i > i)
		total = rev_i - i + 1;
	res = (char *)malloc((total + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (i <= rev_i && rev_i > 0)
		res[j++] = s1[i++];
	res[j] = '\0';
	return (res);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int	main(void)
// {
// 	char *str1 = "lorem \n ipsum \t dolor \n sit \t amet";
// 	char *str2 = "lorem ipsum dolor sit amet";
// 	char *str3 = "";
// 	char *str4 = "stwHellostw";
// 	char *str5 = "NoSpacesHere";
// 	char *result1 = ft_strtrim(str1, " ");
// 	char *result2 = ft_strtrim(str2, "te");
// 	char *result3 = ft_strtrim(str3, "");
// 	char *result4 = ft_strtrim(str4, "stw");
// 	char *result5 = ft_strtrim(str5, "No");
// 	printf("expected output: \"Hello, World!   n\" | \"%s\"\n", result1);
// 	printf("expected output: \"12345\" | \"%s\"\n", result2);
// 	printf("expected output: \"Lorem ipsum\" | \"%s\"\n", result3);
// 	printf("expected output: \"Hello\" | \"%s\"\n", result4);
// 	printf("expected output: \"NoSpacesHere\" | \"%s\"\n", result5);
// 	free(result1);
// 	free(result2);
// 	free(result3);
// 	free(result4);
// 	free(result5);
// 	return (0);
// }
