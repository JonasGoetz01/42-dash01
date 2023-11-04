/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:30:04 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 11:30:07 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (!('0' <= c && '9' >= c))
		return (0);
	return (1);
}
// #include <stdio.h>
// #include <unistd.h>
// int	main(void)
// {
// 	printf("%i\n", ft_isdigit('0'));
// 	printf("%i\n", ft_isdigit(0));
// 	printf("%i\n", ft_isdigit('a'));
// }
