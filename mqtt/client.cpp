#include "client.hpp"

#include <string>

namespace mqtt {

Client::Client(std::string id) {
  // TODO: error handling
  mosq = mosquitto_new(id.c_str(), true, NULL);
}

Client::~Client() {
  // TODO: error handling
  mosquitto_destroy(mosq);
}

int Client::connect(std::string host, int port, int duration) {
  return mosquitto_connect(mosq, host.c_str(), port, duration);
}

int Client::disconnect() {
  return mosquitto_disconnect(mosq);
}

} // namespace mqtt