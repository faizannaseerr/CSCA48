/* 
 * CSC A48 - Assignment 3 - Ingredient networks
 * 
 * In this assignment, you will practice and strengthen your
 * understanding of graph and recursion. The application 
 * you're working on is a simple network for studying
 * how food ingredients interact. 
 * 
 * This kind of network is the basic model that very
 * powerful systems such as IMB's Watson use as the 
 * basis for creating new combinations of ingredients
 * that are likely to go well together, but haven't been
 * used in previously printed recipes.
 * 
 * Your work here has several components:
 * 
 * - Understanding how the graph is represented by an
 *   adjacency matrix.
 * - Using the adjacency matrix to figure out, given
 *   an input ingredient, what other ingredients it is
 *   related to directly
 * - Using the adjacency matrix to determine, given
 *   a specific ingredient, which others are related
 *   to it directly *and* indirectly by a distance 
 *   of k hops along the graph (k>=1).
 * - Get lits of ingredients that are related, but
 *   not including ingredients from a separate
 *   list of ingredients
 * - *crunchy* Using the adjacency matrix that, given
 *   a recipe (which a list of ingredients) and 
 *   a target ingredient (part of the recipe) to
 *   replace, finds the best replacement from the
 *   remaining ingredients in the graph and updates
 *   the recipe.
 * 
 * This file contains the functions that set up
 * the adjacency matrix and the list of ingredients
 * for you. We provide you with 2 graphs, a 
 * small one with 10 ingredients (and an adjacency
 * matrix of size 10x10), and a full one with 
 * 400 ingredients (adjacency matrix is 400x400).
 * 
 * Use the 10x10 while implementing and testing your
 * solution, and only move to the full-size one once
 * you're confident your code works well.
 * 
 * Select which matrix to use by uncommenting the
 * respective #define statement below.
 * 
 * Sections where you have to implement code are
 * clearly marked
 * ********
 * TO DO:
 * ********
 * 
 * (c) F. Estrada, March 2022
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024
#ifndef __testing
#define MAT_SIZE 10	// Use the small graph
// #define MAT_SIZE 400	// Use full-size graph
#endif

// The following are GLOBAL variables you can use
// anywhere in your code. They include the 
// adjacency matrix, as well as an array of strings
// to store the ingredient names.
double AdjMat[MAT_SIZE][MAT_SIZE];
char ingredients[MAT_SIZE][MAX_STR_LEN];

// Bare-bones implementation of a linked-list of
// integers, you can use it to return the ingredient
// lists requested from functions you have to
// implement. DO NOT CHANGE THE IMPLEMENTATION
// OF THE LINKED LISTS.

typedef struct intNode_struct
{
    int  x;
    struct intNode_struct *next;
} intNode;

intNode *insertInt(intNode *h, int x)
{
  // Inserts the int 'x' into the linked list 
  // whose head is at the address in 'h'
  
  intNode *newNode;
  
  newNode=(intNode *)calloc(1,sizeof(intNode));
  newNode->x=x;
  newNode->next=NULL;
  
  if (h!=NULL)
    newNode->next=h;
  
  return newNode;
}

int searchInt(intNode *h, int x)
{
  // Search the linked list for the value 'x', if
  // found, it returns 1, else it returns 0
  while (h!=NULL)
  {
    if (h->x==x) return 1;
    h=h->next;
  }
  return 0;
}

intNode *deleteList(intNode *h)
{
  // Delete list and free memory
  intNode *q;
  if (h==NULL) return NULL;
  
  while (h!=NULL)
  {
     q=h->next;
     free(h);
     h=q;
  }
  
  return NULL;
}

// Read the adjacency matrix from file, and read the ingredient
// names
void load_ingredients(void)
{
  // Loads the adjacency matrix and ingredients list from file,
  // N must be either 10 (small graph), or 400 (full-size).
  
  FILE *f;
  int n=MAT_SIZE;
  
  if (n==10) f=fopen("AdjMat_small.dat","rb");
  else f=fopen("AdjMat_full.dat","rb");
  if (f==NULL)
  {
    printf("Can not open file with adjacency matrix. Please make sure it's in this directory\n");
    return;
  }
  fread(&AdjMat[0][0],n*n*sizeof(double),1,f);
  fclose(f);
  
  if (n==10) f=fopen("Ingredient_names_small.txt","r");
  else f=fopen("Ingredient_names_full.txt","r");
  if (f==NULL)
  {
    printf("Can not open file with ingredient names. Please make sure it's in this directory\n");
    return;
  }
  printf("Reading ingredient names. Available ingredient are:\n");
  for (int i=0; i<n; i++)
  {
    fgets(&ingredients[i][0],MAX_STR_LEN,f);
    for (int j=0; j<strlen(ingredients[i]); j++)
      if (ingredients[i][j]==10||ingredients[i][j]==13) ingredients[i][j]=0;
    printf("%s\n",ingredients[i]);
  }
  fclose(f);
}

/***************************************************************
 * The part of the assignment you need to implement starts below
 ***************************************************************/

void print_ingredients(intNode *h)
{
    /*
     * This function prints out all the ingredients corresponding
     * to the ingredient indexes stored in the linked list
     * whose head is 'h'.
     */
    
    /*****
     * TO Do:
     * Complete this function
     *****/

    intNode *traversal_pointer = NULL;
    traversal_pointer = h;
    while (traversal_pointer != NULL){
      printf("%s\n", ingredients[traversal_pointer -> x]);
      traversal_pointer = traversal_pointer -> next;
    }
}

int ingredient_index(char source_ingredient[MAX_STR_LEN])
{
    /*
     * This function looks into the array with ingredient
     * names for one that matches the requested 
     * 'source_ingredient'. If a match is found, it
     * returns the index at which the matching ingredient
     * name was found.
     * 
     * If the 'source_ingredient' is *not* in the ingredients
     * array, the function returns -1
     */
    
    /******
     * TO Do:
     * Implement this function
     *****/

    for (int i = 0; i < MAT_SIZE; i++){
      if (strcmp(source_ingredient, ingredients[i]) == 0){
        return i;
      }
    }
    return -1;
}

void related_ingredients(char source_ingredient[MAX_STR_LEN])
{
    /*
     * This function prints out all the ingredients related
     * to the source ingredient. 
     * 
     * One per line, with no additional characters or symbols.
     *
     * Format of the adjacency matrix:
     * 
     * AdjMat[i][j] = 0 if two ingredients i and j are not directly linked
     *                (no edge in the graph between them, this means
     *                 they never appeared together in one recipe)
     * AdjMat[i][j] > 0 if two ingredients i and j are neighbours (they
     * 			appeared together in at least a recipe). The
     * 			actual value indicates how many times these two
     * 			ingredients appeared together in a recipe
     * 
     * Make sure you understand what this is telling you about the
     * ingredients in your graph. You'll need it later
     */
    
    /**********
     * TO DO:
     * Implement this function
     * ********/

  int ing_index = ingredient_index(source_ingredient);
  for (int j = 0; j < MAT_SIZE; j++){
    if (AdjMat[ing_index][j] > 0 && j != ing_index){
      printf("%s\n", ingredients[j]);
    }
  }

}

intNode *related_k_dist(intNode *h, char source_ingredient[MAX_STR_LEN], int k, int dist)
{
    /*
     * This function determines the ingredients related to the
     * specified source ingredient by a distance of at most k.
     * k >= 1 
     * 
     * (for k=1, this produces the same list as related_ingredients)
     * 
     * For instance, if k=2, the list should contain all the
     * ingredients who are neighbours of source_ingredient[]
     * as well as the ingredients that are neighbours of
     * the neighbours (distance=2).
     * 
     * If k=3, then we want source_ingredients' neighbours, its
     * neighbours' neighbours, and its neighbours' neighbours'
     * neighbours. And so on.
     * 
     * *****  This function MUST use recursion  ******
     * 
     * Ingredients are returned as *indexes*, so, for instance,
     * if we find a related ingredient 'chicken' is stored at
     * index 7 in ingredients[][], then we store 7 in the
     * linked list of related ingredients.
     * 
     * The returned list MUST CONTAIN NO DUPLICATES.
     * 
     * And be smart about it, or you'll end up in an infinite
     * recursion! So think carefully about the base case(s)
     * and about what the recursive case must do.
     *
     * Example call:
     * 
     * Our test code may call your function in this way:
     * 
     * intNode *head=NULL;
     * head=related_k_dist(head,"rice",2,0);
     * 
     * After that call, 'head' must point to a linked list with
     * all the ingredients related to 'rice' up to a distance of
     * 2 away.
     * 
     * It's up to *you* to figure out what the 'dist' parameter
     * is for!
     * 
     */
    
    /*******
     * TO DO:
     * Complete this function
     *******/

    int ing_index = ingredient_index(source_ingredient);

    if (k - 1 == dist){
      for (int j = 0; j < MAT_SIZE; j++){
        if (AdjMat[ing_index][j] > 0 && j != ing_index && searchInt(h, j) == 0){
          h = insertInt(h, j);
        }
      }
      return h;
    }
    else {
      for (int j = 0; j < MAT_SIZE; j++){
        if(AdjMat[ing_index][j] > 0 && j != ing_index){
          if (searchInt(h, j) == 0){
            if (h == NULL){
              intNode *newNode;
              newNode = (intNode *)calloc(1, sizeof(intNode));
              newNode -> x = j;
              newNode -> next = NULL;
              h = newNode;
            }
            else {
              h = insertInt(h, j);
            }
          }
          h = related_k_dist(h, ingredients[j], k, dist + 1);
        }
      }
    }
    return h;
}

/////////////////////////////////////helper///////////////////////////////////////////

intNode *related_with_restrictions_helper(intNode *h, char source_ingredient[MAX_STR_LEN], int k, int dist, intNode *h1, char avoid[MAX_STR_LEN])
{
    
    int ing_index = ingredient_index(source_ingredient);

    if (k - 1 == dist){
      for (int j = 0; j < MAT_SIZE; j++){
        if (AdjMat[ing_index][j] > 0 && j != ing_index && searchInt(h, j) == 0 && searchInt(h1, j) == 0 && j != ingredient_index(avoid)){
          h = insertInt(h, j);
        }
      }
      return h;
    }
    else {
      for (int j = 0; j < MAT_SIZE; j++){
        if(AdjMat[ing_index][j] > 0 && j != ing_index && searchInt(h, j) == 0 && searchInt(h1, j) == 0 && j != ingredient_index(avoid)){
          if (h == NULL){
            intNode *newNode;
            newNode = (intNode *)calloc(1, sizeof(intNode));
            newNode -> x = j;
            newNode -> next = NULL;
            h = newNode;
          }
          else {
            h = insertInt(h, j);
          }
          h = related_with_restrictions_helper(h, ingredients[j], k, dist + 1, h1, avoid);
        }
      }
    }
    
    return h;
}

/////////////////////////////////////helper///////////////////////////////////////////

intNode *related_with_restrictions(char source_ingredient[MAX_STR_LEN], char avoid[MAX_STR_LEN], int k_source, int k_avoid)
{
    /*
     * This function returns a linked list that contains the indexes of
     * all ingredients related to source_ingredient[] with a distance
     * of at most k_source.
     * 
     * BUT, the list *must not contain* any ingredients related to avoid[]
     * (including avoid[] itself) by a distance of up to k_avoid.
     * 
     * Example:
     * 
     * intNode *head=NULL;
     * head=related_with_restrictions("rice", "nuts", 2, 0);
     * (yes, we know the function doesn't take the head of a linked list as a parameter,
     *  that's not a mistake)
     * 
     * Should return a pointer to the head of a list of ingredients related to 
     * 'rice' by a distance of up to 2, NOT INCLUDING 'nuts'.
     * 
     * intNode *head=NULL;
     * head=related_with_restrictions("rice", "chicken", 2, 1);
     * 
     * Should return a list of ingredients related to 'rice' by a distance
     * of up to 2, NOT INCLUDING 'nuts' and any ingredients related
     * to 'nuts' with a distance of up to 1.
     * 
     */
    
    /****
     * TO DO:
     * Implement this function
     *****/

    intNode *h1 = NULL;
    h1 = related_k_dist(h1, avoid, k_avoid, 0);
    intNode *h = NULL;
    h = related_with_restrictions_helper(h, source_ingredient, k_source, 0, h1, avoid);
    return h;
}

/////////////////////////////////////helper///////////////////////////////////////////

int potential_replacement_p1(char ingredient[MAX_STR_LEN], char recipe[10][MAX_STR_LEN], char to_change[MAX_STR_LEN])
{
  int ing_index = ingredient_index(ingredient);
  int count = 0;
  int appearance_value = 0;
  int recipe_ing_index;
  while (strcmp(recipe[count], "") != 0){
    if (strcmp(recipe[count], to_change) != 0){
      recipe_ing_index = ingredient_index(recipe[count]);
      appearance_value = appearance_value + AdjMat[ing_index][recipe_ing_index];
    }
    count += 1;
    if (count == 10){
      break;
    }
  }

  return appearance_value;
}

int potential_replacement_p2(char ingredient[MAX_STR_LEN], char recipe[10][MAX_STR_LEN], char to_change[MAX_STR_LEN])
{
  int ing_index = ingredient_index(ingredient);
  int count = 0;
  int ing_relation_value = 0;
  int recipe_ing_index;
  while (strcmp(recipe[count], "") != 0){
    if (strcmp(recipe[count], to_change) != 0){
      recipe_ing_index = ingredient_index(recipe[count]);
      if (AdjMat[ing_index][recipe_ing_index] > 0){
        ing_relation_value += 1;
      }
    }
    count += 1;
    if (count == 10){
      break;
    }
  }
  return ing_relation_value;

}
/////////////////////////////////////helper///////////////////////////////////////////

void substitute_ingredient(char recipe[10][MAX_STR_LEN], char to_change[MAX_STR_LEN])
{
  /*
   * *CRUNCHY!*
   * 
   * This function takes a recipe (which is an array of ingredients with up to 10
   * ingredients), and replaces the one in 'to_change' by *the most compatible
   * ingredient from the graph*
   * 
   * By most compatible, we mean the ingredient that appears most often with 
   * the remaining ingredients in the recipe.
   * 
   * The definition above may seem fuzzy, but it's not if you consider that the
   * weights in the adjacency matrix are meaningful.
   * 
   * As you see, nothing is returned - the result of this function is that the
   * ingredient 'to_change' is replaced in the recipe by the most compatible
   * ingredient given the graph that is *not already in the recipe*.
   * 
   * Assume that the input recipe is such that *all ingredients are in the
   * array of ingredients* (i.e. you don't have to worry about ingredients
   * that don't exists).
   * 
   * However, the recipe *may have less than 10 ingredients*, in which case
   * unused ingredients will be set to empty strings ("")
   */
  
   /*******
    * TO DO:
    * Complete this function!
    ******/

   // helper function that goes through all the ingredients in the ingredients list and
   // checks total score between other 9 ingredients in recipe
   // ingredient with highest score takes place of to_change

    // int high = 0;
    // char replacement[MAX_STR_LEN];
    // for (int i = 0; i < MAT_SIZE; i++){
    //   if (strcmp(ingredients[i], to_change) != 0){
    //     int potential_replacement_value = potential_replacement(ingredients[i], recipe, to_change);
    //     if (potential_replacement_value > high){
    //       high = potential_replacement_value;
    //       strcpy(replacement, ingredients[i]);
    //     }
    //   }
    // }

    // for (int i = 0; i < 10; i++){
    //   if (strcmp(recipe[i], to_change) == 0){
    //     strcpy(recipe[i], replacement);
    //     break;
    //   }
    // }

    int high1 = -1;
    int high2 = -1;
    int index = 0;
    char replacement[MAT_SIZE - 1][MAX_STR_LEN];
    char to_change_with[MAX_STR_LEN];

    for (int i = 0; i < MAT_SIZE; i++){
      if (strcmp(ingredients[i], to_change) != 0){
        int potential_replacement_value2 = potential_replacement_p2(ingredients[i], recipe, to_change);
        if (potential_replacement_value2 > high2){
          index = 0;
          high2 = potential_replacement_value2; 
          strcpy(replacement[index], ingredients[i]);
        }
        else if (potential_replacement_value2 == high2){
          index += 1;
          strcpy(replacement[index], ingredients[i]);
        }
      }
    }

    for (int i = 0; i < index + 1; i++){
      int potential_replacement_value1 = potential_replacement_p1(replacement[i], recipe, to_change);
      if (potential_replacement_value1 >= high1){
        high1 = potential_replacement_value1;
        strcpy(to_change_with, replacement[i]);
      }
    }

    for (int i = 0; i < 10; i++){
      if (strcmp(recipe[i], to_change) == 0){
        strcpy(recipe[i], to_change_with);
        break;
      }
    }

}

