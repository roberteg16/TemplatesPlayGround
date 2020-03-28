#ifndef __PRINTER_H__
#define __PRINTER_H__

#include <iostream>

class Printer
{
    public:
        constexpr Printer (std::ostream& stream) : stream(stream) {}

        template <typename T>
        Printer& print(T&& t) { stream << t; return *this; }

        template<typename T>
        Printer& printws(T&& t) { stream << t; return *this; }

        template <typename T>
        Printer& println(T&& t) { stream << t << std::endl; return *this; }

        ~Printer () = default;

    private:
        std::ostream& stream;
};


class CoutPrinter : public Printer
{
    public:
        constexpr CoutPrinter() : Printer(std::cout) {}

        CoutPrinter& set_console_color(std::size_t color) {
            /* Change color */
            return *this;
        }

        ~CoutPrinter () = default;
};


int main(int argc, char *argv[])
{

    CoutPrinter printer;

    // This example does not work because [printws, print, println] returns a reference to Printer, and Printer does not have
    // a function called set_console_color.
    //                      v------------ at this point we have a Printer not a CoutPrinter
    printer.printws("Hello").set_console_color(10).print("wold");

    return 0;
}


#endif /* __PRINTER_H__ */
