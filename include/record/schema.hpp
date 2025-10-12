// Schema-related types
#ifndef SCHEMA_HPP
#define SCHEMA_HPP

#include <cstdint>
#include <vector>
#include <string>
#include <unordered_map>

namespace record {

// Matches Rust enum discriminants: Integer=4, Varchar=12
enum class Type : std::int32_t {
	Integer = 4,
	Varchar = 12,
};

struct FieldInfo {
  Type type_;
  size_t length;
};

struct Schema {
  std::vector<std::string> fields;
  std::unordered_map<std::string, FieldInfo> info;
};

}

#endif // SCHEMA_HPP
