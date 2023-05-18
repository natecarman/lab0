# Hash Hash Hash
This lab is a test of proficiency with locking and making thread-safe programs, by adding thread locks to a
hash table implementation.

## Building
```shell
$make
```

## Running
```shell
 ./hash-table-tester -t 8 -s 50000
Generation: 35,383 usec
Hash table base: 963,518 usec
  - 0 missing
```

## First Implementation
In the `hash_table_v1_add_entry` function, I initialized a static pthread_mutex_t variable "mutex". Then I locked the
mutex before the part of the hash_table_v2_add_entry function that involves modifying values and unlocked the mutex
at the end of the function. By locking around this portion, I know that only one thread at a time will be modifying
values within the hash, which means that no two threads will be modifying values at the same time. Therfore, the
danger of race conditions has been averted, and the code will perform accurately consistently. 
Then I destroyed the mutex at the end of the hash table destruction function, and checked after each mutex call
for errors

### Performance
```shell
./hash-table-tester -t 8 -s 50000
Generation: 35,383 usec
Hash table base: 963,518 usec
  - 0 missing
Hash table v1: 3,370,583 usec
  - 0 missing
```

This time version 1 is slower than the base version because only one thread can add to the hash table at a time
due to the universal mutex lock

## Second Implementation
In the `hash_table_v2_add_entry` function, I made a pthread_mutex_t "mutex" as a data member of the hash_table_entry
and called each hash entry's specific mutex lock whenever that hash entry was being accessed. This way all other threads can add to the hash table as long as they are not trying to access the specific hash entry that one thread is already accessing. By having # table entries = # mutex, we ensure maximum efficiency along with thread safety

### Performance
```shell
./hash-table-tester -t 8 -s 50000
Generation: 35,383 usec
Hash table base: 963,518 usec
  - 0 missing
Hash table v1: 3,370,583 usec
  - 0 missing
Hash table v2: 193,121 usec
  - 0 missing
```

This time the speed up is roughly 4 or 5 times faster than the base version, this is because all threads are changing the hash table at the same time unless they are trying to access the same hash entry. By having all threads modifying simultaneously, the program can finish much faster

## Cleaning up
```shell
make clean
```