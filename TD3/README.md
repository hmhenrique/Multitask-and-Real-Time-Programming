# [TD-3] Classes pour la gestion du temps

*Author : Henrique RODRIGUES*

To directly compile all the files, run:
```
./compile_all.sh
```
You may need to give permission for .sh files as follows:
```
chmod +x compile_all.sh
```
------------------

## a)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td3a.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp -o main_td3a -lrt -lpthread
```

Or run:

```
./compile_main_td3a.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td3a 
```

------------------

## b)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td3b.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/Timer/Timer.cpp src/PeriodicTimer/PeriodicTimer.cpp src/CountDown/CountDown.cpp -o main_td3b -lrt -lpthread
```

Or run:

```
./compile_main_td3b.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td3b <nLoops>
```
Example: ./main_td3b 15

------------------


## c)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra -Wno-psabi src/main_td3c.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/Timer/Timer.cpp src/PeriodicTimer/PeriodicTimer.cpp src/Looper/Looper.cpp src/Calibrator/Calibrator.cpp src/CpuLoop/CpuLoop.cpp -o main_td3c -lrt -lpthread
```

Or run:

```
./compile_main_td3c.sh 
```

2. **Execute in the Raspberry Pi**:

```
./main_td3c <samplingPeriod_ms> <nSamples> <duration_ms>
```

Example: ./main_td3c 100 10 1000