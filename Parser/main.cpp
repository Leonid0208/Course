#include <iostream>
#include <string>
#include "Document.h"
#include "Node.h"
#include <vector>
#include <fstream>
#include <regex>
using namespace std;


std::string OpenFile(){
    std::string line;
    std::string Html;

    std::ifstream in("/home/leonid/Parser/Index.html"); // путь
    if (in.is_open()){
        while (getline(in, line)){
            Html += line;
        }
    }
    in.close();
    return Html;
}

struct Vacancy
{
    string header;
    string employer;
    string place;
    string exposition;
    string salary;
    string link;
};

void Parse(string Html){
    std::string page = Html;
    CDocument doc;
    int it;
    string end;
    doc.parse(page.c_str());
    Vacancy vacancy[100];
    for(int i=0;i<100; i++){
        CNode pNode = doc.find("div.vacancy-serp a.HH-LinkModifier").nodeAt(i); // Заголовок
        std::string content = page.substr(pNode.startPos(), pNode.endPos() - pNode.startPos());
        vacancy[i+1].header = content.c_str();

        cout << vacancy[i+1].header << endl;

        pNode = doc.find("div.vacancy-serp a.bloko-link_secondary").nodeAt(i); // Компания
        content = page.substr(pNode.startPos(), pNode.endPos() - pNode.startPos());
        vacancy[i+1].employer = content.c_str();

        cout << vacancy[i+1].employer << endl;

        pNode = doc.find("div.vacancy-serp span.vacancy-serp-item__meta-info").nodeAt(i); // Локация
        content = page.substr(pNode.startPos(), pNode.endPos() - pNode.startPos());
        vacancy[i+1].place = content.c_str();

        cout << vacancy[i+1].place << endl;

        pNode = doc.find("div.vacancy-serp div[data-qa=vacancy-serp__vacancy_snippet_requirement]").nodeAt(i); // Описание
        content = page.substr(pNode.startPos(), pNode.endPos() - pNode.startPos());
        string excess_exposition = "<span class=\"highlighted highlighted_short\">С++</span>";
        end = content.c_str();
        it = end.find(excess_exposition, 0);
        while (it != string::npos){
            end.replace(it, excess_exposition.size(), "C++");
            it = end.find(excess_exposition, it);
        }

        vacancy[i+1].exposition = end;


        cout << vacancy[i+1].exposition << endl;


        pNode = doc.find("div.vacancy-serp-item__sidebar span").nodeAt(i); // ЗП
        content = page.substr(pNode.startPos(), pNode.endPos() - pNode.startPos());
        string excess_salary = "&nbsp;";
        end = content.c_str();
        it = end.find(excess_salary, 0);
        while (it != string::npos){
            end.replace(it, excess_salary.size(), " ");
            it = end.find(excess_salary, it);
        }
        vacancy[i+1].salary = end;

        cout << vacancy[i+1].salary << endl;

        pNode = doc.find("div.vacancy-serp span.g-user-content").nodeAt(i); // Ссылка
        content = page.substr(pNode.startPos(), pNode.endPos() - pNode.startPos());
        end = content.c_str();
        regex regular("href=[\'\"]"
                      "(.+?)"
                      "[\'\"]");
        cmatch result;
        regex_search(content.c_str(), result, regular);
        end = result[1];

        vacancy[i+1].link = end;
        cout << vacancy[i+1].link << endl;

        cout << endl;
    }
}


int main()
{
  string Html;
  Html = OpenFile();
  Parse(Html);
}
