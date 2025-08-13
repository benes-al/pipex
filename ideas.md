| Process        | `stdin` from  | `stdout` to    |
| -------------- | ------------- | -------------- |
| `cmd1` (child) | infile        | pipe write-end |
| `cmd2` (child) | pipe read-end | outfile        |



🧠 What You’ll Learn in Pipex

Let’s break it down into manageable sections, with theory, practice exercises, and finally how to implement Pipex step-by-step.
🧱 THEORY YOU NEED TO MASTER
1. Processes and fork()

    A process is a running instance of a program.

    fork() creates a new child process.

    Both parent and child run concurrently from the same point in code.

🧪 Try:

pid_t pid = fork();
if (pid == 0)
    printf("I'm the child!\n");
else
    printf("I'm the parent!\n");

2. Pipes and pipe()

    A pipe is a unidirectional communication channel between two processes.

    pipe(int fd[2]) creates a pipe:

        fd[0] → read end

        fd[1] → write end

🧪 Try:

int fd[2];
pipe(fd);
write(fd[1], "42", 2);
char buf[3] = {0};
read(fd[0], buf, 2);
printf("Received: %s\n", buf);

3. dup2() and file descriptors

    dup2(old_fd, new_fd) duplicates a file descriptor.

    Used to redirect input/output:

        dup2(fd[0], STDIN_FILENO) → input from pipe

        dup2(fd[1], STDOUT_FILENO) → output to pipe

🧪 Try:

int fd[2];
pipe(fd);
dup2(fd[1], STDOUT_FILENO);
printf("This will go to the pipe\n");

4. execve() and executing commands

    Replaces the current process with a new one.

    Use execve(char *path, char *const argv[], char *const envp[])

🧪 Try:

char *args[] = {"/bin/ls", "-l", NULL};
execve(args[0], args, NULL);

5. Handling input/output files

    Use open(), read(), write(), and close() to work with files.

    Redirect input/output using dup2() after opening the file.

🧪 Try:

int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
dup2(fd, STDOUT_FILENO);
printf("This will go into the file\n");

🧪 PRACTICE EXERCISES TO MASTER EACH STEP
Concept	Exercise
fork()	Create a child that prints "child", and parent prints "parent"
pipe()	Send a message from parent to child
dup2()	Redirect stdout to a file
execve()	Run ls from your code
Files	Read from a file and print to stdout
🔧 PIPEX PROJECT EXPLAINED STEP-BY-STEP

Pipex mimics this shell behavior:

< infile cmd1 | cmd2 > outfile

🧩 Step-by-step Plan
✅ Step 1: Parse Arguments

./pipex infile cmd1 cmd2 outfile

🧪 You should be able to extract:

    argv[1]: infile

    argv[2]: cmd1

    argv[3]: cmd2

    argv[4]: outfile

✅ Step 2: Create a pipe

int fd[2];
pipe(fd);

This pipe connects:

    cmd1's stdout → pipe write end

    cmd2's stdin → pipe read end

✅ Step 3: Fork the first child (for cmd1)

if (fork() == 0) {
    int infile = open(argv[1], O_RDONLY);
    dup2(infile, STDIN_FILENO);   // stdin ← infile
    dup2(fd[1], STDOUT_FILENO);   // stdout → pipe write end
    close(fd[0]);                 // close unused read end
    execve(...);                 // run cmd1
}

✅ Step 4: Fork the second child (for cmd2)

if (fork() == 0) {
    int outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(fd[0], STDIN_FILENO);    // stdin ← pipe read end
    dup2(outfile, STDOUT_FILENO); // stdout → outfile
    close(fd[1]);                 // close unused write end
    execve(...);                 // run cmd2
}

✅ Step 5: Parent closes both ends and waits

close(fd[0]);
close(fd[1]);
wait(NULL);
wait(NULL);

🧰 TOOLS YOU NEED TO WRITE:
✅ char **ft_split(char *cmd)

Split a command string like "ls -l" into:

{"ls", "-l", NULL}

✅ char *find_cmd_path(char *cmd, char **envp)

Search PATH for the full path to cmd.
🧑‍💻 PUTTING IT TOGETHER: FILE STRUCTURE EXAMPLE

pipex/
│
├── pipex.c         # Main logic
├── utils.c         # ft_split, find_path, error handling
├── pipex.h         # Header file
└── Makefile

🏁 MINIMUM VIABLE PIPEX IMPLEMENTATION

    Parse arguments.

    Create a pipe.

    Fork two processes.

    In first child:

        Redirect infile to stdin

        Redirect stdout to pipe write end

        Execute cmd1

    In second child:

        Redirect pipe read end to stdin

        Redirect stdout to outfile

        Execute cmd2

    Close pipe ends in parent and wait.

🧱 NEXT STEPS

    Implement ft_split

    Implement find_cmd_path

    Build command execution

    Add error handling

    Handle quotes (bonus)

    Support here_doc (bonus)


