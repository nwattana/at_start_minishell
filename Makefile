

#LREAD_DIR = /opt/homebrew/Cellar/readline/8.1.2


#LIBS =	-lreadline -L$(LREAD_DIR)/lib

UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	LREAD_DIR = -L/usr/local/lib -I/usr/local/include/ -lreadline 
else
	LREAD_DIR = /usr/include/
endif


all:
	echo $(UNAME)
	gcc main.c $(LREAD_DIR)

## prototype
## gcc main.c -L/usr/local/lib/ -I/usr/local/include -lreadline