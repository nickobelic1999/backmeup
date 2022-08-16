#include <iostream>
#include <fstream>
#include <sstream>

#include "cURLpp.hpp"
#include "Easy.hpp"
#include "Options.hpp"

#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"

using json = nlohmann::json;

std::string Auth_Account_Url = "https://api.backblazeb2.com/b2api/v2/b2_authorize_account";

int main(int argc, const char* argv[])
{
    std::string fileName = "./response.json";
    std::ofstream outFile(fileName);
    std::ifstream inFile(fileName);

    std::stringstream jsonString;
    cURLpp::Easy easyHandle;
    json data;

    std::cout << "Initialized cURLpp" << std::endl;
    cURLpp::initialize();

    easyHandle.setOpt(cURLpp::Options::Url(Auth_Account_Url));
    easyHandle.setOpt(cURLpp::Options::UserPwd("d3d4ac0eb209:004147fd7ce03cb42ace6b9a87747d0f7780b632f7"));

    easyHandle.setOpt(cURLpp::Options::WriteStream(&jsonString));

    jsonString << easyHandle.perform();
    outFile << jsonString.rdbuf();
    outFile.flush();
    outFile.close();

    data = json::parse(inFile);



    std::cout << "Terminated cURLpp" << std::endl;
    cURLpp::terminate();

    return 0;
}
