#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/dist_sink.h>
#include <spdlog/sinks/stdout_sinks.h>

#define TRACE_HERE (std::cerr << "Trace: " << __FILE__ << "(" << __LINE__ << ")" << std::endl)

int main()
{
    TRACE_HERE; auto distributorSink = std::make_shared<spdlog::sinks::dist_sink_mt>();
    TRACE_HERE; auto platformSink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
    TRACE_HERE; distributorSink->add_sink(platformSink);

    TRACE_HERE; auto logger = std::make_shared<spdlog::logger>("test", distributorSink);
    TRACE_HERE; spdlog::register_logger(logger);
    TRACE_HERE; logger->error("test");
    TRACE_HERE; return 0;
}