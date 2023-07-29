/* C program that creates five zombie processes */

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
	pid_t zombie;
	int i;

	for (i = 0; i < 5; i++)
	{
		zombie = fork();
		if (!zombie)
			return (0);
		printf("Zombie process created, PID: %d\n", zombie);
	}

	infinite_while();
	return (0);
}
