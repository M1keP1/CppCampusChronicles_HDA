#ifndef ORT_H
#define ORT_H

#include <iostream>

class Ort
{
public:
    Ort(double lat, double lon, std::string name);
    virtual ~Ort() = default;

    virtual void anzeigen() const = 0;

    double berechneEntfernung(const Ort& andererOrt) const;

    double getLatitude() const;
    double getLongitude() const;

    int getId() const;

    std::string getName() const;

    void setId(int newId);


protected:
    double latitude;
    double longitude;
      std::string name;
    static int idCounter;


private:
    int id;

};

#endif // ORT_H