# [TD-5] Inversion de priorité

*Author : Henrique RODRIGUES*


1. **Compile**:

```
arm-linux-g++ -Wall -Wextra -Wno-psabi src/main_td5.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Timer/Timer.cpp src/PeriodicTimer/PeriodicTimer.cpp src/Looper/Looper.cpp src/Calibrator/Calibrator.cpp src/CpuLoop/CpuLoop.cpp src/Mutex/Mutex.cpp src/CpuMutexLoop/CpuMutexLoop.cpp -o main_td5 -lrt -lpthread
```

Or run:

```
./compile_main_td5.sh
```

You may need to give permission for .sh files:
```
chmod +x compile_main_td5.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td5 <InversionSafe>
```

Example: ./main_td5 notInversionSafe

Example: ./main_td5 InversionSafe

