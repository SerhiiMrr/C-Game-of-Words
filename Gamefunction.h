#include <ctime>

using namespace std;

int m=0;// getword |
int b=0; // getword |
int n=0; // rightword |
int q = 0; // getword |

void rulespintf(string & bufer)
{
    if (bufer == "�������")
    {
    cout << "�������: �� ������� ��� � ���������� ��� ������� ���� �� ���. ϳ��� ����� ������ ��� ������������."<<endl;
    cout << "�� ������� ����� ������(��), � �� �������� �������� �����, ��� ���������� �� ������� ����� ����� � �������."<<endl;
    cout << "��������? � ������ �������...\n��� �����:'���������' - �� �����:'�����' - ��� �����:'���' � �.�"<<endl;
    cout << "����� �� ����� �������� ������� � ����-���� ������.\n������ ����� '�������'!"<<endl;
    cout << "������ ���!"<<endl;
    system("pause");
    }
}
bool IfwordsHight(char b) // �������� �� ����� �����
{
    if(b>'�'-1&&b<'�'+1)
        return 1;
    return 0;
}

void ConverttoLow(string & b)// ������������ ���� � �������
{
    for(int i = 0;i<b.length();i++)
    {
        if(IfwordsHight(b[i]))
            b[i]=char(int(b[i])+32);
    }
}

void LOGAD ( string & word ) // �������� � ���
{
    ofstream LOG("LOGS.txt",ios_base::out|ios_base::app);
    LOG<<word<<endl;
    LOG.close();
}

bool searchinLOG(string & word) // �� � ����� � ���?
{
    string line_srch="";
    ifstream LOG("LOGS.txt",ios_base::in);
    while(!LOG.eof())
    {
        getline(LOG,line_srch);

        if ( line_srch == word )
        {
            return 1;
        }
    }
    return 0;
}

string getword(string & bufer, string & filename,int & setsize,string & word,int & ls_lt)
{
    m=0; // ����
    b=0; // ��������

    string line[80];
    vector<string> words;

    ifstream file (filename.c_str(), ios_base::in); //��������� ����

    while (!file.eof())
    {
        b++;
        for (int i=0; i<b; i++)
        {
            getline(file,line[i]);
            bufer.length(); /////////////// ���� -1, �� ��� �������� �� �, ����� ��� ���� -2 // ��������
            if  (line[i][0] == bufer[bufer.length() - ls_lt]) // �� ����� ����� ��������� = ������� ���� ��������� bufer[50][bufer[50].length()
            {
                words.push_back(line[i]);
            }
        }
    }

    file.close();
    setsize = words.size();
    q=0;
    do
    {
        q++;
        word = words.at(rand()% (setsize+0));
        m++;
        if (q > 1000)
        {
            cout <<"������� � ����� �����..." <<endl;
            q = -9999999;
        }

        else if ( m > 300)
        {
            word = "end";
            return word;
        }

    }while (searchinLOG(word) == 1);
    words.clear();
    return word;
}


bool rightword(string & bufer, string & filename)
{
    n=0;
    string line;
    vector<string> words;
    words.clear();
    ifstream file (filename.c_str());
    while (!file.eof() )
    {
        n++;
        getline(file,line);
        words.push_back(line);
        for ( int i = 0; i<n; i++)
        {
            if (bufer == words[i])
            {
                return 1;
            }
        }
    }
    return 0;
}

bool exit(string & bufer)
{
    if (bufer == "�����" || bufer == "������")
        {
            cout << "�� ������� �������, ����� �� ���!\n����������!!!"<<endl;
            return 1;
        }
}
