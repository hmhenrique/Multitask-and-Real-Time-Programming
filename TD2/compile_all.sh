arm-linux-g++ -Wall -Wextra src/main_td2a.cpp src/TimerLib/TimerLib.cpp -o main_td2a -lrt -lpthread;
arm-linux-g++ -Wall -Wextra src/main_td2b.cpp src/TimerLib/TimerLib.cpp -o main_td2b -lrt -lpthread;
arm-linux-g++ -Wall -Wextra src/main_td2c.cpp src/TimerLib/TimerLib.cpp -o main_td2c -lrt -lpthread;
scp main_td2a main_td2b main_td2c root@192.168.50.51:ROB305/TD2;
rm main_td2a;
rm main_td2b;
rm main_td2c;