/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:35:35 by sjones            #+#    #+#             */
/*   Updated: 2017/05/07 21:35:53 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prox_eyes.h"

void	init_prox(t_prox *pr, char **av)
{
	welcome();
	bzero((char*)&pr->serv_addr, sizeof(pr->serv_addr));
	bzero((char*)&pr->cli_addr, sizeof(pr->cli_addr));
	pr->serv_addr.sin_family = AF_INET;
	pr->serv_addr.sin_port = htons(atoi(av[1]));
	pr->serv_addr.sin_addr.s_addr = INADDR_ANY;
	pr->sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (pr->sockfd < 0)
		error("Problem initializing socket");
	if (bind(pr->sockfd, (struct sockaddr*)&pr->serv_addr,
				sizeof(pr->serv_addr)) < 0)
		error("Error on binding");
	listen(pr->sockfd, 50);
	pr->clilen = sizeof(pr->cli_addr);
}
