# C++ lexical analyzer

## GCC compiler options
`g++ -std=c++11 main.cpp -o cpp_lexical_analyzer`

## Example

### Input
```
while(!(input_string = find_next_token(input_string)).empty()) {}
```

### Output
```
while | keywords
( | punctuators
! | operators
( | punctuators
input_string | identifiers
= | operators
find_next_token | identifiers
( | punctuators
input_string | identifiers
) | punctuators
) | punctuators
. | operators
empty | identifiers
( | punctuators
) | punctuators
) | punctuators
{ | punctuators
} | punctuators
```
