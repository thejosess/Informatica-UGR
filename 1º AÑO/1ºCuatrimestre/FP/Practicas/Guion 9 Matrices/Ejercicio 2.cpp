cu=0;
	for(i=0;i<f;i++){
		for(j=0;j<c;j++){
			cout<<"Introduce el "<<j+1<<" valor de la "<<i+1<<" fila: ";
			cin>>m[i][j];
		}
	}
	for(j=0;j<c;j++){
		colunica=true;
		for(k=0;k<c;k++){
			colrep=true;
			for(i=0;i<f;i++){
				if(m[i][j]!=m[i][k]){
					colrep=false;
				}
				if(colrep==true&&j!=k){
					colunica=false;
				}
			}
		}
		if(colunica==true){
			cu++;
		}
	}
	cout<<"El numero de columnas unicas es: "<<cu;
