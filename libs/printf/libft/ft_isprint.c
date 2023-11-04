/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:30:12 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 11:30:13 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
// #include <stdio.h>
// int	main(void)
// {
//     printf("ft_isprint: expected output: 1 | %d\n", ft_isprint(' '));
//     printf("ft_isprint: expected output: 1 | %d\n", ft_isprint('A'));
//     printf("ft_isprint: expected output: 1 | %d\n", ft_isprint('z'));
//     printf("ft_isprint: expected output: 1 | %d\n", ft_isprint('~'));
//     printf("ft_isprint: expected output: 0 | %d\n", ft_isprint('\t'));
//     printf("ft_isprint: expected output: 0 | %d\n", ft_isprint('\n'));
//     printf("ft_isprint: expected output: 0 | %d\n", ft_isprint('\r'));
//     printf("ft_isprint: expected output: 0 | %d\n", ft_isprint('\b'));
//     printf("ft_isprint: expected output: 0 | %d\n", ft_isprint('\v'));
//     printf("ft_isprint: expected output: 0 | %d\n", ft_isprint('\f'));
//     return (0);
// }
