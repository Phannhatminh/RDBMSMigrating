#include <iostream>
#include "helper/utility.hpp"
#include "helper/query_update.hpp"
#include "api/driver.hpp"
#include "api/connection.hpp"
#include "api/statement.hpp"

int main() {
  std::string s;

  // Prompt for connection string.
  std::cout << "Connect> ";
  std::getline(std::cin, s);
  trim_end(s);

  // Determine which driver to use based on the connection string.
  bool is_embedded = (s.find("//") == std::string::npos);
  std::unique_ptr<Driver> driver;
  if (is_embedded) {
    driver = std::make_unique<EmbeddedDriver>();
  } else {
    driver = std::make_unique<NetworkDriver>();
  }

  // Establish the connection
  std::unique_ptr<Connection> conn = driver -> connect(s);
  s.clear();
  // Create a statement from the connection.
  std::unique_ptr<Statement> stmt = conn -> create_statement();

  // Enter SQL command loop.
  std::cout << "\nSQL> " << std::flush;
  while (std::getline(std::cin, s)) {
    trim_end(s);
    if (s == "exit" || s == "quit") {
      break;
    }
    if (s.find("select") != 0) {
      do_query(stmt.get(), s);
    } else {
      do_update(stmt.get(), s);
    }
    s.clear();
    std::cout << "\nSQL> " << std::flush;
  }
  conn -> close();

  return 0;
}