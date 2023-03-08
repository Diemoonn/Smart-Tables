#pragma once

#include <qstring.h>

extern std::string lang;

inline QString uni(std::string text) { return QString::fromStdString(text); } // unicode convertion function

std::string parseText(int stringNum, std::string path);

inline QString text(int stringNum, std::string path = lang) { return uni(parseText(stringNum, path)); }

