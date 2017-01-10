#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include "funciones.cpp"

using namespace std;

int main()
{
  //1001000100011010001
  //0101100111100010011010
  //10111100110111100001111
  bitset<19> v_1 (std::string("1001000100011010001"));
  bitset<22> v_2 (std::string("0101100111100010011010"));
  bitset<23> v_3 (std::string("10111100110111100001111"));
  vector<int> secuencia_cifrante;
  vector<int> cifrado;

  string texto_original;

  imprimir(v_1,v_2,v_3);

  cout << "Introducir texto original: ";
  cin >> texto_original;

  cout << endl;
  //XOR
  int i=0;
  while(i<=texto_original.length())
  {
    cout << "-------------------------------------------" << endl;
    cin.get();
    imprimir(v_1,v_2,v_3);
    int resultado_1 = 0;
    resultado_1 = v_1.test(13) ^ v_1.test(16) ^ v_1.test(17) ^ v_1.test(18);
    cout << "Datos:" << endl;
    cout << "\t-Xor vector 1: " << resultado_1 << ", ";

    int resultado_2 = 0;
    resultado_2 = v_2.test(21) ^ v_2.test(20);
    cout << "Xor vector 2: " << resultado_2 <<", ";

    int resultado_3 = 0;
    resultado_3 = v_3.test(22) ^ v_3.test(21) ^ v_3.test(20) ^ v_3.test(7);
    cout << "Xor Vector 3: " << resultado_3 << endl;
    int fin = 0;
    //fin = resultado_1 ^ resultado_2 ^ resultado_3;
    fin = v_1.test(18) ^ v_2.test(21) ^ v_3.test(22);
    cout << "\t-z(t): a(t) ^ b(t) ^ c(t) => " << v_1.test(18)  << " ^ " << v_2.test(21) << " ^ " << v_3.test(22) << " = " << fin << endl;
    secuencia_cifrante.resize(secuencia_cifrante.size()+1);
    secuencia_cifrante[i] = fin;
    funcion_mayoria(v_1,v_2,v_3,resultado_1,resultado_2,resultado_3);
    //cout << "Desplazamiento..." << endl;
    i++;
    cout << endl;
    cout << "Presione enter para la siguiente iteracion..." << endl;
  }

  cout << "-------------------------------------------" << endl;
  cout << "Secuencia cifrante resultante. z(t) =  ";
  for(int i=0;i<secuencia_cifrante.size();i++)
  {
    cout << secuencia_cifrante[i];
    if(i< secuencia_cifrante.size()-1)
    {
      cout << ",";
    }
  }
  cout << endl;

  /*
  //Hacer el xor del mensaje original con la secuencia cifrante
  cout << "-------------------------------------------" << endl;
  cout << "XOR:" << endl;
  if(texto_original.size() == secuencia_cifrante.size())
  {
    //Recorriendo secuencia_cifrante de izquierda a derecha
    cifrado.resize(texto_original.size());
    for(int i=0;i<texto_original.size();i++)
    {
        cifrado[i] = ((bool)texto_original[i] ^ secuencia_cifrante[i]);
        cout << (bool)texto_original[i] << " ^ " << secuencia_cifrante[i] << " = " << cifrado[i] << endl;
    }
    //Recorriendo secuencia_cifrante de derecha a izquierda
    /*int cont1=0;
    int cont2=secuencia_cifrante.size()-1;
    while(cont1 < texto_original.size() && cont2 >=0)
    {
      cifrado[cont1] = ((bool)texto_original[cont1] ^ secuencia_cifrante[cont2]);
      cout << (bool)texto_original[cont1] << " ^ " << secuencia_cifrante[cont2] << " = " << cifrado[cont1] << endl;
    }*/
/*  }

  cout << "Resultado cifrado: " << endl;
  for(int i=0;i<cifrado.size();i++)
  {
    cout << cifrado[i];
    if(i< cifrado.size()-1)
    {
      cout << ",";
    }
  }
  */
  //---------------------MODIFICACIÓN----------------
  cout << endl;
  cout << "Modificacion:" << endl;
  bitset<19> a;
  bitset<22> b;
  bitset<23> c;
  bitset<64> clave (std::string("1011110011011110000111101011001111000100110101001000100011010001"));
  cout << "Inicializacion de vectores: " << endl;
  imprimir(a,b,c);
  cout << "Vector clave: " << clave << endl;
  int ciclo = 0;
  cout << "Comenzar[ENTER]" << endl;
  while(ciclo < 10)
  {
    cout << "---------------------------------------------" << endl;
    cin.get();
    cout << "Ciclo: " << ciclo+1 << endl;
    //Xor vector 1
    int resultado_1 = 0;
    resultado_1 = a.test(13) ^ a.test(16) ^ a.test(17) ^ a.test(18) ^ clave.test(ciclo);
    cout << "-Xor vector 1: " << a.test(18) << " ^ " << a.test(17) << " ^ " << a.test(16) << " ^ " << a.test(13) << " ^ " << clave.test(ciclo) << " => " << resultado_1 << endl;
    //Xor vector 2
    int resultado_2 = 0;
    resultado_2 =  b.test(21) ^ b.test(20) ^ clave.test(ciclo);
    cout << "-Xor vector 2: " << b.test(21) << " ^ " << b.test(20) << " ^ " << clave.test(ciclo) << " => " << resultado_2 << endl;
    //Xor vector 3
    int resultado_3 = 0;
    resultado_3 = c.test(22) ^ c.test(21) ^ c.test(20) ^ c.test(7) ^ clave.test(ciclo);
    cout << "-Xor vector 3: " << c.test(22) << " ^ " << c.test(21) << " ^ " << c.test(20) << " ^ " << c.test(7) << " ^ " << clave.test(ciclo) << " => " << resultado_3 << endl;

    //Desplazamientos
    a = a << 1;
    a.set(0,resultado_1);
    b = b << 1;
    b.set(0,resultado_2);
    c = c << 1;
    c.set(0, resultado_3);

    imprimir(a,b,c);
    ciclo++;
    cout << endl;
    cout << "Presione enter para la siguiente iteracion..." << endl;
  }
  cout << endl;
  return 0;
}
