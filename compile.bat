g++ -std=c++11 src\Ball.cpp src\Bar.cpp src\Brick.cpp src\easylogging++.cc main.cpp -Iinclude -I"%home%\libs\SFML-2.5.1\include" -L"%home%libs\SFML-2.5.1\bin" sfml-graphics-d-2.dll sfml-audio-d-2.dll sfml-network-d-2.dll sfml-window-d-2.dll sfml-system-d-2.dll -o game

