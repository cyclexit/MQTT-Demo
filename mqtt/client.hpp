#ifndef MQTT_CLIENT_HPP_
#define MQTT_CLIENT_HPP_

#include <string>

extern "C" {
#include <mosquitto.h>
}

namespace mqtt {

class Client {
 private:
  mosquitto* mosq;
 
 public:
  Client(std::string id);
  ~Client();

  int connect(std::string host, int port, int duration);
  int disconnect();
};

} // namespace mqtt

#endif