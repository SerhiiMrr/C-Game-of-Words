#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <fstream>  // ВВОДИТИ СЛОВА З ПРОБІЛАМИ LOGAD SEARCHINLOG і тд
#include <conio.h>
#include <iterator>
#include <algorithm>
#include <set>
#include <vector>
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

   // cout << "\t Привіт!!\nСьогодні ми зіграємо в гру 'Слова'\nЗараз я розкажу тобі правила"<<endl<<endl;

    //system("pause");
   // system("cls");

    string bufer = "правила";
    //rulespintf(bufer);

    ifstream LOGF("LOGS.txt",ios_base::in);
    system("cls");
    string filename;

    int setsize=0;
    while(true)
    {
        cout << " Напиши 'міста', щоб вибрати тему гри 'міста України'\n\t'країни', щоб вибрати тему гри 'країни світу (члени ООН)' \n\t'прізвища', щоб вибрати тему 'Прізвища 143 групи'"<<endl;
        getline(cin,bufer);

        if (exit(bufer) == 1) return 0;

        if ( bufer == "Правила" || bufer == "правила")
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

    string Random[50];
    string line2;
    bufer="";
    char b = '\0';

    bool f=0;
    string word;
    label:// СПАГЕТТІ >>> використано goto
    int i;
    srand(time(NULL));

    cin >> bufer;
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
            //ваіпаcin >> bufer;
        }
        else if(searchinLOG(bufer) == 1)
            {
                cout<<"Не хитруй!\nЦе слово вже використовувалось."<<endl;
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

        setsize=0;
        //rightword(bufer,filename);

       // while (rightword(bufer,filename) == true)
        //{
        LOGAD(bufer);
        b = bufer[bufer.length()-1];//Буква на яку потрібне слово
        if( b == 'ь' || b == 'и' )
        {
            cout<<"Немає слів на - "<<b<<endl;
            b = bufer[bufer.length()-2];
        }
        cout<<"Я повинна сказати слово на букву - "<<b<<endl;
        file.open(filename.c_str(),ios_base::in);
        word = "";
        i=0;//ітератор

           /* while(!file.eof())
            {
                f=1;//добавить слово в обработку
                file>>word;// нове слово

                f = !(searchinLOG(word));
                if( word[0] != b )
                    f=0;
                else if(f)
                {
                    Random[i] = word;
                    i++;
                }
                else if( i == 100 )
                {
                    break;
                }
            }*/

        srand(time(NULL));

        getword(bufer,filename,setsize,i,line2);

        word = line2;
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
            cin>>bufer;

            ConverttoLow(bufer);
            if (exit(bufer) == 1) return 0;

            if ( bufer == "правила" )
            {
                rulespintf(bufer);
                system("cls");
                bufer="";
                cout << "Введи слово - ";
                goto label2;
            }

            //ConverttoLow(bufer);

            if(searchinLOG(bufer) == 1)
            {
                cout<<"Не хитруй!\nЦе слово вже використовувалось."<<endl;
                continue;
            }

            if(bufer[0] == b)
                break;

            cout<<"Скажи слово на букву - "<<b<<endl;

            }
            file.close();
       // }

        }
        /*cout << "Не хитруй!\nЦе не слово або це слово не по темі222222222"<< endl;
        if ( b == '\0')
                cout << "Скажи своє слово - ";
        else cout << "Скажи слово на букву - "<<b<<endl;
        goto label;*/
        file.close();
        file.clear();
   return 0;
}
