# [TD-1] Mesure de temps et échantillonnage en temps

*Author : Henrique RODRIGUES*

To directly compile all the files, run:
```
./compile_all.sh
```
You may need to give permission for .sh files:
```
chmod +x compile_all.sh
```
------------------

## a)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td1a.cpp src/TimerLib/TimerLib.cpp -o main_td1a -lrt -lpthread
```

Or run:

```
./compile_main_td1a.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td1a
```

------------------

## b)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td1b.cpp -o main_td1b -lrt -lpthread
```

Or run:

```
./compile_main_td1b.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td1b
```

------------------


## c)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td1c.cpp src/TimerLib/TimerLib.cpp -o main_td1c -lrt -lpthread
```

Or run:

```
./compile_main_td1c.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td1c <nLoops>
```

Example: ./main_td1c 15

------------------


## d)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td1d.cpp src/TimerLib/TimerLib.cpp -o main_td1d -lrt -lpthread
```

Or run:
```
./compile_main_td1d.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td1d
```

------------------

## e)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td1e.cpp src/TimerLib/TimerLib.cpp -o main_td1e -lrt -lpthread
```

Or run:

```
./compile_main_td1e.sh
```


2. **Execute in the Raspberry Pi**:

```
./main_td1e
```
