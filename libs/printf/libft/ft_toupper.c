/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:34:12 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 11:34:13 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
// #include <stdio.h>
// int	main(void)
// {
//     printf("ft_toupper: expected output: A | %c\n", ft_toupper('a'));
//     printf("ft_toupper: expected output: Z | %c\n", ft_toupper('z'));
//     printf("ft_toupper: expected output: 1 | %c\n", ft_toupper('1'));
//     printf("ft_toupper: expected output: $ | %c\n", ft_toupper('$'));
//     printf("ft_toupper: expected output: \\n | %cend\n", ft_toupper('\n'));
//     printf("ft_toupper: expected output: \\t | %cend\n", ft_toupper('\t'));
//     return (0);
// }
