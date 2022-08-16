#include <iostream>

#include "cURLpp.hpp"
#include "Easy.hpp"
#include "Options.hpp"


std::string Auth_Account_Url = "https://api.backblazeb2.com/b2api/v2/b2_authorize_account";

int main()
{
    cURLpp::Easy easyhandle;
    std::cout << "Initialized cURLpp" << std::endl;
    cURLpp::initialize();

    easyhandle.setOpt(cURLpp::Options::Url(Auth_Account_Url));
    easyhandle.setOpt(cURLpp::Options::UserPwd("APPLICATION_KEY_ID:APPLICATION_KEY"));

    easyhandle.perform();

    std::cout << std::endl;

    std::cout << "Terminated cURLpp" << std::endl;
    cURLpp::terminate();

    return 0;
}
