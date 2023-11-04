/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:34:06 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 11:34:07 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
// #include <stdio.h>
// int	main(void)
// {
//     printf("ft_tolower: expected output: a | %c\n", ft_tolower('A'));
//     printf("ft_tolower: expected output: z | %c\n", ft_tolower('Z'));
//     printf("ft_tolower: expected output: 1 | %c\n", ft_tolower('1'));
//     printf("ft_tolower: expected output: $ | %c\n", ft_tolower('$'));
//     printf("ft_tolower: expected output: \\n | %cend\n", ft_tolower('\n'));
//     printf("ft_tolower: expected output: \\t | %cend\n", ft_tolower('\t'));
//     return (0);
// }
