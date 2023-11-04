/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:30:36 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/08 11:30:37 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*successor;

	while (*lst != NULL)
	{
		successor = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = successor;
	}
	free(*lst);
	*lst = NULL;
}
// #include <stdio.h>
// #include <stdlib.h>
// void	delete(void *p)
// {
// 	unsigned char	*point;

// 	point = NULL;
// 	p = (void *)point;
// }
// void print_list(t_list *lst) {
//     t_list *current = lst;
//     while (current != NULL) {
//         printf("%d -> ", *((int*)current->content));
//         current = current->next;
//     }
//     printf("NULL\n");
// }
// int main() {
//     // Initialize an empty list
//     int a = 1;
//     int b = 2;
//     int c = 3;
//     t_list *head = NULL;
//     // Create new nodes
//     t_list *node1 = ft_lstnew(&a);
//     t_list *node2 = ft_lstnew(&b);
//     t_list *node3 = ft_lstnew(&c);
//     // Add nodes to the list
//     ft_lstadd_back(&head, node1);
//     ft_lstadd_back(&head, node2);
//     ft_lstadd_back(&head, node3);
//     // Print the list before clearing
//     printf("List before clearing:\n");
//     print_list(head);
//     // Clear the list and free memory
//     ft_lstclear(&head, delete);
//     // Print the list after clearing (should be NULL)
//     printf("List after clearing:\n");
//     print_list(head);
//     return 0;
// }
