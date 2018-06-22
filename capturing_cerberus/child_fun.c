/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:18:14 by sjones            #+#    #+#             */
/*   Updated: 2017/05/07 21:19:32 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prox_eyes.h"

void	child_fun(t_prox *pr)
{
	init_child(pr);
	if (((strncmp(pr->t1, "GET", 3) == 0)) &&
			(strncmp(pr->t2, "http://", 7) == 0) &&
			((strncmp(pr->t3, "HTTP/1.1", 8) == 0) ||
			(strncmp(pr->t3, "HTTP/1.0", 8))))
		http_work(pr);
	else
		send(pr->newsockfd, "400 : BAD REQUEST\nONLY HTTP REQUESTS ALLOWED",
				18, 0);
	close(pr->sockfd1);
	close(pr->newsockfd);
	close(pr->sockfd);
	exit(0);
}
