/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:36:10 by sjones            #+#    #+#             */
/*   Updated: 2017/05/07 21:36:26 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prox_eyes.h"

int		main(int ac, char **av)
{
	t_prox pr;

	if (ac != 2)
		error("./prox_eyes <port>");
	init_prox(&pr, av);
	while (1)
	{
		accept_new(&pr);
		pr.pid = fork();
		if (pr.pid == 0)
			child_fun(&pr);
		else
			close(pr.newsockfd);
	}
	return (0);
}
