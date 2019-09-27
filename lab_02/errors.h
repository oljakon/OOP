#ifndef errors_h
#define errors_h

#include <stdio.h>
#include <exception>
#include <string.h>

class base_exception : public std::exception
{
public:
    base_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
    {
        err_info = "filename: " + filename + "\nline: " + std::to_string(line)
        + "\ntime: " + time + "\ninfo: " + info;
    }
    virtual std::string what(void) {return "MyBaseException.\n" + this->err_info;};
protected:
    std::string err_info;
};

class index_out_of_range_exception : public base_exception
{
public:
    index_out_of_range_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
    : base_exception(filename, classname, line, time, info) {};
    std::string what(void) {return "Index out of range.\n" + this->err_info;}
};

class is_not_equal_exception : public base_exception
{
public:
    is_not_equal_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
    : base_exception(filename, classname, line, time, info) {};
    std::string what(void) {return "Matrix is not equal\n" + this->err_info;}
};

class is_empty_exception : public base_exception
{
public:
    is_empty_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
    : base_exception(filename, classname, line, time, info) {};
    std::string what(void) {return "Matrix is empty\n" + this->err_info;}
};

class cannot_mult_matrix_exception : public base_exception
{
public:
    cannot_mult_matrix_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
    : base_exception(filename, classname, line, time, info) {};
    std::string what(void) {return "Cannot mult matrix\n" + this->err_info;}
};

class is_not_square_exception : public base_exception
{
public:
    is_not_square_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
    : base_exception(filename, classname, line, time, info) {};
    std::string what(void) {return "Matrix is not square\n" + this->err_info;}
};

#endif /* errors_h */
