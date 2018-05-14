#pragma once

#include <iostream>
#include <string>

class Calc_error: public std::runtime_error {
public:
    Calc_error(std::runtime_error* previous,const std::string str,const std::string file,const int line)
    : std::runtime_error(str), m_previous(previous), m_file(file), m_line(line), m_str(str){}

    static void handler();

private:
    const std::string m_str;
    const std::string m_file;
    const int m_line;
    std::runtime_error* m_previous=NULL;

};
