#include <iostream>
#include <string>

extern "C" {
#include <mosquitto.h>
}

#include "mqtt/pub_client.hpp"

int main() {
  ::mosquitto_lib_init();

  std::string client_id = "test_pub";
  std::string pub_topic = "test/pub";
  mqtt::PubClient pub_client(client_id, pub_topic);

  std::string host = "localhost";
  int port = 1883; // default port for mqtt
  int duration = 60;
  int rc = pub_client.connect(host, port, duration);
  if (rc != 0) {
    // Simple error handling
    std::cout << "Client could not connect to broker! Error Code: " << rc << std::endl;
    return -1;
  }
  std::cout << "Client successfully connected to the broker!" << std::endl;

  std::string content = "Hahahaha!";
  int qos = 0;
  bool retain = false;
  rc = pub_client.publish(NULL, content, qos, retain);
  if (rc != 0) {
    std::cout << "Failed to publish! Error Code: " << rc << std::endl;
    return -1;
  }

  ::mosquitto_lib_cleanup();
  return 0;
}