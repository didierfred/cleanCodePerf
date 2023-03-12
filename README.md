# Clean code performance tests


After reading https://www.computerenhance.com/p/clean-code-horrible-performance , I tested it using calculation time 


I tried in javascript/python and C++

The test has been executed on Ubuntu 20.04.5 LTS , with following machine characteristics 

```
Architecture :                          x86_64
Mode(s) opératoire(s) des processeurs : 32-bit, 64-bit
Boutisme :                              Little Endian
Address sizes:                          39 bits physical, 48 bits virtual
Processeur(s) :                         8
Liste de processeur(s) en ligne :       0-7
Thread(s) par cœur :                    2
Cœur(s) par socket :                    4
Socket(s) :                             1
Nœud(s) NUMA :                          1
Identifiant constructeur :              GenuineIntel
Famille de processeur :                 6
Modèle :                                158
Nom de modèle :                         Intel(R) Core(TM) i7-7820HQ CPU @ 2.90GHz
Révision :                              9
Vitesse du processeur en MHz :          2900.000
Vitesse maximale du processeur en MHz : 3900,0000
Vitesse minimale du processeur en MHz : 800,0000
BogoMIPS :                              5799.77
Virtualisation :                        VT-x
Cache L1d :                             128 KiB
Cache L1i :                             128 KiB
Cache L2 :                              1 MiB
Cache L3 :                              8 Mi
```

# To use

## Javascript

```
node js/clean.js

node js/unclean.js
```


## Python 

```
python3 python/clean.py 

python3 python/unclean.py 
```


## C++ 



```
#Compile 
cd cpp
g++ clean.cpp -o clean 
g++ unclean.cpp -o unclean 

#Execute 

./clean

./unclean

```

## C++ with optimization 


```
#Compile 
cd cpp
g++ -03 clean.cpp -o clean 
g++ -03 unclean.cpp -o unclean 

#Execute 

./clean

./unclean

```




# Results 

| Language     | Clean code | Not clean code
| ----------- | ----------- | -----------
| C++      | 23ms       | 28ms
| C++ with optimization | 14ms | 0.003ms
| JavaScript   | 20ms        | 52ms
| Python | 677ms | 1806ms