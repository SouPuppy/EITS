#pragma once

#include "history/history.h"
#include <HoTT/HoTT.h>

extern EITS::Runtime runtime;
extern HistoryManager history;

#include <unordered_map>
extern std::unordered_map<std::string, std::string> replacement_table;
