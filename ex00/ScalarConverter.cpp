
#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
    return;
}

ScalarConverter::~ScalarConverter()
{
    return;
}

ScalarConverter::ScalarConverter(ScalarConverter const & other)
{
    static_cast<void>(other);
    return ;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const & other)
{
    static_cast<void>(other);
    return (*this);
}

void    display_all_the_stuff(std::string ch, std::string integer, std::string floater, std::string doubl)
{
    std::cout << "char: " << ch << std::endl;
    std::cout << "int: " << integer << std::endl;
    std::cout << "float: " << floater << std::endl;
    std::cout << "double: " << doubl << std::endl;
}

std::string floatToString(float num) {
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

std::string doubleToString(double num) {
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

void    display_all_the_stuff_type(char c, int i, float f, double d)
{
    std::string fl = floatToString(f);
    std::string dou = doubleToString(d);

    if (fl.find(".") == std::string::npos)
    {
        fl += ".0";
    }
    if (dou.find(".") == std::string::npos)
    {
        dou += ".0";
    }

    if (i < 0)
    {
        std::cout << "char: impossible overflow" << std::endl;
    }
    else if (c >= 32 && c <= 126)
    {
        std::cout << "char: '" << c << "\'" <<  std::endl;
    }
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << fl << "f" << std::endl;
    std::cout << "double: " << dou << std::endl;
}

void    display_handle_nan(void)
{
    display_all_the_stuff("impossible", "impossible", "nanf", "nan");
}

void    display_handle_inf(std::string str)
{
    if (str.size() == 5)
    {
        str = str.substr(0, str.size() - 1);
    }
    display_all_the_stuff("imposible", str, str + "f", str);
}

bool is_numeric(char c)
{
    if (c >= '0' && c <='9')
        return 1;
    return 0;
}

bool check_if_bad(std::string str, int *minus)
{
    int must_dot = 0;
    int seen_dot = 0;
    if (str.size() == 1)
        return (false);
    if (str[0] == '+' || str[0] == '-')
    {
        if (str[0] == '-')
            *minus = 1;
        str = str.substr(1, str.size() - 1);
    }
    if (str[str.size() - 1] == 'f')
    {
        str = str.substr(0, str.size() - 1);
        must_dot = 1;
    }
    if (str.size() == 0)
        return (true);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            if (seen_dot)
            {
                return (true);
            }
            seen_dot = 1;
        }
        else if (!is_numeric(str[i]))
        {
            return true;
        }
    }
    if ((must_dot == 1 && seen_dot == 0) || (seen_dot == 1 && str.size() == 1))
        return true;
    return false;
}

void    handle_int(std::string str)
{
    std::istringstream iss(str);
    double integer;
    (iss >> integer);
    char c = static_cast<char>(integer);
    double d = static_cast<double>(integer);
    float f = static_cast<float>(integer);
    display_all_the_stuff_type(c, integer, f, d);
}

void    handle_char(std::string str)
{
    char c = str[0];
    int i = static_cast<int>(c);
    double d = static_cast<double>(c);
    float f = static_cast<float>(c);
    display_all_the_stuff_type(c, i, f, d);
}

void    handle_double(std::string str)
{
    std::istringstream iss(str);
    double d;
    (iss >> d);
    int i = static_cast<int>(d);
    char c = static_cast<char>(d);
    float f = static_cast<float>(d);
    display_all_the_stuff_type(c, i, f, d);
}

void    handle_float(std::string str)
{
    str = str.substr(0, str.size() - 1);
    std::istringstream iss(str);
    float f;
    (iss >> f);
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    double d = static_cast<float>(f);
    display_all_the_stuff_type(c, i, f, d);
}

void    ScalarConverter::convert(std::string str)
{
    int minus = 0;

    if (str == "nanf" || str == "nan")
    {
        display_handle_nan();
        return ;
    }
    else if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
    {
        display_handle_inf(str);
        return ;
    }
    else if (check_if_bad(str, &minus))
    {
        display_all_the_stuff("imposible", "imposible", "imposible", "imposible");
        return ;
    }
    else
    {
        if (str.size() == 1 && !is_numeric(str[0]))
            handle_char(str);
        else if ((str.size() == 1 && is_numeric(str[0])) || str.find(".") == std::string::npos)
            handle_int(str);
        else if (str.find("f") != std::string::npos)
            handle_float(str);
        else
            handle_double(str);
    }
}