#ifndef MQTT_SUB_CLIENT_HPP_
#define MQTT_SUB_CLIENT_HPP_

#include <string>

extern "C" {
#include <mosquitto.h>
}

#include "client.hpp"

namespace mqtt {

class SubClient : Client {
 private:
  std::string topic;

 public:
  SubClient(std::string _id, std::string _topic);
  ~SubClient() {};

  int connect(std::string host, int port, int duration) override;
  int disconnect() override;
  int start();
  int stop(bool force);
};

} // namespace mqtt

#endif