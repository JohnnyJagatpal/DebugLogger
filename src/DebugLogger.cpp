#include "DebugLogger.h"

void DebugLogger::log(const String &level, const String &context, const String &message) {
    Serial.println("[" + level + "] " + context + ": " + message);
}

void DebugLogger::error(const String &context, const String &message) {
    log("ERROR", context, message);
}

void DebugLogger::warning(const String &context, const String &message) {
    log("WARNING", context, message);
}

void DebugLogger::info(const String &context, const String &message) {
    log("INFO", context, message);
}

void DebugLogger::debug(const String &context, const String &message) {
    log("DEBUG", context, message);
}
