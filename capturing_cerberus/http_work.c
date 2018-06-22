/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:34:26 by sjones            #+#    #+#             */
/*   Updated: 2017/05/07 21:35:02 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prox_eyes.h"

void	http_work(t_prox *pr)
{
	grab_host(pr);
	put_host(pr);
	exec_request(pr);
	pr->n = send(pr->sockfd1, pr->buffer, strlen(pr->buffer), 0);
	printf("\n%s\n", pr->buffer);
	if (pr->n < 0)
		error("Error writing to socket");
	else
	{
		while (pr->n > 0)
		{
			bzero((char*)pr->buffer, 500);
			pr->n = recv(pr->sockfd1, pr->buffer, 500, 0);
			if (!(pr->n <= 0))
				send(pr->newsockfd, pr->buffer, pr->n, 0);
		}
	}
}
