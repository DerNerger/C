int main(){

  int i=0;

  while(i < 5) {
    i = i + 1;
  }

  do {
    i--;
  } while(i > 0);

  for(i=0; i < 5 ; i++){
		break;
  }

  for(;i < 10;){
		i++;
  }

  for(i = 0; i < 5; i--){
		i++;
  }
	
	printf("Erfolgreich beendet! i=%d",i);

  return 0;
}
