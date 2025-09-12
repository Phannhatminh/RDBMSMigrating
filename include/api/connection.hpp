#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <memory>

class Statement;

class Connection {
public:
  virtual ~Connection() = default;
  virtual std::unique_ptr<Statement> create_statement() = 0;
  virtual void close() = 0;
};

class EmbeddedConnection : public Connection {
  std::unique_ptr<Statement> create_statement();
  void close();
};
class NetworkConnection : public Connection {
  std::unique_ptr<Statement> create_statement();
  void close();
};


#endif // CONNECTION_HPP