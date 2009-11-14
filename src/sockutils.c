#include "../includes/sockheads.h"

//create socket, bind to port
int createsocket(struct sockaddr_in *saddr, char *caddr, int iport, int stype, int bopt)
{
	int sockfd;
	memset(saddr, 0, sizeof(saddr));
	saddr->sin_family = AF_INET;
	if(!strcmp("any",caddr))
		saddr->sin_addr.s_addr = htons(INADDR_ANY);
	else
		if(inet_pton(AF_INET, caddr, &saddr->sin_addr) == -1)
			progerror("pton error");
	if (iport != 0)
		saddr->sin_port=htons(iport);
	if((sockfd = socket(AF_INET, stype, 0)) == -1)
		progerror("socket creation error");
	if(bopt == 1)
	{
		if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &bopt, sizeof(int)) == -1)
			progerror("reuse port error");
		//printf("trying to bind to port %d\n", iport);
		if(bind(sockfd, (struct sockaddr *)saddr, sizeof(struct sockaddr)) == -1)
			progerror("bind error");
	}

	return sockfd;
}

//print error and exit
void progerror(char *errorstr)
{
	printf("%s, with errno %d\n",errorstr, errno);
	exit(1);
}