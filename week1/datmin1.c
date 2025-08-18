#include <stdio.h>

enum KDD {
preprocessing = 1,
integration,
selection,
mining,
evaluation,
presentation
};

void explain(int value){
	if(value == preprocessing)
		printf("tahap ke %d dalam KDD\n",value);
        else if(value == integration)
                printf("tahap ke %d dalam KDD\n",value);        
	else if(value == selection)
                printf("tahap ke %d dalam KDD\n",value);	
        else if(value == mining)
                printf("tahap ke %d dalam KDD\n",value);
        else if(value == evaluation)
                printf("tahap ke %d dalam KDD\n",value);
        else
                printf("tahap ke %d dalam KDD",value);
};

int main(){
explain(integration);
explain(selection);
explain(mining);
return 0;
};
