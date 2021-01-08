#ifndef MQTT_PUB_CLIENT_HPP_
#define MQTT_PUB_CLIENT_HPP_

#include <string>

extern "C" {
#include <mosquitto.h>
}

#include "client.hpp"

namespace mqtt {

class PubClient : public Client {
 private:
  std::string topic;
 
 public:
  PubClient(std::string _id, std::string _topic);
  ~PubClient();

  int connect(std::string host, int port, int duration) override;
  int disconnect() override;
  int publish(int* msg_id, std::string content, int qos, bool retain);
};

} // namespace mqtt

#endif