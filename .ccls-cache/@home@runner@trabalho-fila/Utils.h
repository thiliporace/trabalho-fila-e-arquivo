#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>

void ClearScreen();
void Pause(const std::string& message = "Pressione ENTER para continuar...");

bool WriteStringToFile(const std::string& info, const std::string& contents);
std::string ReadFileAsString(const std::string& info, bool& isOK);

#endif
