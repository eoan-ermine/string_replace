# Homework assignment: replacements in a string

## Assignment

Imagine you are asked to replace all occurrences of a substring in a string

```c++
std::string str = "Hello, $name, how are you doing, $name?";
std::string from = "$name";
std::string to = "Eric";
```

Write something here, maybe some function

```c++
std::cout << str << std::endl;
> Hello, Eric, how are you doing here, Eric?
```

How will you do it?

## Solution

Full solution is available in [string_replace/replace.hpp](string_replace/replace.hpp)

### Design considerations

The function does not accept the source by reference, because this would lead to double indirection when we try to access its content.

These considerations are also valid for the from and to arguments.

The current interface allows the user how to pass a copy to the function, so source string remains:

```c++
std::string str = "Hello, $name, how are you doing, $name?";
auto newStr = replace(str, "$name", "Eric");
// str content's remains the same
```

So, if the user no longer plans to use the source string, pass it by move:

```c++
std::string str = "Hello, $name, how are you doing, $name?";
auto newStr = replace(std::move(str), "$name", "Eric");
// str remains in valid but unspecified state
```