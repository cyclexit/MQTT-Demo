#include <iostream>
#include <string>

extern "C" {
#include <mosquitto.h>
}

#include "sub_client.hpp"

namespace mqtt {

namespace {

void on_message(mosquitto* mosq, void* obj, const mosquitto_message* msg) {
  std::cout << std::string(msg->topic) << ": " << std::string((char*) msg->payload) << std::endl;
}

} // anonymous namespace

SubClient::SubClient(std::string _id, std::string _topic) : Client(_id), topic(_topic) {
  mosquitto_message_callback_set(mosq, on_message);
}

int SubClient::connect(std::string host, int port, int duration) {
  int rc = mosquitto_connect(mosq, host.c_str(), port, duration);
  if (rc == 0) mosquitto_subscribe(mosq, NULL, topic.c_str(), 0);
  return rc;
}

int SubClient::disconnect() {
  return mosquitto_disconnect(mosq);
}

int SubClient::start() {
  return mosquitto_loop_start(mosq);
}

int SubClient::stop(bool force) {
  return mosquitto_loop_stop(mosq, force);
}

} // namespace mqtt