#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include "converterjson.h"
#include <vector>
#include <map>
#include <string>
//#include <gtest/gtest.h>

struct Entry {
    size_t doc_id, count =1;
    // Данный оператор необходим для проведения тестовых сценариев
    bool operator ==(const Entry& other) const {
    return (doc_id == other.doc_id &&
            count == other.count);
    }
};
class InvertedIndex {
public:
InvertedIndex() = default;
std::string path;
/**
* Обновить или заполнить базу документов, по которой будем совершать
поиск
* @param texts_input содержимое документов
*/
std::vector<std::string> OpenFile(std::string str){
    std::vector<std::string> wordList;
    std::string word;
    std::ifstream file(path+"\\"+str);
    while(!file.eof()){
        file >> word;
        wordList.push_back(word);
    }

    file.close();
    return  wordList;
};
void SetPath(std::string _path){
    path = _path;
};

void UpdateDocumentBase(std::vector<std::string> input_docs){
    std::vector<std::string> new_docs;
    for(int i=0;i<input_docs.size();i++){
        bool add =false;
        for(int j=0;j<docs.size() && !add;j++)
            add =(input_docs[i] == docs[j]);

        if(!add){
            new_docs.push_back(input_docs[i]);
        }
    }

    Entry wordCase;
    for(int i=0;i<new_docs.size();i++){
        std::vector<std::string> textList = OpenFile(new_docs[i]);
        int a;
        for(int j=0;j<textList.size();j++)
        {
            a =docs.size()+1;
            auto search = freq_dictionary.find(textList[j]);
            if(search != freq_dictionary.end()){
                bool add =false;
                for(int k=0;k<search->second.size() && !add;k++)
                    if(search->second[k].doc_id == a){
                        add =true;
                        search->second[k].count++;
                    }
                if(!add){
                    Entry wordCase = Entry();
                    wordCase.doc_id=a;
                    search->second.push_back(wordCase);
                }
            }else{
                Entry wordCase = Entry();
                wordCase.doc_id=a;
                freq_dictionary[textList[j]].push_back(wordCase);
            }
        }

        docs.push_back(new_docs[i]);
    }

    //std::cout << freq_dictionary.size() << std::endl;
    docsSize = docs.size();
};
/**
* Метод определяет количество вхождений слова word в загруженной базе
документов
* @param word слово, частоту вхождений которого необходимо определить
* @return возвращает подготовленный список с частотой слов
*/
std::vector<Entry> GetWordCount(const std::string& word){
    auto search = freq_dictionary.find(word);
    if(search != freq_dictionary.end())
        return search->second;
    return std::vector<Entry>();

};
int docsSize;
private:
std::vector<std::string> docs; // список содержимого документов
std::map<std::string, std::vector<Entry>> freq_dictionary; // частотный словарь
};



/*
using namespace std;
void TestInvertedIndexFunctionality(
const vector<string>& docs,
const vector<string>& requests,
const std::vector<vector<Entry>>& expected
) {
std::vector<std::vector<Entry>> result;
InvertedIndex idx;
idx.UpdateDocumentBase(docs);
for(auto& request : requests) {
std::vector<Entry> word_count = idx.GetWordCount(request);
result.push_back(word_count);
}
ASSERT_EQ(result, expected);
}
TEST(TestCaseInvertedIndex, TestBasic) {
const vector<string> docs = {
"london is the capital of great britain",
"big ben is the nickname for the Great bell of the striking clock"
};
const vector<string> requests = {"london", "the"};
const vector<vector<Entry>> expected = {
{
{0, 1}
}, {
{0, 1}, {1, 3}
}
};
TestInvertedIndexFunctionality(docs, requests, expected);
}
TEST(TestCaseInvertedIndex, TestBasic2) {
const vector<string> docs = {
"milk milk milk milk water water water",
"milk water water",
"milk milk milk milk milk water water water water water",
"americano cappuccino"
};
const vector<string> requests = {"milk", "water", "cappuchino"};
const vector<vector<Entry>> expected = {
{
{0, 4}, {1, 1}, {2, 5}
}, {
{0, 2}, {1, 2}, {2, 5}
}, {
{3, 1}
}
};
TestInvertedIndexFunctionality(docs, requests, expected);
}
TEST(TestCaseInvertedIndex, TestInvertedIndexMissingWord) {
const vector<string> docs = {
"a b c d e f g h i j k l",
"statement"
};
const vector<string> requests = {"m", "statement"};
const vector<vector<Entry>> expected = {
{
}, {
{1, 1}
}
};
TestInvertedIndexFunctionality(docs, requests, e
*/
#endif // INVERTEDINDEX_H
