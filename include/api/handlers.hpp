#pragma once

#include <httplib.h>

namespace API::Handler
{
    void tags(const httplib::Request&, httplib::Response& res);
}
