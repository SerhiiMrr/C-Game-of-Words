using namespace std;
typedef ostream_iterator<string> output_str;
void rulespintf(string & bufer)
{
    string rules;
    rules = bufer;
    if ((rules == "�������") || (rules == "�������"))
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

void ConverttoLow(string& b)// ������������ ���� � �������
{
    for(int i = 0;i<b.length();i++)
    {
        if(IfwordsHight(b[i]))
            b[i]=char(int(b[i])+32);
    }
}

bool searchinLOG(string & word) // �� � ����� � ���?
{
    vector<string> wordis;
    string line;
    ifstream LOG("LOGS.txt",ios_base::in);
    while(!LOG.eof())
    {
        getline(LOG,line);
        cout << line<<endl;//cout<<endl;
       // cout << line<<endl;
/*for (int i=0; i<500; i++) // ���� ��̲���
        {
            getline(LOG,line[i]);
            wordis.push_back(line[i]);*/
        wordis.push_back(line);
        for (int i=0;i<wordis.size();)
        {
            if (wordis[i] == word)
            {
               // cout<<wordis[i]<<" HELO"<<endl<<endl;
                wordis.clear();
                return 1;
            }
            i++;
        }
    }
    //cout <<"wordis.size "<< wordis.size()<<endl;
    //cout <<"vec_size "<< vec_size<<endl;
    //copy(wordis.begin(), wordis.end(), output_str(std::cout, "\n") );
   // cout<<endl;
   // cout << searchinLOG;
    return 0;
}

void LOGAD( string & word) // �������� � ���
{
    ofstream LOG("LOGS.txt",ios_base::out|ios_base::app);
    LOG<<word<<endl;
}

int random(int & setsize)
{
    srand(time(NULL));
    int q=0;
    return q + rand()%setsize;
}

string getword(string & bufer, string & filename,int & setsize,int &i,string &line2)
{
    typedef ostream_iterator<string> output_str;
    string line[500];
    vector<string> word;
    word.clear();
    setsize=0;
    ifstream file (filename.c_str(), ios_base::in); //��������� ����
    while (!file.eof())
    {
        for (int i=0; i<500; i++)
        {
            getline(file,line[i]);
            bufer.length();
            if  (line[i][0] == bufer[bufer.length()-1]) // �� ����� ����� ��������� = ������� ���� ��������� bufer[50][bufer[50].length()
            {
                word.push_back(line[i]);
                setsize++;
            }
        }
    }
   // copy(word.begin(), word.end(), output_str(std::cout, "\n") );
    file.close();

    srand(time(NULL));
    i=random(setsize);
    cout << i << " I";
    line2=word.at(i);
    //searchinLOG(line2);
   // cout << searchinLOG;
   // }while (searchinLOG == 0);
    return line2;
}


bool rightword(string & bufer, string & filename)
 {
    string line;
    ifstream file (filename.c_str());
    while (!file.eof() )
    {
        getline(file,line);//������� ����� �����
        if (bufer == line)
        {
            return 1;
        }
    }
            return 0;
}

bool exit(string & bufer)
{
    if (bufer == "�����" || bufer == "�����" || bufer == "������" || bufer == "������")
        {
            cout << "�� ������� �������, ����� �� ���!\n����������!!!"<<endl;
            return 0;
        }
        //else return 1;
}

//#endif  Gamefunc
    /*ifstream in("slova.cpp",ios::binary);
    //set<char>buf;
    int size = in.seekg(0,ios::end).tellg();
    in.seekg(0);
    char * buf =new char [size+1];
    in.read(buf,size);
    buf[size] = 0;
    while (!in.eof())
    {
        if (bufer[50][50] == buf)
        {
            return 1;
        }
    }
    return 0;
}


  /* // char Slovo[6];
   //Slovo[0] = word[0];
    ifstream fil;
    fil.open("slova.txt",ios_base::in);
    string temp;
    int z;
    while(!fil.eof())
    {
        fil >> temp;
        if(bufer[50][50] == temp)
        {
            fil.close();
            return z=1;
        }
        else return z=0;
    }
    /*
    ofstream fout;
    fout.open("slova.txt",ios_base::out|ios_base::app);
    fout<<word<<endl;
    fout.close();
    fil.close();
    char Slovo[6];
    ifstream fil;
        Slovo[0] = word[0];
        Slovo[1] = '.';
        Slovo[2] = 't';
        Slovo[3] = 'x';
        Slovo[4] = 't';
        Slovo[5] = '\0';
        fil.open(Slovo,ios_base::in);
        string temp;
    while(!fil.eof())
    {
        fil >> temp;
        if(word == temp)
        {
            fil.close();
            return;
        }
    }
    ofstream fout;
    fout.open(Slovo,ios_base::out|ios_base::app);
    fout<<word<<endl;
    fout.close();
    fil.close();*/
