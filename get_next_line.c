/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:46:33 by iusantos          #+#    #+#             */
/*   Updated: 2023/06/01 17:11:25 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

t_node	*new_data_node(void)
{
	t_node	*new_node_ptr;
	
	new_node_ptr = (t_node *) malloc(sizeof(t_node));
	if (!new_node_ptr)
		return NULL;
	new_node_ptr->content = (char *)malloc(BUFFER_SIZE + 1);
	new_node_ptr->next = NULL;
	return (new_node_ptr);
}

void	node_addback(t_node **head, t_node *new)
{
	t_node	*last;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

// -1 if there is no newline. If found, return index on last node's content.
int	find_next_newline(t_node **head)
{
	t_node	*node;
	int	counter;

	node = *head;
	if (*head == NULL)
		return (-1);
	while (1)
	{
		counter = 0;
		while (node->content[counter] != '\0')
		{
			if (node->content[counter] == '\n')
			{
				node->content = &(node->content[counter]);
				return (counter);
			}
			counter++;
		}
		if (node->next == NULL)
			break;
		node = node->next;
	}
	return (-1);
}


char	*get_next_line(int fd)
{
	t_node	*node_recent_read;
	static t_control	control;

	if (fd < 0)
		return (NULL);
	if (!control.head)
	{
		control.head = calloc(sizeof(t_node *), 1);
	}
	while (find_next_newline(control.head) < 0)
	{
	node_recent_read = new_data_node();
	node_recent_read->content[read(fd, node_recent_read->content, BUFFER_SIZE)] = '\0';
	node_addback(control.head, node_recent_read);
	control.number_of_bfnodes++;
	}
	//chamar funcao para retornar string até aqui. gravar estado para proxima run.
	return NULL;
}

