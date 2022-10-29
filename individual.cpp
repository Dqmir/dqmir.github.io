#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void mostrarCodigo(string a[], string b[], string c[], int n, string nombre);
void rellenarMonedas(string a[], string b[], string c[], int n);
string decapitalize(string a);
string capitalize(string a);

int main (void)
{
    SetConsoleOutputCP(1252);
    string monedas[100], monedasjunto[100], monedasmasporcientos[100];
    string nombre, aux;
    int n, i;
    nombre = "";
    cout << "Enter the number of words the country has: ";
    cin >> i;
    for(int j=1;j<=i;j++)
    {
        aux = "";
        cout << "Enter the word number " << j << ": ";
        cin >> aux;
        nombre = nombre + aux + " ";
    }
    cout << "Enter the amount of coins to introduce: ";
    cin >> n;
    rellenarMonedas(monedas, monedasjunto, monedasmasporcientos, n);
    mostrarCodigo(monedas, monedasjunto, monedasmasporcientos, n, nombre);
}

void rellenarMonedas(string a[], string b[], string c[], int n)
{
    string valor, denominacion, anho, extra, aux;
    for(int i=0; i<n; i++)
    {
        cout << "Enter the denomination of the coin (1, 1/2, 10, ...): ";
        cin >> valor;
        cout << "Enter the currency: ";
        cin >> denominacion;
        cout << "Enter the year: ";
        cin >> anho;
        cout << "Enter the number of words the extra information has: ";
        cin >> i;
        extra = "";
        for(int j=1;j<=i;j++)
        {
            aux = "";
            cout << "Enter the word number " << j << ": ";
            cin >> aux;
            extra = extra + aux + " ";
        }

        system("CLS");

        if (extra == "0")
        {
            a[i] = valor + " " + denominacion + " " + anho;
            b[i] = valor + decapitalize(denominacion) + anho;
            c[i] = valor + "%20" + denominacion + "%20" + anho;
        }
        else
        {
            a[i] = valor + " " + denominacion + " " + anho + " (" + extra + ")";
            b[i] = valor + decapitalize(denominacion) + anho + "(" + decapitalize(extra) + ")";
            c[i] = valor + "%20" + denominacion + "%20" + anho + "%20(" + extra + ")";
        }

    }
    return;
}

void mostrarCodigo(string a[], string b[], string c[], int n, string nombre)
{
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang=\"en-UK\" dir=\"ltr\">" << endl;
    cout << "  <head>" << endl;
    cout << "    <meta charset=\"utf-8\">" << endl;
    cout << "    <title> " << nombre << " </title>" << endl;
    cout << "    <link rel=\"stylesheet\" type=\"text/css\" href=\"file:///C:/Users/damir/Desktop/1/Banknotes%20and%20Coins/Coins/countryStyle.css\">" << endl;
    cout << "  </head>" << endl;
    cout << "  <body>" << endl;

    for(int i=0; i<n; i++)
    {
        cout << "    <p style=\"font-size:20px;\">" << endl;
        cout << "      <b> " << a[i] << " </b> <br>" << endl;
        cout << "      <img src=\"" << a[i] << ".jpg\" alt=\"Image not found\" width=\"20%\" height=\"20%\" usemap=\"#" << b[i] << "\">" << endl;
        cout << "      <map name=\"" << b[i] << "\">" << endl;
        cout << "        <area shape=\"rect\" coords=\"0,0,4000,2000\" href=\"" << c[i] << ".jpg\" target=\"_blank\" alt=\"Image not found\">" << endl;
        cout << "      </map>" << endl;
        cout << "    </p>" << endl;
    }

    cout << "    <a href=\"file:///C:/Users/damir/Desktop/1/Banknotes%20and%20Coins/Coins/coinCollection.html\" style=\"color: #05e3e3\"> Return to main page </a>  <br>" << endl;
    cout << "  </body>" << endl;
    cout << "</html>" << endl;
}

string decapitalize(string a)
{
    char f;
    f = a[0];
    f = f + 32;
    a[0] = f;

    return a;
}

