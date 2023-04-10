# 42 pipex

Pipex is a project that re-creates in C the way two commands are piped together via | in the shell.

```bash
$> < file1 cmd1 | cmd2 > file2
```
will look like this:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```

