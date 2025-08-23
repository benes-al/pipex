```plaintext
        _                 
  _ __ (_)_ __   _____  __
 | '_ \| | '_ \ / _ \ \/ /
 | |_) | | |_) |  __/>  < 
 | .__/|_| .__/ \___/_/\_\
 |_|     |_|              
```

The Pipex project is part of the curriculum at 42 School.

"This project will allow you to explore a UNIX mechanism in detail, one that
you are already familiar with, by implementing it in your program." 

Project Structure

```plaintext
pipex/
├── includes/
│   ├── pipex.h            # Header file with function prototypes and structure declarations
├── src/
│   ├── helpers/           # Helper functions used throughout the project
│   │   ├── ft_bzero.c
│   │   ├── ft_calloc.c
│   │   ├── ft_isallspaces.c
│   │   ├── ft_putstr_fd.c
│   │   ├── ft_split.c
│   │   ├── ft_strjoin.c
│   │   ├── ft_strlen.c
│   │   └── ft_strncmp.c
│   ├── program/           # Core logic for process execution and piping
│   │   ├── child1_process.c
│   │   ├── child2_process.c
│   │   ├── ft_wait.c
│   │   ├── get_all_paths.c
│   │   ├── get_cmd_path.c
│   │   ├── get_cmd.c
│   │   ├── parse_and_open_file1.c
│   │   ├── parse_and_open_file2.c
│   │   ├── parse_and_store_cmd1.c
│   │   └── parse_and_store_cmd2.c
│   ├── utils/             # Utility functions for error handling and memory management
│   │   ├── ft_error.c
│   │   ├── ft_free_struct.c
│   │   └── init_struct.c
│   └── main.c             # Main program entry point
├── .gitignore             # Git ignore file to avoid committing unwanted files
├── Makefile               # Makefile to compile and manage the project
└── README.md              # Project documentation

```

## Pipex Project - Explanation of the Pipe Command

The **Pipex** project is a simplified implementation of the pipe (`|`) operator in a shell environment, where the output of one command is passed as input to another. The shell's pipe functionality connects the standard output (stdout) of one command to the standard input (stdin) of another command.

### Shell Pipe (`|`) Command

In a typical shell, the pipe operator (`|`) allows you to connect two commands, so the output of the first command becomes the input for the second one. Here's a breakdown of how the pipe command works in a shell:

`< file1 cmd1 | cmd2 > file2`

* **`file1`**: The first input file that will be passed to `cmd1` as its input.
* **`cmd1 args1`**: The first command (`cmd1`) is executed with its arguments (`args1`), using `file1` as input.
* **`cmd2 args2`**: The second command (`cmd2`) takes the output of `cmd1` as its input (this is done through a pipe), and is executed with its own set of arguments (`args2`).
* **`file2`**: The final output is redirected to `file2`, capturing the output of `cmd2`.

### Simulation of Pipe in the Pipex Project

The **Pipex** project simulates the shell's behavior of handling pipes, file redirection, and process management in C. Here’s how the project simulates the functionality of the pipe operator:

1. **Opening Files**:
   The program first opens `file1` for reading and `file2` for writing.

2. **Command Execution (cmd1)**:
   `cmd1` is executed as a child process. The program passes the contents of `file1` to `cmd1` as input.

3. **Pipe Setup**:
   A pipe is created between the two commands. The output of `cmd1` is written to the pipe.

4. **Command Execution (cmd2)**:
   `cmd2` is executed as a second child process, reading from the pipe, which contains the output of `cmd1`.

5. **Redirecting Output**:
   The output of `cmd2` is then redirected to `file2`, completing the pipe simulation.

### Program Usage

The program follows the format of the shell's pipe command but requires explicit arguments for each part of the process. Here's the format:

`./pipex file1 cmd1 args1 cmd2 args2 file2`

Where:

* **`file1`**: The input file that will be passed to `cmd1` as its standard input (stdin).
* **`cmd1 args1`**: The first command to be executed, along with its arguments.
* **`cmd2 args2`**: The second command to be executed, with its arguments, receiving input from the pipe.
* **`file2`**: The output file that will store the result of `cmd2`.

### Example Command

For example, if you wanted to count the number of lines in a file (using `wc -l`), you could use the following command in a shell:

`< file1 cat | wc -l > file2`

This would:

1. Take the contents of `file1`, pass it to the `cat` command.
2. Pipe the output of `cat` to `wc -l` to count the number of lines.
3. Redirect the result to `file2`.

### Pipex Simulation with C

In the **Pipex** project, running the following command:

`./pipex file1 cat "" wc -l file2`

Simulates the exact behavior:

* `file1` is read and passed to `cat` via a pipe.
* The output of `cat` is piped to `wc -l`, which counts the lines.
* The result is written into `file2`.

---

This is the overall purpose of the **Pipex** project: to recreate the pipe (`|`) functionality of a shell using C, handling file I/O, pipes, and child processes.

