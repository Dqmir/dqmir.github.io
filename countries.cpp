#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

void rellenarPaises(string a[], string b[], int n);
void mostrarPaises(string a[], string b[], int n);
string decapitalize(string a);
string capitalize(string a);

int main (void)
{
    SetConsoleOutputCP(1252);
    string paises[100], coordenadas[100];
    int n;
    cout << "Introduzca el número de países que quiere añadir: ";
    cin >> n;
    rellenarPaises(paises, coordenadas, n);
    mostrarPaises(paises, coordenadas, n);

}

void rellenarPaises(string a[], string b[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << "Introduzca el nombre del país " << i+1 << ": ";
        cin >> a[i];
        cout << "Introduzca las coordenadas del país " << i+1 << ": ";
        cin >> b[i];
        system("CLS");
    }
    return;
}

void mostrarPaises(string a[], string b[], int n)
{

    for(int i=0; i<n; i++)
    {
        if(b[i].size()<=10)
        {
            cout << "<!-- " << a[i] << " -->" << endl;
            cout << "<div class=\"myDIV\">" << endl;
            cout << "  <area shape=\"circle\" coords=\"" << b[i] << "\" href=\"" << a[i] << "/" << decapitalize(a[i]) << ".html\" alt=\"" << a[i] << "\">" << endl;
            cout << "</div>" << endl;
            cout << "<div class=\"hide\">" << endl;
            cout << "<div class=\"country\">" << endl;
            cout << "  " << capitalize(a[i]) << endl;
            cout << "</div>" << endl;
            cout << "<img src=\"Flags/" << a[i] << ".png\" alt=\"Flag_of_" << a[i] << "\" width=\"45\" height=\"30\" style=\"position:relative;\">" << endl;
            cout << "</div>" << endl;
            cout << endl;
        }
        else
        {
            cout << "<!-- " << a[i] << " -->" << endl;
            cout << "<div class=\"myDIV\">" << endl;
            cout << "  <area shape=\"poly\" coords=\"" << b[i] << "\" href=\"" << a[i] << "/" << decapitalize(a[i]) << ".html\" alt=\"" << a[i] << "\">" << endl;
            cout << "</div>" << endl;
            cout << "<div class=\"hide\">" << endl;
            cout << "<div class=\"country\">" << endl;
            cout << "  " << capitalize(a[i]) << endl;
            cout << "</div>" << endl;
            cout << "<img src=\"Flags/" << a[i] << ".png\" alt=\"Flag_of_" << a[i] << "\" width=\"45\" height=\"30\" style=\"position:relative;\">" << endl;
            cout << "</div>" << endl;
            cout << endl;
        }

    }
    return;
}

string decapitalize(string a)
{
    char f;
    f = a[0];
    f = f + 32;
    a[0] = f;

    return a;
}

string capitalize(string a)
{
    char f;
    for(int i=1; i<a.size(); i++)
    {
        f = a[i];
        f = f - 32;
        a[i] = f;
    }
    return a;
}
