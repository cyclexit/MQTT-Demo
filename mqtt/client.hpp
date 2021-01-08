#ifndef MQTT_CLIENT_HPP_
#define MQTT_CLIENT_HPP_

#include <string>

extern "C" {
#include <mosquitto.h>
}

namespace mqtt {

class Client {
 protected:
  std::string id;
  mosquitto* mosq;
 
 public:
  Client(std::string _id);
  ~Client();

  virtual int connect(std::string host, int port, int duration);
  virtual int disconnect();
};

} // namespace mqtt

#endif