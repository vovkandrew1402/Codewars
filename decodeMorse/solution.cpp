#include <regex>

std::regex morse("[^\\s]+|\\s{3}");

std::string decodeMorse(std::string morseCode) {
  std::string decoded;  
  auto begin = morseCode.begin() + morseCode.find_first_not_of(' ');
  auto end = morseCode.begin() + morseCode.find_last_not_of(' ') + 1;
  
  for (auto it = std::sregex_iterator(begin, end, morse); it != std::sregex_iterator(); it++){
    std::string t_str = it->str();
    decoded += t_str == "   " ? " " : MORSE_CODE[t_str];
  }
  
  return decoded;
}