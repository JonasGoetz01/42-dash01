/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:30:17 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/11 18:39:06 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*result;
	int		start;

	nb = (long) n;
	len = ft_numlen(nb) + 1;
	start = (nb < 0);
	if (nb < 0)
		nb *= -1;
	result = (char *)malloc(len * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	result[len - 1] = '\0';
	len -= 2;
	while (len >= start)
	{
		result[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int	main(void)
// {
//     int num1 = 12345 - 300;
//     int num2 = -1;
//     int num3 = 0;
//     int num4 = -2147483648;
//     int num5 = 2147483647;
//     char *result1 = ft_itoa(num1);
//     char *result2 = ft_itoa(num2);
//     char *result3 = ft_itoa(num3);
//     char *result4 = ft_itoa(num4);
//     char *result5 = ft_itoa(num5);
//     printf("ft_itoa: expected output: \"12045\" | \"%s\"\n", result1);
//     printf("ft_itoa: expected output: \"-6789\" | \"%s\"\n", result2);
//     printf("ft_itoa: expected output: \"0\" | \"%s\"\n", result3);
//     printf("ft_itoa: expected output: \"-2147483648\" | \"%s\"\n", result4);
//     printf("ft_itoa: expected output: \"2147483647\" | \"%s\"\n", result5);
//     free(result1);
//     free(result2);
//     free(result3);
//     free(result4);
//     free(result5);
//     return (0);
// }
