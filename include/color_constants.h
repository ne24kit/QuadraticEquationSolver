#pragma once

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define PRINT_COLORFUL_STRING(string, color)  printf(color string ANSI_COLOR_RESET)