#include "Initial.h"
void workerFunc(int workerId)
{
    // 创建日志记录器
    auto logger = spdlog::stdout_color_mt("worker-" + std::to_string(workerId));
    // 执行一些工作并记录日志
    for (int i = 0; i < 10; ++i)
    {
        LOG_TRACE("Worker {} - Log entry {}", workerId, i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
int main()
{
    Turn_on_Log(0, 0);

    std::vector<std::thread> workers;
    for (int i = 1; i <= 3; ++i)
    {
        workers.emplace_back(workerFunc, i);
    }

    // 等待所有工作线程完成
    for (auto &worker : workers)
    {
        worker.join();
    }
    spdlog::set_pattern("[%H:%M:%S.%f] [%l] [%!][%s:%#]: %^%v%$");
    // Compile time log levels
    // Note that this does not change the current log level, it will only
    // remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
    LOG_TRACE("Some trace message with param {}", 42);
    LOG_DEBUG("Some debug message");
    LOG_WARN("Some WARNING message");
    LOG_INFO("Positional args are {1} {0}..", "too", "supported");
    LOG_ERROR("Some error message");
    LOG_FATAL("Some CRITICAL message with param {}", 552);
}
