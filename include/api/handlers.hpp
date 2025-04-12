#pragma once

#include <httplib.h>

namespace API::Handler
{
    void tags(const httplib::Request&, httplib::Response& res);
    void ps(const httplib::Request&, httplib::Response& res);
    void version(const httplib::Request&, httplib::Response& res);
}  // namespace API::Handler
