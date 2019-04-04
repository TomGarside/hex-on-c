# include <stdio.h>
# include <strings.h>
# include <stdlib.h>

//hexon
//prints hex values beneath text reads from files or from stdio
// Thomas Garside

void readFile(char*);
char hexNums(int); 
void readStdin(); 
void processLine(char*);

int main(int argc, char** argv){
  // read list of files from argv if none exist read from stdin

  if (argc > 1){
    for( int e = 0; e < argc; e++)
      readFile(argv[e]);
  }
  else{
    readStdin();
  }
  
}
//read from stdin
void readStdin(){
 char* line = NULL;
 size_t len = 0;
 ssize_t read; 
 
while((read = getline(&line, &len, stdin)) != -1){                                       
    processLine(line);                                                                      
    }    
  
}
//process and print a single line 
void processLine(char* line){
    int linelen=strlen(line);   
    char line1[linelen];
    char line2[linelen];

    for( int i=0; i<linelen; i++){
       
      line1[i] = hexNums(line[i]);
      line2[i] = hexNums(line[i]/16);;
    }
    printf(" %s", line);
    printf("|%s|\n",line2);
    printf("|%s|\n",line1); 
 
}

// process a single file 
void readFile(char* filename){
  FILE* file = fopen(filename, "r");
  char* line = NULL;
  size_t len = 0;
  ssize_t read;

  if (file == NULL)
    exit(EXIT_FAILURE);

  while((read = getline(&line, &len, file)) != -1){
    processLine(line);    
  }
  
}

// convert a char to its hex components 
char hexNums(int charVal){
  char hexnum;
  int temp = charVal % 16;
  if (temp < 10){
    hexnum = temp + 48; 
  }
  else {
    hexnum = temp + 55;
  }

  return hexnum; 

}
