char* convert(char* s, int numRows) {
    if(s==NULL||strlen(s)<=1||numRows==1){
        return s;
    }
    int length=strlen(s);
    int step=-1;
    int *rowLength=(int*)calloc(numRows,sizeof(int));
    int currentRow=0;
    for(int i=0;i<length;i++){
        rowLength[currentRow]++;
        if(currentRow==0||currentRow==numRows-1){
            step=-step;
        }
        currentRow+=step;
    }
    char** rows=(char**)malloc(numRows*sizeof(char*));
    int* index=(int*)calloc(numRows,sizeof(int));
    int totalLength=0;
    for(int i=0;i<numRows;i++){
        rows[i]=(char*)malloc((rowLength[i]+1)*sizeof(char));
        totalLength+=rowLength[i];
    }
    currentRow=0;
    step=-1;
    char*result=(char*)malloc((totalLength+1)*sizeof(char));
    for(int i=0;i<length;i++){
        rows[currentRow][index[currentRow]++]=s[i];
        if(currentRow==0||currentRow==(numRows-1)){
            step=-step;
        }
        currentRow+=step;
    }

    int r=0;
    for(int i=0;i<numRows;i++){
        for(int j=0;j<rowLength[i];j++){
            result[r++]=rows[i][j];
        }
        free(rows[i]);
    }
    result[r] = '\0';
    free(rows);
    free(index);
    free(rowLength);
return result;


}
