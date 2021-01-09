#include <iostream>
#include <string>

extern "C" {
#include <mosquitto.h>
}

#include "mqtt/sub_client.hpp"

int main() {
  ::mosquitto_lib_init();

  std::string client_id = "test_sub";
  std::string sub_topic = "test/sub";
  mqtt::SubClient sub_client(client_id, sub_topic);

  std::string host = "localhost";
  int port = 1883; // default port for mqtt
  int duration = 60;
  int rc = sub_client.connect(host, port, duration);
  if (rc != 0) {
    // Simple error handling
    std::cout << "Client could not connect to broker! Error Code: " << rc << std::endl;
    return -1;
  }
  std::cout << "Client successfully connected to the broker!" << std::endl;

  sub_client.start();
  std::cout << "Press Enter to continue..." << std::endl;
  getchar(); // This is not good...
  sub_client.stop(true);

  sub_client.disconnect();

  ::mosquitto_lib_cleanup();
  return 0;
}