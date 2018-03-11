//      findmaxsubarray.c
//      
//      Copyright 2018 jlee <jack1234822@yahoo.com>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int *find_max_subarray(int *array,int num);

int main(int argc, char** argv)
{	
	int i=0;
	struct timeval time_start,time_end;
	double time_used;
	int *array = (int *)malloc(sizeof(int)*atoi(argv[2]));
	if(array==NULL)
		perror("array=NULL\n");
	freopen(argv[1],"r",stdin);
	while(scanf("%d",&array[i])==1){
		i++;
	}
	gettimeofday(&time_start,NULL);
	int *ret = find_max_subarray(array,i);
	gettimeofday(&time_end,NULL);
	time_used =  1000000*(time_end.tv_sec-time_start.tv_sec)+time_end.tv_usec-time_start.tv_usec;
	printf("time used : %lfus\n",time_used);
	printf("----left point: %d----right point: %d----sum: %d\n",ret[0],ret[1],ret[2]);
	return 0;
}

int *find_max_subarray(int *array,int num){
	if(num<1)
			return NULL;
	int l,r,ll,current_max,candidate_max;
	l = r = ll = 0;
	current_max	= candidate_max = array[0];
	int i;
	for(i=1;i<num;i++){
		if(candidate_max<0){
			candidate_max=array[i];
			ll=i;
		}
		else
			candidate_max+=array[i];
		if(current_max>candidate_max)
			continue;
		else{
			l=ll;
			r=i;
			current_max = candidate_max;
		}
	}
	int *ret = malloc(sizeof(int)*3);
	ret[0] = l;
	ret[1] = r;
	ret[2] = current_max;
	return ret;
}
