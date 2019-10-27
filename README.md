# Game Of Life

## Establishments

The goal of this project is to implement an interesting "play in life" scenario. According to the traditional approach, on the unlimited board divided into square cells there are individuals whose state changes in subsequent moments. Each cell can be "alive" or "dead", and its condition in the next moment depends only on the number of its neighbors (if there are too few - the cell dies from "loneliness", too much - dies from "overpopulation"). If the dead cell has three neighbors - in the next unit of time it will become alive ("born").
The new approach will involve the presence of 2 groups: herbivores and carnivores. In addition, there will be other elements on the board: water sources, plants (food for herbivores). The traditional approach will preserve the existence of time units and the slightly modified life cycle of individuals. If two individuals from the same group meet, a new individual is born, which inherits the characteristics of the parents (after crossing and mutation). Herbivores die if they are killed by predators, from hunger or thirst, and carnivores - from hunger or thirst. Both groups can also die of old age. A herbivore can hide from a predator in a cave, but must leave it to drink or get food.
The user will be able to track the development of both populations (in the form of graphs), and view the characteristics of the selected individual (its condition and parameters). It will also decide on the initial state of these populations.

## Description of application

The scenario of the proposed simulation of a "game of life" assumes the struggle for survival of two dinosaur populations: herbivores and carnivores. Animals that do not eat meat (green coloration) feed on trees and can be eaten by predators (brown coloration). A rescue for herbivores is to escape to the cave. At this point, the meat eater gives up the attack and is looking for another target. Individuals from both populations must eat and drink cyclically to survive. When they have basic needs met and have reached adulthood, they can reproduce. Reproduction consumes some of the energy dinosaurs have, so they must satisfy hunger and thirst again. The newborn dinosaur inherits the parents' characteristics as an arithmetic mean. However, a mutation of up to 10% in parameter deviation may occur. The probability of its occurrence is 2%.
Individuals differ in speed of movement. However, faster-moving dinosaurs have smaller stomach capacities, so they need to eat more often. This approach leads to equal opportunities for reproduction of individuals with different characteristics.
Death of a dinosaur can occur naturally (from old age), from hunger or from thirst. Herbivores can also be eaten by predators.
In order to facilitate statistical analysis, the basic life parameters of both populations are presented in charts. In addition, you can also display the data of individual individuals by selecting the left mouse button. This action produces a sound and displays a "cloud" with the basic life parameters of the dinosaur, and the individual enters the manual control mode (arrows on the keyboard). Clicking on the field outside the dinosaur causes a return to automatic control and hides the "cloud".

## Installation

In order to apply the application on the Ubuntu 16.04 operating system, the following packages must be introduced:
- qtbase5-dev
- qtmultimedia5-dev
- libboost-dev

Then use the QtCreator installer (https://www.qt.io/download), or using the instructions:
wget http://download.qt.io/official_releases/qt/5.7/5.7.0/qt-opensource-linux-x64-5.7.0.run
Before running, you must change the file permissions:
chmod + x qt-unified-linux-x64-3.0.2-online.run
./qt-unified-linux-x64-3.0.2-online.run

During installation, select the options:
Qt 5.9.3 -> Desktop gcc 64-bit
Qt 5.9.3 -> Qt charts

Then, after applying the installation, apply the application without starting the environment.

Go to Game-in-life consideration and run the commands:
<folder_to_ktorego_z installed_Qt> /5.9.3/gcc_64/bin/qmake
do

The procedures should be repeated for the unit test project - in the folder Game-in-life / Tests_stand / test_stand.

## Authors:
- Andrzej Dziwiński
- Adam Siwak


# Gra w życie

## Założnia projektowe

Celem niniejszego projektu jest implementacja ciekawego scenariusza „gry w życie”. Zgodnie z tradycyjnym podejściem, na nieograniczonej planszy podzielonej na kwadratowe komórki istnieją osobniki, których stan zmienia się w kolejnych chwilach czasowych. Każda komórka może być „żywa” lub „martwa”, a jej stan w kolejnej chwili jest zależny tylko od liczby jej sąsiadów (jeśli jest ich zbyt mało – komórka umiera z „samotności”, zbyt dużo – umiera z „przeludnienia”). Jeśli martwa komórka ma trzech sąsiadów – w następnej jednostce czasu stanie się żywa („urodzi się”). 
Nowe podejście polegało będzie na obecności 2 grup: roślinożerców i mięsożerców. Oprócz tego na planszy będą istniały inne elementy: źródła wody, rośliny (jedzenie dla roślinożerców). Z tradycyjnego podejścia zachowane zostanie istnienie jednostek czasu oraz lekko zmodyfikowany cykl życia osobników. Jeśli spotkają się dwa osobniki z tej samej grupy, rodzi się nowy osobnik, który dziedziczy cechy rodziców (po krzyżowaniu i mutacji). Roślinożercy giną, jeśli zabiją je drapieżniki, z głodu lub pragnienia, a mięsożercy – z głodu lub pragnienia. Obie grupy mogą także umrzeć ze starości. Roślinożerca może się ukryć przed drapieżnikiem w jaskini, musi z niej jednak wyjść, aby się napić lub zdobyć pożywienie.
Użytkownik będzie miał możliwość śledzenia rozwoju obu populacji (w postaci wykresów), oraz podglądania cech wybranego osobnika (jego stan oraz parametry). Będzie także decydował o stanie początkowym tych populacji.

## Opis progaramu

Scenariusz zaproponowanej symulacji „gry w życie” zakłada walkę o przetrwanie dwóch populacji dinozaurów: roślinożerców i mięsożerców. Zwierzęta niejedzące mięsa (ubarwienie zielone) odżywiają się drzewami i mogą być pożarte przez drapieżniki (ubarwienie brązowe). Ratunkiem dla roślinożercy jest ucieczka do jaskini. W tym momencie mięsożerca rezygnuje z ataku i poszukuje innego celu. Osobniki obu populacji muszą się cyklicznie odżywiać i pić aby przetrwać. Gdy mają zaspokojone podstawowe potrzeby i osiągnął wiek dojrzałości mogą się rozmnażać. Reprodukcja pochłania część energii jaką dysponują dinozaury, więc znowu muszą zaspokoić głód i pragnienie. Nowonarodzony dinozaur dziedziczy cechy rodziców jako średnią arytmetyczną. Może jednak zajść mutacja do 10 % odchylania parametrów. Prawdopodobieństwo jej wystąpienia to 2 %. 
Osobniki różnią się miedzy sobą prędkością poruszania się. Dinozaury szybciej przemieszczające się charakteryzuje jednak mniejsza pojemność żołądka, więc muszą częściej się odżywiać. Takie podejście prowadzi do wyrównania szans na reprodukcję osobników o różnych cechach. 
Śmierć dinozaura może nastąpić w sposób naturalny (ze starości), z głodu lub z pragnienia. Roślinożercy mogą być również pożarci przez drapieżniki. 
W calu ułatwienia analizy statystycznej podstawowe parametry życiowe obu populacji przedstawiono na wykresach. Ponadto można również wyświetlić dane poszczególnych osobników po wybraniu lewym klawiszem myszy. Akcja ta powoduje wydanie dźwięku i wyświetlenie „chmurki” z podstawowymi parametrami życiowymi dinozaura, a sam osobnik przechodzi w tryb sterowania ręcznego (strzałki na klawiaturze). Klikniecie na pole poza dinozaurem powoduje powrót do automatycznego sterowania i ukrycie „chmurki”. 

## Instalacja

W celu uruchomienia aplikacji na systemie operacyjnym Ubuntu 16.04 należy zainstalować następujące pakiety:
- qtbase5-dev
- qtmultimedia5-dev
- libboost-dev

Następnie należy pobrać instalator środowiska QtCreator (https://www.qt.io/download), lub przy użyciu polecenia:
wget http://download.qt.io/official_releases/qt/5.7/5.7.0/qt-opensource-linux-x64-5.7.0.run
Przed uruchomieniem należy zmienić uprawnienia pliku:
chmod +x qt-unified-linux-x64-3.0.2-online.run
./qt-unified-linux-x64-3.0.2-online.run

Podczas instalacji należy wybrać opcje: 
Qt 5.9.3 -> Desktop gcc 64-bit
Qt 5.9.3 -> Qt Charts

Następnie po zakończeniu instalacji należy zamknąć aplikację bez uruchamiania środowiska.

Należy przejść do folderu Gra-w-zycie i uruchomić polecenia:
<folder_do_ktorego_zainstalowano_Qt>/5.9.3/gcc_64/bin/qmake
make

Procedurę należy powtórzyć dla projektu testów jednostkowych - w folderze Gra-w-zycie/Testy_jednostkowe/testy_jednostkowe.

## Autorzy:
- Andrzej Dziwiński
- Adam Siwak
