#LREAD_DIR = /opt/homebrew/Cellar/readline/8.1.2
LREAD_DIR = /usr/include/

#LIBS =	-lreadline -L$(LREAD_DIR)/lib



all:
	gcc -I$(LREAD_DIR) -lreadline main.c