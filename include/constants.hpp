#pragma once

namespace API::Header
{
    namespace Type
    {
        inline constexpr const char* TEXT = "text/plain";
        inline constexpr const char* JSON = "application/json";
    }  // namespace Type
}  // namespace API::Header

namespace Dummy::Response
{
    inline constexpr const char* TAGS = "dummy_response/api_tags.json";
    inline constexpr const char* PS = "dummy_response/api_ps.json";
    inline constexpr const char* VERSION = "dummy_response/api_version.json";
}  // namespace Dummy::Response
