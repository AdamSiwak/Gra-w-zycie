# Gra-w-zycie

Mapa składa się z kwadratów, na których mogą znajdować się następujące typy obiektów:
- dinozaury:
  * drapieżniki
  * roślinożercy
- drzewa - pokarm dla roślinożerców
- źródła wody - zarówno dla drapieżników, jak i roślinożerców
- jaskinie - kryjówki dla roślinożerców

Parametry dinozaura:
- wiek
- energia
- prędkość
- zasięg widzenia
- kąt widzenia
- poziom głodu
- poziom pragnienia

Dodatkowe parametry drapieżnika:
- siła
- głośność

Dodatkowe parametry roślinożercy:
- obrona
- słuch
- lokalizacja ostatnio widzianej kryjówki


Zachowania dinozaura:
- jeśli jest spragniony - szuka wody, ignoruje jedzenie
- jeśli jest głodny - szuka jedzenia
- jeśli nie jest głodny ani spragniony, a widzi innego dinozaura tego samego gatunku - reprodukcja
- jeśli widzi jedzenie, nawet, gdy nie jest głodny - je

Zachowania drapieżnika:
- jeśli w jego polu widzenia jest roślinożerca - porusza się w jego stronę i atakuje
- jeśli jest głodny - bardziej zdesperowany, szybciej się porusza

Zachowania roślinożercy:
- jeśli usłyszy drapieżnika - zdesperowany, szybciej się porusza, ale też szybciej traci energię, biegnie do ostatnio widzianej kryjówki (jeśli nie znalazł, to na oślep)
- jeśli schowa się do kryjówki, wychodzi z niej gdy zgłodnieje lub z powodu pragnienia
