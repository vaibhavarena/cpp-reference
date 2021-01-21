#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <future>
#include <sstream>

void modifyString(std::promise<std::string> &&prms, std::string s)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    s += " has been modified";

    prms.set_value(s);
}

int main()
{
    auto myid = std::this_thread::get_id();
    std::stringstream ss;
    ss << myid;
    std::string a = ss.str();
    std::string msg =  a + " thread";

    std::cout<< msg << "\n";

    std::promise<std::string> prms;         // Create a promise and future channel
    std::future<std::string> ftr = prms.get_future();

    std::thread t(modifyString, std::move(prms), msg);  // A promise and future is a single channel, so only move

    msg = ftr.get();        // get the setValue back from function

    std::cout<< msg << "\n";

    t.join();
}