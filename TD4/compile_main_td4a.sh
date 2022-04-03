arm-linux-g++ -Wall -Wextra src/main_td4a.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Incrementer/Incrementer.cpp -o main_td4a -lrt -lpthread;
scp main_td4a root@192.168.50.51:ROB305/TD4;
rm main_td4a;