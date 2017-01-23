# rsh : Toy Shell
----
### The files
* `shell.c` contains the source code of the toy shell which I created.
* `shell.out` is the compiled executable of `shell.c` made using `gcc -g shell.c -o shell.out`.

### Compilation
`gcc -g shell.c -o shell.out` to create the executable then `./shell.out` to execute it.

### Features
* Prints a prompt.
* Reads line from user.
* Parses the input delimited by spaces.
* Spawns a child process to execute a command. And parent waits unless a '&' is used.
* After child finishes process the shell prompts for input again.
* `exit` and `Ctrl+D` exits from shell.
* `cd` changes directory.
* Processes will run in the background if suceeded by '&'. eg `<program name> <arg1> <arg2> ... <argN> [&] [<program name> <arg1> <arg2> .... <argN> [&] [<program name> <arg1> <arg2> .... <argN> [&] [...] ...] ]` is also valid.
* Pipelines work in the following form `<program1> <arglist1> | <program2> <arglist2> | ... | <programN> <arglistN> [&]` but with it exists bugs that have not been resolved. eg: `cat textfile | grep something` works but `cat textfile | gzip -f` doesn't work.

