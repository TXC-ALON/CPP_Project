#pragma once
#include "lib.h"
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/details/os-inl.h>
using namespace spdlog::sinks;
namespace Utils
{
    namespace LOG
    {
        std::string get_log_name();
        void set_multi_sink(int console_level = 1, int file_level = 0);
        void Turn_on_Log(int console_level = 1, int file_level = 0);
        void Turn_off_Log();
    };

};
