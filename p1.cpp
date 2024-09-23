// autor
// descripcion

#include <iostream>
#include <format>
using namespace std;

int main()
{
  int dolares, pesetas, dimes, vellones, chavos;

  cout << "Cantidad de $1, 25¢, 10¢, 5¢, 1¢ a devolver: ";
  cin >> dolares >> pesetas >> dimes >> vellones >> chavos;
  cout << format("Ingresaste {} dolares, {} pesetas, {} dimes, {} vellones y {} chavos\n", 
                  dolares, pesetas, dimes, vellones, chavos);
  
  return 0;
}
