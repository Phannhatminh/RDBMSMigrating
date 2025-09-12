#include "helper/query_update.hpp"
#include "api/statement.hpp"
#include <iostream>

void do_query(Statement *stmt, const std::string &cmd) {
    std::cout << "Executing query: " << cmd << std::endl;
    // Implement query logic here.
}

void do_update(Statement *stmt, const std::string &cmd) {
    std::cout << "Executing update: " << cmd << std::endl;
    // Implement update logic here.
}