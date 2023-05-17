# Hash Hash Hash
This lab is a test of proficiency with locking and making thread-safe programs, by adding thread locks to a
hash table implementation.

## Building
```shell
$make
```

## Running
```shell
$ ./hash-table-tester -t (# of Cores to Run On) -s (# of iterations)
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

```

This time version 1 is xxx

## Second Implementation
In the `hash_table_v2_add_entry` function, xxx

### Performance
```shell

```

This time the speed up is xxx

## Cleaning up
```shell

```