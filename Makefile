# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwattana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 00:34:26 by nwattana          #+#    #+#              #
#    Updated: 2022/12/27 01:14:56 by nwattana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#LREAD_DIR = /opt/homebrew/Cellar/readline/8.1.2


#LIBS =	-lreadline -L$(LREAD_DIR)/lib

UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	LREAD_DIR = -L/usr/local/lib -I/usr/local/include/ -lreadline 
else 
	LREAD_DIR = -L/usr/local/opt/readline -I/usr/local/opt/readline/include -lreadline
endif


all:
	@printf "\n\nNow you complie in \e[1;34m$(UNAME)\e[0m\n\n"
	gcc main.c $(LREAD_DIR)

## prototype
## gcc main.c -L/usr/local/lib/ -I/usr/local/include -lreadline
