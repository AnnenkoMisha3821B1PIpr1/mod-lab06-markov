// Copyright 2024 Annenko Misha

//#include "textgen.h"
#include "../include/textgen.h"

// количество слов в префиксе
const int NPREF = 2;
//объем текста на выходе
const int MAXGEN = 1000;


void Read_and_show_old_text(std::string& File_contents) {
    std::ifstream file("text.txt");
    std::string str;
    while (std::getline(file, str))
    {
        std::string g = str;
        if (g.size() == 0) {
            str += " ";
        }
        File_contents += str;
    }
    file.close();
}

int main()
{
    setlocale(LC_ALL, "");

    textgen Markov_Chain;

    std::string file_contents;

    Read_and_show_old_text(file_contents);
    
    Markov_Chain.memorization(file_contents, NPREF);

    std::cout << Markov_Chain.generate__text(MAXGEN, NPREF);
}
