#pragma once

#include <httplib.h>

namespace API::Handler
{
    void tags(const httplib::Request&, httplib::Response& res);
    void ps(const httplib::Request&, httplib::Response& res);
    void sse(const httplib::Request& req, httplib::Response& res);
    void version(const httplib::Request&, httplib::Response& res);
    void chat(const httplib::Request& req, httplib::Response& res);
}  // namespace API::Handler
