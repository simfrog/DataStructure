#include "LSLineEditor.h"
#include <iostream>
#include <limits>

void Usage(){
    std::cout << "[메뉴선택] i-입력, d-삭제, r-변경, p-출력, l-파일읽기, s-저장, q-종료=> ";
}

int main(){
    LineEditor editor;
    char command;
    do{
        Usage();
        command = std::getchar();
        std::cin.sync();
        switch(command) {
            case 'd': 
                editor.DeleteLine();
                break;
            case 'i': 
                editor.InsertLine();
                break;
            case 'r': 
                editor.ReplaceLine(); 
                break;
            case 'l': 
                editor.LoadFile("test.txt");
                break; 
            case 's': 
                editor.SaveFile("test.txt");
                break;
            case 'p': 
                editor.Display();
                break;
            case 'q':
                break;
        }     
    } while(command != 'q');
    return 0;
}