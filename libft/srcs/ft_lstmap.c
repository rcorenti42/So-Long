/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:42:02 by rcorenti          #+#    #+#             */
/*   Updated: 2021/08/13 05:42:03 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *)/*, void (*del)(void *)*/)
{
    t_list *tmp;
    t_list *new;
    t_list *result;

    new = NULL;
    while (lst)
    {
        tmp = f(lst);
        if (!new)
        {
            new = tmp;
            result = new;
            lst->next = NULL;
        }
        else
        {
            new->next = tmp;
            tmp->next = NULL;
            new = new->next;
        }
        lst = lst->next;
    }
    return (result);
}