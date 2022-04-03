arm-linux-g++ -Wall -Wextra src/main_td1a.cpp src/TimerLib/TimerLib.cpp -o main_td1a -lrt -lpthread;
arm-linux-g++ -Wall -Wextra src/main_td1b.cpp -o main_td1b -lrt -lpthread
arm-linux-g++ -Wall -Wextra src/main_td1c.cpp src/TimerLib/TimerLib.cpp -o main_td1c -lrt -lpthread
arm-linux-g++ -Wall -Wextra src/main_td1d.cpp src/TimerLib/TimerLib.cpp -o main_td1d -lrt -lpthread
arm-linux-g++ -Wall -Wextra src/main_td1e.cpp src/TimerLib/TimerLib.cpp -o main_td1e -lrt -lpthread
scp main_td1a main_td1b main_td1c main_td1d main_td1e root@192.168.50.51:ROB305/TD1;
rm main_td1a;
rm main_td1b;
rm main_td1c;
rm main_td1d;
rm main_td1e;