#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> salida;
    for (int i = 0; i < s.size(); ++i) {
        bool check = true;
        for (int j = i+1; j < s.size() ; ++j) {
            if (s[i] == s[j]){
                check = false;
            }
        }
        if (check){
            salida.push_back(s[i]);
        }
    }
    return salida;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> aux_set;
    vector<int> salida;
    
    for (int i = 0; i <s.size() ; ++i) {
        aux_set.insert(s[i]);
    }
    salida.assign(aux_set.begin(), aux_set.end());
    return salida;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    int i =0;
    bool check=true;
    while (i<a.size() & check){
        check=false;
        for (int j = 0; j < b.size() ; ++j) {
            if(a[i]==b[j]){
                check=true;
            }
        }
    i=i+1;
    }
    return i ==a.size() & check;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return true;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    int acumulador = 0;
    map<int, int> salida;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size() ; ++j) {
            if (s[i] == s[j]){
                acumulador +=1;
            }
        }
        salida[s[i]]=acumulador;
        acumulador = 0;
    }
    return salida;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> salida;
    int contador;
    for (int i = 0; i < s.size(); ++i) {
        contador=0;
        for (int j = 0 ; j < s.size() ; ++j) {
            if (s[i] == s[j]){
                contador+=1;
            }
        }
        if (contador<2){
            salida.push_back(s[i]);
        }
    }
    return salida;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> salida;
    for (int x : a ) {
        if(b.count(x) == 1){
            salida.insert(x);
        }
    }
    return salida;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {

    map<int, set<int>> salida;
    for (int n : s) {
        int group = n % 10;

        if (salida.count(group) == 1){
            salida[group].insert(n);
        } else{
            set<int> aux_set;
            aux_set.insert(n);
            salida[group] =  aux_set;
        }
    }
    return salida;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> salida;
    if (tr.size() != 0) {
        for (char n : str) {
            bool check = true;
            for (int i = 0; i < tr.size(); ++i) {
                if (n == tr[i].first) {
                    salida.insert(salida.end(), tr[i].second);
                    check = false;
                }
            }
            if (check) {
                salida.insert(salida.end(), n);
            }
        }
    } else {
        salida = str;
    }
    return salida;
}


// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool check = false;
    for (int i = 0; i < s.size() & !check ; ++i) {
        set<LU> LUs ;
        LUs = s[i].libretas();
        for (LU LU1 : LUs) {
            for (int j = i+1; j < s.size() & !check ; ++j) {
                set<LU> LUs2 ;
                LUs2 = s[j].libretas();
                for (LU  LU2 : LUs2){
                    if (LU1 == LU2 & LUs2 != LUs){
                        check= true;
                    }
                }
            }
        }
    }
    return check;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();

  
}
