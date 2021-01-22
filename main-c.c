#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
	if(argc < 3)
		printf("too few arguments !\n");

	else 
	{

		int srcFile_fd = open(argv[1], O_RDONLY);
		

		if (srcFile_fd == -1)
			printf("there is no file called %s !!\n", argv[1] );
		
		else 
		{
			int desFile_fd = open(argv[2], O_CREAT | O_WRONLY, S_IRUSR);

			if (desFile_fd == -1)
				printf("there is already file called %s !!\n", argv[2] );
			
			else 
			{

				char buffer[2];
				ssize_t charCount ;
				while ( (charCount =read(srcFile_fd, buffer, sizeof(buffer))) )
				{

					write(desFile_fd, buffer, charCount);

				}

				remove(argv[1]);

			}

		}	

	}

}