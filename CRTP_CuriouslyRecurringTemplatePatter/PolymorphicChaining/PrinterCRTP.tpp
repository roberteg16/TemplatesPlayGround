#ifndef __PRINTER_H__
#define __PRINTER_H__

#include <iostream>

template<typename ConcretePrinter>
class Printer
{
    public:
        constexpr Printer (std::ostream& stream) : stream(stream) {}

        template <typename T>
        ConcretePrinter& print(T&& t) { stream << t; return *static_cast<ConcretePrinter*>(this); }

        template<typename T>
        ConcretePrinter& printws(T&& t) { stream << t << ' '; return *static_cast<ConcretePrinter*>(this); }

        template <typename T>
        ConcretePrinter& println(T&& t) { stream << t << std::endl; return *static_cast<ConcretePrinter*>(this); }

        ~Printer () = default;

    private:
        std::ostream& stream;
};


class CoutPrinter : public Printer<CoutPrinter>
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

    // This now works because of CRTP. As we can see, now Printer returns the correct type.
    printer.printws("Hello").set_console_color(10).println("wold");

    return 0;
}


#endif /* __PRINTER_H__ */
