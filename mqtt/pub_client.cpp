#include <string>

extern "C" {
#include <mosquitto.h>
}

#include "pub_client.hpp"

namespace mqtt {

PubClient::PubClient(std::string _id, std::string _topic) : Client(_id), topic(_topic) {}

int PubClient::connect(std::string host, int port, int duration) {
  return mosquitto_connect(mosq, host.c_str(), port, duration);
}

int PubClient::disconnect() {
  return mosquitto_disconnect(mosq);
}

int PubClient::publish(int* msg_id, std::string content, int qos, bool retain) {
  return mosquitto_publish(
    mosq, 
    msg_id, 
    topic.c_str(), 
    content.size() + 1, 
    content.c_str(), 
    qos, 
    retain
  );
}

} // namespace mqtt