#include "server.h"
#include <unistd.h>
#include "tcp_link.h"
#include "util/log.h"

Server::Server(){
	_link = NULL;
}

Server::~Server(){
	delete _link;
}

Link* Server::link() const{
	return _link;
}

int Server::listen(const char *host, int port){
	TcpLink *tcp = TcpLink::listen(host, port);
	if(!tcp){
		log_error("failed to listen at %s:%d, %s", host, port, strerror(errno));
		return -1;
	}
	this->_link = tcp;
	return 0;
}