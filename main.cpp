#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <fstream>  // ������� ����� � ��������� LOGAD SEARCHINLOG � ��
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

    ifstream file;//������ ������ � �������
    ofstream fout;

   // cout << "\t �����!!\n������� �� ������ � ��� '�����'\n����� � ������� ��� �������"<<endl<<endl;

    //system("pause");
   // system("cls");

    string bufer = "�������";
    //rulespintf(bufer);

    ifstream LOGF("LOGS.txt",ios_base::in);
    system("cls");
    string filename;

    int setsize=0;
    while(true)
    {
        cout << " ������ '����', ��� ������� ���� ��� '���� ������'\n\t'�����', ��� ������� ���� ��� '����� ���� (����� ���)' \n\t'�������', ��� ������� ���� '������� 143 �����'"<<endl;
        getline(cin,bufer);

        if (exit(bufer) == 1) return 0;

        if ( bufer == "�������" || bufer == "�������")
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

    string Random[50];
    string line2;
    bufer="";
    char b = '\0';

    bool f=0;
    string word;
    label:// ������Ҳ >>> ����������� goto
    int i;
    srand(time(NULL));

    cin >> bufer;
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
            //����cin >> bufer;
        }
        else if(searchinLOG(bufer) == 1)
            {
                cout<<"�� ������!\n�� ����� ��� �����������������."<<endl;
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

        setsize=0;
        //rightword(bufer,filename);

       // while (rightword(bufer,filename) == true)
        //{
        LOGAD(bufer);
        b = bufer[bufer.length()-1];//����� �� ��� ������� �����
        if( b == '�' || b == '�' )
        {
            cout<<"���� ��� �� - "<<b<<endl;
            b = bufer[bufer.length()-2];
        }
        cout<<"� ������� ������� ����� �� ����� - "<<b<<endl;
        file.open(filename.c_str(),ios_base::in);
        word = "";
        i=0;//��������

           /* while(!file.eof())
            {
                f=1;//�������� ����� � ���������
                file>>word;// ���� �����

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
            cin>>bufer;

            ConverttoLow(bufer);
            if (exit(bufer) == 1) return 0;

            if ( bufer == "�������" )
            {
                rulespintf(bufer);
                system("cls");
                bufer="";
                cout << "����� ����� - ";
                goto label2;
            }

            //ConverttoLow(bufer);

            if(searchinLOG(bufer) == 1)
            {
                cout<<"�� ������!\n�� ����� ��� �����������������."<<endl;
                continue;
            }

            if(bufer[0] == b)
                break;

            cout<<"����� ����� �� ����� - "<<b<<endl;

            }
            file.close();
       // }

        }
        /*cout << "�� ������!\n�� �� ����� ��� �� ����� �� �� ���222222222"<< endl;
        if ( b == '\0')
                cout << "����� ��� ����� - ";
        else cout << "����� ����� �� ����� - "<<b<<endl;
        goto label;*/
        file.close();
        file.clear();
   return 0;
}
