#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {

  if (mkfifo("client_write", 0644) == -1)
    {
      printf("server making pipe error %d: %s\n", errno, strerror(errno));
    }
  else
    {
      printf("server made a pipe\n");
    }

  
  int fd_write;
  int fd_read;
  char buffer[BUFFER_SIZE];

  if (fd_read = open("client_write", O_RDONLY) == -1)
    {
      printf("server opening read file error %d: %s\n", errno, strerror(errno));
    }
  else
    {
      printf("server opened pipe created by server\n");
    }
  
  if (read(fd_read, buffer, HANDSHAKE_BUFFER_SIZE) == -1)
    {
      printf("server reading from client error %d: %s\n", errno, strerror(errno));
    }
  else
    {
      printf("from client: %s\n", buffer);
    }
  
  
  return 0;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {

  if (mkfifo("server_write", 0644) == -1)
    {
      printf("client making pipe error %d: %s\n", errno, strerror(errno));
    }
  else
    {
      printf("client made a pipe\n");
    }
  
  int fd_write;
  int fd_read;
  char buffer[BUFFER_SIZE];

  if (fd_write = open("client_write", O_WRONLY) == -1)
    {
      printf("client opening read file error %d: %s\n", errno, strerror(errno));
    }
  else
    {
      printf("client opened pipe created by server\n");
    }

  strcpy(buffer, "server_write\0");
  printf("server buffer has: %s\n", buffer);
  
  if (write(fd_write, buffer, HANDSHAKE_BUFFER_SIZE == -1))
    {
      printf("client writing to server error %d: %s\n", errno, strerror(errno));
    }
  else
    {
      printf("client attempted to write to server\n");
    }

  if (fd_read = open("server_write", O_RDONLY) == -1)
    {
      printf("client opening read file error %d: %s\n", errno, strerror(errno));
    }
  else
    {
      printf("client opened pipe created by server\n");
    }

  if (read(fd_read, buffer, HANDSHAKE_BUFFER_SIZE) == -1)
    {
      printf("client reading from server error %d: %s\n", errno, strerror(errno));
    }
  else
    {
      printf("from server: %s\n", buffer);
    }

  
  return 0;
}