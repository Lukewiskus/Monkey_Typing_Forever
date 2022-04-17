//In H FILE

// typedef struct hashNode {
//     char word[MAXVALUESZ];
//     struct hashNode *next;

// } hashNode;


// int Hash(char* key);
// void populateHashMap();

// hashNode *createNewNode(char* word);
// // hashNode *InsertNewNode(hashNode *root, char *word);

// struct hashNode *hashMap[HASH_TABLE_SIZE];

// int check[HASH_TABLE_SIZE];

//Other code


// int Hash(char* key){
//     int hash = 0;
//     int length = strlen(key);
//     for (int j=0; j < length; j++) {
//         hash = 31 * hash + key[j];
//     }

//     return abs(hash % 300000);
// }

// /*
// creates a new hashNode
// */
// hashNode *createNewNode(char* word){
//     hashNode *newNode = (hashNode *)malloc(sizeof(hashNode));
//     strcpy(newNode->word, word);
//     newNode->next = NULL;
//     return newNode;
// }

// /*
// returns a new node or inserts a new node if there is already a node there,
// and then returns the root
// */

// hashNode *InsertNewNode(hashNode *root, char *word){
// 	hashNode *tempNode = root;
// 	if(root == NULL){
//         return createNewNode(word);
//     }
	
// 	while(tempNode -> next != NULL){
//         tempNode = tempNode -> next;
//     }

// 	tempNode -> next = createNewNode(word);
// 	return root;
// }

// void populateHashMap(){
//     int bufferLength = 70;
//     int hash = 0;
//     for(int i = 0; i < 300000; i++){
//         hashMap[i] = NULL;
//     }
//     //Open File
//     char buffer[bufferLength];
//     FILE *filePointer = fopen("text/100k_wrds_.txt", "r");
//     if(filePointer == NULL){
//         perror("Cant open file because: ");
//     }
//     char c;
//     int counter = 0;
//     char insertWord[71];
//     int thisSize = 0;
//     while ((c = fgetc (filePointer)) != EOF ){
//         if(c =='\n'){
//             hash = Hash(insertWord);
//             //printf("word is:  %s  \n", insertWord);
//             thisSize = strlen(insertWord); //Total size of string
//             //insertWord[thisSize-1] = '\0';
//             hashMap[hash] = InsertNewNode(hashMap[hash], insertWord);
//             memset(insertWord, 0, 71);
//             counter++;
//         }else {
//              strncat(insertWord, &c, 1);
//         }
       
//     }
//     printf("counter: %d\n", counter);


//     /*
//     1: grab each word which is seperate by a new line
//     2: decrement it once to get rid of \n char
//     3: hash the word to be inserted
//     4: use InsertNewNode which will insert a new node into the hash map,
//        and if there is already a node there, insert the node at the end 
//        of the linked list
//     */

//     fclose(filePointer);
// }

// int InHashTable(char* newWord){
//     int hash = Hash(newWord);
//     //printf("word given %s, hash generated %d\n", word, hash);
//     if(hash >= 300000){
//         return 0;
//     }
//     if(hashMap[hash] != NULL){
//         if(strcmp(hashMap[hash]->word, newWord) == 0){
//             return 1;
//         } else {
//             hashNode *tempNode = hashMap[hash];

//             while(tempNode[hash].next != NULL){
//                 if(strcmp(tempNode[hash].word, newWord) == 0){
//                     return 1;
//                 } else {
//                     tempNode[hash].next = tempNode[hash].next;
//                 }
//             }

//         }
//     } 
//     return 0;
// }

