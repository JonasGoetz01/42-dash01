/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:29:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 11:29:49 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')))
		return (0);
	return (1);
}
// #include <stdio.h>
// #include <unistd.h>
// int	main(void)
// {
// 	printf("%i\n", ft_isalpha('a'));
// 	printf("%i\n", ft_isalpha('3'));
// 	printf("%i\n", ft_isalpha('b'));
// }
