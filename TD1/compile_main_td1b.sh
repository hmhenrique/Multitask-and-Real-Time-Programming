arm-linux-g++ -Wall -Wextra src/main_td1b.cpp -o main_td1b -lrt -lpthread
scp main_td1b root@192.168.50.51:ROB305/TD1;
rm main_td1b;