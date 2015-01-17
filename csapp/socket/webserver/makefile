#Makefile
CXX = g++

SRCS_CGI = cgi.cpp

SRCS_WEBSERVER = webserver.cpp ../Rio.cpp ../SocketBase.cpp

LIBS =

FLAGS = -I../

OBJS = $(SRCS:.cpp=.o)

EXECUTABLE_CGI = cgi-bin/cgi

EXECUTABLE_WEBSERVER = webserver

all:
	$(CXX) -Wall -o $(EXECUTABLE_CGI) $(SRCS_CGI) $(FLAGS) $(LIBS)
	$(CXX) -Wall -o $(EXECUTABLE_WEBSERVER) $(SRCS_WEBSERVER) $(FLAGS) $(LIBS)

.PHONY:clean

clean:
	rm $(OBJS) $(EXECUTABLE_CGI) $(EXECUTABLE_WEBSERVER)
