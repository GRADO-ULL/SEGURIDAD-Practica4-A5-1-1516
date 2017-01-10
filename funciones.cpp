using namespace std;

void inicializar(bitset<19> &v1,bitset<22> &v2,bitset<23> &v3)
{
  cout << "Introduzca secuencia de bits para vector 1: ";
  cin >> v1;
  cout << "Introduzca secuencia de bits para vector 2: ";
  cin >> v2;
  cout << "Introduzca secuencia de bits para vector 3: ";
  cin >> v3;
}

void imprimir(bitset<19> &v1,bitset<22> &v2,bitset<23> &v3)
{
  cout << "Vectores: " << endl;
  cout << "Vector 1: " << v1 << "\t\t," << "Dimension: " << v1.size() << endl;
  cout << "Vector 2: " << v2 << "\t," << "Dimension: " << v2.size() << endl;
  cout << "Vector 3: " << v3 << "\t," << "Dimension: " << v3.size() << endl;
}

void funcion_mayoria(bitset<19> &v1,bitset<22> &v2,bitset<23> &v3,int res1,int res2,int res3)
{
  bitset<3> v;
  v.set(0, v1.test(8));
  v = v << 1;
  v.set(0, v2.test(10));
  v = v << 1;
  v.set(0, v3.test(10));
  int i=0;

  cout << "\tControl reloj: " << v << endl;
  cout << "\tSe desplazan: ";
  //cout << "\tNumero de 1: " << v.count() << endl;
  //cout << "\tNumero de 0: " << v.size()-v.count() << endl;

  if(v.count() > (v.size()-v.count()))
  {
      //cout << "\tHay mas 1 que 0" << endl;
      if(v1.test(8) == 1)
      {
        cout << "Vector 1 , ";
        v1 = v1 << 1;
        v1.set(0,res1);
      }
      if(v2.test(10) == 1)
      {
        cout << "Vector 2 , ";
        v2 = v2 << 1;
        v2.set(0,res2);
      }
      if(v3.test(10) == 1)
      {
        cout << "Vector 3 , ";
        v3 = v3 << 1;
        v3.set(0,res3);
      }
  }
  else
  {
    //cout << "\tHay mas 0 que 1" << endl;
    if(v1.test(8) == 0)
    {
      cout << "Vector 1 , ";
      v1 = v1 << 1;
      v1.set(0,res1);
    }
    if(v2.test(10) == 0)
    {
      cout << "Vector 2 , ";
      v2 = v2 << 1;
      v2.set(0,res2);
    }
    if(v3.test(10) == 0)
    {
      cout << "Vector 3 , ";
      v3 = v3 << 1;
      v3.set(0,res3);
    }
  }
}
