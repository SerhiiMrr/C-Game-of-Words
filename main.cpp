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
    SetConsoleCP(1251); // ��� ���������
    SetConsoleOutputCP(1251);// ���� ���������

    ofstream LOG("LOGS.txt"); // ��� ����
    LOG.close();// �������� ����
    //������ ������ � �������
    ifstream file;
    ofstream fout;

    cout << "\t �����!!\n������� �� ������ � ��� '�����'\n����� � ������� ��� �������"<<endl<<endl;

    system("pause");
    system("cls");

    string bufer = "�������";
    rulespintf(bufer);

    system("cls");
    string filename;

    int setsize=0;
    while(true)
    {
        cout << " ������ '����', ��� ������� ���� ��� '���� ������'\n\t'�����', ��� ������� ���� ��� '����� ���� (����� ���)' \n\t'�������', ��� ������� ���� '������� 143 �����'"<<endl;
        getline(cin,bufer);


        if (exit(bufer) == 1) return 0;

        else if ( bufer == "�������" || bufer == "�������")
        {
             rulespintf(bufer);
             cout << "������ �����:";
             bufer="";
        }
        else if ( bufer == "����" || bufer == "̳���")
        {
            system("cls");
            cout << "�� ������ ���� '���� ������'. ����, �������� ���!\n����� ����� - ";
            filename = "����.cpp";
            break;
        }
        else if ( bufer == "�����" || bufer == "�����")
        {
            system("cls");
            cout << "�� ������ ���� '����� ���� (����� ���)'. ����, �������� ���!\n����� ����� - ";
            filename = "�����.cpp";
            break;
        }
        else if ( bufer == "�������" || bufer == "�������")
        {
            system("cls");
            cout << "�� ������ ���� '������� 143 �����'. ����, �������� ���!\n����� ����� - ";
            filename = "�����.cpp";
            break;
        }
        else system("cls");
    }

    bufer="";
    char b = '\0';
    int ls_lt; // ������ ������� �� ������������ ����� � ����
    srand ( time(NULL) );
    bool f=0;
    string word;
    label:// ������Ҳ >>> ����������� goto
    int i;

    getline(cin,bufer);

    ConverttoLow(bufer);

    if (exit(bufer) == 1) return 0;

    while(true)//��������� ����
    {
        ConverttoLow(bufer);

        if (exit(bufer) == 1) return 0;

        else if ( bufer == "�������" )
        {
            rulespintf(bufer);
            system("cls");
            cout << "������ ����� - ";
            bufer="";
            goto label;
        }
        while(rightword(bufer,filename) == 0)
        {
            cout << "�� ������!\n�� �� ����� ��� �� ����� �� �� ���"<< endl;
            if ( b == '\0')
            {
                cout << "����� ��� ����� - ";
            }
            else
            {
                cout << "����� ����� �� ����� - "<<b<<endl;
            }
            goto label;
        }
        if(searchinLOG(bufer) == 1)
        {
            cout<<"�� ������!\n�� ����� ��� �����������������."<<endl;
            goto label;
        }

        setsize=0;
        ls_lt = 1;

        LOGAD(bufer); // ϳ��� �������� ����������� ��������� ����� �������� ���� � ���.

        b = bufer[bufer.length()-1];//����� �� ��� ������� �����
        if( b == '�' || b == '�' )
        {
            ls_lt = 2;
            cout<<"���� ��� �� - "<<b<<endl;
            b = bufer[bufer.length() - ls_lt];
        }
        cout<<"� ������� ������� ����� �� ����� - "<<b<<endl;
        file.open(filename.c_str(),ios_base::in);
        word = "";

        i=0;//��������

        getword(bufer,filename,setsize,word,ls_lt);

        LOGAD(word);

        if( word == "end" )
        {
            cout<<"� �� ���� ����� ��� �� ����� - "<<b<<endl;
            cout<<"�� ������(��). �����������"<<endl;
            cin.get();
            return 0;
        }
        cout<<"��� ������� - ";
        cout<<word<<endl;

        b = word[word.length()-1];
        cout<<"��� �� ����� - "<<b<<endl;

        if( b=='�'||b=='�' )
        {
            cout << "���� ��� �� ����� - "<< b << endl;
            b = word [word.length()-2];
            cout << "����� ����� �� ����� - "<< b << endl;
        }
        LOG.close();
        LOG.open("LOGS.txt",ios_base::in);
        while(true)
        {
            label2:

            getline(cin,bufer);

            ConverttoLow(bufer); // ������������ � ������ ����� ����

            if (exit(bufer) == 1) return 0;// �������� �� �� �����

            if ( bufer == "�������" )// �������� �� �� �������
            {
                rulespintf(bufer);
                system("cls");
                bufer="";
                cout << "����� ����� - ";
                goto label2; // ������� �� ������� while �����
            }

            if(bufer[0] == b)
                break;

            cout<<"����� ����� �� ����� - "<<b<<endl;

            }
            file.close();
            LOG.close();
        }
        file.close();
        file.clear();
   return 0;
}
