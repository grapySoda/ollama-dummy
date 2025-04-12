#include "api/endpoints.hpp"
#include "api/handlers.hpp"

#include <iostream>
#include <httplib.h>

void setupEndpoints(httplib::Server& svr)
{
    svr.Get(API::Endpoints::TAGS, API::Handler::tags);
    svr.Get(API::Endpoints::PS, API::Handler::ps);
    svr.Get(API::Endpoints::VERSION, API::Handler::version);
}

int main()
{
    httplib::Server svr;

    setupEndpoints(svr);

    std::cout << "Server is running at http://localhost:11434\n";
    svr.listen("0.0.0.0", 11434);
}
