## UID: 705769539

(IMPORTANT: Only replace the above numbers with your true UID, do not modify spacing and newlines, otherwise your tarfile might not be created correctly)

# A Kernel Seedling

When insmoded into kernel the program loops through current running processes and prints the number
to /proc/count

## Building

Inputting "$make" will build the module through the Makefile

## Running

input "$sudo insmod proc_count.ko" to insert the module into the kernel

## Cleaning Up

input "$sudo rmmod proc_count" to remove the module from the kernel

## Testing

Tested on Release Version: 5.14.8-arch1-1
