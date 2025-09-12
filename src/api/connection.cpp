#include "api/connection.hpp"
#include "api/statement.hpp" 
#include <iostream>

std::unique_ptr<Statement> EmbeddedConnection::create_statement() {
  return std::make_unique<Statement>();
}

void EmbeddedConnection::close() {
  std::cout << "Connection closed." << std::endl;
}

std::unique_ptr<Statement> NetworkConnection::create_statement() {
  return std::make_unique<Statement>();
}

void NetworkConnection::close() {
  std::cout << "Connection closed." << std::endl;
}