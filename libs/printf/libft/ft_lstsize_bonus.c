/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:31:21 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 11:31:22 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*successor;
	int		len;

	len = 0;
	while (lst != NULL)
	{
		successor = lst->next;
		lst = successor;
		len++;
	}
	return (len);
}
// #include <stdio.h>
// int	main(void)
// {
// 	 t_list	*lst;
// 	 t_list	*elem1;
// 	 t_list	*elem2;
// 	 t_list	*elem3;
// 	 elem1 = ft_lstnew("Hello");
// 	 elem2 = ft_lstnew("World");
// 	 elem3 = ft_lstnew("!");
// 	 elem1->next = elem2;
// 	 elem2->next = elem3;
// 	 lst = elem1;
// 	 printf("%d\n", ft_lstsize(lst));
// 	 return (0);
// }
