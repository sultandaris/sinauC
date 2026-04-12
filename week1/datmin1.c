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
		printf("tahap ke %d KDD\n membersihkan data yang cacat\n ",value);
        else if(value == integration)
                printf("tahap ke %d KDD\n"
		"menggabungkan data yang cocok dari tabel\n",value);        
	else if(value == selection)
                printf("tahap ke %d KDD\n"
		"memilih kolom/fitur yang paling membawa dampak pada tujuan\n",value);	
        else if(value == mining)
                printf("tahap ke %d KDD\n" 
		"mengaplikasikan algoritma dalam data" 
		"dan melakukan interpretasi atau mengembangkan model\n",value);
        else if(value == evaluation)
                printf("tahap ke %d KDD\n"
		"mengamati dan menilai kinerja" 
		"dari model ataupun hasil interpretasi\n",value);
        else
                printf("tahap ke %d KDD\n"
		"mempresentasikan hasil kepada"
		"stakeholder melalui visualisasi\n",value);
};

int main(){

explain(integration);
explain(selection);
explain(mining);
return 0;

};
