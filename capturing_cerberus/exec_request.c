/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_request.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:21:04 by sjones            #+#    #+#             */
/*   Updated: 2017/05/07 21:33:23 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prox_eyes.h"

void	exec_request(t_prox *pr)
{
	bzero((char*)&pr->host_addr, sizeof(pr->host_addr));
	pr->host_addr.sin_port = htons(pr->port);
	pr->host_addr.sin_family = AF_INET;
	bcopy((char*)pr->host->h_addr, (char*)&pr->host_addr.sin_addr.s_addr,
			pr->host->h_length);
	pr->sockfd1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	pr->newsockfd1 = connect(pr->sockfd1, (struct sockaddr*)&pr->host_addr,
			sizeof(struct sockaddr));
	sprintf(pr->buffer, "\nConnected to %s  IP - %s\n", pr->t2,
			inet_ntoa(pr->host_addr.sin_addr));
	if (pr->newsockfd1 < 0)
		error("Error in connecting to remote server");
	printf("\n%s\n", pr->buffer);
	bzero((char*)pr->buffer, sizeof(pr->buffer));
	if (pr->temp != NULL)
		sprintf(pr->buffer, "GET /%s %s\r\nHost: "
		"%s\r\nConnection: close\r\n\r\n", pr->temp, pr->t3, pr->t2);
	else
		sprintf(pr->buffer, "GET / %s\r\nHost: "
		"%s\r\nConnection: close\r\n\r\n", pr->t3, pr->t2);
}
