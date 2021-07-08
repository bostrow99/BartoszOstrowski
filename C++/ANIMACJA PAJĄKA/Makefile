CC = g++
CFLAGS  = -g -Wall

INCLUDES = 
SRCS = main.cpp abdomen.cpp body.cpp head.cpp leg.cpp spider.cpp
LIBS = -lm

OBJS = $(SRCS:.c=.o)

MAIN = spider

.PHONY: depend clean

all:    $(MAIN)
	@echo  spider compilation sucessful

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^
