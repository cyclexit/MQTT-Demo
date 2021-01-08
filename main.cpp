#include <iostream>

extern "C" {
#include <mosquitto.h>
}

int main() {
  mosquitto_lib_init();
  mosquitto_lib_cleanup();
  return 0;
}