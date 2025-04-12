#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "httplib.h"

using json = nlohmann::json;

void root_handler(const httplib::Request&, httplib::Response& res) {
    res.set_content("Hello, world! This is C++ backend.", "text/plain");
}

void api_hello_handler(const httplib::Request&, httplib::Response& res) {
    json response = {
        {"message", "Hello from API"},
        {"status", "success"},
        {"version", 1.0}
    };

    res.set_content(response.dump(), "application/json");
}

void api_tags_handler(const httplib::Request&, httplib::Response& res) {
    json response = json::parse(std::ifstream("dummy_response/api_tags.json"));

    res.set_content(response.dump(), "application/json");
}

void setup_routes(httplib::Server& svr) {
    svr.Get("/", root_handler);
    svr.Get("/api/hello", api_hello_handler);
    svr.Get("/api/tags", api_tags_handler);
}

int main() {
    httplib::Server svr;

    setup_routes(svr);

    std::cout << "Server is running at http://localhost:11434\n";
    svr.listen("0.0.0.0", 11434);
}
