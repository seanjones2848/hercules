/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_host.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:36:42 by sjones            #+#    #+#             */
/*   Updated: 2017/05/07 21:36:43 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prox_eyes.h"

void	put_host(t_prox *pr)
{
	if (pr->flag == 1)
	{
		pr->temp = strtok(NULL, "/");
		pr->port = atoi(pr->temp);
	}
	strcat(pr->t1, "^]");
	pr->temp = strtok(pr->t1, "//");
	pr->temp = strtok(NULL, "/");
	if (pr->temp != NULL)
		pr->temp = strtok(NULL, "^]");
	printf("\npath = %s\nPort = %d\n", pr->temp, pr->port);
}
