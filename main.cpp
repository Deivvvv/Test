#include <iostream>
#include "converterjson.h"
#include "converterjson.cpp"
#include "invertedindex.h"
#include "searchserver.h"

#include <vector>
#include <string>
//using namespace std;

/*
#include "gtest/gtest.h"
TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
};*/

std::string FindPath(std::string word){
    int a=0;
    for( int i=0;i<word.size();i++)
        if(word[i] =='\\')
                a=i;

    std::string str;
    for( int i=0;i<a;i++)
    str +=word[i];

    return str;
}

int main(int argc, char *argv[])
{
    std::string mainPath = FindPath(std::string(argv[0]));
    //std::cout <<  mainPath << std::endl;
    InvertedIndex index;
    index.SetPath(mainPath);

    ConverterJSON conv = ConverterJSON(mainPath);
    //conv.GetTextDocuments();
    index.UpdateDocumentBase(conv.GetTextDocuments());

    SearchServer search(index);
    std::vector<std::vector<RelativeIndex>> result = search.search(conv.GetRequests());

    std::vector<std::vector<std::pair<int, float>>> answers = std::vector<std::vector<std::pair<int, float>>>(result.size());
    for(int i=0;i< result.size();i++){
        std::vector<std::pair<int, float>>resultCase =std::vector<std::pair<int, float>>(result[i].size());
        for(int i1=0;i1< result[i].size();i1++){
        std::pair<int, float> resultCaseData =  std::pair<int, float>();
        std::cout <<result[i][i1].doc_id <<std::endl;
        resultCaseData.first = result[i][i1].doc_id;
        resultCaseData.second = result[i][i1].rank;
        resultCase[i1] = resultCaseData;
        }
        answers[i] =resultCase;
    }
    conv.putAnswers(answers);
   // index.

   // std::string str(argv[0]);
   // str.split
//SetConverter
    //ConverterJSON conv = ConverterJSON(mainPath);
    //conv.GetTextDocuments(mainPath);
   // conv.Test(mainPath);
   // conv.GetTextDocuments();
    //std::vector<std::string> str =conv.GetTextDocuments();

    std::cout << "Hello World!" << std::endl;
    return 0;
}
