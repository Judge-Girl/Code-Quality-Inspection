#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	int count;
	struct node *left;
	struct node *right;
	int count_left;
	int count_right;
}
node;

node* Initialize( void )
{
	node *root = malloc( sizeof( node ) );
	*root = (node){ 0, 0, NULL, NULL, 0, 0 };
	return root;
}

/* void Arrange( node *root )
{
	
} */

#ifndef DEBUG
	void Print( node *root )
	{
		if( root->left != NULL )
		{
			Print( root->left );
		}
		
		if( root->data != 0 )
		{
			printf( "%c %d ", root->data, root->count );
		}
		
		if( root->right != NULL )
		{
			Print( root->right );
		}
	}
#endif

#ifdef DEBUG
	void Print( node *root )
	{
		if( root->left != NULL )
		{
			Print( root->left );
		}
		
		printf( "data = %c, count = %d ", root->data, root->count );
		if( root->left != NULL )
		{
			printf( "left EXISTS, count = %d, ", root->count_left );
		}
		else
		{
			printf( "left = NULL, count = %d, ", root->count_left );
		}
		if( root->right != NULL )
		{
			printf( "right EXISTS, count = %d\n", root->count_right );
		}
		else
		{
			printf( "right = NULL, count = %d\n", root->count_right );
		}
		
		if( root->right != NULL )
		{
			Print( root->right );
		}
	}
#endif

int Insert( node *root, int data, int count, int position )
{
	#ifdef DEBUG
		printf( "#DEBUG : Insert %d %c at position %d, ", count, data, position );
	#endif
	if( root->left == NULL && root->right == NULL && root->data == 0 )
	{
		#ifdef DEBUG
			printf( "EMPTY, insert\n" );
		#endif
		root->data = data;
		root->count = count;
		
		return 0;
	}
	else if( root->data == data && position > root->count_left && position <= root->count_left + root->count + 1 )
	{
		#ifdef DEBUG
			printf( "same character, add\n" );
		#endif
		root->count += count;
		
		return 0;
	}
	else if( position <= root->count_left + 1 )
	{
		if( root->left != NULL )
		{
			#ifdef DEBUG
				printf( "left EXISTS, next\n" );
			#endif
			Insert( root->left, data, count, position );
			root->count_left += count;
			
			return -1;
		}
		else
		{
			#ifdef DEBUG
				printf( "left = NULL, insert\n" );
			#endif
			node *new_node = malloc( sizeof( node ) );
			*new_node = (node){ data, count, NULL, NULL, 0, 0 };
			root->left = new_node;
			root->count_left = count;
			
			return -1;
		}
	}
	else if( position <= root->count_left + root->count )
	{
		#ifdef DEBUG
			printf( "in the middle, insert\n" );
		#endif
		node *new_left = malloc( sizeof( node ) );
		node *new_right = malloc( sizeof( node ) );
		
		*new_left = (node){ root->data, position - root->count_left - 1, root->left, NULL, root->count_left, 0 };
		*new_right = (node){ root->data, root->count_left + root->count - position + 1, NULL, root->right, 0, root->count_right };
		*root = (node){ data, count, new_left, new_right, new_left->count_left + new_left->count, new_right->count_right + new_right->count };
		
		return 0;
	}
	else if( root->right != NULL )
	{
		#ifdef DEBUG
			printf( "right EXISTS, next\n" );
		#endif
		Insert( root->right, data, count, position - root->count - root->count_left );
		root->count_right += count;
		
		return 1;
	}
	else
	{
		#ifdef DEBUG
			printf( "right = NULL, insert\n" );
		#endif
		node *new_node = malloc( sizeof( node ) );
		*new_node = (node){ data, count, NULL, NULL, 0, 0 };
		root->right = new_node;
		root->count_right = count;
		
		return 1;
	}
}

int main( void )
{
	char command[ 8 ] = {0};
	node *root = Initialize( );
	
	while( ~scanf( "%s", command ) )
	{
		if( strcmp( command, "print" ) == 0 )
		{
			Print( root );
			printf( "$\n" );
		}
		else if( strcmp( command, "insert" ) == 0 )
		{
			char position[ 16 ] = {0};
			char data[ 4 ] = {0};
			int count = 0;
			scanf( "%s%s%d", position, &data, &count );
			#ifdef DEBUG
				printf( "#DEBUG : position = %s, data = %s, count = %d\n", position, data, count );
			#endif
			if( strcmp( position, "left" ) == 0 )
			{
				Insert( root, (int)( data[ 0 ] ), count, 1 );
			}
			else if( strcmp( position, "right" ) == 0 )
			{
				Insert( root, (int)( data[ 0 ] ), count, root->count + root->count_left + root->count_right + 1 );
			}
			else
			{
				Insert( root, (int)( data[ 0 ] ), count, atoi( position ) );
			}
			
			//Arrange( root );
		}
	}
	
	return 0;
}
