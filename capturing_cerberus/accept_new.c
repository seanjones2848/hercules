/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:15:16 by sjones            #+#    #+#             */
/*   Updated: 2017/05/07 23:11:44 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prox_eyes.h"

void	accept_new(t_prox *pr)
{
	pr->newsockfd = accept(pr->sockfd, (struct sockaddr*)&pr->cli_addr,
			(socklen_t*)&pr->clilen);
	if (pr->newsockfd < 0)
		error("Problem accepting connection");
}
