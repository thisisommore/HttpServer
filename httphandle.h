#include "server.h"
#include <fstream>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;
void HandleHttp(HttpServer *server) {
  int addrLen = sizeof(server->address);

  while (1) {
    int clientSocket =
        accept(server->socketFd, (struct sockaddr *)&server->address,
               (socklen_t *)&addrLen);
    if (clientSocket < 0) {
      cout << "Failed to accept request from client\n";
      exit(EXIT_FAILURE);
    }

    char *responseBuffer = "HTTP/1.1 200 OK"
                           "\n"
                           "Content-Type: text/html"
                           "\n"
                           "Content-Length: 1592"
                           "\n\n";

    write(clientSocket, responseBuffer, strlen(responseBuffer));
    write(
        clientSocket,
        "<!DOCTYPE html><html lang='en'><head>    <meta charset='UTF-8'>    "
        "<title>Document</title>    <script>        window.onload = (a, b) => "
        "{            document.getElementById('sUrl').innerText = "
        "window.location.host        }    </script>    <style>        .green { "
        "           background: green;        }        .box {            "
        "padding: 10px;            color: white;            font-size: 20px;   "
        "         margin: 10px;            border-radius: 30px;            "
        "padding: 20px;            height: 200px;            z-index: 10;      "
        "  }        .flex {            display: flex;            align-items: "
        "center;            justify-content: center;            align-items: "
        "center;        }        .left {            height: 100px;            "
        "width: 100px;            background: rgb(146, 21, 21);            "
        "transform: translateX(30%);            border-radius: 10px;           "
        " transition: 0.3s;        }        .left:hover {            "
        "transform: translateX(-20%) !important;        }        .right:hover "
        "{            transform: translateX(40%) !important;        }        "
        ".right {            height: 100px;            width: 100px;           "
        " background: rgb(12, 91, 122);            transform: "
        "translateX(-30%);            border-radius: 10px;            "
        "transition: 0.3s;        }        #sUrl {            margin-left: "
        "10px;        }    </style></head><body>    <div class='flex'>        "
        "<div class='left'></div>        <div class='flex box green'>          "
        "  <p>Custom server is running on </p><span id='sUrl'></span>        "
        "</div>        <div class='right'></div>    </div></body></html>",
        1592);
    close(clientSocket);
  }
}