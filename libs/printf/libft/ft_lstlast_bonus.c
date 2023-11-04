/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:30:54 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/09 22:32:42 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*successor;
	t_list	*current;

	current = lst;
	if (lst == NULL)
		return (NULL);
	else
	{
		while (current->next != NULL)
		{
			successor = current->next;
			current = successor;
		}
	}
	return (current);
}
// #include <stdio.h>
// int main() {
//     // Initialize an empty list
// 	int a = 1;
// 	int b = 2;
// 	int c = 3;
//     t_list *head = NULL;
//     // Create new nodes
//     t_list *node1 = ft_lstnew(&a);
//     t_list *node2 = ft_lstnew(&b);
// 	t_list *node3 = ft_lstnew(&c);
//     // Add nodes to the list
//     ft_lstadd_back(&head, node1);
//     ft_lstadd_back(&head, node2);
//     ft_lstadd_back(&head, node3);
//     // Print the list to check the order
//     printf("List after adding nodes to the back:\n");
// 	t_list *last = ft_lstlast(head);
// 	printf("last content: %d", *((int*)last->content));
//     // Clean up memory
//     free(node1);
//     free(node2);
//     free(node3);
//     return 0;
// }
