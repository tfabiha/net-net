#include "pipe_networking.h"


int main() {

  int to_server; // write
  int from_server; // read

  from_server = client_handshake( &to_server );
}
