#include <chrono>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

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

    void sse(const httplib::Request& req, httplib::Response& res)
    {
        res.set_chunked_content_provider(
            "text/plain", [](size_t offset, httplib::DataSink& sink) {
                std::vector<std::string> messages = {
                    "Hello, ", "this is ", "a streamed ", "response from ",
                    "the server.\n"};

                for (const auto& msg : messages) {
                    sink.write(msg.c_str(), msg.size());
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }

                sink.done();
                return true;
            });
    }

    void version(const httplib::Request&, httplib::Response& res)
    {
        /* Dumymy response */
        json response = json::parse(std::ifstream(Dummy::Response::VERSION));

        res.set_content(response.dump(), API::Header::Type::JSON);
    }

    void chat(const httplib::Request& req, httplib::Response& res)
    {
        using namespace std::chrono;

        bool stream = true;

        json body;
        json bodyStreaming =
            json::parse(std::ifstream(Dummy::Response::CHAT_STREAMING));
        json bodyFinal =
            json::parse(std::ifstream(Dummy::Response::CHAT_FINAL));

        // auto now = zoned_time{current_zone(), system_clock::now()};
        // std::string timestamp = std::format("{:%FT%T.%N%Ez}", now);

        const auto getStreamStatus = [](json j) {
            if (j.contains(API::Json::Keys::DONE)) {
                if (j[API::Json::Keys::DONE] == true) {
                    return true;
                }
            }

            return false;
        };

        try {
            json j = json::parse(req.body);
            std::string model = j[API::Json::Keys::MODEL];
            std::string content =
                j[API::Json::Keys::MESSAGES][API::Json::Keys::CONTENT];

            if (j.contains(API::Json::Keys::STREAM)) {
                if (j[API::Json::Keys::STREAM] != false) {
                    stream = false;
                }
            }

            if (stream) {
                body = bodyStreaming;
            } else {
                body = bodyFinal;
            }

            std::string response = "Received JSON: name = ";
            res.set_content(response, "text/plain");

        } catch (const std::exception& e) {
            res.status = 400;
            res.set_content(std::string("Invalid JSON: ") + e.what(),
                            "text/plain");
        }
    }
}  // namespace API::Handler
