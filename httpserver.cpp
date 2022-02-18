#include "common.h"
#include "httphandle.h"
#include "httpinit.h"

int main(int argc, char **argv) {
  int PORT = atoi(argv[1]);

  HttpServer *server = InitServer(PORT, 20);
  HandleHttp(server);
  return 0;
}