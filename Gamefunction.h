//typedef ostream_iterator<string> output_str;

using namespace std;

int m=0;
int b=0; ///////////////// ПРОБЛЕМА В СЕРЧІНЛОГ
int n=0;
int q=0;
int randomS=0;///////////////////////////////  ШОСЬ ЗРОИТИ З КІЛЬКІСТЮ ІТЕРАЦІЙ

void rulespintf(string & bufer)
{
    if (bufer == "правила")
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
    if(b>'А'-1&&b<'Я'+1)
        return 1;
    return 0;
}

void ConverttoLow(string & b)// перетворення букв в маленькі
{
    for(int i = 0;i<b.length();i++)
    {
        if(IfwordsHight(b[i]))
            b[i]=char(int(b[i])+32);
    }
}

bool searchinLOG(string & word) // Чи є слово в лозі?
{
    int i = 0;
    do{
    vector<string> wordis;
    q=0;
    //i=0;
    wordis.clear();
    string line_srch;
    ifstream LOG("LOGS.txt",ios_base::in);
    while(!LOG.eof())
    {
        q++;
        getline(LOG,line_srch);
        wordis.push_back(line_srch);
        for ( ; i<q+1; i++)
        {
            if ( wordis[i] == word )
            {
                cout << i <<endl;
                cout << wordis[i] << endl;
                cout << " searchinLOG V CIKLI" << endl;
                i++;
                return 1;
            }
        }
    }
    cout << " searchinLOG " << endl;
    }while (false);
    return 0;
}

void LOGAD ( string & word ) // Записати в лог
{
    ofstream LOG("LOGS.txt",ios_base::out|ios_base::app);
    LOG<<word<<endl;
    cout << "LOGAD" << endl;
    LOG.close();
}

int random(int & setsize)
{
    srand(time(NULL));
    rand()%setsize;
   /* if (rand()%setsize == rand()%setsize)
    {
        cout << rand()%setsize << "V CIKLI" << endl;
        while (rand()%setsize < setsize+1)
        {
            rand()%setsize++;
        }
        random(setsize);
    }
    //randomS = rand()%setsize;
    cout << rand()%setsize << " NE V CIKLI" << endl;
    srand(time(NULL));*/
    return rand()%(setsize);
}

string getword(string & bufer, string & filename,int & setsize,int &i,string &line2)
{
    n=0; // мітка
    b=0;

    string line[80];
    vector<string> word;

    ifstream file (filename.c_str(), ios_base::in); //відкриваємо файл
    while (!file.eof())
    {
        b++;
        for (int i=0; i<b; i++)
        {
            getline(file,line[i]);
            bufer.length();
            if  (line[i][0] == bufer[bufer.length()-1]) // чи перша буква зчитаного = останній букві введеного bufer[50][bufer[50].length()
            {
                word.push_back(line[i]);
            }
        }
    }

    setsize = word.size();
    file.close();
    label1:
    line2=word.at(random(setsize));
   // cout << random(setsize);
    //cout << line2;
    n++;
    cout << "getword" << endl;
    cout << line2 << endl;
    //copy(word.begin(), word.end(), output_str(std::cout, "\n") );
    if (n == 100)
        line2 = "end";
    if(searchinLOG(line2) == 1)
    {
        goto label1;
    }
    word.clear();
    return line2;
}


bool rightword(string & bufer, string & filename)
 {
    string line;
    vector<string> words;
    words.clear();
    n=0;
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
                cout << "rightword" << endl;
                //words.clear();
                return 1;
            }
        }

    }
    cout << "rightword 2" << endl;
   // words.clear();
            return 0;
}

bool exit(string & bufer)
{
    if (bufer == "вихід" || bufer == "здаюсь")
        {
            cout << "Ти чудовий гравець, дякую за гру!\nПовертайся!!!"<<endl;
            return 1;
        }
}
