/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:35:51 by cnorton-          #+#    #+#             */
/*   Updated: 2023/08/22 14:35:54 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//checks for PATH variable in envp using ft_strnstr
//splits PATH by directory (using ft_split and splitting by :)
//adds a slash and the cmd (potential_path/cmd) to the end of each directory
//checks through potential paths until finding an executable file
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;
	char	*add_slash;
	char	*check_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		add_slash = ft_strjoin(paths[i], "/");
		check_path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (access(check_path, F_OK | X_OK) == 0)
		{
			free_things(paths);
			return (check_path);
		}
		free(check_path);
		i++;
	}
	return (free_things(paths), NULL);
}

//calls split_pipex: an edited version of ft_split
//which splits cmd by spaces unless inside quotation marks
//calls find_path which finds the path to an executable file 
//for the bash cmd inside the environmental pointer
//replaces current process with the bash command using execve
void	ft_exec(char *arg, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	cmd = split_pipex(arg);
	path = find_path(cmd[0], envp);
	i = -1;
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		perror("error creating path");
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, envp) == -1)
		perror("error execve");
	exit(EXIT_FAILURE);
}

//opens infile
//infile is duplicated to STDIN
//write end of pipe is duplicated to STDOUT
//calls ft_exec function for cmd1
void	child_process(char **argv, char **envp, int *pipe_fd)
{
	int		infile;

	close(pipe_fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("ERROR opening infile");
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(infile);
	close(pipe_fd[1]);
	ft_exec(argv[2], envp);
}

//opens or creates outfile if it doesn't exits
//0644 is the default permissions of files created by bash
//read end of pipe is duplicated as STDIN
//outfile is duplicated as STDOUT
//calls ft_exec function for cmd2
void	parent_process(char **argv, char **envp, int *pipe_fd)
{
	int		outfile;

	close(pipe_fd[1]);
	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("ERROR opening outfile");
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(pipe_fd[0]);
	ft_exec(argv[3], envp);
}

//checks for correct no. of arguments
//forks into 2 processes
//waitpid is called to ensure that parent process 
//doesn't terminate before child process finishes
int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("incorrect arguments, follow format:\n", 2);
		ft_putstr_fd("./pipex infile \"cmd1\" \"cmd2\" outfile", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("ERROR creating pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		child_process(argv, envp, pipe_fd);
	else
	{
		parent_process(argv, envp, pipe_fd);
		waitpid(pid, NULL, 0);
	}
	return (0);
}
