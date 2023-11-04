/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:29:54 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 11:29:56 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
// #include <stdio.h>
// int	ft_isascii(int c);
// int	main(void)
// {
//     printf("ft_isascii: expected output: 1 | %d\n", ft_isascii(0));
//     printf("ft_isascii: expected output: 1 | %d\n", ft_isascii(32));
//     printf("ft_isascii: expected output: 1 | %d\n", ft_isascii(64));
//     printf("ft_isascii: expected output: 1 | %d\n", ft_isascii(126));
//     printf("ft_isascii: expected output: 0 | %d\n", ft_isascii(-1));
//     printf("ft_isascii: expected output: 0 | %d\n", ft_isascii(128));
//     printf("ft_isascii: expected output: 0 | %d\n", ft_isascii(255));
//     return (0);
// }
