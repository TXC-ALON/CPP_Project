#include <spdlog/spdlog.h>

int main()
{
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");

    // change log pattern
    // spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^%L%$] [thread %t] %v");
    spdlog::set_pattern("[%H:%M:%S.%f] [\033[1;33m%l\033[0m] [%!][%s:%#]: %^%v%$");
    // Compile time log levels
    // Note that this does not change the current log level, it will only
    // remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_INFO("Positional args are {1} {0}..", "too", "supported");
    SPDLOG_DEBUG("Some debug message");
    SPDLOG_ERROR("Some error message");
    SPDLOG_CRITICAL("Some CRITICAL message with param {}", 552);
}