#include "api/endpoints.hpp"
#include "api/handlers.hpp"

#include <iostream>
#include <httplib.h>

void setupEndpoints(httplib::Server& svr)
{
    svr.Get(API::Endpoints::TAGS, API::Handler::tags);
    svr.Get(API::Endpoints::PS, API::Handler::ps);
    svr.Post(API::Endpoints::SSE, [](const httplib::Request& req,
                                     httplib::Response& res) {
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
    });
    svr.Get(API::Endpoints::VERSION, API::Handler::version);
    svr.Post(API::Endpoints::CHAT, API::Handler::chat);
}

int main()
{
    httplib::Server svr;

    setupEndpoints(svr);

    std::cout << "Server is running at http://localhost:11434\n";
    svr.listen("0.0.0.0", 11434);
}
