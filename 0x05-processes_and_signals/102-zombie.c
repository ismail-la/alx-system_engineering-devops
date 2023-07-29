/* C program that creates 5 zombie processes */

/*
 * File: 102-zombie.c
 * Auth: Brennan D Baraban
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>


/**
 * infinite_while - Function that run an infinite while loop.
 *
 * Return: Always 0
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Main function that creates five zombie processes.
 *
 * Return: Always 0
 */

int main(void)
{
	char count = 0;
	pid_t pid;

	while (count < 5)
	{
		pid = fork();
	
		if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
			sleep(1);
			count++;
		}
		else
			exit(0);
	}

	infinite_while();
	return (EXIT_SUCCESS);
}
