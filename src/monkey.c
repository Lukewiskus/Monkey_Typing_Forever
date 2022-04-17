#include "monkey.h"

#define ENTRIES 68514

#define MAXLEN 9



void insert(char* key, struct node** leaf, Compare cmp)
{
    int res;
    if( *leaf == NULL ) {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->value = malloc( strlen (key) +1 );     // memory for key
        strcpy ((*leaf)->value, key);                   // copy the key
        (*leaf)->p_left = NULL;
        (*leaf)->p_right = NULL;
        //printf(  "\nnew node for %s" , key);
    } else {
        res = cmp (key, (*leaf)->value);
        if( res < 0)
            insert( key, &(*leaf)->p_left, cmp);
        else if( res > 0)
            insert( key, &(*leaf)->p_right, cmp);
        else                                            // key already exists
            printf ("Key '%s' already in tree\n", key);
    }
}

int CmpStr(const char *a, const char *b)
{
    return (strcmp (a, b));     // string comparison instead of pointer comparison
}

char *input( void )
{
    static char line[MAXLEN+1];       // where to place key    
    printf("Please enter a string : ");
    fgets( line, sizeof line, stdin );
    return ( strtok(line, "\n" ));    // remove trailing newline
}

int search(char* key, struct node* leaf, Compare cmp) {
    int res;
    if( leaf != NULL ) {
        res = cmp(key, leaf->value);
        if( res < 0)
            return search( key, leaf->p_left, cmp);
        else if( res > 0)
            return search( key, leaf->p_right, cmp);
        else {
            return 1;
        } 
    }
    return 0;
}

void delete_tree(struct node** leaf) {
    if( *leaf != NULL ) {
        delete_tree(&(*leaf)->p_left);
        delete_tree(&(*leaf)->p_right);
        free( (*leaf)->value );         // free the key
        free( (*leaf) );
    }
}

void menu() {
    printf("\nPress 'i' to insert an element\n");
    printf("Press 's' to search for an element\n");
    printf("Press 'p' to print the tree inorder\n");
    printf("Press 'f' to destroy current tree\n");
    printf("Press 'q' to quit\n");
}

void populateTree(){
    FILE *filePointer = fopen("text/words_.txt", "r");
   
    if(filePointer == NULL){
        perror("Cant open file because: ");
    }
    char c;
    int counter = 0;
    char insertWord[71];
    int thisSize = 0;
    char test[100];
    while (fscanf(filePointer, "%s", insertWord) != EOF){
        //ßprintf("%s\n", insertWord);
        insert(insertWord,&p_root, (Compare)CmpStr);
    }
    fclose(filePointer);

    return;
}




int main(int argc, char *argv[]) { 
    char* id = argv[1];
    //printf("monkey: %s\n", id);
    srand(time(NULL));   

    //create the hash map
    //populateHashMap();
    populateTree();

    printf("---Tree Is Populated---\n");
    
    //create its directories
    char *dirname = malloc(300*sizeof(char));

    snprintf(dirname,20,"output/monkey%s",id);

    mkdir(dirname, 0777);

    free(dirname);

    char *newDirectories = malloc(300*sizeof(char));
    for(int i = 2; i < 21; i++){
        snprintf(newDirectories, 200,"output/monkey%s/%d_word_storys",id, i);
        mkdir(newDirectories, 0777);
        memset(newDirectories, 0,200);
    }

    free(newDirectories);

    clock_t c0 = clock();
    clock_t c1;

    char story[10000];
    int numWords = 0;
    memset(story, 0,10000);
    char word[75];
    int run = 1;
    int count = 0;
    int numOfStories = 0;

    double runtime_diff_ms = 0;
    double checkTime = 0;
    char *newStoryPath = malloc(1000*sizeof(char));
    while(runtime_diff_ms < 30){
        c1 = clock();
        runtime_diff_ms = ((c1 - c0) * 1000 / CLOCKS_PER_SEC) / 1000;

        if(strlen(word) > 69){
            memset(word, 0, 70);
        }
        char letter;
        int r = rand() % 28;
        r = r + 97;
        if(r == 123 || r == 124){
            //printf("word after space: %s\n", word);
            numWordsMade++;
            if(search(word, p_root,(Compare)CmpStr)){
                //printf("The word %s was generated, and is english!\n",word);
                strcat(story, word);
                strcat(story, " ");

                numWords++;

            } else {
                if(numWords >= 2){
                    numOfStories++;
                    printf("Monkey %s made the story: %s\n", id, story);

                    snprintf(newStoryPath, 200,"output/monkey%s/%d_word_storys/Story%d.txt",id, numWords, numOfStories);

                    FILE *newFile = fopen(newStoryPath, "w");
                    fprintf(newFile, "%s", story); 
                    fclose(newFile);

                    memset(newStoryPath, 0, 300);

                    
                }            
                memset(story, 0,10000);
                numWords = 0;


            }

            memset(word, 0, 75);
        } else {
            letter = (char)r;
            strncat(word, &letter, 1);
        }   
        //printf("letter typed by monkey: %c number: %d\n", letter, letter);
    }
    free(newStoryPath);
    printf("Monkey %s made %d words\n", id ,numWordsMade);

}