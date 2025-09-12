#include "api/driver.hpp"
#include "api/connection.hpp"
#include <iostream>
#include <memory>

std::unique_ptr<Connection> EmbeddedDriver::connect(const std::string& c) {
  return std::make_unique<EmbeddedConnection>();
}

std::unique_ptr<Connection> NetworkDriver::connect(const std::string& c) {
  return std::make_unique<NetworkConnection>();
}