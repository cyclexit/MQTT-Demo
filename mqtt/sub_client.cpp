#include <iostream>
#include <functional>

extern "C" {
#include <mosquitto.h>
}

#include "sub_client.hpp"

namespace mqtt {

namespace {

void on_message(mosquitto* mosq, void* obj, const mosquitto_message* msg) {
  std::cout << msg->topic << ": " << msg->payload << std::endl;
}

} // anonymous namespace

SubClient::SubClient(std::string _id, std::string _topic) : Client(_id), topic(_topic) {
  mosquitto_message_callback_set(mosq, on_message);
}

int SubClient::connect(std::string host, int port, int duration) {
  return mosquitto_connect(mosq, host.c_str(), port, duration);
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