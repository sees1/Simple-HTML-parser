#include <iostream>
#include <fstream>
#include <iomanip>

std::string ReadAll(const std::string &filename)
{
    std::ifstream ifs;
    ifs.open(filename);
    ifs.seekg(0, std::ios::end);
    size_t lenght = ifs.tellg();
    ifs.seekg(0,std::ios::beg);
    std::string buff (lenght, 0);
    ifs.read(&buff[0], lenght);
    ifs.close();

    return buff;
}

void WriteAll(std::string &row_seq)
{
    
}

int main(){
    std::string row_seq = ReadAll("sait.html");
    std::cout<<"First word is = "<<word;
}