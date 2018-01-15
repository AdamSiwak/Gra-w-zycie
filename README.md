# Instalacja

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

# Autorzy:
- Andrzej Dziwiński
- Adam Siwak
