# Running median
## Co realizuje ten projekt

* Projekt zawiera aplikację pozwalającą na wyznaczanie mediany napływających
  danych. Użytkownik ma za zadanie wpisywać kolejne liczby, a wciśnięcie przycisku
  'q' powoduje zamkniecie porgramu. Przycisk 'm' wywołuje wypisanie na wyjściu
  standardowym aktualnie wyznaczonej mediany. Program nie przyjmuje parametrów


## Opis algorytmów

Realizowany problem jest znany jako 'running median'. Jest kilka podejść
umożliwiających realizację zadania. Wybrano podejście wykorzystujące dwa leżące
na przeciwko siebie Kopce (`Heaps`). Lewy kopiec (`maxHeap`) przechowuje
wartości aktulnie mniejsze niż wyliczona mediana, zaś prawy (`minHeap`) większe.
W trakcie dodowania nowych danych algorytm dba aby:
  * dane trafiły do odpowiedniego kopca
  * ilość danych w kopcach była identyczna z dokładnością do jednego
Następnie  wyznaczona jest mediana.
Algorytm de facto wyznacza medianę za każdym razem gdy dostarczane mu są dane.

Złożoność obliczeniowa dodawania danych : `O(log_n)`
Następują w najgorszym wypadku trzy operacje:
 * zdjęcie z czubka sterty
 * włożenie na przeciwną stertę czubka,
 * odłożenie na stertę nowej wartości

Każda z operacji ma złożoność `O(log_n)`

**UWAGA**
Implementacja stosu, jest klasyczną implementacją tablicową.
Zgodnie z założeniami, strumień nie ma określonego rozmiaru. Tak więc w przypadku
przekroczenia zakresu zaalokowanej pamięci klasa `BaseHeap` dokona realokacji,
w tej sytuacji złożoność takiego dodanan wynosi `O(N)`.


## Testy

Testy przeprowadzają :
 * test realokacji pamięci sterty
 * testy utrzymania struktury stosu przy dodawaniu danych
 * testy utrzymania struktury stosu przy usuwaniu czubka sterty
 * testy wyznaczenia mediany na podstawie danych przygotowanych za pomocą biblioteki Numpy (Python)  

## Środowisko:

* Ubuntu `Ubuntu 16.04.3 LTS`
* GCC `5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.10)`
* CMAKE `cmake version 3.5.1`
* python `Python 2.7.12`
