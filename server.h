class HttpServer {
public:
  struct sockaddr_in address;
  int socketFd;
  HttpServer(struct sockaddr_in _address, int _socketFd) {
    address = _address;
    socketFd = _socketFd;
  }
};