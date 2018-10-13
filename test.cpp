//
// Created by Zelda Hessler on 10/12/18.
//

#include <string>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/signals2.hpp>

using namespace std;

struct HelloWorld {
    void operator()() const {
        std::cout << "Hello, from a signal!" << std::endl;
    }
};

void print_something() {
    std::string hello("Hello, from Boost!");

    BOOST_FOREACH(char ch, hello) {
                    std::cout << ch;
                }
}


void do_signal() {
    boost::signals2::signal<void()> sig;
    HelloWorld hello;
    sig.connect(hello);

    sig();
}