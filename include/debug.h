#pragma once

#include <cstdint>

enum LogLevel : int32_t {
    LOG_OFF = 0,
    LOG_ERROR = 1,
    LOG_WARN = 2,
    LOG_INFO = 3,
    LOG_DEBUG = 4,
    LOG_TRACE = 5,
};

class LoggingSupport {
public:
    LoggingSupport();
    ~LoggingSupport();

    static int32_t &level() {
        static int32_t lvl = LOG_TRACE;
        return lvl;
    }

    static void set_log_level(int32_t t_lvl) {
        level() = t_lvl;
    }
};

#define log_trace(format, ...)                                            \
    do {                                                                  \
        if (LoggingSupport::level() >= LogLevel::LOG_TRACE)               \
            printf("\x1b[96m[trace] \x1b[0m" format "\n", ##__VA_ARGS__); \
    } while (0);

#define log_debug(format, ...)                                            \
    do {                                                                  \
        if (LoggingSupport::level() >= LogLevel::LOG_DEBUG)               \
            printf("\x1b[94m[debug] \x1b[0m" format "\n", ##__VA_ARGS__); \
    } while (0);

#define log_info(format, ...)                                            \
    do {                                                                 \
        if (LoggingSupport::level() >= LogLevel::LOG_INFO)               \
            printf("\x1b[92m[infos] \x1b[0m" format "\n", ##__VA_ARGS__); \
    } while (0);

#define log_warn(format, ...)                                            \
    do {                                                                 \
        if (LoggingSupport::level() >= LogLevel::LOG_WARN)               \
            printf("\x1b[95m[warns] \x1b[0m" format "\n", ##__VA_ARGS__); \
    } while (0);

#define log_error(format, ...)                                            \
    do {                                                                  \
        if (LoggingSupport::level() >= LogLevel::LOG_ERROR)               \
            printf("\x1b[91m[error] \x1b[0m" format "\n", ##__VA_ARGS__); \
    } while (0);
