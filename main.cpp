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

    ifstream file;//������ ������ � �������
    ofstream fout;

    cout << "\t �����!!\n������� �� ������ � ��� '�����'\n����� � ������� ��� �������"<<endl<<endl;

    system("pause");
    system("cls");

    string bufer = "�������";
    rulespintf(bufer);

    ifstream LOGF("LOGS.txt",ios_base::in);
    system("cls");
    string fhdhfgd;
    int z;
    int setsize=0;
  // PIPISLA
    for (;;)
    {
        cout << " ������ '����', ��� ������� ���� ��� '���� ������'\n\t'�����', ��� ������� ���� ��� '����� ���� (����� ���)' \n\t'�������', ��� ������� ���� '������� 143 �����'"<<endl;
        getline(cin,bufer);
        if (bufer == "�����" || bufer == "�����")
        {
            return 0;
        }
        if (bufer == "�������" || bufer == "�������")
        {
             rulespintf(bufer);
             cout << "������ �����:";
             bufer="";
        }
        if ((bufer == "����") || ( bufer == "̳���"))
        {
            system("cls");
            cout << "�� ������ ���� '���� ������'. ����, �������� ���!\n����� ����� - ";
            filename = "����.cpp";
            break;
        }
        if ((bufer == "�����") || ( bufer == "�����"))
        {
            system("cls");
            cout << "�� ������ ���� '����� ���� (����� ���)'. ����, �������� ���!\n����� ����� - ";
            filename = "�����.cpp";
            break;
        }
        if ((bufer == "�������") || ( bufer == "�������"))
        {
            system("cls");
            cout << "�� ������ ���� '������� 143 �����'. ����, �������� ���!\n����� ����� - ";
            filename = "�����.cpp";
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
    while(true)//��������� ����
    {
        if (bufer == "�������" || bufer == "�������")
        {
            rulespintf(bufer);
            system("cls");
            cout << "������ ����� - ";
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
            b = bufer[bufer.length()-1];//����� �� ��� ������� �����
            if( b=='�' || b=='�' )
            {
                cout<<"���� ��� �� - "<<b<<endl;
                b = bufer[bufer.length()-2];
            }
            cout<<"� ������� ������� ����� �� ����� - "<<b<<endl;
            //NameFile[0] == b;//������ ������� � ����
            file.open(filename.c_str(),ios_base::in);
            string word;
            word = "";
            i=0;//��������

            while(!file.eof())
            {
                f=1;//�������� ����� � ���������
                file>>word;//����� ����� � �������

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
                cout<<"� �� ���� ����� ��� �� ����� - "<<b<<endl;
                cout<<"�� ������(��). �����������"<<endl;
                cin.get();
                return 0;
            }
       //for (int i=0; i<)
        //i=getword(bufer,filename,setsize);

        getword(bufer,filename,setsize);
        srand(time(NULL));
        i=random(setsize);
       // cout << random(setsize)<<"RA�D"<<endl;
        word=Random[i];
        LOGAD(word);


        while((word.find('\n') == string::npos) != 1);
        {



        cout<<"��� ������� - ";
        cout<<word<<endl;
        }
        b = word[word.length()-1];
        cout<<"��� �� ����� - "<<b<<endl;

        if( b=='�'||b=='�' )
        {
            cout<<"���� ��� �� ����� - "<<b<<endl;
            b = word [word.length()-2];
            cout<<"����� ����� �� ����� - "<<b<<endl;
        }
        LOG.close();
        LOG.open("LOGS.txt",ios_base::in);

        while(true)
        {
            cin>>bufer;
            if (bufer == "�������" || bufer == "�������")
            {
                rulespintf(bufer);
                system("cls");
                bufer="";
                cout << "����� ����� - ";
                cin >> bufer;
                if (bufer == "�������" || bufer == "�������")
                {
                    rulespintf(bufer);
                }
            }

            ConverttoLow(bufer);

            if(searchinLOG(bufer))
            {
                cout<<"�� ������!\n�� ����� ��� �����������������."<<endl;
                continue;
            }

            exit(bufer);

            if(bufer[0] == b)
                break;
            cout<<"����� ����� �� ����� - "<<b<<endl;
            exit(bufer);
            }
            file.close();
        }
        cout << "�� ������!\n�� �� ����� ��� �� ����� �� �� ���"<< endl;
        cout << "����� ����� �� ����� - "<<b<<endl;
        goto label;
        }
        file.close();
        file.clear();
   return 0;
}
