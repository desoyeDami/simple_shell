# Simple Shell

This is a simple UNIX command-line interpreter created as part of a project for ALX Software Engineering. The goal of this project is to implement a basic shell that can execute commands, handle arguments, and provide some built-in functionality.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)

## Description

This project involves creating a simple shell that mimics the behavior of `/bin/sh`. It can execute external commands, handle arguments, and provide a few built-in commands such as "exit," "env," "setenv," "unsetenv," and "cd." The shell also supports features like command separators (;), logical operators (&& and ||), aliases, variable replacement ($? and $$), and comments (#).

## Features

- Command execution with arguments.
- PATH handling to find and execute programs.
- Built-in commands: exit, env, setenv, unsetenv.
- Variable replacement for $? (exit status) and $$ (process ID).
- Interactive and non-interactive modes.
- Reading commands from files as input.

## Installation

1. Clone the repository to your local machine:

   ```shell
   git clone https://github.com/your-username/simple_shell.git
   ```

2. Compile the shell using gcc:

   ```shell
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```

3. Run the shell:

   ```shell
   ./hsh
   ```

## Usage

The shell provides a command-line interface where you can enter commands. It supports both interactive and non-interactive modes. You can execute external programs, use built-in commands, and take advantage of additional features like command separators, logical operators, aliases, and variable replacement.

### Examples:

Execute a command:
```shell
$ /bin/ls
```

Use built-in commands:
```shell
$ exit
$ env
$ setenv VARIABLE VALUE
$ unsetenv VARIABLE
```

Variable replacement:
```shell
$ echo $?
$ echo $$
```
