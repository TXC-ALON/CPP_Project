#include "utils.h"

namespace Utils
{
    std::string Utils::get_log_name()
    {
        std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm *timeinfo = std::localtime(&now);
        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", timeinfo);

        std::string logFileName = "log/" + std::string(timestamp) + ".log";
        return logFileName;
    }

    void Utils::set_multi_sink(int console_level, int file_level)
    {
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_pattern("%^[%H:%M:%S.%f] [%L] [thread:%t] [%!](%s:%#): %v%$");
        console_sink->set_level(static_cast<spdlog::level::level_enum>(console_level));
        std::string logFileName = Utils::get_log_name();
        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFileName, true);
        file_sink->set_pattern("%^[%Y.%m.%d %H:%M:%S.%F] [%l] [thread:%t]: [%!](%s:%#)%$ : %v");
        file_sink->set_level(static_cast<spdlog::level::level_enum>(file_level));

        std::shared_ptr<spdlog::logger> logger = std::make_shared<spdlog::logger>("root", spdlog::sinks_init_list({console_sink, file_sink}));
        logger->set_level(spdlog::level::trace);
        spdlog::register_logger(logger);
        spdlog::set_default_logger(logger);
    }

    void Utils::Turn_on_Log(int console_level, int file_level) { set_multi_sink(console_level, file_level); };
    void Utils::Turn_off_Log() { set_multi_sink(6, 6); };

};
