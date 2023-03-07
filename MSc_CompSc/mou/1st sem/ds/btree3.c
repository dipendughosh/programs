struct binaryTree{
       int frequency;       
       struct binaryTree * left;
       struct binaryTree * right;
       char word[20];
       };
struct chapter{
       struct chapter *next;
       struct binaryTree *words;
       int distinct;
       int height;
       char chapterTitle[20];
};

struct chapter * readChapters(struct chapter * list, FILE * infile);
struct binaryTree * addWord(struct binaryTree * words, char * word);
int searchFrequency(struct binaryTree * words, char * word);
struct binaryTree * insertWord(struct binaryTree * words, struct binaryTree * temp);
void deleteWord(struct binaryTree * words);


main(){
       FILE * infile;
       char fileName[20], file1[10], file2[10], file3[10], word[20];
       int totalChapters = 0, counter=0, totalSearching=0, totalDeleting=0;
       struct chapter * list = NULL;
      // list = intializeChapter(list);
       
       //Get filename which holds the names of the other 3 files.
       printf("Enter the name of the file: ");
       scanf("%s", &fileName);
       
       infile = fopen(fileName, "r");
       //scan <strong class="highlight">in</strong> the three file names
       fscanf(infile, "%s%s%s", &file1,&file2,&file3);
       //close file which contains names of three other files.     
       fclose(infile);
       //open file number one of the three
       infile = fopen(file1, "r");
       //scan <strong class="highlight">in</strong> the total number of chapters
       fscanf(infile,"%d", &totalChapters);
       //scan each chapter and contents
       for(counter=0; counter < totalChapters; counter++){
               //read chapter words                                                           
               list =  readChapters(list, infile);                               
                                            
       }
      
        //close file 1
        fclose(infile);
       
        //open file 2 for searching
        infile = fopen(file2, "r");
        printf("\nSEARCHING\n");
       
        fscanf(infile, "%d", &totalSearching);
        //read and search each word <strong class="highlight">in</strong> the book
        for(counter=0; counter<totalSearching; counter++){
                      
                  fscanf(infile, "%s", word);
                  printf("%s:\n", word);
                  //search function  also at bottom.                    
                      
        }
         //close file 2               
        fclose(infile);
        //open file 3 for deleting
        infile = fopen(file3, "r");
        printf("\nDELETION\n");
       
        fscanf(infile, "%d", &totalDeleting);
       
        for(counter=0; counter<totalDeleting; counter++){
                      
                  fscanf(infile, "%s", word);
                  printf("%s:\n", word);
                  //delete function at bottom. didnt have time to write it into main.                      
        }
            
       
        //close file 3
        fclose(infile);
        system("pause");      
       
       
}
//create a new chapter and scan <strong class="highlight">in</strong> content
struct chapter * readChapters(struct chapter * list, FILE * infile){
     int totalWords=0, counter=0;
     char word[20];
     //create new chapter
     struct chapter * newChapter = NULL, * current = NULL ;
     newChapter = (struct chapter *) malloc (sizeof(struct chapter));
     newChapter->words = NULL;
     newChapter->next = NULL;
     newChapter->distinct = 0;
     newChapter->height = 0;
     //scan <strong class="highlight">in</strong> chapter title and total words <strong class="highlight">in</strong> this chapter  
       
     fscanf(infile, "%s%d", newChapter->chapterTitle, &totalWords);
    
     printf("-----------------\n%s\n%d\n", newChapter->chapterTitle, totalWords);
     
     //scan each word <strong class="highlight">in</strong> the this chapter
     for(counter=0; counter < totalWords; counter++){
                    
         fscanf(infile, "%s", &word);
         //printf("%s\n", word);
         newChapter->words = addWord(newChapter->words, word);
                   
                    
     }
    
    
     if(list ==NULL){
            
         return newChapter;
            
     }else{
          current = list;
          while(current->next != NULL){
                current = current->next;
                 
          }
                        
          current->next = newChapter;
          
          
          
          return list;
          
      }
    
     
   
     
     
}
//add word to chapter
struct binaryTree * addWord(struct binaryTree * words, char * word){
     int results = 1; 
     struct binaryTree * newWord = (struct binaryTree*) malloc (sizeof(struct binaryTree));
     struct binaryTree * newPlace = NULL;
     strcpy(newWord->word,word);
     newWord->left = NULL;
     newWord->right = NULL;
     newWord->frequency = 1;
     //see if word exists
     results = searchFrequency(words, word);
     
     //if it doesnt exist then add it to the chapter
     if(results == 0){
    
         if(words == NULL){
                 printf("%s\n", newWord->word);
                 return newWord;
         }
         else{
              //add the word to the binary <strong class="highlight">tree</strong>
             newPlace = insertWord(words, newWord);
             
             newPlace = newWord;
             printf("%s\n", newPlace->word);
             return words;
         }
         
       
     }
   

            
             
}
//see if word exists, if it does increment the frequency
int searchFrequency(struct binaryTree * words, char * word){
   
    if(words == NULL){
                 return 0;
    }
    else if(strcmp(words->word, word) < 0){
             searchFrequency(words->right, word);
    }else if(strcmp(words->word, word) > 0){
                searchFrequency(words->left, word);                  
    }
     else //(strcmp(words->word, word) == 0)
    {            
                 words->frequency +=1;
                 return 1;
    }

}
//insert the word into the 
struct binaryTree * insertWord(struct binaryTree * words, struct binaryTree * newWord){
   
    if(words == NULL){
             return words;
              
     }
     else {
          if(strcmp(words->word, newWord->word) < 0){
            words->right = insertWord(words->right, newWord);
            }
          else if(strcmp(words->word, newWord->word) > 0){
            words->left = insertWord(words->left, newWord);       
                      
            }
      }
     return words;
    
    /* if(words == NULL){
             return words;
              
     }
     else if(strcmp(words->word, newWord->word) < 0){
            insertWord(words->right, newWord);
            }
      else if(strcmp(words->word, newWord->word) > 0){
            insertWord(words->left, newWord);                  
     }*/
     
}