/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:37:50 by iusantos          #+#    #+#             */
/*   Updated: 2023/06/01 17:03:10 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 4

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}	t_node;

typedef struct s_control
{
	t_node	**head;
	int	number_of_bfnodes;
	int	position_of_next_newline;
	int	prev_newline;
}	t_control;

char	*get_next_line(int fd);

#endif
