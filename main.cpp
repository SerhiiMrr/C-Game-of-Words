#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <iterator>
#include <algorithm>
#include <set>
#include <ctime>
#include "Gamefunction.h"
//using namespace System;
//using namespace System::Windows::Forms;
using namespace std;

/*[STAThread]
void main2() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MyForm form;
	Application::Run(%form);
*/


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ofstream LOG("LOGS.txt");
    LOG.close();

    ifstream file;//потоки работы с файлами
    ofstream fout;

    cout << "\t Привіт!!\nСьогодні ми зіграємо в гру 'Слова'\nЗараз я розкажу тобі правила"<<endl<<endl;

    system("pause");
    system("cls");

    string bufer = "правила";
    rulespintf(bufer);

    ifstream LOGF("LOGS.txt",ios_base::in);
    system("cls");
    string fhdhfgd;
    int z;
    int setsize=0;
  // PIPISLA
    for (;;)
    {
        cout << " Напиши 'міста', щоб вибрати тему гри 'міста України'\n\t'країни', щоб вибрати тему гри 'країни світу (члени ООН)' \n\t'прізвища', щоб вибрати тему 'Прізвища 143 групи'"<<endl;
        getline(cin,bufer);
        if (bufer == "вихід" || bufer == "Вихід")
        {
            return 0;
        }
        if (bufer == "Правила" || bufer == "правила")
        {
             rulespintf(bufer);
             cout << "Введіть слово:";
             bufer="";
        }
        if ((bufer == "міста") || ( bufer == "Міста"))
        {
            system("cls");
            cout << "Ти вибрав тему 'міста України'. Отож, починаємо гру!\nВведи слово - ";
            filename = "міста.cpp";
            break;
        }
        if ((bufer == "країни") || ( bufer == "Країни"))
        {
            system("cls");
            cout << "Ти вибрав тему 'країни світу (члени ООН)'. Отож, починаємо гру!\nВведи слово - ";
            filename = "країни.cpp";
            break;
        }
        if ((bufer == "прізвища") || ( bufer == "Прізвища"))
        {
            system("cls");
            cout << "Ти вибрав тему 'Прізвища 143 групи'. Отож, починаємо гру!\nВведи слово - ";
            filename = "марки.cpp";
            break;
        }
        else system("cls");
    }

    string Random[100];
    bufer="";
    char b;

    bool f=0;
    char NameFile[6];
    label: int i;
    srand(time(NULL));

    cin >> bufer;
    exit(bufer);
    while(true)//загальний цикл
    {
        if (bufer == "Правила" || bufer == "правила")
        {
            rulespintf(bufer);
            system("cls");
            cout << "Введіть слово - ";
            bufer="";
            cin >> bufer;
        }
        exit(bufer);

        int setsize=0;
        ConverttoLow(bufer);
        rightword(bufer,filename);

        while (rightword(bufer,filename) == true)
        {
            LOGAD(bufer);
            b = bufer[bufer.length()-1];//Буква на яку потрібне слово
            if( b=='ь' || b=='и' )
            {
                cout<<"Немає слів на - "<<b<<endl;
                b = bufer[bufer.length()-2];
            }
            cout<<"Я повинна сказати слово на букву - "<<b<<endl;
            //NameFile[0] == b;//Шукаємо відповідь в файлі
            file.open(filename.c_str(),ios_base::in);
            string word;
            word = "";
            i=0;//ітератор

            while(!file.eof())
            {
                f=1;//добавить слово в обработку
                file>>word;//новое слово в словаре

                f = !(searchinLOG(word));
                if( word[0] != b )
                    f=0;
                if(f)
                {
                    Random[i] = word;
                    i++;
                }
                if( i == 100 )
                {
                    break;
                }
            }

            i-=2;
            if( i <= -2 )
            {
                cout<<"Я не знаю більше слів на букву - "<<b<<endl;
                cout<<"Ти переміг(ла). Поздоровляю"<<endl;
                cin.get();
                return 0;
            }
       //for (int i=0; i<)
        //i=getword(bufer,filename,setsize);

        getword(bufer,filename,setsize);
        srand(time(NULL));
        i=random(setsize);
       // cout << random(setsize)<<"RAНD"<<endl;
        word=Random[i];
        LOGAD(word);


        while((word.find('\n') == string::npos) != 1);
        {



        cout<<"Моя відповідь - ";
        cout<<word<<endl;
        }
        b = word[word.length()-1];
        cout<<"Тобі на букву - "<<b<<endl;

        if( b=='ь'||b=='и' )
        {
            cout<<"Немає слів на букву - "<<b<<endl;
            b = word [word.length()-2];
            cout<<"Скажи слово на букву - "<<b<<endl;
        }
        LOG.close();
        LOG.open("LOGS.txt",ios_base::in);

        while(true)
        {
            cin>>bufer;
            if (bufer == "Правила" || bufer == "правила")
            {
                rulespintf(bufer);
                system("cls");
                bufer="";
                cout << "Введи слово - ";
                cin >> bufer;
                if (bufer == "Правила" || bufer == "правила")
                {
                    rulespintf(bufer);
                }
            }

            ConverttoLow(bufer);

            if(searchinLOG(bufer))
            {
                cout<<"Не хитруй!\nЦе слово вже використовувалось."<<endl;
                continue;
            }

            exit(bufer);

            if(bufer[0] == b)
                break;
            cout<<"Скажи слово на букву - "<<b<<endl;
            exit(bufer);
            }
            file.close();
        }
        cout << "Не хитруй!\nЦе не слово або це слово не по темі"<< endl;
        cout << "Скажи слово на букву - "<<b<<endl;
        goto label;
        }
        file.close();
        file.clear();
   return 0;
}
