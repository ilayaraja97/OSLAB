# Lab 4
-----
* Downloaded and unziped the linux kernel version 4.9.7 into Desktop
* Made a directory inside the root folder by the name raja using `mkdir raja`.
* And so that the kernel knows that this folder is part of the kernel added I edited the Makefile at line 842 from `core-y += kernel/ mm/ fs/ ipc/ security/ crypto/ block/ ` to `core-y += kernel/ mm/ fs/ ipc/ security/ crypto/ block/ raja/`. 
* Made a C file containing the definition of my syscall called `sys_raja()` in the file raja.c this file is in this repo.
* Followed by a makefile in the same directory which contains `obj-y = hello` done so that the make process knows the name of the object file to be generated.
* Add a line in `arch/x64/entry/syscalls/syscall_64.tbl` this maps the syscall. Added `332 common raja sys_raja`.
* Added the syscall to the header file syscalls.h. `asmlinkage` is used to indicate that the parameter of the function will be on the stack.
* Before compiling this command was run `sudo apt-get install fakeroot build-essential ncurses-dev xz-utils libssl-dev bc`.
* `make menuconfig` to make a configuration file for compilation
* `make -j 4` compile on 4 cores.
* `sudo make maodules_install install` to install the new kernel.
* `reboot` to see the effect.
* now after this another file named userspace.c was made.
* it called `syscall(332)` 
* after running the program execute `dmesg` in the last line raja would be printed.
