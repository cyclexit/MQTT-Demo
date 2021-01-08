#include "client.hpp"

#include <string>

extern "C" {
#include <mosquitto.h>
}

namespace mqtt {

Client::Client(std::string _id) : id(_id) {
  // TODO: error handling
  mosq = mosquitto_new(id.c_str(), true, NULL);
}

Client::~Client() {
  // TODO: error handling
  mosquitto_destroy(mosq);
}

} // namespace mqtt