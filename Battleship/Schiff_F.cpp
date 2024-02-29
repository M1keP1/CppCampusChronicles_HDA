#include"Schiff_H.h"


int Schiffteil::get_reihe()
{
    return m_reihe;
}
int Schiffteil::get_spalte()
{
    return m_spalte;
}
Status Schiffteil::get_status()
{
    return m_status;
}

void Schiffteil::set_status(Status stat)
{
    m_status=stat;
}
