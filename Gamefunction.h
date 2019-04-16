#ifndef Gamefunc
#define Gamefunc

using namespace std;

void rulespintf(string & bufer)
{
    string rules;
    rules = bufer;
    if ((rules == "правила") || (rules == "Правила"))
    {
    cout << "Правила: На початку гри я запропоную тобі вибрати одну із тем. Після твого вибору гра розпочнеться."<<endl;
    cout << "Ти називаєш слово першим(ою), а моє завдання написати слово, яке починається на останню букву твого і навпаки."<<endl;
    cout << "Зрозуміло? Я наведу приклад...\nТвоє слово:'Програміст' - Моє слово:'Теорія' - Твоє слово:'Ямб' і т.д"<<endl;
    cout << "Також ти можеш уточнити правила в будь-який момент.\nПросто введи 'Правила'!"<<endl;
    cout << "Успіхів тобі!"<<endl;
    system("pause");
    }
}
bool IfwordsHight(char b) // Перевірка чи букви великі
{
    if(b>'А'-1&&b<'Ю'+1)
        return 1;
    return 0;
}

void ConverttoLow(string& b)// перетворення букв в маленькі
{
    for(int i = 0;i<b.length();i++)
    {
        if(IfwordsHight(b[i]))
            b[i]=char(int(b[i])+32);
    }
}

bool searchinLOG(string & word) // Чи є слово в лозі?
{
    string wordis = "";
    ifstream LOG("LOGS.txt",ios_base::in);
    while(!LOG.eof())
        {
            LOG >> wordis;
            if(word == wordis)
            {
                return 1;
            }
     }
    return 0;
}

void LOGAD( string & word) // Записати в лог
{
    ofstream LOG("LOGS.txt",ios_base::out|ios_base::app);
    LOG<<word<<endl;
}

void getword(string & bufer, string & filename,int & setsize)
{
    typedef ostream_iterator<string> output_str;
    string line[500];
    set<string> word;
    setsize=0;
    ifstream file (filename.c_str(), ios_base::in); //відкриваємо файл
    while (!file.eof())
    {
        for (int i=0; i<500; i++)
        {
            getline(file,line[i]);
            bufer.length();

       // cout << "line 3 " << line[i]<< endl;
       // cout << bufer[50][bufer[50].length()-1];
    if  (line[i][0] == bufer[bufer.length()-1]) // чи перша буква зчитаного = останній букві введеного bufer[50][bufer[50].length()
        {
           word.insert(line[i]);
            setsize++;
            }
        }
    }
    //copy(word.begin(), word.end(), output_str(std::cout, "\n") );
    word.clear();
    file.close();
}

int random(int & setsize)
{
    srand(time(NULL));
    int q=0;
    return q + rand()%setsize;
}
/*const int len = 30, strings = 5;
	const char ch = '\n';
	char mass[len][strings];

	ifstream fs("strings.txt", ios::in | ios::binary);

	if(!fs) return 1; //Если ошибка открытия файла, то завершаем программу

	for(int r = 0; r<strings; r++)
	{
		fs.getline(mass[r], len-1,ch); //Считываем строки в массив
		cout << "String " << r+1 << " = "<< mass[r] << endl; //Выводи строку из массива
	}
	fs.close(); //Закрываем файл
	return 0;*/

bool rightword(string & bufer, string & filename)
 {
    string line;
    ifstream file (filename.c_str());
    while (!file.eof() )
    {
        getline(file,line);//зчитуємо кожне слово
        if (bufer == line)
        {
            return 1;
        }
    }
            return 0;
}

bool exit(string & bufer)
{
    if (bufer == "вихід" || bufer == "Вихід" || bufer == "Здаюсь" || bufer == "здаюсь")
        {
            cout << "Ти чудовий гравець, дякую за гру!\nПовертайся!!!"<<endl;
            return 0;
        }
        else return 1;
}

#endif  Gamefunc
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
