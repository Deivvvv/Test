#include "converterjson.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;

std::vector<std::string> GetTextDocuments(){
    std::vector<std::string> words = std::vector<std::string>();
    /*std::fstream file;
    file.open (QDir::homePath().toStdString()+"\\Documents\\search_engine\\" +str);


   // QStringList *words = new  QStringList();
    std::vector<std::string> words =std::vector<std::string>() ;
    std::string word;
    while(!file.eof()){
        file >> word;
        words.push_back(word);
    }
    file.close();

    return words;*/
    std::ifstream file;
    file.open ("config.json");
    json jf = json::parse(file);
    std::cout << jf;

    std::string str(R"({"json": "beta"})");
    json js = json::parse(str);
    return words;
}
int GetResponsesLimit();
/**
* Метод получения запросов из файла requests.json
* @return возвращает список запросов из файла requests.json
*/
std::vector<std::string> GetRequests();
/**
* Положить в файл answers.json результаты поисковых запросов
*/
void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers);
