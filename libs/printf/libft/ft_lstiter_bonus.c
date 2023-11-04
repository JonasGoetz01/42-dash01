/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:30:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 21:23:34 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// #include <stdio.h>
// static void	print_elem(void *)
// {
//     printf("%s\n", (char *)elem->content);
// }
// int	main(void)
// {
//     t_list	*lst;
//     t_list	*elem1;
//     t_list	*elem2;
//     t_list	*elem3;
//     elem1 = ft_lstnew("Hello", 6);
//     elem2 = ft_lstnew("World", 6);
//     elem3 = ft_lstnew("!", 2);
//     elem1->next = elem2;
//     elem2->next = elem3;
//     lst = elem1;
//     ft_lstiter(lst, &print_elem);
//     return (0);
// }
