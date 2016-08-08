all:
	g++ -std=c++0x Server.cpp main.cpp Client.cpp communication.cpp \
	-o cs -lpthread
clean:
	rm cs
