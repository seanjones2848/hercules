/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:35:22 by sjones            #+#    #+#             */
/*   Updated: 2017/05/07 21:35:24 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prox_eyes.h"

void	init_child(t_prox *pr)
{
	pr->flag = 1;
	pr->port = 0;
	pr->temp = NULL;
	bzero((char*)pr->buffer, 500);
	recv(pr->newsockfd, pr->buffer, 500, 0);
	sscanf(pr->buffer, "%s %s %s", pr->t1, pr->t2, pr->t3);
}
