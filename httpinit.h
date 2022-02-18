HttpServer *InitServer(int port, int maxConnections) {
  int socketFd;
  struct sockaddr_in address;

  int addrLen = sizeof(address);
  socketFd = socket(AF_INET, SOCK_STREAM, 0);
  HttpServer *server = new HttpServer(address, socketFd);

  if (socketFd == 0) {
    cout << "Failed to create socket";
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  int bindStatus = bind(socketFd, (struct sockaddr *)&address, addrLen);
  if (bindStatus < 0) {
    cout << "Failed to bind address to socket";
    exit(EXIT_FAILURE);
  }

  int listenStatus = listen(socketFd, maxConnections);
  if (listenStatus < 0) {
    cout << "Failed to listen on socket";
    exit(EXIT_FAILURE);
  }

  return server;
}