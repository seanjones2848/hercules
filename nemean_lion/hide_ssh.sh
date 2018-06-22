# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hide_ssh.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjones <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 20:39:10 by sjones            #+#    #+#              #
#    Updated: 2017/02/10 22:34:52 by sjones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if $(id -u) != 0; then exit 1
fi
sed -i 's/deb cdrom/# deb cdrom/' /etc/apt/sources.list
apt-get update
apt-get upgrade
apt-get install openssh-server
sed -i 's/Port 22/Port 65521/' /etc/ssh/sshd_config
service ssh restart
