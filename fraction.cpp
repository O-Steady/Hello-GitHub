#include "fraction.h"

using namespace std;

fraction::fraction(int numerateur  , int denominateur): m_numerateur(numerateur) , m_denominateur(denominateur)
{
    if (!denominateur)
        m_denominateur = 1;
}

int fraction::getNumerateur() const
{
    return m_numerateur;
}

int fraction::getDenominateur() const
{
    return m_denominateur;
}

void fraction::denominateurCommun(fraction& a)
{
    int D = m_denominateur * a.m_denominateur;
    m_numerateur *= a.m_denominateur;
    a.m_numerateur *= m_denominateur;
    m_denominateur = D;
    a.m_denominateur = D;
}

void fraction::simplification()
{
    int PGCD , a = m_numerateur , b = m_denominateur , r;
    if (m_numerateur != 0)
    {
        if (a > b)
            r = b;
        else
            r = a;
        while (r != 0)
        {
            PGCD = r;
            if (a > b)
                r = a % b;
            else
                r = b % a;
            a = b;
            b = r;
        }
        m_numerateur /= PGCD;
        m_denominateur /= PGCD;
    }
}

void fraction::setNumerateur(int numerateur)
{
    m_numerateur = numerateur;
}

void fraction::setDenominateur(int denominateur)
{
    m_denominateur = denominateur;
}

void fraction::afficher(ostream& flux) const
{
    if (m_denominateur == 1)
        flux<<m_numerateur;
    else
        flux<<m_numerateur<<"/"<<m_denominateur;
}

void fraction::lire(istream& flux)
{
    int n,d;
    cout<<"numerator: ";
    flux>>n;
    cout<<"denominator: ";
    flux>>d;
    m_numerateur = n;
    m_denominateur = d;
}

fraction operator+(fraction a , fraction b)
{
    fraction somme;
    a.denominateurCommun(b);
    somme.setNumerateur(a.getNumerateur() + b.getNumerateur());
    somme.setDenominateur(a.getDenominateur());
    a.simplification();
    b.simplification();
    somme.simplification();
    return somme;
}

fraction operator*(fraction a , fraction b)
{
    fraction produit;
    produit.setNumerateur(a.getNumerateur() * b.getNumerateur());
    produit.setDenominateur(a.getDenominateur() * b.getDenominateur());
    produit.simplification();
    return produit;
}

ostream& operator<<(ostream& flux , fraction a)
{
    a.afficher(flux);
}

istream& operator>>(istream& flux , fraction& a)
{
    a.lire(flux);
    if (a.getDenominateur() == 0)
        throw("MATH ERROR: denominator null \n");
}
