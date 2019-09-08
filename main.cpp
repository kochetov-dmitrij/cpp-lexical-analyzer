#include <iostream>
#include <string>
#include <regex>

typedef std::pair<std::string, std::regex> t_regex_pair;
std::vector<t_regex_pair> regex_tokens;

std::string find_next_token(std::string input_string) {
  std::smatch match;
  for (const auto& regex_token: regex_tokens) {
    if (std::regex_match(input_string, match, regex_token.second)) {
      std::cout << match[1].str() << " | " << regex_token.first << std::endl;
      return match[2].str();
    }
  }
  return std::string();
}

int main()
{
  regex_tokens.push_back(t_regex_pair("keywords", "^\\s*(alignas|alignof|asm|auto|bool|break|case|catch|char|char16_t|char32_t|class|const|constexpr|const_cast|continue|"
    "decltype|default|delete|do|double|dynamic_cast|else|enum|explicit|export|extern|float|for|friend|goto|if|inline|int|long|mutable|namespace|new|noexcept|"
    "operator|private|protected|public|register|reinterpret_cast|return|short|signed|sizeof|static|static_assert|static_cast|struct|switch|template|this|thread_local|throw|"
    "try|typedef|typeid|typename|union|unsigned|using|virtual|void|volatile|wchar_t|while)(?![a-zA-Z0-9_])([\\s\\S]*)"));
  regex_tokens.push_back(t_regex_pair("boolean literals", "^\\s*(false|true)(?![a-zA-Z0-9_])([\\s\\S]*)"));
  regex_tokens.push_back(t_regex_pair("pointer literals", "^\\s*(nullptr)(?![a-zA-Z0-9_])([\\s\\S]*)"));
  regex_tokens.push_back(t_regex_pair("comments", "^\\s*(//.*|/\\*(?:(?!\\*/)[\\s\\S])*\\*/)([\\s\\S]*)"));
  regex_tokens.push_back(t_regex_pair("operators", "^\\s*((?:bitand|bitor|compl|(?:and|not|x?or)(?:_eq)?)(?![a-zA-Z0-9_])|(?:[><*%+&|^=/\\-]?)=|\\.\\*|->\\*|\\?:|::|->|"
    "\\+{1,2}|-{1,2}|&{1,2}|<(?![:%])|<<=?|>{1,2}=?|\\|{1,2}|%(?![:>])|\\.(?!\\.)|[?~!^\\*\\/])([\\s\\S]*)"));
  regex_tokens.push_back(t_regex_pair("identifiers", "^\\s*([a-zA-Z_][a-zA-Z0-9_]*)([\\s\\S]*)"));
  regex_tokens.push_back(t_regex_pair("punctuators", "^\\s*([\\(){}\\[\\]\\\\;:,]|#{1,2}|<:|:>|<%|%>|(?:%:){1,2}|\\.{3})([\\s\\S]*)"));
  regex_tokens.push_back(t_regex_pair("floating literals", "^\\s*((?:(?:(?:[0-9](?:'?[0-9])*)*\\.[0-9](?:'?[0-9])*|[0-9](?:'?[0-9])*\\.)(?:[Ee][-+]?[0-9](?:'?[0-9])*)?|"
    "(?:[0-9](?:'?[0-9])*)(?:[Ee][-+]?[0-9](?:'?[0-9])*))[FfLl]?)(?![a-zA-Z0-9_\\.])([\\s\\S]*)"));
  regex_tokens.push_back(t_regex_pair("integer literals", "^\\s*((?:0[Bb](?:[01]'?)*[01]|0(?:[0-7]'?)*[0-7]|(?:[0-9]'?)*[0-9]|0[Xx](?:[0-9A-Fa-f]'?)*[0-9A-Fa-f])"
    "(?:[Uu](?:l{1,2}|L{1,2})?|(?:l{1,2}|L{1,2})[Uu]?)?)(?![a-zA-Z0-9_\\.])([\\s\\S]*)"));
  regex_tokens.push_back(t_regex_pair("character literals", "^\\s*((?:u8|u|U|L)?'(?:[^'\\\\\\n]|\\\\['\"?\\\\abfnrtv]|\\\\[0-8]{1,3}|\\\\x[0-9A-Fa-f]+)')(?![a-zA-Z0-9_])([\\s\\S]*)"));
  regex_tokens.push_back(t_regex_pair("string literals", "^\\s*((?:u8|u|U|L)?\"(?:[^\"\\\\\\n]|\\\\['\"?\\\\abfnrtv]|\\\\[0-8]{1,3}|\\\\x[0-9A-Fa-f]+)*\")(?![a-zA-Z0-9_])([\\s\\S]*)"));

  std::cout << "\n             ===  C++ LEXICAL ANALYZER  ===\n\nWrite the source code of a c++ programm. Press Ctrl+D to confirm.\n\n";
  std::string input_string(std::istreambuf_iterator<char>(std::cin), {});
  while(!(input_string = find_next_token(input_string)).empty()) {}
}
