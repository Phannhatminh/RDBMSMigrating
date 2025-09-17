#include <gtest/gtest.h>
#include <sstream>
#include <functional>
#include <string>
#include "helper/query_update.hpp"
#include "api/statement.hpp"

// Helper to capture std::cout during the call
static std::string capture(std::function<void()> fn) {
  std::ostringstream oss;
  auto* oldbuf = std::cout.rdbuf(oss.rdbuf());
  fn();
  std::cout.rdbuf(oldbuf);
  return oss.str();
}

TEST(QueryUpdate, PrintsQueryMessage) {
  Statement s; // trivial type
  auto out = capture([&]{ do_query(&s, "select * from t"); });
  EXPECT_NE(out.find("Executing query: select * from t"), std::string::npos);
}

TEST(QueryUpdate, PrintsUpdateMessage) {
  Statement s;
  auto out = capture([&]{ do_update(&s, "update t set c=1"); });
  EXPECT_NE(out.find("Executing update: update t set c=1"), std::string::npos);
}
