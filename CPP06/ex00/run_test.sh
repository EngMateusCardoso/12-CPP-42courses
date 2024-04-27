#!/bin/bash

echo 
echo -e "------------------------ CONVERT TEST -------------------------"
echo -e "---------------------------------------------------------------"
echo -e "No argument test.."
echo -e "---------------------------------------------------------------"

# Test with no argument
echo "./convert"
./convert

echo -e "---------------------------------------------------------------"
echo -e "Invalid input tests..."
echo -e "---------------------------------------------------------------"

# Test with invalid inputs
echo "./convert 🌊"
./convert 🌊 
echo "./convert 🌊🌊"
./convert 🌊🌊
echo "./convert teste"
./convert teste
echo "./convert \"teste\""
./convert "teste"
echo "./convert 'teste'"
./convert 'teste'
echo "./convert 0000r"
./convert 0000r
echo "./convert 9f"
./convert 9f
echo "./convert 99f"
./convert 99f
echo "./convert '\\n'"
./convert "'\n'"
echo "./convert '\\t'"
./convert "'\t'"
echo "./convert '\\r'"
./convert "'\r'"
echo "./convert '\\v'"
./convert "'\v'"
echo "./convert '\\b'"
./convert "'\b'"
echo "./convert '\\f'"
./convert "'\f'"
echo "./convert '\\a'"
./convert "'\a'"
echo "./convert '\\e'"
./convert "'\e'"
echo "./convert '\\0'"
./convert "'\0'"
echo "./convert '\\x0'"
./convert "'\x0'"
echo "./convert '\\x0f'"
./convert "'\x0f'"
echo "./convert ' '"
./convert "' '"
echo "./convert '	'"
./convert "'	'"

echo -e "---------------------------------------------------------------"
echo -e "Limit tests..."
echo -e "---------------------------------------------------------------"

# Test with limits
echo "./convert 2147483647"
./convert 2147483647
echo "./convert -2147483648"
./convert -2147483648
echo "./convert 2147483648"
./convert 2147483648
echo "./convert -2147483649"
./convert -2147483649

echo -e "---------------------------------------------------------------"
echo -e "Char tests..."
echo -e "---------------------------------------------------------------"

# Test with char
echo "./convert 'A'"
./convert "A"
echo "./convert 'l'"
./convert "l"
echo "./convert 'e'"
./convert "e"
echo "./convert 'x'"
./convert "x"
echo "./convert '/'"
./convert "/"
echo "./convert '?'"
./convert "?"
echo "./convert ':'"
./convert ":"
echo "./convert '%'"
./convert "%"
echo "./convert '@'"
./convert "@"

echo -e "---------------------------------------------------------------"
echo -e "Int tests..."
echo -e "---------------------------------------------------------------"

# Test with integer
echo "./convert 0"
./convert 0
echo "./convert 1"
./convert 1
echo "./convert -1"
./convert -1
echo "./convert 42"
./convert 42
echo "./convert -42"
./convert -42

echo -e "---------------------------------------------------------------"
echo -e "Float tests..."
echo -e "---------------------------------------------------------------"

# Test with float
echo "./convert 0.0f"
./convert 0.0f
echo "./convert 1.1f"
./convert 1.1f
echo "./convert -1.1f"
./convert -1.1f
echo "./convert 42.42f"
./convert 42.42f
echo "./convert -42.42f"
./convert -42.42f
echo "./convert +3.14f"
./convert +3.14f
echo "./convert -3.14f"
./convert -3.14f

echo -e "---------------------------------------------------------------"
echo -e "Double tests..."
echo -e "---------------------------------------------------------------"

# Test with double
echo "./convert 0.0"
./convert 0.0
echo "./convert 1.1"
./convert 1.1
echo "./convert -1.1"
./convert -1.1
echo "./convert 42.42"
./convert 42.42
echo "./convert -42.42"
./convert -42.42
echo "./convert +3.14"
./convert +3.14
echo "./convert -3.14"
./convert -3.14

echo -e "---------------------------------------------------------------"
echo -e "Pseudo literal tests..."
echo -e "---------------------------------------------------------------"

# Test with pseudo literal
echo "./convert nan"
./convert nan
echo "./convert nanf"
./convert nanf
echo "./convert +inf"
./convert +inf
echo "./convert -inf"
./convert -inf
echo "./convert +inff"
./convert +inff
echo "./convert -inff"
./convert -inff

echo -e "---------------------------------------------------------------"
echo -e "Tests finished..."
echo -e "---------------------------------------------------------------"
