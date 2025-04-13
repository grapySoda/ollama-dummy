#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

#include "api/handlers.hpp"
#include "constants.hpp"

using json = nlohmann::json;

namespace API::Handler
{
    void tags(const httplib::Request&, httplib::Response& res)
    {
        /* Dumymy response */
        json response = json::parse(std::ifstream(Dummy::Response::TAGS));

        res.set_content(response.dump(), API::Header::Type::JSON);
    }

    void ps(const httplib::Request&, httplib::Response& res)
    {
        /* Dumymy response */
        json response = json::parse(std::ifstream(Dummy::Response::PS));

        res.set_content(response.dump(), API::Header::Type::JSON);
    }

    void version(const httplib::Request&, httplib::Response& res)
    {
        /* Dumymy response */
        json response = json::parse(std::ifstream(Dummy::Response::VERSION));

        res.set_content(response.dump(), API::Header::Type::JSON);
    }
}  // namespace API::Handler
