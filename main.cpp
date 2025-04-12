#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "httplib.h"

using json = nlohmann::json;

void apiTagsHandler(const httplib::Request&, httplib::Response& res) {
    json response = json::parse(std::ifstream("dummy_response/api_tags.json"));

    res.set_content(response.dump(), "application/json");
}

void setup_routes(httplib::Server& svr) {
    svr.Get("/api/tags", apiTagsHandler);
}

int main() {
    httplib::Server svr;

    setup_routes(svr);

    std::cout << "Server is running at http://localhost:11434\n";
    svr.listen("0.0.0.0", 11434);
}
