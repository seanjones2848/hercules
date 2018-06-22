# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    bird_killer.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjones <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/17 18:54:38 by sjones            #+#    #+#              #
#    Updated: 2017/03/18 17:32:18 by sjones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import os

BOOL = {'TRUE' : ['Y', 'YES', 'TRUE'], 'FALSE' : ['N', 'NO', 'FALSE']}
def search(dic, search_for):
	for k in dic:
		for v in dic[k]:
			if search_for in v:	return k
	return None
project_name = raw_input("What is your project's name?\n")
project_path = raw_input("What directory would you like this in?(/.../)\n")
ppath = project_path + project_name
if search(BOOL, raw_input("Is your project in C?\n").upper()) == 'TRUE': print ("Good, that's the only language.")
else: print ("I'll take that as a joke, you're coding in C.")
if search(BOOL, raw_input("Need a local git clone?\n").upper()) == 'TRUE':
	os.system('git clone ' + raw_input("What is your project's git repo?\n") + ' ' + ppath)
else:
	if os.path.exists(ppath) != True: os.mkdir(ppath)
print ('Your project is located at :' + ppath)
if search(BOOL, raw_input("Do you want a .gitignore file?\n").upper()) == 'TRUE':
	gitig = open(ppath + '/.gitignore', 'w+') 
	gitig.write("a.out\n*.dSYM\n*.o\n*.swp\n")
if search(BOOL, raw_input("Do you want libft in here?\n").upper()) == 'TRUE':
	lpath = ppath + '/libft'
	os.mkdir(lpath)
	os.system('rsync -r --exclude .git --exclude *.o ~/libft ' + ppath)
	l = 1
else: l = 0
if search(BOOL, raw_input("Do you want a main?\n").upper()) == 'TRUE':
	main = open(ppath + '/main.c', 'w+')
	m = 1
	if l == 1: main.write('#include "libft/libft.h"\n')
else: m = 0
if search(BOOL, raw_input("Do you want a Makefile?\n").upper()) == 'TRUE':
	make = open(ppath + '/Makefile', 'w+')
	make.write("NAME = " + project_name + '\n\nSRCS =')
	if m == 1: make.write(' main.c')
	make.write('\n\nOBJS = $(SRCS:.c=.o)\n\nFLGS = -Wextra -Werror -Wall\n\n')
	if l == 1: make.write("LIBFT = " + lpath + '\n\nLIBMK = cd libft && make\n\n')
	make.write('$(NAME):\n\tgcc &(FLGS) $(SRCS) -o $(NAME)')
	if l == 1: make.write (" libft/libft.a")
	make.write("\n\nall: $(NAME)\n\nclean:\n\trm -rf $(OBJS)")
	if l == 1: make.write('\n\t$(LIBMK) clean')
	make.write("\n\n.phony all clean fclean re\n")
if search(BOOL, raw_input("Do you want a Header file?\n").upper()) == 'TRUE':
	head = open(ppath + '/' + project_name + '.h', 'w+')
	head.write("#ifndef %s_H\n# define %s_H\n" % (project_name.upper(), project_name.upper()))
	if l == 1: head.write('# include "libft/libft.h"\n')
	head.write("#endif\n")
if search(BOOL, raw_input("Do you need an author file?\n").upper()) == 'TRUE':
	author = open(ppath + '/author', 'w+')
	author.write("sjones")
