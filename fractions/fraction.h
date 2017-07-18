#ifndef DEFF_FRACTION
#define DEFF_FRACTION

#include <iostream>

class fraction
{
public:
    fraction(int numerateur = 0 , int denominateur = 1);
    void denominateurCommun(fraction& a);
    void simplification();
    int getNumerateur() const;
    int getDenominateur() const;
    void afficher(std::ostream& flux) const;
    void lire(std::istream& flux);
    void setNumerateur(int numerateur);
    void setDenominateur(int denominateur);

private:
    int m_numerateur;
    int m_denominateur;
};
fraction operator+(fraction a , fraction b);
fraction operator*(fraction a , fraction b);
std::ostream &operator<<(std::ostream& flux , fraction a);
std::istream &operator>>(std::istream& flux , fraction& a);
#endif // DEFF_FRACTION
