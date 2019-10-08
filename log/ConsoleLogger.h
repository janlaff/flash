#pragma once

#include "Logger.h"

#include <mutex>

namespace flash {
    class ConsoleLogger : public Logger {
    public:
        void log(const LogEntry& entry) override;
    };
}