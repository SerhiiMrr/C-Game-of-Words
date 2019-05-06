#include <ctime>

using namespace std;

int m=0;// getword |
int b=0; // getword |
int n=0; // rightword |
int q = 0; // getword |

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

void LOGAD ( string & word ) // Записати в лог
{
    ofstream LOG("LOGS.txt",ios_base::out|ios_base::app);
    LOG<<word<<endl;
    LOG.close();
}

bool searchinLOG(string & word) // Чи є слово в лозі?
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
    m=0; // мітка
    b=0; // лічильник

    string line[80];
    vector<string> words;

    ifstream file (filename.c_str(), ios_base::in); //відкриваємо файл

    while (!file.eof())
    {
        b++;
        for (int i=0; i<b; i++)
        {
            getline(file,line[i]);
            bufer.length(); /////////////// якщо -1, то при закінченні на ь, треба щоб було -2 // ЗРОБЛЕНО
            if  (line[i][0] == bufer[bufer.length() - ls_lt]) // чи перша буква зчитаного = останній букві введеного bufer[50][bufer[50].length()
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
            cout <<"Зачекай я думаю слово..." <<endl;
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
    if (bufer == "вихід" || bufer == "здаюсь")
        {
            cout << "Ти чудовий гравець, дякую за гру!\nПовертайся!!!"<<endl;
            return 1;
        }
}
