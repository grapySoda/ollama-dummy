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
        json response = json::parse(std::ifstream(Dummy::Response::TAGS));

        res.set_content(response.dump(), API::MIME::JSON);
    }
}  // namespace API::Handler
