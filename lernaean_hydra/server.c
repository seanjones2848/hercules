/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:44:19 by sjones            #+#    #+#             */
/*   Updated: 2017/02/20 15:22:23 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int		main(void)
{
	char				buff[256];
	int					forme_fd;
	int					foryou_fd;
	struct sockaddr_in	addr;

	forme_fd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htons(INADDR_ANY);
	addr.sin_port = htons(8888);
	bind(forme_fd, (struct sockaddr*)&addr, sizeof(addr));
	listen(forme_fd, 10);
	foryou_fd = accept(forme_fd, (struct sockaddr*)NULL, NULL);
	while (1)
	{
		bzero(buff, 256);
		read(foryou_fd, buff, 256);
		if (strcmp(buff, "ping\n") == 0)
			ft_putendl_fd("pong\npong", foryou_fd);
		close(foryou_fd);
		foryou_fd = accept(forme_fd, (struct sockaddr*)NULL, NULL);
	}
	return (0);
}
