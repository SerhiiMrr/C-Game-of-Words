#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h> // SetConsoleOutputCP & SetConsoleCP
#include <fstream>
#include <conio.h>
#include <vector>
#include <ctime>
#include "Gamefunction.h"

using namespace std;

int main()
{
    SetConsoleCP(1251); // Ввід кирилицею
    SetConsoleOutputCP(1251);// Вивід кирилицею

    ofstream LOG("LOGS.txt"); // Ств файл
    LOG.close();// Зберігаємо файл
    //потоки роботи з файлами
    ifstream file;
    ofstream fout;

    cout << "\t Привіт!!\nСьогодні ми зіграємо в гру 'Слова'\nЗараз я розкажу тобі правила"<<endl<<endl;

    system("pause");
    system("cls");

    string bufer = "правила";
    rulespintf(bufer);

    system("cls");
    string filename;

    int setsize=0;
    while(true)
    {
        cout << " Напиши 'міста', щоб вибрати тему гри 'міста України'\n\t'країни', щоб вибрати тему гри 'країни світу (члени ООН)' \n\t'прізвища', щоб вибрати тему 'Прізвища 143 групи'"<<endl;
        getline(cin,bufer);


        if (exit(bufer) == 1) return 0;

        else if ( bufer == "Правила" || bufer == "правила")
        {
             rulespintf(bufer);
             cout << "Введіть слово:";
             bufer="";
        }
        else if ( bufer == "міста" || bufer == "Міста")
        {
            system("cls");
            cout << "Ти вибрав тему 'міста України'. Отож, починаємо гру!\nВведи слово - ";
            filename = "міста.cpp";
            break;
        }
        else if ( bufer == "країни" || bufer == "Країни")
        {
            system("cls");
            cout << "Ти вибрав тему 'країни світу (члени ООН)'. Отож, починаємо гру!\nВведи слово - ";
            filename = "країни.cpp";
            break;
        }
        else if ( bufer == "прізвища" || bufer == "Прізвища")
        {
            system("cls");
            cout << "Ти вибрав тему 'Прізвища 143 групи'. Отож, починаємо гру!\nВведи слово - ";
            filename = "марки.cpp";
            break;
        }
        else system("cls");
    }

    bufer="";
    char b = '\0';
    int ls_lt; // беремо останню чи передостанню літеру в слові
    srand ( time(NULL) );
    bool f=0;
    string word;
    label:// СПАГЕТТІ >>> використано goto
    int i;

    getline(cin,bufer);

    ConverttoLow(bufer);

    if (exit(bufer) == 1) return 0;

    while(true)//загальний цикл
    {
        ConverttoLow(bufer);

        if (exit(bufer) == 1) return 0;

        else if ( bufer == "правила" )
        {
            rulespintf(bufer);
            system("cls");
            cout << "Введіть слово - ";
            bufer="";
            goto label;
        }
        while(rightword(bufer,filename) == 0)
        {
            cout << "Не хитруй!\nЦе не слово або це слово не по темі"<< endl;
            if ( b == '\0')
            {
                cout << "Скажи своє слово - ";
            }
            else
            {
                cout << "Скажи слово на букву - "<<b<<endl;
            }
            goto label;
        }
        if(searchinLOG(bufer) == 1)
        {
            cout<<"Не хитруй!\nЦе слово вже використовувалось."<<endl;
            goto label;
        }

        setsize=0;
        ls_lt = 1;

        LOGAD(bufer); // Після перевірки правильності введеного слова записуємо його у лог.

        b = bufer[bufer.length()-1];//Буква на яку потрібне слово
        if( b == 'ь' || b == 'и' )
        {
            ls_lt = 2;
            cout<<"Немає слів на - "<<b<<endl;
            b = bufer[bufer.length() - ls_lt];
        }
        cout<<"Я повинна сказати слово на букву - "<<b<<endl;
        file.open(filename.c_str(),ios_base::in);
        word = "";

        i=0;//ітератор

        getword(bufer,filename,setsize,word,ls_lt);

        LOGAD(word);

        if( word == "end" )
        {
            cout<<"Я не знаю більше слів на букву - "<<b<<endl;
            cout<<"Ти переміг(ла). Поздоровляю"<<endl;
            cin.get();
            return 0;
        }
        cout<<"Моя відповідь - ";
        cout<<word<<endl;

        b = word[word.length()-1];
        cout<<"Тобі на букву - "<<b<<endl;

        if( b=='ь'||b=='и' )
        {
            cout << "Немає слів на букву - "<< b << endl;
            b = word [word.length()-2];
            cout << "Скажи слово на букву - "<< b << endl;
        }
        LOG.close();
        LOG.open("LOGS.txt",ios_base::in);
        while(true)
        {
            label2:

            getline(cin,bufer);

            ConverttoLow(bufer); // Перетворення в реєстер малих букв

            if (exit(bufer) == 1) return 0;// Перевірка чи не вихід

            if ( bufer == "правила" )// Перевірка чи не правила
            {
                rulespintf(bufer);
                system("cls");
                bufer="";
                cout << "Введи слово - ";
                goto label2; // Перехід на початок while циклу
            }

            if(bufer[0] == b)
                break;

            cout<<"Скажи слово на букву - "<<b<<endl;

            }
            file.close();
            LOG.close();
        }
        file.close();
        file.clear();
   return 0;
}
