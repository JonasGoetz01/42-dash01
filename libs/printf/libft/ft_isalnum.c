/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:29:31 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 11:29:32 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
			|| ('0' <= c && '9' >= c)))
		return (0);
	return (1);
}
// #include <stdio.h>
// int	main(void)
// {
//     printf("ft_isalnum: expected output: 1 | %d\n", ft_isalnum('a'));
//     printf("ft_isalnum: expected output: 1 | %d\n", ft_isalnum('Z'));
//     printf("ft_isalnum: expected output: 1 | %d\n", ft_isalnum('0'));
//     printf("ft_isalnum: expected output: 1 | %d\n", ft_isalnum('9'));
//     printf("ft_isalnum: expected output: 0 | %d\n", ft_isalnum(' '));
//     printf("ft_isalnum: expected output: 0 | %d\n", ft_isalnum('\n'));
//     printf("ft_isalnum: expected output: 0 | %d\n", ft_isalnum('\t'));
//     printf("ft_isalnum: expected output: 0 | %d\n", ft_isalnum('$'));
//     printf("ft_isalnum: expected output: 0 | %d\n", ft_isalnum('['));
//     printf("ft_isalnum: expected output: 0 | %d\n", ft_isalnum('{'));
//     return (0);
// }
