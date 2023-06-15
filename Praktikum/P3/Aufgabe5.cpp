#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MP3Tag {
public:

    enum Genre {
        Rock,
        Pop,
        Jazz,
        Musical,
        Klassik
    };

private:
    string interpret;
    string titel;
    int dauer;
    bool kopiergeschuetzt;
    Genre genre;

public:
    // Konstruktor
    MP3Tag(const string& interpret, const string& titel, int dauer, bool kopiergeschuetzt, Genre genre)
        : interpret(interpret), titel(titel), dauer(dauer), kopiergeschuetzt(kopiergeschuetzt), genre(genre) {}

    // Getter-Methoden
    string getInterpret() const {
        return interpret;
    }

    string getTitel() const {
        return titel;
    }

    int getDauer() const {
        return dauer;
    }

    bool istKopiergeschuetzt() const {
        return kopiergeschuetzt;
    }

    Genre getGenre() const {
        return genre;
    }

    // Setter-Methoden
    void setKopiergeschuetzt(bool kopiergeschuetzt) {
        this->kopiergeschuetzt = kopiergeschuetzt;
    }

    void setGenre(Genre genre) {
        this->genre = genre;
    }

    // Ausgabe auf der Konsole
    void print() const {
        cout << "Interpret: " << interpret << endl;
        cout << "Titel: " << titel << endl;
        cout << "Dauer: " << dauer << " Sekunden" << endl;
        cout << "Kopiergeschützt: " << (kopiergeschuetzt ? "Ja" : "Nein") << endl;
        cout << "Genre: " << getGenreString() << endl;
    }

private:
    // Hilfsfunktion zur Umwandlung des Genre-Enums in einen String
    string getGenreString() const {
        switch (genre) {
            case Rock:
                return "Rock";
            case Pop:
                return "Pop";
            case Jazz:
                return "Jazz";
            case Musical:
                return "Musical";
            case Klassik:
                return "Klassik";
            default:
                return "Unbekannt";
        }
    }
};

// Supportfunktion zum Befüllen des Vektors mit MP3Tag-Objekten
void fill(vector<MP3Tag>& vmp3tags) {
    string interpret, titel;
    int dauer;
    bool kopiergeschuetzt;
    int genreChoice;

    cout << "Eingabe der MP3-Tags (Leerzeile zum Beenden):" << endl;
    while (true) {
        cout << "Interpret: ";
        getline(cin, interpret);
        if (interpret.empty()) {
            break;
        }

        cout << "Titel: ";
        getline(cin, titel);

        cout << "Dauer (in Sekunden): ";
        cin >> dauer;
        cin.ignore();  // Ignoriere das Zeichen für die Eingabetaste

        cout << "Kopiergeschützt (1 = Ja, 0 = Nein): ";
        cin >> kopiergeschuetzt;
        cin.ignore();  // Ignoriere das Zeichen für die Eingabetaste

        cout << "Genre (0 = Rock, 1 = Pop, 2 = Jazz, 3 = Musical, 4 = Klassik): ";
        cin >> genreChoice;
        cin.ignore();  // Ignoriere das Zeichen für die Eingabetaste

        MP3Tag::Genre genre;
        switch (genreChoice) {
            case 0:
                genre = MP3Tag::Rock;
                break;
            case 1:
                genre = MP3Tag::Pop;
                break;
            case 2:
                genre = MP3Tag::Jazz;
                break;
            case 3:
                genre = MP3Tag::Musical;
                break;
            case 4:
                genre = MP3Tag::Klassik;
                break;
            default:
                genre = MP3Tag::Rock;
                break;
        }

        vmp3tags.emplace_back(interpret, titel, dauer, kopiergeschuetzt, genre);
    }
}

int main() {
    vector<MP3Tag> vmp3tags;
    fill(vmp3tags);

    // Ausgabe der Daten aller MP3-Tags im Vector
    for (const auto& mp3 : vmp3tags) {
        mp3.print();
        cout << endl;
    }

    return 0;
}
