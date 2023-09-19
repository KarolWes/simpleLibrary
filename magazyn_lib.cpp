#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdio>
using namespace std;


//_____________________STRUCTURES________________________________//
struct Tdate
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

struct Titem
{
    string id;
    bool availability = true;
    Tdate date_out;
    Tdate date_back;
    string consumer;
    float fine = 0;
};

struct Trekord
{
    unsigned int inv_number;
    string name;
    string author;
    float cost;
    unsigned int quantity;
    bool complited = true;
    Titem books[50];
};

//__________________VARIABLES______________________________//

Trekord library [10000];
Tdate today;
Tdate t_comeback;
const int MonthDaysStd[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
const int MonthDaysSpc[] = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 336, 366};
int y_day;

//__________________FUNCTIONS_COLLATERAL__________________________//

bool end_check(int x)
{
    if (x == 1)
    {
        cin.ignore();
    }
    char answer = getchar();
    if (answer == 'T' || answer == 't')
    {
       return true;
    }
    else{
        return false;
    }
}

void owl(int x)
{
    switch (x)
    {
    case 1:
        {
            cout <<"\t\t\t"<<  "  __________\n";
            cout <<"\t\t\t"<<  " / ___  ___ \\\n";
            cout <<"\t\t\t" <<  "/ / @ \\/ @ \\ \\\n";
            cout <<"\t\t\t"<< "\\ \\___/\\___/ /\\\n";
            cout <<"\t\t\t"<<  " \\____\\/____/||\n";
            cout <<"\t\t\t"<<  " /     /\\\\\\\\\\//\n";
            cout <<"\t\t\t"<<  " |     |\\\\\\\\\\\\\n";
            cout <<"\t\t\t"<<  "  \\      \\\\\\\\\\\\\n";
            cout <<"\t\t\t"<<  "   \\______/\\\\\\\\\n";
            cout <<"\t\t\t"<<  "    _||_||_\n";
            cout <<"\t\t\t"<<  "     -- --\n";
            break;
        }
    case 2:
        {
            cout <<"\t\t\t"<< "    ___\n";
            cout <<"\t\t\t"<< ",,,(o,o),,,\n";
            cout <<"\t\t\t"<< " \';:`-\':;\'\n";
            cout <<"\t\t\t"<< "   -\"-\"-\n";
            break;
        }
    case 3:
        {
            cout << " ,_,\n";
            cout << "(o,o)\n";
            cout << "{`\"\'}\n";
            cout << "-\"-\"-\n";
            break;
        }
    }

}

int data_open()
{
    int i;
    fstream data;

    data.open("data.txt",ios::in);

    if (data.is_open() == false )
    {
        cout << "\b";
    }
    data >> i;

    data.close();
    data.clear();
    return i;
}

void comeback_date_maker()
{
    int steer;
    t_comeback.year = today.year;
    t_comeback.month = today.month;
    t_comeback.day = today.day+30;
    if (today.month == 2)
    {
        steer = 2;
    }
    else if (today.month == 4 || today.month == 6 || today.month == 9 ||today.month == 11)
    {
        steer = 1;
    }
    else{
        steer = 0;
    }
    switch (steer)
        {
        case 0:
            {
                if (t_comeback.day > 31)
                {
                    t_comeback.day-=31;
                    t_comeback.month++;
                    break;
                }
            }
        case 1:
            {
                if (t_comeback.day > 30)
                {
                    t_comeback.day-=30;
                    t_comeback.month++;
                    break;
                }
            }
        case 2:
            {
                if(today.year % 4 == 0 && today.year % 100 !=0 || today.year % 400 == 0)
                {
                    if (t_comeback.day > 29)
                    {
                        t_comeback.day-=29;
                        t_comeback.month++;
                        break;
                    }
                }
                else{
                    if (t_comeback.day > 28)
                    {
                        t_comeback.day-=28;
                        t_comeback.month++;
                        break;
                    }
                }
            }
        }


    if(t_comeback.month > 12)
    {
        t_comeback.month -= 12;
        t_comeback.year ++;
    }
}

int oper = data_open();

//_______________FUNCTIONS_MAIN__________________________//

void insertion()
{
    setlocale(LC_ALL, "");

    bool if_end;
    int i;
    char id_1[4];
    char id_2[4];
    string s_id;
    string buffor;
    string tmp;
    fstream file;
    fstream data;
    fstream outtakes;
    Trekord lib;
    Titem book;

    file.open("library.txt",ios::out | ios::app);

    if (file.is_open() == false )
    {
        cout << "\b";
    }
   do
    {
        cin.ignore();
        cout << "Dodaj ksi¹¿kê: (wpisz \"anuluj\" ¿eby wyjœæ)\n" ;
        cout << "Tytu³: ";
        getline(cin, buffor);
        tmp = buffor;
        transform(buffor.begin(), buffor.end(), buffor.begin(), ::tolower);
        //cout << buffor;
        if(buffor != "anuluj")
        {
            if (oper != 0)
            {
                file << "\n";
            }
            file << oper+1 << "|";
            library[oper].inv_number = oper+1;
            library[oper].name = tmp;
            if(library[oper].name == "")
            {
                library[oper].name = "***";
            }
            file.write(&library[oper].name[0], library[oper].name.size());
            file << "|";
            cout << "Autor: ";
            getline(cin, library[oper].author);
            if(library[oper].author == "")
            {
                library[oper].author = "autor nieznany";
            }
            file.write(&library[oper].author[0], library[oper].author.size());
            file << "|";
            cout << "Cena: ";
            cin >>  library[oper].cost;
            file << library[oper].cost;
            file << "|";
            cout << "Iloœæ: ";
            cin >>  library[oper].quantity ;
            file << library[oper].quantity;
            file << "|";
            library[oper].complited = false;

            oper++;
            cout << "Kontynuowaæ?";
            if_end = end_check(1);
        }
        else{
            if_end = false;
        }
    }while( if_end == true);
    file.close();
    file.clear();


    book = lib.books[0];
    cout << book.availability << endl;

    outtakes.open("outtakes.txt", ios:: out|ios::app);
    for(int x = 0; x < oper; x++)
    {
        lib = library[x];
        if (lib.complited == false)
        {
            for (int j = 0; j < lib.quantity; j++)
            {
                itoa(lib.inv_number, id_1, 10);
                itoa(j, id_2, 10);
                s_id = id_1;
                s_id = s_id + "_"+id_2;

                cout << s_id << endl;
                if(x!=0&&j!=0)
                {
                    outtakes << "\n";
                }
                outtakes << s_id << "|";
                book = lib.books[j];
                outtakes << book.availability << "|";
                book.date_out.day = 0;
                outtakes << book.date_out.day << "/";
                book.date_out.month = 0;
                outtakes << book.date_out.month << "/";
                book.date_out.year = 0;
                outtakes << book.date_out.year << "|";
                book.date_back.day = 99;
                outtakes << book.date_back.day << "/";
                book.date_back.month = 99;
                outtakes << book.date_back.month << "/";
                book.date_back.year = 9000;
                outtakes << book.date_back.year << "|";
                book.consumer = "";
                outtakes << book.consumer<< "|";
                outtakes << book.fine;
                outtakes << "|";
            }
            lib.complited = true;
        }
    }
    outtakes.close();
    outtakes.clear();

    data.open("data.txt", ios::out|ios::trunc);
    data << oper;
    data.close();
    data.clear();

    s_id.clear();
    tmp.clear();
    buffor.clear();
}

void outprint()
{

    for(int i = 0; i < oper; i++)
    {

        cout << library[i].inv_number << ". \""<< library[i].name<< "\" - " << library[i].author  << " " <<setprecision(5)<< library[i].cost << "z³ " << library[i].quantity;
        switch(library[i].quantity)
        {
        case 1:
            {
                cout << " sztuka";
                break;
            }
        case 2:
            {
                cout << " sztuki";
                break;
            }
        case 3:
            {
                cout << " sztuki";
                break;
            }
        default:
            {
                cout << " sztuk";
                break;
            }
        }
        cout << '\n';
    }
    cout << "Naciœnij aby zakoñczyæ wyœwietlanie";
    cin.ignore();
    getchar();
}

void state()
{
    int number = 0;
    float sum = 0;


    for (int i =0; i < oper; i++)
    {
        for (int j = 0; j < library[i].quantity; j++)
        {
            if (library[i].books[j].availability == 1)
            {
                number++;
            }
        }

        cout << library[i].inv_number <<". \""<< library[i].name << "\"  - " << library[i].author;
        if (number == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout << " Niedostêpne";
        }
        else{
            switch(number)
            {
                case 1:
                {
                    cout << ": Dostêpna ";
                    break;
                }
                case 2:
                {
                    cout << ": Dostêpne ";
                    break;
                }
                case 3:
                {
                    cout << ": Dostêpne ";
                    break;
                }
                default:
                {
                    cout << ": Dostêpnych ";
                    break;
                }
            }
            if(number!=library[i].quantity)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            }
            cout << number << "/" << library[i].quantity;
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<< ", Wartoœæ ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
        cout << number*library[i].cost << "z³" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        sum +=number*library[i].cost;
        number = 0;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    cout << "\tWartoœæ ksiêgozbioru: " << sum << "z³" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout << "\tNaciœnij aby zakoñczyæ wyœwietlanie";
    cin.ignore();
    getchar();
}

void lent_state()
{
    cout << "Wypo¿yczenia:\n";
    for (int i =0; i < oper; i++)
    {
        for (int j = 0; j < library[i].quantity; j++)
        {
            if (library[i].books[j].availability == 0)
            {
                cout << (library[i].books[j].id) << " (\"" << (library[i].name) << "\" - " << (library[i].author) << "), wypo¿yczona: "<< (library[i].books[j].date_out.day) << "/" << (library[i].books[j].date_out.month) << "/" << (library[i].books[j].date_out.year) << ", do zwrotu: " << (library[i].books[j].date_back.day) << "/" << (library[i].books[j].date_back.month) << "/" << (library[i].books[j].date_back.year) <<"; Wypo¿yczaj¹cy: " << (library[i].books[j].consumer) <<  ";";
                if(library[i].books[j].fine > 1)
                {
                    cout << " Kara: " << (library[i].books[j].fine);
                }

                cout << endl;
            }
        }
    }
    cout << "Naciœnij aby zakoñczyæ wyœwietlanie";
    cin.ignore();
    getchar();
}

void lend()
{
    bool if_end;
    bool available = false;
    bool corect = false;
    int tmp;//index linii wypo¿yczenia
    int y_day_book;
    int bug;
    float fine;
    string answer;
    string title;
    string buffor;
    string needed;
    string user;
    fstream file;
    fstream new_file;
    fstream rejestr;

    do
    {
        answer = "";
        if_end = false;
        tmp = 0;
        cout << "\tWypo¿yczyæ (1), czy zwróciæ(2)? (wpisz \"anuluj\" ¿eby wyjœæ)\n \tTwój wybór: ";
        cin >> answer;
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);


        if(answer != "anuluj")
        {
            if(answer == "1")//wypo¿yczenie
            {
                cin.ignore();
                cout << "\tPodaj tytu³: ";
                getline(cin, title);
                transform(title.begin(), title.end(), title.begin(), ::tolower);


                for (int i = 0; i < oper; i++)
                {
                    buffor = library[i].name;
                    transform(buffor.begin(), buffor.end(), buffor.begin(), ::tolower);
                    if(buffor == title)
                    {
                        corect = true;
                        for (int j = 0; j < library[i].quantity; j++)
                        {
                            if(library[i].books[j].availability == 1)
                            {
                                available = true;
                                cout << "\tCzy na pewno chcesz wypo¿yczyæ \"" << library[i].name << "\" " << library[i].books[j].id << "? ";
                                if(end_check(0))
                                {

                                    library[i].books[j].availability = 0;
                                    library[i].books[j].date_out.day = today.day;
                                    library[i].books[j].date_out.month = today.month;
                                    library[i].books[j].date_out.year = today.year;
                                    library[i].books[j].date_back.day = t_comeback.day;
                                    library[i].books[j].date_back.month = t_comeback.month;
                                    library[i].books[j].date_back.year = t_comeback.year;

                                    file.open("outtakes.txt",ios::in|ios::out);
                                    new_file.open("tmp.txt", ios::out);

                                    if(tmp == 0)
                                    {
                                        new_file <<  library[i].books[j].id << "|" << library[i].books[j].availability << "|" << library[i].books[j].date_out.day<< "/" << library[i].books[j].date_out.month << "/" << library[i].books[j].date_out.year << "|" << library[i].books[j].date_back.day << "/" << library[i].books[j].date_back.month << "/" << library[i].books[j].date_back.year << "|";
                                    cout << "\tPodaj numer karty czytelnika: ";
                                    cin.ignore();
                                    getline(cin, library[i].books[j].consumer);
                                    new_file << library[i].books[j].consumer << "|" << library[i].books[j].fine << "|";
                                    getline (file, buffor, '\n');
                                    }

                                    else{
                                        getline (file, buffor, '\n');
                                        new_file.write(&buffor[0], buffor.size());

                                        for(int x = 1; x < tmp; x++)
                                        {
                                            new_file << "\n";
                                            getline (file, buffor, '\n');
                                            new_file.write(&buffor[0], buffor.size());
                                        }

                                        new_file << '\n' ;
                                        new_file <<  library[i].books[j].id << "|" << library[i].books[j].availability << "|" << library[i].books[j].date_out.day<< "/" << library[i].books[j].date_out.month << "/" << library[i].books[j].date_out.year << "|" << library[i].books[j].date_back.day << "/" << library[i].books[j].date_back.month << "/" << library[i].books[j].date_back.year << "|";
                                        cout << "\tPodaj numer karty czytelnika: ";
                                        cin.ignore();
                                        getline(cin, library[i].books[j].consumer);
                                        new_file << library[i].books[j].consumer << "|" << library[i].books[j].fine << "|";
                                        getline (file, buffor, '\n');
                                    }

                                    while (file.eof() == false)
                                    {
                                        new_file << "\n";
                                        getline (file, buffor, '\n');
                                        new_file.write(&buffor[0], buffor.size());
                                    }

                                    file.close();
                                    if (remove("outtakes.txt") != 0)
                                    {
                                        cout << "ERROR\n";
                                    }

                                    new_file.close();
                                    rename("tmp.txt", "outtakes.txt");

                                    rejestr.open("rejestr.txt", ios::out|ios::app);

                                    rejestr << library[i].books[j].date_out.day<< "/" << library[i].books[j].date_out.month << "/" << library[i].books[j].date_out.year <<  " Czytelnik " << library[i].books[j].consumer  << " wypo¿yczy³ " << library[i].books[j].id << " (\"" << library[i].name << "\"), do zwrotu " << library[i].books[j].date_back.day << "/" << library[i].books[j].date_back.month << "/" << library[i].books[j].date_back.year <<"\n";

                                    rejestr.close();

                                    cout << "\tWypo¿yczono\n";
                                }

                                break;
                            }
                            tmp++;

                        }
                        if(available == false)
                        {
                            cout << "\tWszystkie ksi¹¿ki wypo¿yczone.\n";
                        }

                        Sleep(500);
                        break;
                    }
                    else{
                        tmp+=library[i].quantity;
                    }
                }
                if (corect == false)
                {
                    cout << "\tBrak pozycji w bibliotece. Upewnij siê, ¿e tytu³ zosta³ wpisany poprawnie\n";
                }
                cout << "\tKontynuowaæ? ";
                if_end = end_check(0);

            }
           else if (answer == "2") //zwrot
           {
                cin.ignore();
                cout << "\tPodaj identyfikator ksi¹¿ki: ";
                getline(cin, title);
                file.open("outtakes.txt", ios::out|ios::in);
                if (file.is_open() == false )
    {
        cout << "ERROR";
    }
                for (int i = 0; i < oper; i++)
                {
                    for(int j = 0; j < library[i].quantity; j++)
                    {
                        if (library[i].books[j].id == title)
                        {
                            if(library[i].books[j].availability == 0)
                            {

                                corect = true;

                                if (library[i].books[j].date_back.year % 4 == 0 && library[i].books[j].date_back.year % 100 !=0 || library[i].books[j].date_back.year % 400 == 0)
                                {
                                    y_day_book = MonthDaysSpc[library[i].books[j].date_back.month-2] + library[i].books[j].date_back.day;
                                }
                                else{
                                    y_day_book = MonthDaysStd[library[i].books[j].date_back.month-2] + library[i].books[j].date_back.day;
                                }

                                if(library[i].books[j].date_back.year == today.year)
                                {
                                    if (y_day > y_day_book)
                                    {
                                        library[i].books[j].fine = (y_day - y_day_book)*0.1;
                                        fine = library[i].books[j].fine;
                                    }
                                }
                                else{

                                    library[i].books[j].fine = (365*(today.year - library[i].books[j].date_back.year) - y_day + y_day_book) *0.1;
                                    fine = library[i].books[j].fine;
                                }

                                library[i].books[j].availability = 1;
                                library[i].books[j].date_out.day = 0;
                                library[i].books[j].date_out.month = 0;
                                library[i].books[j].date_out.year = 0;
                                library[i].books[j].date_back.day = 99;
                                library[i].books[j].date_back.month = 99;
                                library[i].books[j].date_back.year = 9000;
                                user = library[i].books[j].consumer;
                                library[i].books[j].consumer = "";



                                if(library[i].books[j].fine > 0)
                                {
                                    cout << "\tZwrócono po terminie.\n";
                                    if (library[i].books[j].fine > 1)
                                    {
                                        cout << "\tDo zap³aty: " << library[i].books[j].fine << "z³.\n";
                                    }
                                    library[i].books[j].fine = 0;
                                }


                                new_file.open("tmp.txt", ios::out);
                                if(tmp == 0)
                                {
                                    new_file << library[i].books[j].id << "|" << library[i].books[j].availability << "|" << library[i].books[j].date_out.day<< "/" << library[i].books[j].date_out.month << "/" << library[i].books[j].date_out.year << "|" << library[i].books[j].date_back.day << "/" << library[i].books[j].date_back.month << "/" << library[i].books[j].date_back.year << "|" << library[i].books[j].consumer << "|" << library[i].books[j].fine << "|";
                                    getline (file, buffor, '\n');
                                }
                                else{

                                    getline (file, buffor, '\n');
                                    new_file.write(&buffor[0], buffor.size());

                                    for(int x = 1; x < tmp; x++)
                                    {
                                        new_file << "\n";
                                        getline (file, buffor, '\n');
                                        new_file.write(&buffor[0], buffor.size());
                                    }

                                    new_file << '\n';
                                    new_file << library[i].books[j].id << "|" << library[i].books[j].availability << "|" << library[i].books[j].date_out.day<< "/" << library[i].books[j].date_out.month << "/" << library[i].books[j].date_out.year << "|" << library[i].books[j].date_back.day << "/" << library[i].books[j].date_back.month << "/" << library[i].books[j].date_back.year << "|" << library[i].books[j].consumer << "|" << library[i].books[j].fine << "|";
                                    getline (file, buffor, '\n');


                                }

                                    while (file.eof() == false)
                                    {
                                        new_file << "\n";
                                        getline (file, buffor, '\n');
                                        new_file.write(&buffor[0], buffor.size());

                                    }
                                    file.close();

                                    if (remove("outtakes.txt") != 0)
                                    {
                                        cout << "ERROR\n";
                                    }

                                    new_file.close();
                                    bug = rename("tmp.txt", "outtakes.txt");
                                    if (bug != 0)
                                    {
                                        cout << "ERROR!\n";
                                    }

                                    rejestr.open("rejestr.txt", ios::out|ios::app);
                                    rejestr << today.day<< "/" << today.month << "/" << today.year <<  " Czytelnik " << user  << " zwróci³ " << library[i].books[j].id << " (\"" << library[i].name << "\"). ";
                                    if (fine > 1)
                                    {
                                        rejestr << "Wp³acono karê " << fine;
                                    }
                                    rejestr << "\n";
                                    rejestr.close();



                                    cout << "\tZwrócono\n";
                            }
                            break;
                        }
                        tmp++;
                    }
                }

                if(corect == false)
                {
                    cout << "\tNie znaleziono pozycji. Upewnij siê, ¿e dane zosta³y wprowadzone poprawnie.\n";
                }

                cout << "\tKontynuowaæ? ";
                if_end = end_check(0);

           }
           else{
                cout << "\tProszê wybraæ jedn¹ z powy¿szych opcji\n";
                Sleep(500);
                if_end = true;
           }
        }
        else{
            if_end = false;
        }


    }while(if_end == true);


    rejestr.clear();
    file.clear();
    new_file.clear();
    answer.clear();
    title.clear();
    buffor.clear();
    needed.clear();
}

void start()
{
    setlocale(LC_ALL, "");

    time_t t = time(0);
    int oper = data_open();
    int y_day_book;
    string buffor;
    fstream file;
    fstream outtakes;



    tm* now = localtime(&t);
    today.year = (now->tm_year+1900);
    today.month = (now->tm_mon+1);
    today.day = (now->tm_mday);

    if(today.year % 4 == 0 && today.year % 100 !=0 || today.year % 400 == 0)
    {
        y_day = MonthDaysSpc[today.month-2] + today.day;
    }
    else{
        y_day = MonthDaysStd[today.month-2] + today.day;
    }


    comeback_date_maker();

    file.open("library.txt",ios::in);
    if (file.is_open() == false )
    {
        cout << "\b";
    }

    for(int i = 0; i < oper; i++)
    {
        //cout << i << endl;
        file >> library[i].inv_number;
        //cout << library[i].inv_number << endl;
        getline (file, buffor, '|');
        getline(file, library[i].name, '|');
        //cout << library[i].name << endl;
        getline(file, library[i].author, '|');
        //cout << library[i].author << endl;
        file >> library[i].cost;
        //cout << library[i].cost << endl;
        getline (file, buffor, '|');
        file >> library[i].quantity;
        //cout << library[i].quantity << endl;
        getline (file, buffor, '\n');
        buffor.clear();
        //cout << "____________\n";
    }
file.close();
file.clear();

outtakes.open("outtakes.txt",ios::in);

    if (outtakes.is_open() == false )
    {
        cout << "\b";
    }
for (int i =0; i < oper; i++)
{
    for (int j = 0; j < library[i].quantity; j++)
    {
            getline (outtakes, library[i].books[j].id, '|');
            //cout << library[i].books[j].id << endl;
            outtakes >> library[i].books[j].availability;
            //cout << library[i].books[j].availability << endl;

            getline (outtakes, buffor, '|');

            outtakes >> library[i].books[j].date_out.day;
            getline (outtakes, buffor, '/');
            //cout << library[i].books[j].date_out.day << "/";
            outtakes >> library[i].books[j].date_out.month;
            getline (outtakes, buffor, '/');
            //cout << library[i].books[j].date_out.month << "/";
            outtakes >> library[i].books[j].date_out.year;
            getline (outtakes, buffor, '|');
            //cout << library[i].books[j].date_out.year << endl;

            outtakes >> library[i].books[j].date_back.day;
            getline (outtakes, buffor, '/');
            //cout << library[i].books[j].date_back.day << "/";
            outtakes >> library[i].books[j].date_back.month;
            getline (outtakes, buffor, '/');
            //cout << library[i].books[j].date_back.month << "/" ;
            outtakes >> library[i].books[j].date_back.year;
            //cout << library[i].books[j].date_back.year << endl;

            getline (outtakes, buffor, '|');
            getline (outtakes, library[i].books[j].consumer, '|');
            //cout << library[i].books[j].consumer << endl;

            outtakes >> library[i].books[j].fine;
            //cout << library[i].books[j].fine << endl;


            getline (outtakes, buffor, '\n');
            buffor.clear();


    }
}
outtakes.close();
outtakes.clear();
}

void correction()
{
    bool if_end;
    int x;
    int steer = 0;
    char answer;
    fstream tmp;
    fstream file;

    do
    {
        cout << "Któr¹ liniê chcesz poprawiæ (aby anulowaæ wpisz 0) ";
        cin >> x;
        if (x == 0)
        {
            if_end = false;
        }
        else if (x > oper)
        {
            cout << "B³¹d. Podaj liczbê mniejsz¹ od " << oper << endl;
            Sleep(1000);
            if_end = true;
        }
        else{

            do
            {
                cout << "Tytu³: " << library[x-1].name << endl;
                cout << "Autor: " << library[x-1].author << endl;
                cout << "Cena: " << library[x-1].cost << endl;
                cout << "Co chcesz poprawiæ? [t,a,c]? (Wpisz 0 aby zakoñczyæ) ";

                cin >> answer;
                cin.ignore();

                switch (answer)
                {
                case 't':
                    {

                        cout << "WprowadŸ nowy tytu³: ";
                        getline(cin, library[x-1].name);

                        break;
                    }
                case 'T':
                {

                    cout << "WprowadŸ nowy tytu³: ";
                    getline(cin, library[x-1].name);

                    break;
                }
                case 'a':
                    {

                        cout << "WprowadŸ nowe dane autora: ";
                        getline(cin, library[x-1].author);

                        break;
                    }
                case 'A':
                    {

                        cout << "WprowadŸ nowe dane autora: ";
                        getline(cin, library[x-1].author);

                        break;
                    }
                case 'c':
                    {

                        cout << "WprowadŸ now¹ cenê: ";
                        cin >> library[x-1].cost;
                        cin.ignore();
                        break;
                    }
                case 'C':
                    {

                        cout << "WprowadŸ now¹ cenê: ";
                        cin >> library[x-1].cost;
                        cin.ignore();
                        break;
                    }
                case '0':
                    {
                        break;
                    }
                default:
                    {

                        cout << "WprowadŸ t, a, c lub 0";
                        cin.ignore();
                    }
                }
            }while(answer != '0');


            cout << "\tKontynuowaæ? ";
            if_end = end_check(steer);
        }
    }while (if_end == true);

    file.open("library.txt", ios::out | ios::trunc);
    for (int i = 0; i < oper; i++)
    {
         if (i != 0)
            {
                file << "\n";
            }
            file << library[i].inv_number << "|";
            file.write(&library[i].name[0], library[i].name.size());
            file << "|";
            file.write(&library[i].author[0], library[i].author.size());
            file << "|";
            file << library[i].cost;
            file << "|";
            file << library[i].quantity;
            file << "|";
    }
    file.close();
    file.clear();




}

//_________________FUNCTIONS_CALLABLE___________________________//
void menu()
{

    int x;
    bool if_end = false;
    start();

    do
    {
        system("cls");
        owl(1);
        cout << "\t\t\tSystem biblioteczny \"Puszczyk\"\n";
        cout << "\n\n\n\n\n";
        cout << "\t\t\t 1. Dodaj pozycjê\n";
        cout << "\t\t\t 2. Wyœwietl tytu³y\n";
        cout << "\t\t\t 3. Stan ksiêgozbioru\n";
        cout << "\t\t\t 4. Edytuj wpisy\n";
        cout << "\t\t\t 5. Wypo¿ycz/zwróæ\n";
        cout << "\t\t\t 6. Stan wypo¿yczeñ\n";
        cout << "\t\t\t 101. Koniec\n";
        cout << "\n\n\n\n\n\t\t\t Twój wybór: ";

        cin >> x;

        if (!cin)
        {
            cin.clear();
            cin.sync();
            x = 0;
        }

        switch(x)
        {
        case 1:
            {
                insertion();
                break;
            }
        case 2:
            {
                outprint();
                break;
            }
        case 3:
            {
                state();
                break;
            }
        case 4:
            {
                correction();
                break;
            }
        case 5:
            {
                lend();
                break;
            }
        case 6:
            {
                lent_state();
                break;
            }
        case 101:
            {
                cout << "\t\t\tCzy aby na pewno? ";
                if_end = end_check(1);
                break;
            }
        default:
            {
                cout << "Proszê wybraæ jedn¹ z powy¿szych opcji";
                Sleep(500);
            }
        }
    }while( if_end != true);
    owl(3);
    cout << "\n\t\tCoded by Pitagoras Sofware\n";
    owl(3);

    Sleep(1000);
    system("cls");
}


