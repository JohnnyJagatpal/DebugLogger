#pragma once

#include <Arduino.h>

// Log Level Flags: Defined using -DDEBUG or -DINFO in build flags
#ifdef DEBUG
    #define LOG_DEBUG_ENABLED
    #define LOG_INFO_ENABLED
    #define LOG_WARNING_ENABLED
    #define LOG_ERROR_ENABLED
#elif defined(INFO)
    #define LOG_INFO_ENABLED
    #define LOG_WARNING_ENABLED
    #define LOG_ERROR_ENABLED
#elif defined(WARNING)
    #define LOG_WARNING_ENABLED
    #define LOG_ERROR_ENABLED
#elif defined(ERROR)
    #define LOG_ERROR_ENABLED
#else
    #define LOG_ERROR_ENABLED 
#endif

// DebugLogger class to handle actual log output
class DebugLogger {
public:
    static void log(const String &level, const String &context, const String &message);

    // Helpers for log level
    static void error(const String &context, const String &message);
    static void warning(const String &context, const String &message);
    static void info(const String &context, const String &message);
    static void debug(const String &context, const String &message);
};

// Macros for easy logging
#ifdef LOG_ERROR_ENABLED
    #define LOG_ERROR(message) DebugLogger::error(__PRETTY_FUNCTION__, String(message))
#else
    #define LOG_ERROR(message)
#endif

#ifdef LOG_WARNING_ENABLED
    #define LOG_WARNING(message) DebugLogger::warning(__PRETTY_FUNCTION__, String(message))
#else
    #define LOG_WARNING(message)
#endif

#ifdef LOG_INFO_ENABLED
    #define LOG_INFO(message) DebugLogger::info(__PRETTY_FUNCTION__, String(message))
#else
    #define LOG_INFO(message)
#endif

#ifdef LOG_DEBUG_ENABLED
    #define LOG_DEBUG(message) DebugLogger::debug(__PRETTY_FUNCTION__, String(message))
#else
    #define LOG_DEBUG(message)
#endif

// Log with custom context (e.g., no class name)
#define LOG_CONTEXT(level, message) DebugLogger::log(level, "[]", String(message))
