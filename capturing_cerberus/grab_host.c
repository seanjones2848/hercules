/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_host.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:33:55 by sjones            #+#    #+#             */
/*   Updated: 2017/05/07 23:13:00 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prox_eyes.h"

void	grab_host(t_prox *pr)
{
	strcpy(pr->t1, pr->t2);
	pr->flag = 0;
	pr->i = 7;
	while (pr->i < (int)strlen(pr->t2))
	{
		if (pr->t2[pr->i] == ':')
		{
			pr->flag = 1;
			break ;
		}
		pr->i++;
	}
	pr->temp = strtok(pr->t2, "//");
	if (pr->flag == 0)
	{
		pr->port = 80;
		pr->temp = strtok(NULL, "/");
	}
	else
		pr->temp = strtok(NULL, ":");
	sprintf(pr->t2, "%s", pr->temp);
	printf("host = %s", pr->t2);
	pr->host = gethostbyname(pr->t2);
}
