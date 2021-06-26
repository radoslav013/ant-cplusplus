#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const int MAX_FILMS = 500;

struct Film{
    string name;
    string plot;
    string actor;
    string director;
    int rate;
};

void tokenize(string* params, string s, string del = " "){
    int start = 0;
    int end = s.find(del);
    int i = 0;
    while (end != -1) {
        params[i] = s.substr(start, end - start);
        start = end + del.size();
        end = s.find(del, start);
        i++;
    }
    *(params+i) = s.substr(start, end - start);
}

int readFile(Film* films) {
    string currentLine;

    ifstream file("films.txt");

    int i = 0;
    while (getline(file, currentLine)) {
        string params[5];
        tokenize(&params[0], currentLine, ",");

        Film currentFilm;
        currentFilm.name = params[0];
        currentFilm.actor = params[1];
        currentFilm.director = params[2];
        currentFilm.plot = params[3];
        currentFilm.rate = stoi(params[4]);

        *(films+i) = currentFilm;
        i++;
    }

    // Close the file
    file.close();
    return i;
}

void printMoviesAndDirectors(){
    Film films[MAX_FILMS];
    int filmCount = readFile(&films[0]);
    for(int i = 0; i < filmCount; i++) {
        cout << "Film's name: " << films[i].name << " director: " << films[i].director << endl;
    }
}

void writeMovie(){
    Film film;

    cout<< "Enter movie title: ";
    getline(cin,film.name);
    cout<< "Enter movie actor: ";
    getline(cin,film.actor);
    cout<< "Enter movie director: ";
    getline(cin,film.director);
    cout<< "Enter movie rate: ";
    cin>>film.rate;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<< "Enter movie plot: ";
    getline(cin,film.plot);

    ofstream file("films.txt", fstream::out | fstream::app);
    file << film.name<< ","<<film.actor<<","<<film.director<<","<<film.plot<<","<<film.rate<<endl;
    file.close();

}

void printRating(){
    // cout<<film.name<<"rating is "<<film.rate;

}

void printActor(){
    // cout<<film.name<<"actor is: "<<film.actor;
}

void printPlot(){
    // cout<<film.name<<"plot is: "<<film.plot;
}

int main()
{
    while(true){
        int n;
        cout << "Press 1 to print all movies and their directors" << endl;
        cout << "Press 2 to write movie, director, plot, actor and rating"<< endl;
        cout << "Press 3 to print all film's rating"<< endl;
        cout << "Press 4 to print film's actor"<< endl;
        cout << "Press 5 to print all films and their plot"<< endl;
        cout << "Press 0 to stop "<< endl;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(n==0){
            break;
        }
        //TODO: show films with rating 10
        switch(n){
            case 1: printMoviesAndDirectors(); break;
            case 2: writeMovie(); break;
            case 3: printMoviesAndDirectors(); break;
            case 4: printActor(); break;
            case 5: printPlot(); break;
        }
    }
    return 0;
}
