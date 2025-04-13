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
    inline constexpr const char* CHAT_FINAL =
        "dummy_response/api_chat_final.json";
    inline constexpr const char* CHAT_STREAMING =
        "dummy_response/api_chat_streaming.json";
}  // namespace Dummy::Response

namespace API::Json::Keys
{
    inline constexpr const char* MODEL = "model";
    inline constexpr const char* MESSAGES = "messages";
    inline constexpr const char* ROLE = "role";
    inline constexpr const char* CONTENT = "content";
    inline constexpr const char* CREATED_AT = "created_at";
    inline constexpr const char* IMAGES = "images";
    inline constexpr const char* DONE = "done";
    inline constexpr const char* STREAM = "stream";
}  // namespace API::Json::Keys