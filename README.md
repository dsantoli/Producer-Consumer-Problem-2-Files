# Producer-Consumer-Problem-2-Files
The producer generates items and puts items onto the table. The consumer will pick up items. The table can only hold two items at the same time. When the table is complete, the producer will wait. When there are no items, the consumer will wait. We use semaphores to synchronize producer and consumer.  Mutual exclusion should be considered. We use threads in the producer program and consumer program. Shared memory is used for the “table”. 
# What is happening 
Creates one producer and one consumer. Producer produces 100 random numbers and consumer consumes 100 numbers. The producer and consumer are synchronized working as fast as possible. Producer will most likely produce 2 items to start then consumer will start consuming. Producer will produce after item is consumed.The first item produced is last consumed. The code will output what number is "produced" or "consumed".
# My Implementation 
I implemented this using two files. producer.c and consumer.c 

More producers can be created by altering THREADSIZE.
# How to compile 

two source files, compile them into object files without linking

-c flag tells the compiler to stop after the compilation phase, without linking. Then link two object files.

Compile :

$ gcc producer.c -pthread -o producer.o -c

$ gcc consumer1.c -pthread -o consumer1.o -c

$ gcc -o producerconsumer producer.o consumer.o

$ ./producerconsumer

# Example Run & Output
dsant@LAPTOP- MINGW64 ~/Desktop/VS code projects/C-C++ workspace (master)
$ gcc producer.c -pthread -o producer.o -c

dsant@LAPTOP- MINGW64 ~/Desktop/VS code projects/C-C++ workspace (master)
$ gcc consumer.c -pthread -o consumer.o -c

dsant@LAPTOP- MINGW64 ~/Desktop/VS code projects/C-C++ workspace (master)
$ gcc -o producerconsumer producer.o consumer.o

dsant@LAPTOP- MINGW64 ~/Desktop/VS code projects/C-C++ workspace (master)
$ ./producerconsumer

Produced 41
Produced 167
Consumed 167
Produced 34
Consumed 34
Produced 100
Consumed 100
Produced 269
Consumed 269
Produced 124
Consumed 124
Produced 78
Consumed 78
Produced 258
Consumed 258
Produced 262
Consumed 262
Produced 164
Consumed 164
Produced 5
Consumed 5
Produced 245
Consumed 245
Produced 181
Consumed 181
Produced 27
Consumed 27
Produced 61
Consumed 61
Produced 191
Consumed 191
Produced 295
Consumed 295
Produced 242
Consumed 242
Produced 27
Consumed 27
Produced 36
Consumed 36
Produced 291
Consumed 291
Produced 204
Consumed 204
Produced 2
Consumed 2
Produced 153
Consumed 153
Produced 292
Consumed 292
Produced 82
Consumed 82
Produced 21
Consumed 21
Produced 116
Consumed 116
Produced 218
Consumed 218
Produced 95
Consumed 95
Produced 47
Consumed 47
Produced 126
Consumed 126
Produced 71
Consumed 71
Produced 138
Consumed 138
Produced 69
Consumed 69
Produced 112
Consumed 112
Produced 167
Consumed 167
Produced 199
Consumed 199
Produced 235
Consumed 235
Produced 294
Consumed 294
Produced 203
Consumed 203
Produced 111
Consumed 111
Produced 122
Consumed 122
Produced 33
Consumed 33
Produced 273
Consumed 273
Produced 164
Consumed 164
Produced 141
Consumed 141
Produced 211
Consumed 211
Produced 53
Consumed 53
Produced 268
Consumed 268
Produced 47
Consumed 47
Produced 44
Consumed 44
Produced 262
Consumed 262
Produced 57
Consumed 57
Produced 237
Consumed 237
Produced 259
Consumed 259
Produced 23
Consumed 23
Produced 141
Consumed 141
Produced 229
Consumed 229
Produced 178
Consumed 178
Produced 16
Consumed 16
Produced 35
Consumed 35
Produced 290
Consumed 290
Produced 42
Consumed 42
Produced 288
Consumed 288
Produced 106
Consumed 106
Produced 40
Consumed 40
Produced 242
Consumed 242
Produced 64
Consumed 64
Produced 148
Consumed 148
Produced 146
Consumed 146
Produced 105
Consumed 105
Produced 290
Consumed 290
Produced 129
Consumed 129
Produced 70
Consumed 70
Produced 50
Consumed 50
Produced 6
Consumed 6
Produced 201
Consumed 201
Produced 93
Consumed 93
Produced 248
Consumed 248
Produced 129
Consumed 129
Produced 23
Consumed 23
Produced 84
Consumed 84
Produced 154
Consumed 154
Produced 156
Consumed 156
Produced 140
Consumed 140
Produced 166
Consumed 166
Produced 176
Consumed 176
Produced 131
Consumed 131
Produced 208
Consumed 208
Produced 144
Consumed 144
Produced 39
Consumed 39
Produced 26
Consumed 26
Produced 223
Consumed 223
Produced 137
Consumed 137
Produced 238
Consumed 238
Produced 218
Consumed 218
Produced 282
Consumed 282
Produced 129
Consumed 129
Produced 41
Consumed 41
Consumed 41
# Original project instructions: 
https://learn.kent.edu/bbcswebdav/pid-14620835-dt-content-rid-190571344_1/xid-190571344_1
https://learn.kent.edu/bbcswebdav/pid-14620835-dt-content-rid-190571343_1/xid-190571343_1

